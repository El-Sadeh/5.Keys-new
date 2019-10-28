

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from keys.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef keys_517510321_hpp
#define keys_517510321_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include<chrono>
#include<random>
#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

class NDDSUSERDllExport TrackPosition {

  public:
    TrackPosition();

    TrackPosition(
        float x,
        float y,
        float z);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    TrackPosition (TrackPosition&&) = default;
    TrackPosition& operator=(TrackPosition&&) = default;
    TrackPosition& operator=(const TrackPosition&) = default;
    TrackPosition(const TrackPosition&) = default;
    #else
    TrackPosition(TrackPosition&& other_) OMG_NOEXCEPT;  
    TrackPosition& operator=(TrackPosition&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    float& x() OMG_NOEXCEPT; 
    const float& x() const OMG_NOEXCEPT;
    void x(float value);

    float& y() OMG_NOEXCEPT; 
    const float& y() const OMG_NOEXCEPT;
    void y(float value);

    float& z() OMG_NOEXCEPT; 
    const float& z() const OMG_NOEXCEPT;
    void z(float value);

    bool operator == (const TrackPosition& other_) const;
    bool operator != (const TrackPosition& other_) const;

    void swap(TrackPosition& other_) OMG_NOEXCEPT ;

  private:

    float m_x_;
    float m_y_;
    float m_z_;

};

inline void swap(TrackPosition& a, TrackPosition& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TrackPosition& sample);

struct TrackClassification_def {
    enum type {
        AIR,      
        SURFACE,      
        LAND     
    };
    static type get_default(){ return AIR;}
};

typedef dds::core::safe_enum<TrackClassification_def> TrackClassification;
NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const TrackClassification& sample);

class NDDSUSERDllExport RadarInfo {

  public:
    RadarInfo();

	RadarInfo::RadarInfo(int32_t radarID, int32_t trackID);

    RadarInfo(
        int32_t radarID,
        int32_t trackID,
        const TrackPosition& position,
        const TrackClassification& classification);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    RadarInfo (RadarInfo&&) = default;
    RadarInfo& operator=(RadarInfo&&) = default;
    RadarInfo& operator=(const RadarInfo&) = default;
    RadarInfo(const RadarInfo&) = default;
    #else
    RadarInfo(RadarInfo&& other_) OMG_NOEXCEPT;  
    RadarInfo& operator=(RadarInfo&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

	void UpdateRadarTrackData(int low, int high);


    int32_t& radarID() OMG_NOEXCEPT; 
    const int32_t& radarID() const OMG_NOEXCEPT;
    void radarID(int32_t value);

    int32_t& trackID() OMG_NOEXCEPT; 
    const int32_t& trackID() const OMG_NOEXCEPT;
    void trackID(int32_t value);

    TrackPosition& position() OMG_NOEXCEPT; 
    const TrackPosition& position() const OMG_NOEXCEPT;
    void position(const TrackPosition& value);

    TrackClassification& classification() OMG_NOEXCEPT; 
    const TrackClassification& classification() const OMG_NOEXCEPT;
    void classification(const TrackClassification& value);

    bool operator == (const RadarInfo& other_) const;
    bool operator != (const RadarInfo& other_) const;

    void swap(RadarInfo& other_) OMG_NOEXCEPT ;

  private:

    int32_t m_radarID_;
    int32_t m_trackID_;
    TrackPosition m_position_;
    TrackClassification m_classification_;

};

inline void swap(RadarInfo& a, RadarInfo& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const RadarInfo& sample);

namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<TrackPosition> {
            NDDSUSERDllExport static std::string value() {
                return "TrackPosition";
            }
        };

        template<>
        struct is_topic_type<TrackPosition> : public dds::core::true_type {};

        template<>
        struct topic_type_support<TrackPosition> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const TrackPosition& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(TrackPosition& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(TrackPosition& sample);

            NDDSUSERDllExport 
            static void allocate_sample(TrackPosition& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<RadarInfo> {
            NDDSUSERDllExport static std::string value() {
                return "RadarInfo";
            }
        };

        template<>
        struct is_topic_type<RadarInfo> : public dds::core::true_type {};

        template<>
        struct topic_type_support<RadarInfo> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const RadarInfo& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(RadarInfo& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(RadarInfo& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RadarInfo& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        template<>
        struct dynamic_type<TrackPosition> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<TrackPosition> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<TrackClassification> {
            typedef dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility<TrackClassification> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<RadarInfo> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<RadarInfo> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // keys_517510321_hpp

