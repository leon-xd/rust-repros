typedef void *PVOID;

#ifdef STRICT
typedef void *HANDLE;
#if 0 && (_MSC_VER > 1000)
#define DECLARE_HANDLE(name) struct name##__; typedef struct name##__ *name
#else
#define DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
#endif
#else
typedef PVOID HANDLE;
#define DECLARE_HANDLE(name) typedef HANDLE name
#endif

typedef unsigned char UCHAR;
typedef HANDLE *PHANDLE;
typedef unsigned long ULONG;
typedef UCHAR BOOLEAN;           // winnt


DECLARE_HANDLE(UCXUSBDEVICE);
DECLARE_HANDLE(UCXENDPOINT);


typedef struct _USBDEVICE_MGMT_HEADER {
    ULONG                   Size;
    UCXUSBDEVICE            Hub;
    UCXUSBDEVICE            UsbDevice;
} USBDEVICE_MGMT_HEADER, *PUSBDEVICE_MGMT_HEADER;

typedef struct _ADDRESS0_OWNERSHIP_ACQUIRE {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
} ADDRESS0_OWNERSHIP_ACQUIRE, *PADDRESS0_OWNERSHIP_ACQUIRE;

typedef struct _USBDEVICE_ENABLE_FAILURE_FLAGS {
    ULONG                   InsufficientHardwareResourcesForDefaultEndpoint:1;
    ULONG                   InsufficientHardwareResourcesForDevice:1;
    ULONG                   Reserved:30;
} USBDEVICE_ENABLE_FAILURE_FLAGS;

typedef struct _USBDEVICE_ENABLE {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
    UCXENDPOINT                      DefaultEndpoint;
    USBDEVICE_ENABLE_FAILURE_FLAGS   FailureFlags;
} USBDEVICE_ENABLE, *PUSBDEVICE_ENABLE;

typedef struct _USBDEVICE_RESET {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
    UCXENDPOINT             DefaultEndpoint;
    ULONG                   EndpointsToDisableCount;
    UCXENDPOINT *           EndpointsToDisable;
} USBDEVICE_RESET, *PUSBDEVICE_RESET;

typedef struct _USBDEVICE_PURGEIO {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
    BOOLEAN                 OnSuspend;
} USBDEVICE_PURGEIO, *PUSBDEVICE_PURGEIO;

typedef struct _USBDEVICE_ABORTIO {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
} USBDEVICE_ABORTIO, *PUSBDEVICE_ABORTIO;

typedef struct _USBDEVICE_STARTIO {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
} USBDEVICE_STARTIO, *PUSBDEVICE_STARTIO;

typedef struct _USBDEVICE_TREE_PURGEIO {
#ifdef __cplusplus
    USBDEVICE_MGMT_HEADER            Header;
#else
    USBDEVICE_MGMT_HEADER;
#endif
} USBDEVICE_TREE_PURGEIO, *PUSBDEVICE_TREE_PURGEIO;
