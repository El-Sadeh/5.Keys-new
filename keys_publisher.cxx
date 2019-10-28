
#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()

#include "keys.hpp"

void publisher_main(int domain_id, int sample_count)
{
    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant (domain_id);

    // Create a Topic -- and automatically register the type
    dds::topic::Topic<RadarInfo> topic (participant, "Example RadarInfo");

    // Create a DataWriter with default Qos (Publisher created in-line)
    dds::pub::DataWriter<RadarInfo> writer(dds::pub::Publisher(participant), topic);

	//arbitrary numbers of first ID numbers.
	int32_t nextRadarID = 1;
	int32_t nextTrackID = 100;

	//Random constat positions bounderies 
	const int ARBITRARY_LOW = 10;
	const int ARBITRARY_HIGH = 99;

	//generate tracks with given IDs
	RadarInfo sample1(nextRadarID, nextTrackID);
	nextTrackID++;
	RadarInfo sample2(nextRadarID, nextTrackID);

    for (int count = 0; count < sample_count || sample_count == 0; count++) {
        // Modify the data to be written here
		
		//"see" track1 between cycles 5 to 15, then "lose" track1, then "see" it again at cycle 24.
		if (((count > 4) && (count < 20))||(count > 24))
		{
			sample1.UpdateRadarTrackData(ARBITRARY_LOW, ARBITRARY_HIGH);
			std::cout << "Writing RadarInfo1, count " << count << std::endl;
			writer.write(sample1);
		}

		//At the 10th cycle, the second radar track is discovered:
		if (count > 9)
		{
			sample2.UpdateRadarTrackData(ARBITRARY_LOW, ARBITRARY_HIGH);
			std::cout << "Writing RadarInfo2, count " << count << std::endl;
			writer.write(sample2);
		}
		//20th cycle - dispose the 1st track
		if (count == 20)
		{
			writer.dispose_instance(writer.lookup_instance(sample1));
			std::cout << std::endl << "Disposed of sample1... ";
		}
		//Reminder: at cycle 24 track1 is re-discovered.

		if (count == 30)
		{
			writer.dispose_instance(writer.lookup_instance(sample1));
			std::cout << std::endl << "Disposed of sample1... ";
			writer.dispose_instance(writer.lookup_instance(sample2));
			std::cout << std::endl << "Disposed of sample2... ";
			std::cout << std::endl << "Shutting down Radar";
			break;
		}


        rti::util::sleep(dds::core::Duration(1));
    }
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
        publisher_main(domain_id, sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in publisher_main(): " << ex.what() << std::endl;
        return -1;
    }

    // RTI Connext provides a finalize_participant_factory() method
    // if you want to release memory used by the participant factory singleton.
    // Uncomment the following line to release the singleton:
    //
    // dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}

