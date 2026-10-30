<<<<<<< HEAD
# Voice-Controlled Smart Wheelchair Using Arduino Uno and Bluetooth

## 1. Project Overview

The **Voice-Controlled Smart Wheelchair** is an assistive mobility prototype designed to provide hands-free movement through voice commands.

The system uses an Android application to recognize voice instructions and transmit corresponding commands through an HC-05 Bluetooth module. An Arduino Uno processes these commands and controls four DC motors through an L293D motor driver.

The prototype demonstrates how embedded systems, wireless communication, and motor control can be combined to develop an affordable assistive technology solution.

## 2. Objectives

- Develop a wheelchair prototype controlled through voice commands.
- Establish wireless communication between an Android application and Arduino using Bluetooth.
- Control four DC motors for directional movement.
- Implement basic movement commands: Forward, Backward, Left, Right, and Stop.
- Explore embedded system programming and hardware interfacing.

## 3. Hardware Components

| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno | 1 | Main controller |
| L293D Motor Driver | 1 | DC motor direction and speed control |
| HC-05 Bluetooth Module | 1 | Wireless communication |
| DC Geared Motors | 4 | Wheel movement |
| Rechargeable Battery (7V) | 1 | Power supply |
| ON/OFF Switch | 1 | Power control |
| Android Smartphone | 1 | Voice command input |
| Connecting Wires | As required | Circuit connections |
| Wheelchair Chassis | 1 | Mechanical structure |

## 4. Software Requirements

- Arduino IDE
- Embedded C/C++ (Arduino programming)
- Android voice-control application
- Bluetooth communication
- Serial Monitor for debugging

## 5. System Architecture

The project operates through the following sequence:

1. The user gives a voice command through the Android application.
2. The application converts the voice instruction into a corresponding character.
3. The HC-05 Bluetooth module receives the transmitted command.
4. Arduino Uno reads and processes the received character.
5. The Arduino sends control signals to the L293D motor driver.
6. The motor driver controls the direction of the connected DC motors.
7. The wheelchair prototype performs the requested movement.

### Block Diagram

```text
      User Voice Command
              |
              v
    Android Voice Application
              |
              v
       HC-05 Bluetooth
              |
              v
         Arduino Uno
              |
              v
       L293D Motor Driver
              |
        +-----+-----+
        |           |
        v           v
   Left Motors  Right Motors
     (2 DC)       (2 DC)
        |           |
        +-----+-----+
              |
              v
       Wheel Movement
```

## 6. Bluetooth Command Configuration

The Android application transmits the following characters to Arduino:

| Voice Instruction | Bluetooth Character | Function |
|---|---|---|
| Forward | `F` | Moves forward |
| Backward | `B` | Moves backward |
| Left | `L` | Turns left |
| Right | `R` | Turns right |
| Stop | `S` | Stops the motors |

The Arduino processes these commands using a switch-case control structure.

## 7. Circuit Connections

### HC-05 Bluetooth Module

| HC-05 Pin | Arduino Uno Pin |
|---|---|
| VCC | 5V (compatible breakout board) |
| GND | GND |
| TXD | D2 |
| RXD | D3 through voltage divider |

### L293D Motor Driver

For a common two-channel L293D module:

| Motor Driver Pin | Arduino Uno Pin |
|---|---|
| ENA | D5 |
| IN1 | D8 |
| IN2 | D9 |
| ENB | D6 |
| IN3 | D10 |
| IN4 | D11 |

### Motor Connections

- Two left-side motors are connected to Motor A outputs.
- Two right-side motors are connected to Motor B outputs.

**Note:** These connections assume a compatible two-channel L293D module. Actual wiring may differ depending on the motor driver board.

## 8. Arduino Programming

The Arduino program performs the following tasks:

- Initializes serial communication.
- Establishes Bluetooth communication using SoftwareSerial.
- Configures motor driver control pins.
- Receives commands from the HC-05 module.
- Processes the commands using conditional logic.
- Controls motor direction using digital outputs.
- Controls motor speed using PWM signals.
- Stops the motors when the Stop command is received.

### Motor Speed Control

The motor speed is controlled using PWM.

```cpp
int motorSpeed = 150;
```

PWM values range from:

- `0` – Motor stopped
- `150` – Medium speed
- `255` – Maximum PWM output

Actual motor speed depends on the motor, supply voltage, driver voltage drop, and mechanical load.

## 9. How to Run the Project

1. Assemble the Arduino Uno, HC-05, L293D driver, and DC motors.
2. Connect the hardware according to the circuit connections.
3. Install Arduino IDE on your computer.
4. Open the Arduino source code.
5. Select **Arduino Uno** under Tools → Board.
6. Select the correct COM port.
7. Upload the program to Arduino Uno.
8. Power the circuit using the appropriate battery and regulated supplies.
9. Pair the Android smartphone with the HC-05 Bluetooth module.
10. Open the voice-control application and connect to HC-05.
11. Speak the required movement command.
12. Observe the corresponding motor movement.

## 10. Testing and Expected Results

| Test Case | Input | Expected Result |
|---|---|---|
| Test 1 | Forward | Both motor groups move forward |
| Test 2 | Backward | Both motor groups move backward |
| Test 3 | Left | Left turn |
| Test 4 | Right | Right turn |
| Test 5 | Stop | All motors stop |

Motor direction may require adjustment depending on the physical orientation and polarity of individual motors.

## 11. Applications

- Assistive mobility technology prototypes
- Voice-controlled robotic vehicles
- Bluetooth-based automation systems
- Embedded system learning and experimentation
- Human-machine interaction projects

## 12. Future Enhancements

- Obstacle detection using ultrasonic sensors.
- Emergency stop functionality.
- Battery level monitoring.
- Improved turning and speed control.
- GPS-based location tracking.
- Integration of additional safety sensors.
- Development of a more reliable voice recognition interface.

## 13. Safety Precautions

- Verify the voltage rating of the DC motors before connecting the 7V battery.
- Many yellow TT motors are rated for approximately 3–6V; use a suitable buck converter if required.
- Ensure the combined motor startup and stall current does not exceed the L293D driver's ratings.
- Use a voltage divider for the Arduino TX to HC-05 RX connection.
- Maintain a common ground between the Arduino, Bluetooth module, and motor driver.
- Use an independent physical emergency stop.
- Test the prototype with wheels raised and without a person seated.

**Important:** This is an educational prototype, not a certified or human-safe wheelchair. It must not be used to transport a person without substantial mechanical, electrical, braking, and safety validation.

## 14. Learning Outcomes

Through this project, the following concepts can be explored:

- Arduino Uno and microcontroller programming
- Embedded C/C++ programming
- UART serial communication
- HC-05 Bluetooth interfacing
- L293D H-bridge motor control
- PWM-based motor speed control
- DC motor interfacing
- Basic robotics and automation

## 15. Conclusion

The Voice-Controlled Smart Wheelchair prototype demonstrates the integration of embedded systems, Bluetooth communication, and DC motor control to achieve voice-based mobility.

By using an Android application, HC-05 Bluetooth module, Arduino Uno, and L293D motor driver, the system can execute basic directional commands wirelessly.

The project provides practical experience in embedded programming, hardware interfacing, wireless communication, and assistive technology development.

---

**Project Category:** Embedded Systems | Robotics | Assistive Technology

**Controller:** Arduino Uno

**Programming Language:** Embedded C/C++

**Communication:** Bluetooth (HC-05)
=======
# Voice_Controlled_Smart_Wheelchair
>>>>>>> 5df01868654f9ed80b60e3586f8599909f36bab7
