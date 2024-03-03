#ifndef LED_H_
#define LED_H_

/*****************************************************************************/
/*                              Includes                                     */
/*****************************************************************************/
#include "led_cfg.h"

/*****************************************************************************/
/*                              Defines                                      */
/*****************************************************************************/
#define LED_STATE_ON    0x01
#define LED_STATE_OFF   0x00

#define LED_CONNECTION_FORWARD  0x00
#define LED_CONNECTION_REVERSE  0x01

#define RETURN_OK       0x00
#define RETURN_NOT_OK   0x01

/*****************************************************************************/
/*                              Types                                        */
/*****************************************************************************/
typedef struct {
    void* port;
    uint8_t pin;
    uint8_t led_connection;
    uint8_t led_state;
}ledCfg_t;

/*****************************************************************************/
/*                          Function Prototypes                              */
/*****************************************************************************/
uint8_t led_init(void);
uint8_t led_setState(uint8_t led, uint8_t led_state);

#endif /* LED_H_ */