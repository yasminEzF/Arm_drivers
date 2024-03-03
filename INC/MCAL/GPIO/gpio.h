#ifndef GPIO_H_
#define GPIO_H_

/*****************************************************************************/
/*                              Includes                                     */
/*****************************************************************************/
#include <stdint.h>
#include "gpio_defines.h"

/*****************************************************************************/
/*                              Defines                                      */
/*****************************************************************************/
#define PORT_H     ((volatile void* const)0x40021C00)
#define PORT_E     ((volatile void* const)0x40021000)
#define PORT_D     ((volatile void* const)0x40020C00)
#define PORT_C     ((volatile void* const)0x40020800)
#define PORT_B     ((volatile void* const)0x40020400)
#define PORT_A     ((volatile void* const)0x40020000)

#define PIN_0       0
#define PIN_1       1
#define PIN_2       2
#define PIN_3       3
#define PIN_4       4
#define PIN_5       5
#define PIN_6       6
#define PIN_7       7
#define PIN_8       8
#define PIN_9       9
#define PIN_10      10
#define PIN_11      11
#define PIN_12      12
#define PIN_13      13  
#define PIN_14      14
#define PIN_15      15

#define PIN_VALUE_HIGH      0x01
#define PIN_VALUE_LOW       0x00

#define RETURN_OK           0
#define RETURN_NOT_OK       1

//PUPD2_OTYPE1_MODE2
#define MODE_OUTPUT_PP      (MODE_OUTPUT|OTYPE_PP|PUPD_NONE)
#define MODE_OUTPUT_PP_PU   (MODE_OUTPUT|OTYPE_PP|PUPD_PU)
#define MODE_OUTPUT_PP_PD   (MODE_OUTPUT|OTYPE_PP|PUPD_PD)

#define MODE_OUTPUT_OD      (MODE_OUTPUT|OTYPE_OD|PUPD_NONE)
#define MODE_OUTPUT_OD_PU   (MODE_OUTPUT|OTYPE_OD|PUPD_PU)
#define MODE_OUTPUT_OD_PD   (MODE_OUTPUT|OTYPE_OD|PUPD_PD)

#define MODE_AF_PP          (MODE_AF|OTYPE_PP|PUPD_NONE)
#define MODE_AF_PP_PU       (MODE_AF|OTYPE_PP|PUPD_PU)
#define MODE_AF_PP_PD       (MODE_AF|OTYPE_PP|PUPD_PD)
#define MODE_AF_OD          (MODE_AF|OTYPE_OD|PUPD_NONE)
#define MODE_AF_OD_PU       (MODE_AF|OTYPE_OD|PUPD_PU)
#define MODE_AF_OD_PD       (MODE_AF|OTYPE_OD|PUPD_PD)

#define MODE_IP_FLOATING    (MODE_INPUT|OTYPE_DEFAULT|PUPD_NONE)
#define MODE_IP_PU          (MODE_INPUT|OTYPE_DEFAULT|PUPD_PU)
#define MODE_IP_PD          (MODE_INPUT|OTYPE_DEFAULT|PUPD_PD)

#define MODE_ANALOG         (MODE_AN|OTYPE_DEFAULT|PUPD_NONE)

#define SPEED_LOW           0x00
#define SPEED_MEDIUM        0x01
#define SPEED_HIGH          0x02
#define SPEED_VERY_HIGH     0x03

#define AF_SYSTEM                   0x00
#define AF_TIM_1_2                  0x01
#define AF_TIM_3_4_5                0x02
#define AF_TIM_9_10_11              0x03
#define AF_I2C_1_2_3                0x04
#define AF_SPI_1_2_3_4              0x05
#define AF_SPI_3                    0x06
#define AF_USART_1_2                0x07
#define AF_USART_6                  0x08
#define AF_I2C_2_3                  0x09
#define AF_OTG_FS                   0x0A
#define AF_SDIO                     0x0C
#define AF_EVENTOUT                 0x0F

/*****************************************************************************/
/*                              Types                                        */
/*****************************************************************************/
typedef struct {
    uint8_t pin;
    uint8_t speed;
    uint8_t mode;
    uint8_t af;
    void* port;    
}gpioPin_t;


/*****************************************************************************/
/*                          Function Prototypes                              */
/*****************************************************************************/
uint8_t gpio_initPin(gpioPin_t* pinCfg);
uint8_t gpio_setPinValue(void* port, uint8_t pin, uint8_t pin_value);
uint8_t gpio_getPinValue(void* port, uint8_t pin, uint8_t* pin_value);


#endif /* GPIO_H_ */