/*****************************************************************************/
/*                              Includes                                     */
/*****************************************************************************/
#include "HAL/SW/sw_cfg.h"
#include "HAL/SW/sw.h"
#include "MCAL/GPIO/gpio.h"

/*****************************************************************************/
/*                              Defines                                      */
/*****************************************************************************/

/*****************************************************************************/
/*                              Types                                        */
/*****************************************************************************/

/*****************************************************************************/
/*                           Global Variables                                */
/*****************************************************************************/
const swCfg_t switches[_swsNum] = {
    [sw_red] = {
        .port = PORT_A,
        .pin = PIN_8,
        .sw_connection = SW_CONNECTION_PULLUP
    },
    [sw_blue] = {
        .port = PORT_C,
        .pin = PIN_14,
        .sw_connection = SW_CONNECTION_PULLDOWN
    },
    [sw_green] = {
        .port = PORT_C,
        .pin = PIN_13,
        .sw_connection = SW_CONNECTION_PULLUP
    },
    [sw_yellow] = {
        .port = PORT_C,
        .pin = PIN_15,
        .sw_connection = SW_CONNECTION_PULLDOWN
    }
};

/*****************************************************************************/
/*                      Static Function Prototypes                           */
/*****************************************************************************/

/*****************************************************************************/
/*                           Implementation                                  */
/*****************************************************************************/


