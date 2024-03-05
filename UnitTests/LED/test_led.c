#define TEST
#ifdef TEST

#include "unity.h"
#include "led.h"
#include "mock_gpio.h"


uint8_t n = 15;
ledCfg_t leds [_ledsNum];


void setUp(void)
{
    leds[0].port = (void*)&n;
    leds[0].pin = PIN_0;
}

void tearDown(void)
{
}


void test_led_init_gpio_init_fail() {

    gpio_initPin_IgnoreAndReturn(RETURN_NOT_OK);
    gpio_setPinValue_IgnoreAndReturn(RETURN_OK);
    
    TEST_ASSERT_EQUAL(RETURN_LED_NOT_OK,led_init());
}

void test_led_init_gpio_setPin_fail() {
  
    gpio_initPin_IgnoreAndReturn(RETURN_OK);
    gpio_setPinValue_IgnoreAndReturn(RETURN_NOT_OK);
    
    TEST_ASSERT_EQUAL(RETURN_LED_NOT_OK,led_init());
}

void test_led_init_forward_on() {
    
    leds[0].led_connection = LED_CONNECTION_FORWARD;
    leds[0].led_state = LED_STATE_ON;

    gpioPin_t expectedpin;
    expectedpin.mode = (uint8_t)MODE_OUTPUT_PP;
    expectedpin.speed = (uint8_t)SPEED_HIGH;
    expectedpin.af = (uint8_t)AF_SYSTEM;
    expectedpin.port = leds[0].port;
    expectedpin.pin = leds[0].pin;
    
    gpio_initPin_ExpectAndReturn(&expectedpin,RETURN_OK);
    gpio_setPinValue_ExpectAndReturn(expectedpin.port,expectedpin.pin,PIN_VALUE_HIGH,RETURN_OK);
    
    TEST_ASSERT_EQUAL(RETURN_LED_OK,led_init());
}

void test_led_init_forward_off() {
    
    leds[0].led_connection = LED_CONNECTION_FORWARD;
    leds[0].led_state = LED_STATE_OFF;

    gpioPin_t expectedpin;
    expectedpin.mode = (uint8_t)MODE_OUTPUT_PP;
    expectedpin.speed = (uint8_t)SPEED_HIGH;
    expectedpin.af = (uint8_t)AF_SYSTEM;
    expectedpin.port = leds[0].port;
    expectedpin.pin = leds[0].pin;
    
    gpio_initPin_ExpectAndReturn(&expectedpin,RETURN_OK);
    gpio_setPinValue_ExpectAndReturn(expectedpin.port,expectedpin.pin,PIN_VALUE_LOW,RETURN_OK);
    
    TEST_ASSERT_EQUAL(RETURN_LED_OK,led_init());
}
void test_led_init_reverse_on() {
    
    leds[0].led_connection = LED_CONNECTION_REVERSE;
    leds[0].led_state = LED_STATE_ON;

    gpioPin_t expectedpin;
    expectedpin.mode = (uint8_t)MODE_OUTPUT_PP;
    expectedpin.speed = (uint8_t)SPEED_HIGH;
    expectedpin.af = (uint8_t)AF_SYSTEM;
    expectedpin.port = leds[0].port;
    expectedpin.pin = leds[0].pin;
    
    gpio_initPin_ExpectAndReturn(&expectedpin,RETURN_OK);
    gpio_setPinValue_ExpectAndReturn(expectedpin.port,expectedpin.pin,PIN_VALUE_LOW,RETURN_OK);
    
    TEST_ASSERT_EQUAL(RETURN_LED_OK,led_init());
}
void test_led_init_reverse_off() {
    leds[0].led_connection = LED_CONNECTION_REVERSE;
    leds[0].led_state = LED_STATE_OFF;

    gpioPin_t expectedpin;
    expectedpin.mode = (uint8_t)MODE_OUTPUT_PP;
    expectedpin.speed = (uint8_t)SPEED_HIGH;
    expectedpin.af = (uint8_t)AF_SYSTEM;
    expectedpin.port = leds[0].port;
    expectedpin.pin = leds[0].pin;
    
    gpio_initPin_ExpectAndReturn(&expectedpin,RETURN_OK);
    gpio_setPinValue_ExpectAndReturn(expectedpin.port,expectedpin.pin,PIN_VALUE_HIGH,RETURN_OK);
    
    TEST_ASSERT_EQUAL(RETURN_LED_OK,led_init());
}

void test_led_setState_forward_on() {
    
    leds[0].led_connection = LED_CONNECTION_FORWARD;

    gpio_setPinValue_ExpectAndReturn(leds[0].port,leds[0].pin,PIN_VALUE_HIGH,RETURN_OK);
    
    TEST_ASSERT_EQUAL(RETURN_LED_OK,led_setState(0,LED_STATE_ON));
}

void test_led_setState_forward_off() {

    leds[0].led_connection = LED_CONNECTION_FORWARD;

    gpio_setPinValue_ExpectAndReturn(leds[0].port,leds[0].pin,PIN_VALUE_LOW,RETURN_OK);
    
    TEST_ASSERT_EQUAL(RETURN_LED_OK,led_setState(0,LED_STATE_OFF));
}

void test_led_setState_reverse_on() {
    leds[0].led_connection = LED_CONNECTION_REVERSE;

    gpio_setPinValue_ExpectAndReturn(leds[0].port,leds[0].pin,PIN_VALUE_LOW,RETURN_OK);
    
    TEST_ASSERT_EQUAL(RETURN_LED_OK,led_setState(0,LED_STATE_ON));
}

void test_led_setState_reverse_off() {

    leds[0].led_connection = LED_CONNECTION_REVERSE;

    gpio_setPinValue_ExpectAndReturn(leds[0].port,leds[0].pin,PIN_VALUE_HIGH,RETURN_OK);
    
    TEST_ASSERT_EQUAL(RETURN_LED_OK,led_setState(0,LED_STATE_OFF));
}

void test_led_setState_gpio_setPin_fail() {

    gpio_setPinValue_IgnoreAndReturn(RETURN_NOT_OK);
    
    TEST_ASSERT_EQUAL(RETURN_LED_NOT_OK,led_setState(0,LED_STATE_OFF));
}

#endif // TEST
