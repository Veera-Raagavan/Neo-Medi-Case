# Neo Medi Case

An automatic medicine dispensing box built around an **Arduino Uno**. It helps patients take their medication on time by opening a servo-driven compartment and sounding a buzzer at each scheduled dose.

It is aimed mainly at elderly people and patients with chronic illnesses, who often forget doses. Missed or delayed doses can reduce the effectiveness of treatment and lead to health complications, so this project automates both the reminder and the access to the medicine.

---

## Table of Contents

1. [Features](#features)
2. [Hardware Required](#hardware-required)
3. [How It Works](#how-it-works)
4. [Dose Schedule](#dose-schedule)
5. [Circuit Connections](#circuit-connections)
6. [Project Structure](#project-structure)
7. [Software Setup](#software-setup)
8. [Code Overview](#code-overview)
9. [Applications](#applications)
10. [Advantages](#advantages)
11. [Current Limitations](#current-limitations)
12. [Future Improvements](#future-improvements)
13. [Conclusion](#conclusion)

---

## Features

- Three doses per day: **morning, afternoon and night**
- A servo motor opens the compartment to a preset angle for each dose
- A buzzer alerts the patient when a dose is due
- The compartment closes automatically after a short delay
- The cycle repeats for every dose
- Simple, low-cost hardware that is easy to assemble and customize

---

## Hardware Required

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino Uno | 1 | Runs the timing and control logic |
| Servo motor | 1 | Opens and closes the medicine compartment |
| Buzzer | 1 | Alerts the patient |
| Jumper wires | As needed | Circuit connections |
| Power supply | 1 | Powers the Arduino and servo |
| Medicine box / enclosure | 1 | Holds the medicine and the mechanism |

---

## How It Works

1. The Arduino keeps track of the three daily dose intervals.
2. When a scheduled time arrives, the **servo rotates** to the angle assigned to that dose.
3. The **buzzer sounds** to alert the patient.
4. After a short delay, which gives the patient time to take the medicine, the servo **returns to 0°** (closed position).
5. The cycle repeats automatically for the next dose.

```
Scheduled time  ->  Servo opens  ->  Buzzer sounds  ->  Wait  ->  Servo closes (0°)
```

---

## Dose Schedule

| Dose | Servo angle |
|------|-------------|
| Morning | 30° |
| Afternoon | 45° |
| Night | 90° |
| Closed position | 0° |

---

## Circuit Connections

| Component | Arduino pin |
|-----------|-------------|
| Servo signal | **D9** |
| Servo power (red) | 5V |
| Servo ground (brown/black) | GND |
| Buzzer (+) | *Digital pin of your choice* |
| Buzzer (-) | GND |

The servo pin (D9) is taken from the sketch. The buzzer pin is not defined in the sketch, so set it to match your wiring.

> If the servo draws too much current for the Arduino's 5V pin, power it from a separate supply and connect the grounds together.

---

## Project Structure

```
neo-medi-case/
├── Neo_Medi_Case.ino                  # Arduino sketch
├── Neo_Medi_Case_-_Description.txt    # Project description
└── README.md
```

---

## Software Setup

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Open `Neo_Medi_Case.ino`.
3. Select **Tools > Board > Arduino Uno** and choose the correct **Port**.
4. The `Servo` library is built into the Arduino IDE, so no extra installation is needed.
5. Click **Upload**.
6. Open the **Serial Monitor** at **9600 baud** to see the startup message.

---

## Code Overview

The sketch uses the `Servo` library and the serial port.

| Item | Details |
|------|---------|
| `SERVO_PIN` | `9`, the servo signal pin |
| `BAUD_RATE` | `9600` |
| `setup()` | Attaches the servo, moves it to 0° (closed), starts serial and prints `READY SERVO:D9 BAUD:9600` |
| `loop()` | Reads incoming serial characters, builds a line until a newline, ignores carriage returns, discards lines longer than 64 characters, then passes each complete line to `handleCommand()` |

The startup message `READY SERVO:D9 BAUD:9600` confirms the board is connected and the servo is on pin 9.

---

## Applications

- Dose reminders for elderly patients
- People with chronic illnesses who must follow strict schedules
- Home healthcare setups that promote independence
- Clinics
- Patients living alone

---

## Advantages

- Timely medication intake
- Reduced dependence on caregivers
- Easy to use and customize
- Low cost
- Can be modified for more doses or multiple users

---

## Current Limitations

- Only one compartment, with three doses per day handled by changing the servo angle.
- There is no real-time clock, so timekeeping is not accurate over long periods.
- There is no display, so the schedule cannot be viewed on the device.
- There is no confirmation that the medicine was actually taken.
- No remote alerts for caregivers.

---

## Future Improvements

- Add an **RTC module** (such as DS3231) for accurate timekeeping.
- Add an **LCD** to show the schedule and the next dose.
- Add **Wi-Fi or Bluetooth** for remote monitoring and mobile notifications to caregivers.
- Use **multiple servo-controlled compartments**.
- Add a **"medicine taken" confirmation button**.
- Support more doses and multiple users.

---

## Conclusion

The Neo Medi Case shows how microcontroller technology and simple mechanical actuation can be combined to solve a real healthcare problem. By improving convenience and encouraging consistent medication use, it is a practical step toward integrating technology into everyday patient care.

---

## Author

**Veera Raagavan**

---

## License

This project is intended for educational purposes. Feel free to use and modify it for learning.
