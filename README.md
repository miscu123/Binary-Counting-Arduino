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
- Example for one LED:
