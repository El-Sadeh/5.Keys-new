

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from keys.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "keys.hpp"
#include "keysPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- TrackPosition: 

TrackPosition::TrackPosition() :
    m_x_ (0.0f) ,
    m_y_ (0.0f) ,
    m_z_ (0.0f)  {
}   

TrackPosition::TrackPosition (
    float x,
    float y,
    float z)
    :
        m_x_( x ),
        m_y_( y ),
        m_z_( z ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
TrackPosition::TrackPosition(TrackPosition&& other_) OMG_NOEXCEPT  :m_x_ (std::move(other_.m_x_))
,
m_y_ (std::move(other_.m_y_))
,
m_z_ (std::move(other_.m_z_))
{
} 

TrackPosition& TrackPosition::operator=(TrackPosition&&  other_) OMG_NOEXCEPT {
    TrackPosition tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void TrackPosition::swap(TrackPosition& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_x_, other_.m_x_);
    swap(m_y_, other_.m_y_);
    swap(m_z_, other_.m_z_);
}  

bool TrackPosition::operator == (const TrackPosition& other_) const {
    if (m_x_ != other_.m_x_) {
        return false;
    }
    if (m_y_ != other_.m_y_) {
        return false;
    }
    if (m_z_ != other_.m_z_) {
        return false;
    }
    return true;
}
bool TrackPosition::operator != (const TrackPosition& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
float& TrackPosition::x() OMG_NOEXCEPT {
    return m_x_;
}

const float& TrackPosition::x() const OMG_NOEXCEPT {
    return m_x_;
}

void TrackPosition::x(float value) {
    m_x_ = value;
}

float& TrackPosition::y() OMG_NOEXCEPT {
    return m_y_;
}

const float& TrackPosition::y() const OMG_NOEXCEPT {
    return m_y_;
}

void TrackPosition::y(float value) {
    m_y_ = value;
}

float& TrackPosition::z() OMG_NOEXCEPT {
    return m_z_;
}

const float& TrackPosition::z() const OMG_NOEXCEPT {
    return m_z_;
}

void TrackPosition::z(float value) {
    m_z_ = value;
}

std::ostream& operator << (std::ostream& o,const TrackPosition& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "x: " << std::setprecision(9) <<sample.x()<<", ";
    o << "y: " << std::setprecision(9) <<sample.y()<<", ";
    o << "z: " << std::setprecision(9) <<sample.z() ;
    o <<"]";
    return o;
}

std::ostream& operator << (std::ostream& o,const TrackClassification& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    switch(sample.underlying()){
        case TrackClassification::AIR:
        o << "TrackClassification::AIR" << " ";
        break;
        case TrackClassification::SURFACE:
        o << "TrackClassification::SURFACE" << " ";
        break;
        case TrackClassification::LAND:
        o << "TrackClassification::LAND" << " ";
        break;
    }
    return o;
}

// ---- RadarInfo: 

RadarInfo::RadarInfo() :
    m_radarID_ (0) ,
    m_trackID_ (0) ,
    m_classification_(TrackClassification::get_default())  {
}   

//ELAD: I made this constructor to generate basic radar contact information
RadarInfo::RadarInfo(int32_t radarID, int32_t trackID)
{
	//generate radar and track IDs
	m_radarID_ = (radarID);
	m_trackID_ = (trackID);

	std::default_random_engine generator;
	std::uniform_int_distribution<short> distribution(0, 2); 
	short randomClassfication = (short)distribution(generator);
	switch (randomClassfication)
	{
	case 0:
		m_classification_ = TrackClassification::AIR;
		break;
	case 1:
		m_classification_ = TrackClassification::SURFACE;
		break;
	case 2:
		m_classification_ = TrackClassification::LAND;
		break;
	default:
		m_classification_ = TrackClassification::SURFACE;
		break;
	}
}
RadarInfo::RadarInfo (
    int32_t radarID,
    int32_t trackID,
    const TrackPosition& position,
    const TrackClassification& classification)
    :
        m_radarID_( radarID ),
        m_trackID_( trackID ),
        m_position_( position ),
        m_classification_( classification ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
RadarInfo::RadarInfo(RadarInfo&& other_) OMG_NOEXCEPT  :m_radarID_ (std::move(other_.m_radarID_))
,
m_trackID_ (std::move(other_.m_trackID_))
,
m_position_ (std::move(other_.m_position_))
,
m_classification_ (std::move(other_.m_classification_))
{
} 

RadarInfo& RadarInfo::operator=(RadarInfo&&  other_) OMG_NOEXCEPT {
    RadarInfo tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void RadarInfo::swap(RadarInfo& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_radarID_, other_.m_radarID_);
    swap(m_trackID_, other_.m_trackID_);
    swap(m_position_, other_.m_position_);
    swap(m_classification_, other_.m_classification_);
}  

bool RadarInfo::operator == (const RadarInfo& other_) const {
    if (m_radarID_ != other_.m_radarID_) {
        return false;
    }
    if (m_trackID_ != other_.m_trackID_) {
        return false;
    }
    if (m_position_ != other_.m_position_) {
        return false;
    }
    if (m_classification_ != other_.m_classification_) {
        return false;
    }
    return true;
}
bool RadarInfo::operator != (const RadarInfo& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
int32_t& RadarInfo::radarID() OMG_NOEXCEPT {
    return m_radarID_;
}

const int32_t& RadarInfo::radarID() const OMG_NOEXCEPT {
    return m_radarID_;
}

void RadarInfo::UpdateRadarTrackData(int low, int high)
{
	this->position().x(low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high - low))));
	this->position().y(low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high - low))));
	this->position().z(low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high - low))));
}

