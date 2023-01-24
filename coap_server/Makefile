CONTIKI_PROJECT = coap_server
all: $(CONTIKI_PROJECT)

#Do not try to build on sky or z1 due to code size limitation
PLATFORMS_EXCLUDE = sky z1

MODULES_REL += ./resources

CONTIKI = ../../../..

include ../Makefile.common

include $(CONTIKI)/Makefile.include
