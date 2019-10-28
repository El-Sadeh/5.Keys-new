#include <ctime>
#include <algorithm>
#include <iostream>
#include <chrono>

#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
// Or simply include <dds/dds.hpp> 

#include "keys.hpp"

class RadarInfoReaderListener : public dds::sub::NoOpDataReaderListener<RadarInfo> {
public:

	RadarInfoReaderListener() : count_(0)
	{
	}

	void on_data_available(dds::sub::DataReader<RadarInfo>& reader)
	{
		// Take all samples
		dds::sub::LoanedSamples<RadarInfo> samples = reader.take();

		for (dds::sub::LoanedSamples<RadarInfo>::iterator sample_it = samples.begin();
			sample_it != samples.end(); sample_it++) {

			if (sample_it->info().valid())
			{
				count_++;				
				if (sample_it->info()->state().view_state().operator==(DDS_NEW_VIEW_STATE))
				{
					std::cout << std::endl << "New Track recieved! trackID:" << sample_it->data().trackID();
					std::cout << " sent by radar #" << sample_it->data().radarID();
					//now get the sending timestamp (in seconds) into sampleSendingTimeInSec
					long sampleSendingTimeInSec = sample_it->info().source_timestamp().to_secs();
					
					// convert to year, month,day, hour, minute, sec
					time_t tsInMili = sampleSendingTimeInSec;
					tm local_tm = *localtime(&tsInMili);
					short year = (local_tm.tm_year + 1900);
					short month = (local_tm.tm_mon + 1);
					short day = (local_tm.tm_mday);
					short hour = (local_tm.tm_hour);
					short minutes = (local_tm.tm_min);
					short sec = (local_tm.tm_sec);

					std::cout << " at " << std::setfill('0') << std::setw(2) << day << "/" << month << "/";
					std::cout << year << " at ";
					std::cout << std::setfill('0') << std::setw(2) << hour << ":" << minutes << ":" << sec;
					std::cout << std::endl << std::endl;

				}
				std::cout << sample_it->data() << std::endl;
			}
			else //In case of not valid data:
			{
				if (sample_it->info()->state().instance_state() ==
					(dds::sub::status::InstanceState::not_alive_disposed()))
				{
					RadarInfo tempRadarInfo;
					//Get the key value (radarID and trackID in this case) of the
					//"not_alive_disposed" track data and put it into tempRadarInfo:
					reader.key_value(tempRadarInfo, sample_it->info().instance_handle());
					std::cout << std::endl << "Track ID: " << tempRadarInfo.trackID() << " from radar #"
						<< tempRadarInfo.radarID() << " was disposed." << std::endl << std::endl;
				}
				//the following IF block happens several times even when there is a living writer.
				/*
				if (sample_it->info()->state().instance_state().not_alive_no_writers().operator==(DDS_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE))
				{
					std::cout << "All radars went offline." << std::endl;
				}  */
			}
		}
	}

	int count() const
	{
		return count_;
	}

private:
	int count_;
};

void subscriber_main(int domain_id, int sample_count)
{
	// Create a DomainParticipant with default Qos
	dds::domain::DomainParticipant participant(domain_id);

	// Create a Topic -- and automatically register the type
	dds::topic::Topic<RadarInfo> topic(participant, "Example RadarInfo");

	// Create a DataReader with default Qos (Subscriber created in-line)
	RadarInfoReaderListener listener;
	dds::sub::DataReader<RadarInfo> reader(
		dds::sub::Subscriber(participant),
		topic,
		dds::core::QosProvider::Default().datareader_qos(),
		&listener,
		dds::core::status::StatusMask::data_available());

	while (listener.count() < sample_count || sample_count == 0) {
		std::cout << "RadarInfo subscriber sleeping for 4 sec..." << std::endl;

		rti::util::sleep(dds::core::Duration(4));
	}

	// Unset the listener to allow the reader destruction
	// (rti::core::ListenerBinder can do this automatically)
	reader.listener(NULL, dds::core::status::StatusMask::none());
}

int main(int argc, char *argv[])
{

	int domain_id = 0;
	int sample_count = 0; // infinite loop

	if (argc >= 2) {
		domain_id = atoi(argv[1]);
	}
	if (argc >= 3) {
		sample_count = atoi(argv[2]);
	}

	// To turn on additional logging, include <rti/config/Logger.hpp> and
	// uncomment the following line:
	// rti::config::Logger::instance().verbosity(rti::config::Verbosity::STATUS_ALL);

	try {
		subscriber_main(domain_id, sample_count);
	}
	catch (const std::exception& ex) {
		// This will catch DDS exceptions
		std::cerr << "Exception in subscriber_main(): " << ex.what() << std::endl;
		return -1;
	}

	// RTI Connext provides a finalize_participant_factory() method
	// if you want to release memory used by the participant factory singleton.
	// Uncomment the following line to release the singleton:
	//
	// dds::domain::DomainParticipant::finalize_participant_factory();

	return 0;
}

