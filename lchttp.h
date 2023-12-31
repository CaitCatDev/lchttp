#pragma once


#define LCHTTP_VER_MAJ 0
#define LCHTTP_VER_MIN 4
#define LCHTTP_VER_VENDOR "cat"

#define LCHTTP_VER_STR LCHTTP_VER_MAJ # "." LCHTTP_VER_MIN # "_" LCHTTP_VER_VENDOR

#include <openssl/ssl.h>


#define LCHTTP_METHOD_GET "GET"
#define LCHTTP_METHOD_POST "POST"
#define LCHTTP_METHOD_DELETE "DELETE"
#define LCHTTP_METHOD_HEAD "HEAD"
#define LCHTTP_METHOD_PUT "PUT"
#define LCHTTP_METHOD_CONNECT "CONNECT"
#define LCHTTP_METHOD_OPTIONS "OPTIONS"
#define LCHTTP_METHOD_TRACE "TRACE"
#define LCHTTP_METHOD_PATCH "PATCH"

#define HTTP_VER_09 ""
#define HTTP_VER_10 "HTTP/1.0"
#define HTTP_VER_11 "HTTP/1.1"
#define HTTP_VER_2 "HTTP/2"
#define HTTP_VER_3 "HTTP/3"

typedef struct lchttp_request lchttp_request_t;
typedef struct lchttp_response lchttp_response_t;

typedef int lchttp_ret_t;

enum lchttp_RET_CODES {
	LCHTTP_SUCCESS = 0,
	LCHTTP_MEMORY_ALLOC = 1,
};



lchttp_request_t *lchttp_new_request();
void lchttp_request_set_method(lchttp_request_t *request, char *method);
void lchttp_request_set_path(lchttp_request_t *request, char *path); 
lchttp_ret_t lchttp_request_add_header(lchttp_request_t *request, char *name, char *value);
lchttp_ret_t lchttp_request_add_data(lchttp_request_t *request, char *data);
void lchttp_request_set_http_version(lchttp_request_t *request, char *http_ver);
char *lchttp_request_get_str(lchttp_request_t *request);
lchttp_ret_t lchttp_request_build(lchttp_request_t *request);
void lchttp_request_free(lchttp_request_t *request);
