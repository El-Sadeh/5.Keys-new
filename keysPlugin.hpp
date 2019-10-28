

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from keys.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef keysPlugin_517510321_h
#define keysPlugin_517510321_h

#include "keys.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define TrackPositionPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define TrackPositionPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define TrackPositionPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define TrackPositionPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define TrackPositionPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern TrackPosition*
TrackPositionPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern TrackPosition*
TrackPositionPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern TrackPosition*
TrackPositionPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
TrackPositionPluginSupport_copy_data(
    TrackPosition *out,
    const TrackPosition *in);

NDDSUSERDllExport extern void 
TrackPositionPluginSupport_destroy_data_w_params(
    TrackPosition *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
TrackPositionPluginSupport_destroy_data_ex(
    TrackPosition *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
TrackPositionPluginSupport_destroy_data(
    TrackPosition *sample);

NDDSUSERDllExport extern void 
TrackPositionPluginSupport_print_data(
    const TrackPosition *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
TrackPositionPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
TrackPositionPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
TrackPositionPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
TrackPositionPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
TrackPositionPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    TrackPosition *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
TrackPositionPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    TrackPosition *out,
    const TrackPosition *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
TrackPositionPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const TrackPosition *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
TrackPositionPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    TrackPosition *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
TrackPositionPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const TrackPosition *sample); 

NDDSUSERDllExport extern RTIBool 
TrackPositionPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    TrackPosition **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
TrackPositionPlugin_deserialize_from_cdr_buffer(
    TrackPosition *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern RTIBool
TrackPositionPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
TrackPositionPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
TrackPositionPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
TrackPositionPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
TrackPositionPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const TrackPosition * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
TrackPositionPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
TrackPositionPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
TrackPositionPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
TrackPositionPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const TrackPosition *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
TrackPositionPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    TrackPosition * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
TrackPositionPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    TrackPosition ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
TrackPositionPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    TrackPosition *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
TrackPositionPlugin_new(void);

NDDSUSERDllExport extern void
TrackPositionPlugin_delete(struct PRESTypePlugin *);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
TrackClassificationPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const TrackClassification *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
TrackClassificationPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    TrackClassification *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
TrackClassificationPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
TrackClassificationPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
TrackClassificationPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
TrackClassificationPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
TrackClassificationPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const TrackClassification * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
TrackClassificationPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
TrackClassificationPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
TrackClassificationPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const TrackClassification *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
TrackClassificationPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    TrackClassification * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
TrackClassificationPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    TrackClassification *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
TrackClassificationPluginSupport_print_data(
    const TrackClassification *sample, const char *desc, int indent_level);

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct RadarInfo
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct RadarInfo)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* RadarInfo must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct RadarInfo.
*/
typedef  class RadarInfo RadarInfoKeyHolder;

#define RadarInfoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define RadarInfoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define RadarInfoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define RadarInfoPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define RadarInfoPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define RadarInfoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define RadarInfoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RadarInfo*
RadarInfoPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern RadarInfo*
RadarInfoPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern RadarInfo*
RadarInfoPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
RadarInfoPluginSupport_copy_data(
    RadarInfo *out,
    const RadarInfo *in);

NDDSUSERDllExport extern void 
RadarInfoPluginSupport_destroy_data_w_params(
    RadarInfo *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
RadarInfoPluginSupport_destroy_data_ex(
    RadarInfo *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
RadarInfoPluginSupport_destroy_data(
    RadarInfo *sample);

NDDSUSERDllExport extern void 
RadarInfoPluginSupport_print_data(
    const RadarInfo *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern RadarInfo*
RadarInfoPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern RadarInfo*
RadarInfoPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
RadarInfoPluginSupport_destroy_key_ex(
    RadarInfoKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
RadarInfoPluginSupport_destroy_key(
    RadarInfoKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
RadarInfoPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
RadarInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
RadarInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
RadarInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
RadarInfoPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    RadarInfo *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
RadarInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    RadarInfo *out,
    const RadarInfo *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
RadarInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const RadarInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
RadarInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    RadarInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
RadarInfoPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const RadarInfo *sample); 

NDDSUSERDllExport extern RTIBool 
RadarInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    RadarInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
RadarInfoPlugin_deserialize_from_cdr_buffer(
    RadarInfo *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern RTIBool
RadarInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
RadarInfoPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
RadarInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
RadarInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
RadarInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const RadarInfo * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
RadarInfoPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
RadarInfoPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
RadarInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
RadarInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const RadarInfo *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
RadarInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    RadarInfo * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
RadarInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    RadarInfo ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
RadarInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    RadarInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
RadarInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    RadarInfoKeyHolder *key, 
    const RadarInfo *instance);

NDDSUSERDllExport extern RTIBool 
RadarInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    RadarInfo *instance, 
    const RadarInfoKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
RadarInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const RadarInfo *instance);

NDDSUSERDllExport extern RTIBool 
RadarInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
RadarInfoPlugin_new(void);

NDDSUSERDllExport extern void
RadarInfoPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* keysPlugin_517510321_h */

