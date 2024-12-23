# Tasks Scheduler on TM4C Microcontroller

A simple task scheduler for toggling an LED by a push button on the **TM4C123GH6PM Microcontroller** using **DIO** and **Port AUTOSAR Drivers** and the **SysTick Timer Driver**. It implements the **AUTOSAR 4.0.3 Layered Architecture Model**.

---

## Features

- **DIO and Port AUTOSAR Drivers** for managing digital I/O pins.
- **SysTick Timer Driver** to implement periodic task scheduling for the LED toggle.
- Implements a **Simple Task Scheduler** using the ARM Cortex M4 SysTick timer.
- Modular design following the **AUTOSAR 4.0.3 Layered Architecture**.

---

## Components

1. **DIO AUTOSAR Driver**: Configures and controls digital I/O pins for push button and LED.
2. **Port AUTOSAR Driver**: Manages ports on the microcontroller for the peripherals.
3. **SysTick Timer Driver**: Implements the scheduler using the SysTick timer.
4. **Det Module**: Detects system errors and reports them.
5. **LED Module**: Controls the LED toggle behavior.
6. **Push Button Module**: Handles the push button input.
7. **App Module**: Manages the scheduling and task execution.
8. **Simple Scheduler OS**: Uses SysTick timer to manage periodic tasks.

---

## Contact 

For questions or suggestions, please contact me, Ahmed Desoky at "ahmed0201150@gmail.com".
