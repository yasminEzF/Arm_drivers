/*****************************************************************************/
/*                              Includes                                     */
/*****************************************************************************/
#include "sw.h"
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
extern const swCfg_t switches [_swsNum];

/*****************************************************************************/
/*                      Static Function Prototypes                           */
/*****************************************************************************/

/*****************************************************************************/
/*                           Implementation                                  */
/*****************************************************************************/

uint8_t sw_init(void) {
    uint8_t errorStatus = RETURN_NOT_OK;

    gpioPin_t sw_pin;
    sw_pin.mode = ;
    sw_pin.speed = ;
    for(uint8_t i = 0; i < _swsNum; i++) {
        errorStatus = RETURN_NOT_OK;
        sw_pin.port = switches[i].port;
        sw_pin.pin = switches[i].pin;
        if(gpio_initPin(&sw_pin)) {
            break;
        }
        else {
            errorStatus = RETURN_OK;
        }
    }
    return errorStatus;
}

uint8_t sw_setState(uint8_t sw, uint8_t* sw_state) {
    uint8_t errorStatus = RETURN_NOT_OK;
    uint8_t switch_state;

    if(!gpio_getPinValue(switches[sw].port,switches[sw].pin,&switch_state)) {
        errorStatus = RETURN_OK;
    }
    switch_state ^= switches[sw].sw_connection;

    return errorStatus;
}

