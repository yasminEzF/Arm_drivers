#define TEST
#ifdef TEST

#include "unity.h"

#include "sw.h"
#include "mock_gpio.h"


uint8_t n = 15;
swCfg_t switches[_swsNum];

void setUp(void)
{
    switches[0].port = (void*)&n;
    switches[0].pin = PIN_0;
}

void tearDown(void)
{
}


void test_sw_init_gpio_init_fail() {

    gpio_initPin_IgnoreAndReturn(RETURN_NOT_OK);
    
    TEST_ASSERT_EQUAL(RETURN_SW_NOT_OK,sw_init());
}

void test_sw_init_pullup() {
    
    switches[0].sw_connection = SW_CONNECTION_PULLUP;

    gpioPin_t expectedpin;
    expectedpin.mode = (uint8_t)MODE_IP_PU;
    expectedpin.speed = (uint8_t)SPEED_HIGH;
    expectedpin.af = (uint8_t)AF_SYSTEM;
    expectedpin.port = switches[0].port;
    expectedpin.pin = switches[0].pin;
    
    gpio_initPin_ExpectAndReturn(&expectedpin,RETURN_OK);
    
    TEST_ASSERT_EQUAL(RETURN_SW_OK,sw_init());
}

void test_sw_init_pulldown() {
    
    switches[0].sw_connection = SW_CONNECTION_PULLDOWN;

    gpioPin_t expectedpin;
    expectedpin.mode = (uint8_t)MODE_IP_PD;
    expectedpin.speed = (uint8_t)SPEED_HIGH;
    expectedpin.af = (uint8_t)AF_SYSTEM;
    expectedpin.port = switches[0].port;
    expectedpin.pin = switches[0].pin;
    
    gpio_initPin_ExpectAndReturn(&expectedpin,RETURN_OK);
    
    TEST_ASSERT_EQUAL(RETURN_SW_OK,sw_init());
}
void test_sw_getState_gpio_fail() {
    
    switches[0].sw_connection = SW_CONNECTION_PULLDOWN;

    gpio_getPinValue_IgnoreAndReturn(RETURN_NOT_OK);
    uint8_t s = 2;
    TEST_ASSERT_EQUAL(RETURN_SW_NOT_OK,sw_getState(0,&s));
}
void test_sw_getState_NullPtr() {
    
    switches[0].sw_connection = SW_CONNECTION_PULLDOWN;
    
    TEST_ASSERT_EQUAL(RETURN_SW_NOT_OK,sw_getState(0,NULL));
}
uint8_t a = 2;
uint8_t test_sw_getState_PU_press_callBack(void* pt, uint8_t p, uint8_t* q) {
    
    *q = 0;
    return RETURN_OK;
}
void test_sw_getState_PU_press() {
    switches[0].sw_connection = SW_CONNECTION_PULLUP;
    a = 2;
    gpio_getPinValue_StubWithCallback(test_sw_getState_PU_press_callBack);
    TEST_ASSERT_EQUAL(RETURN_SW_OK,sw_getState(0,&a));
    TEST_ASSERT_EQUAL(SW_STATE_PRESSED,a);
}
uint8_t test_sw_getState_PD_press_callBack(void* pt, uint8_t p, uint8_t* q) {
    
    *q = 1;
    return RETURN_OK;
}
void test_sw_getState_PD_press() {
    
    switches[0].sw_connection = SW_CONNECTION_PULLDOWN;
    a = 2;
    gpio_getPinValue_StubWithCallback(test_sw_getState_PD_press_callBack);
    TEST_ASSERT_EQUAL(RETURN_SW_OK,sw_getState(0,&a));
    TEST_ASSERT_EQUAL(SW_STATE_PRESSED,a);
}
uint8_t test_sw_getState_PU_rel_callBack(void* pt, uint8_t p, uint8_t* q) {
    
    *q = 1;
    return RETURN_OK;
}
void test_sw_getState_PU_rel() {
    switches[0].sw_connection = SW_CONNECTION_PULLUP;
    a = 2;
    gpio_getPinValue_StubWithCallback(test_sw_getState_PU_rel_callBack);
    TEST_ASSERT_EQUAL(RETURN_SW_OK,sw_getState(0,&a));
    TEST_ASSERT_EQUAL(SW_STATE_RELEASED,a);
}
uint8_t test_sw_getState_PD_rel_callBack(void* pt, uint8_t p, uint8_t* q) {
    
    *q = 0;
    return RETURN_OK;
}
void test_sw_getState_PD_rel() {
    
    switches[0].sw_connection = SW_CONNECTION_PULLDOWN;
    a = 2;
    gpio_getPinValue_StubWithCallback(test_sw_getState_PD_rel_callBack);
    TEST_ASSERT_EQUAL(RETURN_SW_OK,sw_getState(0,&a));
    TEST_ASSERT_EQUAL(SW_STATE_RELEASED,a);
}
#endif // TEST
