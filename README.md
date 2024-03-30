# Arm_drivers

## File hierarchy

```bash
├───inc
│   ├───APP
│   │       app.h
│   │
│   ├───HAL
│   │   ├───H_SW
│   │   │       H_sw.h
│   │   │
│   │   ├───LED
│   │   │       led.h
│   │   │       led_cfg.h
│   │   │       README.md
│   │   │
│   │   └───SW
│   │           README.md
│   │           sw.h
│   │           sw_cfg.h
│   │
│   ├───LIB
│   │       bitMasks.h
│   │       STM32F401CC_interrupts.h
│   │
│   ├───MCAL
│   │   ├───GPIO
│   │   │       gpio.h
│   │   │       gpio_defines.h
│   │   │
│   │   ├───NVIC
│   │   │       nvic.h
│   │   │
│   │   ├───RCC
│   │   │       rcc.h
│   │   │       rcc_prescalers.h
│   │   │       README.md
│   │   │
│   │   └───STK
│   │           stk.h
│   │
│   └───SCHED
│           runnables.h
│           sched.h
│
├───src
│   ├───APP
│   │       H_sw_task_main.c
│   │       nvic_main.c
│   │       rcc_led_sw_main.c
│   │       stk_main.c
│   │
│   ├───HAL
│   │   ├───H_SW
│   │   │       H_sw.c
│   │   │
│   │   ├───LED
│   │   │       led.c
│   │   │       led_cfg.c
│   │   │
│   │   └───SW
│   │           sw.c
│   │           sw_cfg.c
│   │
│   ├───LIB
│   ├───MCAL
│   │   ├───GPIO
│   │   │       gpio.c
│   │   │
│   │   ├───NVIC
│   │   │       nvic.c
│   │   │
│   │   ├───RCC
│   │   │       rcc.c
│   │   │
│   │   └───STK
│   │           stk.c
│   │
│   └───SCHED
│           runnables.c
│           sched.c
│
└───UnitTests
    ├───LED
    │   │   test_led.c
    │   │   test_led.pass
    │   │
    │   └───gcov
    │           GcovCoverageResults.css
    │           GcovCoverageResults.functions.html
    │           GcovCoverageResults.html
    │           GcovCoverageResults.led.c.87f02e72e3702b689453f22c5cee5aac.html
    │
    └───SW
        │   test_sw.c
        │   test_sw.pass
        │
        └───gcov
                GcovCoverageResults.css
                GcovCoverageResults.functions.html
                GcovCoverageResults.html
                GcovCoverageResults.sw.c.9fea8688545348641ce60ddfa450e7ea.html

```

README files are under the `INC` directory where each module's file is in its designated directory.



