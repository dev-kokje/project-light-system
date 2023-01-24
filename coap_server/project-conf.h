#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_

#include "../project-conf.common.h"

#define UIP_CONF_BUFFER_SIZE 500

#define LOG_LEVEL_APP LOG_LEVEL_DBG
#define LOG_CONF_LEVEL_COAP LOG_LEVEL_DBG

#define IEEE_ADDR_CONF_HARDCODED 1

/* Change this */
#define IEEE_ADDR_CONF_ADDRESS { 0x00, 0x12, 0x4B, 0x00, 0xAB, 0xCD, 0xEF, 0x00}
#endif /* PROJECT_CONF_H_ */
