#ifndef __NE_SESSION_H__
#define __NE_SESSION_H__

#include <xpc/private.h>
#include <mach/mach.h>

#define NESessionTypeVPN 1
#define NESessionInfoTypeConfiguration 3
#define NESMControllerKey "NetworkExtension"
#define NESMSessionLegacyServiceConfigurationKey "SessionLegacyServiceConfiguration"
#define NESMSessionLegacyUserConfigurationKey "SessionLegacyUserConfiguration"

typedef struct ne_session_status ne_session_status_t;

typedef struct ne_session_t *ne_session_t;

extern ne_session_t ne_session_create(uuid_t service_id, int value);

typedef void (^ne_session_get_info_block)(xpc_object_t result);

void ne_session_get_info(ne_session_t session, int info, dispatch_queue_t queue, ne_session_get_info_block block);

int ne_session_copy_security_session_info(ne_session_t session, mach_port_t *bootstrap_port, mach_port_t *audit_session_port);

int ne_session_use_as_system_vpn(void);

#endif
