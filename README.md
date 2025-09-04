# Arduino Binary Counter with LEDs

This project implements an **8-bit binary counter** on an Arduino board using **Timer1 interrupts**.  
Eight LEDs connected to digital pins `2–9` will count up in binary, incrementing at a fixed time interval, until all LEDs are turned on (`11111111`).  

---

## 🔧 Hardware Setup

- **Board:** Arduino Uno (or compatible)
- **Components:**
  - 8 × LEDs
  - 8 × 220Ω resistors 
  - Breadboard + jumper wires

### Circuit
- Connect each LED **anode (long leg)** to one Arduino pin (`D2`–`D9`) through a resistor.
- Connect each LED **cathode (short leg)** to **GND**.

## 📜 Code Overview

The project is structured into several key functions:

### Global Variables
```cpp
volatile char bits[8] = {0,0,0,0,0,0,0,0}; // Current binary state
volatile char ledPins[8] = {2,3,4,5,6,7,8,9}; // LED pin numbers
volatile bool updateFlag = false; // Signals main loop to refresh LEDs
volatile bool stopFlag = false;   // Stops counter at maximum
```

[Demo video](Arduino_Binary_counter.mp4)


