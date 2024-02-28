/*****************************************************************************/
/*                              Includes                                     */
/*****************************************************************************/
#include "led.h"
#include "GPIO/gpio.h"

/*****************************************************************************/
/*                              Defines                                      */
/*****************************************************************************/


/*****************************************************************************/
/*                              Types                                        */
/*****************************************************************************/


/*****************************************************************************/
/*                           Global Variables                                */
/*****************************************************************************/
extern const ledCfg_t leds [_ledsNum];

/*****************************************************************************/
/*                      Static Function Prototypes                           */
/*****************************************************************************/

/*****************************************************************************/
/*                           Implementation                                  */
/*****************************************************************************/
uint8_t led_init(void) {
    uint8_t errorStatus = RETURN_NOT_OK;

    gpioPin_t led_pin;
    led_pin.mode = MODE_OUTPUT_PP;
    led_pin.speed = ;
    for(uint8_t i = 0; i < _ledsNum; i++) {
        errorStatus = RETURN_NOT_OK;
        led_pin.port = leds[i].port;
        led_pin.pin = leds[i].pin;
        if(gpio_initPin(&led_pin)) {
            break;
        }
        else if(gpio_setPinValue(leds[i].port,leds[i].pin,leds[i].led_state ^ leds[i].led_connection)) {
            break;
        }
        else {
            errorStatus = RETURN_OK;
        }
    }
    return errorStatus;
}

uint8_t led_setState(uint8_t led, uint8_t led_state) {
    uint8_t errorStatus = RETURN_NOT_OK;

    if(!gpio_setPinValue(leds[led].port,leds[led].pin,led_state ^ leds[led].led_connection)) {
        errorStatus = RETURN_OK;
    }

    return errorStatus;
}
