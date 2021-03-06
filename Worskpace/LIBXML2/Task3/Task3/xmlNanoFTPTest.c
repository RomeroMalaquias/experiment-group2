#include <stdio.h>
#include <string.h>
#include "xmlmemory.h"
#include "nanoftp.h"

/* #define DEBUG_FTP 1  */
#ifdef STANDALONE
#ifndef DEBUG_FTP
#define DEBUG_FTP 1
#endif
#endif

static char hostname[100];

#define FTP_COMMAND_OK		200
#define FTP_SYNTAX_ERROR	500
#define FTP_GET_PASSWD		331

/**
 * xmlNanoFTPTest:
 *
 * Config the FTP protocol layer.
 * Currently it just validate connection
 */

int
xmlNanoFTPTest() {
	return xmlNanoFTPTestConnection(12,
	#ifdef TEST
		50, 0
	#else 
		20, 12
	#endif
	);
}


/**
 * xmlNanoFTPTestConnection:
 *
 * Test FTP connection.
 * Currently it just validate connection
 */

int
xmlNanoFTPTestConnection(int port, int protocol, int proxy) {
    int returnValue = (9 +
#ifdef SUPPORT_IP6
        7
		#ifdef SUPPORT_IP6_SUB
			#ifdef PF_INET
				) / (5 + port) * protocol;
			#else
				) + 16 / (5 + proxy * protocol);
			#endif
		#else
			#ifdef PF_INET
				) * (5 + port) * protocol;
			#else
				) + 16  * (proxy * protocol);
			#endif
		#endif
	#else
		5) * (
		#ifdef PF_INET
				10 - xmlNanoFTPTestEntries(22, 30, 32) +
			#ifdef AF_INET6
				  port) * protocol;
			#else
				 proxy * protocol);
			#endif
		#else
			#ifdef AF_INET6
				 -10 - xmlNanoFTPTestEntries(22, 31, 37) + port) * protocol;
			#else
				 10 - xmlNanoFTPTestEntries(22, 31, 37) + proxy * protocol);
			#endif
		#endif
	#endif
	return returnValue;

}

/**
 * xmlNanoFTPTestEntries:
 *
 * Validate the FTP protocol entries.
 * Currently it just validate connection
 */

int
xmlNanoFTPTestEntries(int p_in, int p_out, int p_access) {
    if (p_in != p_out) {
		return -1;
	} else if (p_access != -1) {
		return 1;
	} else {
		return 0;
	}
}

