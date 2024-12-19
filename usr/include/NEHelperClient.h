#ifndef _NEHELPERCLIENT_H
#define _NEHELPERCLIENT_H

#include <uuid/uuid.h>
#include <stdbool.h>
#include <stdint.h>
#include <xpc/xpc.h>
#include <objc/NSObject.h>

#define NE_HAS_EMANLE_VPN

typedef struct NEHelperClient NEHelperClient;

typedef struct NEHelperDelegate NEHelperDelegate;

struct NEHelperClient {
    int _classID;
    xpc_object_t _connection;
    NEHelperDelegate *_delegate;
};

xpc_object_t NEHelperCacheCopyAppUUIDMapping(const char *identity, void *);

void NEHelperClient_dealloc(NEHelperClient *self);

int NEHelperClient_classID(NEHelperClient *self);

NEHelperDelegate *NEHelperClient_delegate(NEHelperClient *self);

xpc_object_t NEHelperClient_connection(NEHelperClient *self);

NEHelperClient *NEHelperClient_initWithConnection(NEHelperClient *self, xpc_object_t arg1, NEHelperDelegate *arg2, int arg3);

int NEHelperVPNSetEnabled(uuid_t, bool);

#endif
