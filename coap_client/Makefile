CONTIKI_PROJECT = coap_client
all: $(CONTIKI_PROJECT)

#Do not try to build on sky or z1 due to code size limitation
PLATFORMS_EXCLUDE = sky z1

CONTIKI = ../../../..

#include COAP implementation
include $(CONTIKI)/Makefile.dir-variables
MODULES += $(CONTIKI_NG_APP_LAYER_DIR)/coap

include $(CONTIKI)/Makefile.include
