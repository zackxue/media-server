#ifndef _rfc4566_sdp_h_
#define _rfc4566_sdp_h_

#ifdef __cplusplus
extern "C" {
#endif

enum { SDP_V_VERSION_0 = 0 };
enum { SDP_C_NETWORK_UNKNOWN=0, SDP_C_NETWORK_IN };
enum { SDP_C_ADDRESS_UNKNOWN=0, SDP_C_ADDRESS_IP4, SDP_C_ADDRESS_IP6 };
enum { SDP_A_SENDONLY = 0, SDP_A_RECVONLY, SDP_A_SENDRECV };

void* sdp_parse(const char* s);
void sdp_destroy(void* sdp);

int sdp_version_get(void* sdp);

/// 5.2. Origin ("o=")
/// @param[out] username username
/// @param[out] session session id
/// @param[out] version session version
/// @param[out] network network type, IN-internet
/// @param[out] addrtype address type, IP4-IP v4, IP6-IP v6
/// @param[out] address connection address, multicast/unicast address
/// @return 0-ok, -1 if don't have connection
int sdp_origin_get(void* sdp, const char **username, const char** session, const char** version, const char** network, const char** addrtype, const char** address);
int sdp_origin_get_network(void* sdp); // SDP_C_NETWORK_IN
int sdp_origin_get_addrtype(void* sdp); // SDP_C_ADDRESS_IP4/SDP_C_ADDRESS_IP6

/// @return NULL-if don't have keyword
const char* sdp_session_get_name(void* sdp);
const char* sdp_session_get_information(void* sdp);
const char* sdp_uri_get(void* sdp);

int sdp_email_count(void* sdp);
int sdp_phone_count(void* sdp);
const char* sdp_email_get(void* sdp, int idx);
const char* sdp_phone_get(void* sdp, int idx);

// c=IN IP4 224.2.36.42/127
// c=IN IP4 224.2.1.1/127/3
// c=IN IP6 FF15::101/3
/// @param[out] network network type, IN-internet
/// @param[out] addrtype address type, IP4-IP v4, IP6-IP v6
/// @param[out] address connection address, multicast/unicast address
/// @return 0-ok, -1 if don't have connection
int sdp_connection_get(void* sdp, const char** network, const char** addrtype, const char** address);
int sdp_connection_get_address(void* sdp, char* ip, int bytes); // ipv4/ipv6 address, alloc by caller
int sdp_connection_get_network(void* sdp); // SDP_C_NETWORK_IN
int sdp_connection_get_addrtype(void* sdp); // SDP_C_ADDRESS_IP4/SDP_C_ADDRESS_IP6

int sdp_bandwidth_count(void* sdp);
const char* sdp_bandwidth_get_type(void* sdp, int idx); // CT/AS
int sdp_bandwidth_get_value(void* sdp, int idx); // kbps-kilobits per second

int sdp_timing_count(void* sdp);
int sdp_timing_repeat_count(void* sdp, int time);
int sdp_timing_repeat_offset_count(void* sdp, int time);
int sdp_timing_timezone_count(void* sdp, int time);
int sdp_timing_get(void* sdp, int idx, const char** start, const char** stop);
const char* sdp_repeat_get(void* sdp, int idx);
const char* sdp_timezone_get(void* sdp, int idx);

/// @return NULL-if don't have keyword
const char* sdp_encryption_get(void* sdp);

int sdp_media_count(void* sdp);
int sdp_media_connection_count(void* sdp);
const char* sdp_media_get_information(void* sdp, int media);
int sdp_media_bandwidth_count(void* sdp, int media);
const char* sdp_media_bandwidth_get_type(void* sdp, int media, int idx); // CT/AS
int sdp_media_bandwidth_get_value(void* sdp, int media, int idx); // kbps-kilobits per second

void sdp_version_set(void* sdp, int version);
void sdp_session_set_name(void* sdp, const char* name);
void sdp_session_set_information(void* sdp, const char* info);
void sdp_uri_set(void* sdp, const char* uri);
void sdp_email_set(void* sdp, const char* email);
void sdp_phone_set(void* sdp, const char* phone);
void sdp_connection_set(void* sdp, const char* connection);
void sdp_bandwidth_set(void* sdp, const char* bandwidth);
void sdp_timing_set(void* sdp, const char* timing);
void sdp_repeat_set(void* sdp, const char* repeat);
void sdp_timezone_set(void* sdp, const char* timezone);
void sdp_encryption_set(void* sdp, const char* encryption);

#ifdef __cplusplus
}
#endif
#endif /* !_sdp_h_ */