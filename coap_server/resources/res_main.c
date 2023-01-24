#include <stdio.h>
#include "contiki.h"
#include "dev/leds.h"
#include "lib/sensors.h"

#if CONTIKI_TARGET_ZOUL
#include "dev/adc-zoul.h"
#include "dev/zoul-sensors.h"
#endif

#include "coap-engine.h"

static void res_get_handler(coap_message_t *request, coap_message_t *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset);

RESOURCE(res_main, "title=\"SENSOR READINGS\", rt=\"JSON\"", res_get_handler, NULL, NULL, NULL);

static void res_get_handler(coap_message_t *request, coap_message_t *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
#if CONTIKI_TARGET_ZOUL
    adc_zoul.configure(SENSORS_HW_INIT, ZOUL_SENSORS_ADC_ALL);
#endif

#if CONTIKI_TARGET_ZOUL

    uint16_t light_sensor_reading = adc_zoul.value(ZOUL_SENSORS_ADC1);
    printf("Light sensor value = %u mV\n", light_sensor_reading);


    char message[COAP_MAX_CHUNK_SIZE] = "";

    int result = snprintf(message, COAP_MAX_CHUNK_SIZE - 1, "Light sensor reading: %u", light_sensor_reading);


    if(result < 0)
    {
        puts("Error while encoding message");
    }
    else
    {
        puts("Success. Sending Values");

        int len = strlen(message);
        memcpy(buffer, message, length);

        coap_set_header_content_format(response, APPLICATION_JSON);
        coap_set_header_etag(response, (uint8_t *)&len, 1);
        coap_set_payload(response, buffer, len);
    }

#endif
}
