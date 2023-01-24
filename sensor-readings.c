#include <stdio.h>
#include "contiki.h"
#include "dev/leds.h"
#include "sys/etimer.h"
#include "dev/adc-sensors.h"

#define ADC_PIN_LIGHT 1
#define ADC_PIN_MOTION 2
#define SENSOR_READ_INTERVAL (CLOCK_SECOND)

PROCESS(read_sensor_data, "Read sensor data");
AUTOSTART_PROCESSES(&read_sensor_data);

static struct etimer et;

PROCESS_THREAD(read_sensor_data, ev, data)
{
    PROCESS_BEGIN();

    uint16_t ldr;

    adc_sensors.configure(ANALOG_GROVE_LIGHT, ADC_PIN);

    while(1)
    {
        etimer_set(&et, SENSOR_READ_INTERVAL);
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));

        ldr = adc_sensors.value(ANALOG_GROVE_LIGHT);

        if(ldr != ADC_WRAPPER_ERROR) {
            printf("LDR Sensor Value = %u\n", ldr);
        } else {
            printf("ERROR while reading data");
            PROCESS_EXIT();
        }
    }

    PROCESS_END();
}
