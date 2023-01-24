DEFINES+=PROJECT_CONF_H=\"project-conf.h\"

CONTIKI_PROJECT = project
CONTIKI_PROJECT += sensor-readings

CONTIKI_TARGET_SOURCEFILES += adc-sensors.c

all: $(CONTIKI_PROJECT)

# Do not try to build on Sky because of code size limitation
PLATFORMS_EXCLUDE = sky z1

# Include CoAP resources
MODULES_REL += ./resources

CONTIKI=../../..

include $(CONTIKI)/Makefile.include