void RadarInfo::radarID(int32_t value) {
    m_radarID_ = value;
}

int32_t& RadarInfo::trackID() OMG_NOEXCEPT {
    return m_trackID_;
}

const int32_t& RadarInfo::trackID() const OMG_NOEXCEPT {
    return m_trackID_;
}

void RadarInfo::trackID(int32_t value) {
    m_trackID_ = value;
}

TrackPosition& RadarInfo::position() OMG_NOEXCEPT {
    return m_position_;
}

const TrackPosition& RadarInfo::position() const OMG_NOEXCEPT {
    return m_position_;
}

void RadarInfo::position(const TrackPosition& value) {
    m_position_ = value;
}

TrackClassification& RadarInfo::classification() OMG_NOEXCEPT {
    return m_classification_;
}

const TrackClassification& RadarInfo::classification() const OMG_NOEXCEPT {
    return m_classification_;
}

void RadarInfo::classification(const TrackClassification& value) {
    m_classification_ = value;
}

std::ostream& operator << (std::ostream& o,const RadarInfo& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "radarID: " << sample.radarID()<<", ";
    o << "trackID: " << sample.trackID()<<", ";
    o << "position: " << sample.position()<<", ";
    o << "classification: " << sample.classification() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<TrackPosition> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member TrackPosition_g_tc_members[3]=
                {

                    {
                        (char *)"x",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"y",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"z",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode TrackPosition_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"TrackPosition", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        TrackPosition_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for TrackPosition*/

                if (is_initialized) {
                    return &TrackPosition_g_tc;
                }

                TrackPosition_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                TrackPosition_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                TrackPosition_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &TrackPosition_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<TrackPosition>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<TrackPosition>::get())));
        }

        template<>
        struct native_type_code<TrackClassification> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member TrackClassification_g_tc_members[3]=
                {

                    {
                        (char *)"AIR",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        TrackClassification::AIR, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"SURFACE",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        TrackClassification::SURFACE, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"LAND",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        TrackClassification::LAND, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode TrackClassification_g_tc =
                {{
                        DDS_TK_ENUM,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"TrackClassification", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        TrackClassification_g_tc_members, /* Members */
                        DDS_VM_NONE   /* Type Modifier */        
                    }}; /* Type code for TrackClassification*/

                if (is_initialized) {
                    return &TrackClassification_g_tc;
                }

                is_initialized = RTI_TRUE;

                return &TrackClassification_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::EnumType& dynamic_type<TrackClassification>::get()
        {
            return static_cast<const dds::core::xtypes::EnumType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<TrackClassification>::get())));
        }

        template<>
        struct native_type_code<RadarInfo> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member RadarInfo_g_tc_members[4]=
                {

                    {
                        (char *)"radarID",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"trackID",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"position",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"classification",/* Member name */
                        {
                            3,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode RadarInfo_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RadarInfo", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        RadarInfo_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for RadarInfo*/

                if (is_initialized) {
                    return &RadarInfo_g_tc;
                }

                RadarInfo_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                RadarInfo_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                RadarInfo_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< TrackPosition>::get().native();

                RadarInfo_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< TrackClassification>::get().native();

                is_initialized = RTI_TRUE;

                return &RadarInfo_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<RadarInfo>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<RadarInfo>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<TrackPosition>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                TrackPositionPlugin_new,
                TrackPositionPlugin_delete);
        }

        std::vector<char>& topic_type_support<TrackPosition>::to_cdr_buffer(
            std::vector<char>& buffer, const TrackPosition& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = TrackPositionPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = TrackPositionPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<TrackPosition>::from_cdr_buffer(TrackPosition& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = TrackPositionPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create TrackPosition from cdr buffer");
        }

        void topic_type_support<TrackPosition>::reset_sample(TrackPosition& sample) 
        {
            rti::topic::reset_sample(sample.x());
            rti::topic::reset_sample(sample.y());
            rti::topic::reset_sample(sample.z());
        }

        void topic_type_support<TrackPosition>::allocate_sample(TrackPosition& sample, int, int) 
        {
        }

        void topic_type_support<RadarInfo>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                RadarInfoPlugin_new,
                RadarInfoPlugin_delete);
        }

        std::vector<char>& topic_type_support<RadarInfo>::to_cdr_buffer(
            std::vector<char>& buffer, const RadarInfo& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = RadarInfoPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = RadarInfoPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<RadarInfo>::from_cdr_buffer(RadarInfo& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = RadarInfoPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create RadarInfo from cdr buffer");
        }

        void topic_type_support<RadarInfo>::reset_sample(RadarInfo& sample) 
        {
            rti::topic::reset_sample(sample.radarID());
            rti::topic::reset_sample(sample.trackID());
            rti::topic::reset_sample(sample.position());
            rti::topic::reset_sample(sample.classification());
        }

        void topic_type_support<RadarInfo>::allocate_sample(RadarInfo& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.position(),  -1, -1);
            rti::topic::allocate_sample(sample.classification(),  -1, -1);
        }

    }
}  

