// #include <Arduino.h>
// #include <Servo.h>

// #define VIBRATION_SENSOR A5
// #define GAS_SENSOR A0
// #define LED 13
// #define BUZZER 12
// #define SERVO_PIN 9
// #define RELAY_PIN 5    // Relay controls solenoid latch

// // Relay Logic (assuming active LOW relay)
// #define RELAY_ON LOW
// #define RELAY_OFF HIGH

// #define ON 1
// #define OFF 0

// int present_condition = 0;
// int previous_condition = 0;

// bool doorOpen = false;
// bool quakeOngoing = false;
// bool gasLeakDetected = false;

// unsigned long quakeEndTime = 0;
// const unsigned long cooldownDuration = 2000; // 2 seconds
// unsigned long lastGasCheckTime = 0;
// const unsigned long gasCheckInterval = 3000; // milliseconds

// Servo doorServo;

// // Solenoid latch activation - mimics turning a valve 3 times
// void activateSolenoidLatch(int times) {
//   for (int i = 0; i < times; i++) {
//     Serial.println("Relay in action");
//     digitalWrite(RELAY_PIN, RELAY_ON);   // Relay ON
//     delay(500);                          // Hold ON for 0.5 sec
//     digitalWrite(RELAY_PIN, RELAY_OFF);  // Relay OFF
//     delay(500);                          // 0.5 sec pause
//   }
// }

// void setup() {
//   Serial.begin(9600);
//   pinMode(VIBRATION_SENSOR, INPUT);
//   pinMode(GAS_SENSOR, INPUT);
//   pinMode(LED, OUTPUT);
//   pinMode(BUZZER, OUTPUT);
//   pinMode(RELAY_PIN, OUTPUT);

//   digitalWrite(RELAY_PIN, RELAY_ON); // Relay (fairy light) ON by default

//   doorServo.attach(SERVO_PIN);
//   doorServo.write(0); // Door closed initially
//   Serial.println("Setup complete. Door closed.");
// }

// void loop() {
//   unsigned long currentTime = millis();

//   // ----- EARTHQUAKE DETECTION -----
//   previous_condition = present_condition;
//   present_condition = digitalRead(VIBRATION_SENSOR);

//   if (present_condition == HIGH) {
//     if (!quakeOngoing) {
//       quakeOngoing = true;
//       doorOpen = true;
//       doorServo.write(180); // Open door
//       Serial.println("Vibration detected!\nDoor opened.");

//       activateSolenoidLatch(3); // Trigger solenoid 3 times
//     }

//     digitalWrite(LED, ON);
//     digitalWrite(BUZZER, ON);
//     quakeEndTime = currentTime;
//   } else {
//     digitalWrite(LED, OFF);
//     digitalWrite(BUZZER, OFF);
//   }

//   if (quakeOngoing && present_condition == LOW && (currentTime - quakeEndTime > cooldownDuration)) {
//     quakeOngoing = false;
//     doorOpen = false;
//     doorServo.write(0); // Close door
//     Serial.println("Earthquake ended. Door closed.");

//     digitalWrite(RELAY_PIN, RELAY_ON); // Turn relay ON (keep light on after earthquake)
//   }

//   // ----- GAS DETECTION (non-blocking) -----
//   if (currentTime - lastGasCheckTime >= gasCheckInterval) {
//     lastGasCheckTime = currentTime;

//     int gasValue = analogRead(GAS_SENSOR);
//     int gasPercentage = map(gasValue, 0, 1023, 0, 100);

//     Serial.print("Gas Concentration: ");
//     Serial.print(gasPercentage);
//     Serial.println("%");

//     if (gasValue > 400 && !gasLeakDetected) {
//       gasLeakDetected = true;
//       Serial.println("Leak detected, gas valve shut off.");
//     } else if (gasValue <= 400 && gasLeakDetected) {
//       gasLeakDetected = false;
//     }
//   }
// }





//------Golden code------


// #include <Servo.h>

// // Pin Definitions
// #define VIBRATION_SENSOR A5
// #define GAS_SENSOR A0
// #define LED 13
// #define BUZZER 12
// #define SERVO_PIN 9
// #define RELAY_PIN 5

// // Relay Logic (Active LOW)
// #define RELAY_ON LOW
// #define RELAY_OFF HIGH

// #define ON HIGH
// #define OFF LOW

// int present_condition = 0;
// int previous_condition = 0;

// bool quakeOngoing = false;
// bool doorOpenedOnce = false;

// unsigned long quakeEndTime = 0;
// const unsigned long cooldownDuration = 2000; // 2 seconds

// Servo doorServo;

// // Function to pulse solenoid latch via relay
// void activateSolenoidLatch(int times) {
//   for (int i = 0; i < times; i++) {
//     digitalWrite(RELAY_PIN, RELAY_ON);
//     delay(500);
//     digitalWrite(RELAY_PIN, RELAY_OFF);
//     delay(500);
//   }
// }

// void setup() {
//   Serial.begin(9600);

//   // Set pin modes
//   pinMode(VIBRATION_SENSOR, INPUT);
//   pinMode(LED, OUTPUT);
//   pinMode(BUZZER, OUTPUT);
//   pinMode(RELAY_PIN, OUTPUT);

//   // Initial states
//   digitalWrite(RELAY_PIN, RELAY_OFF);
//   digitalWrite(LED, OFF);
//   digitalWrite(BUZZER, OFF);

//   doorServo.attach(SERVO_PIN);
//   doorServo.write(0); // Start with door closed

//   Serial.println("System initialized. Waiting for vibration...");
// }

// void loop() {
//   unsigned long currentTime = millis();

//   previous_condition = present_condition;
//   present_condition = digitalRead(VIBRATION_SENSOR);

//   if (present_condition == HIGH) {
//     if (!quakeOngoing) {
//       quakeOngoing = true;

//       if (!doorOpenedOnce) {
//         doorOpenedOnce = true;
//         doorServo.write(180); // Open the door only once
//         Serial.println("Vibration detected: Door opened.");
//       }
//     }

//     // Solenoid latch activates EVERY TIME during earthquake
//     Serial.println("Earthquake or Aftershock detected: Latch triggered.");
//     activateSolenoidLatch(2); // In and out twice per detection

//     digitalWrite(LED, ON);
//     digitalWrite(BUZZER, ON);
//     quakeEndTime = currentTime;
//   } else {
//     digitalWrite(LED, OFF);
//     digitalWrite(BUZZER, OFF);
//   }

//   if (quakeOngoing && present_condition == LOW && (currentTime - quakeEndTime > cooldownDuration)) {
//     quakeOngoing = false;
//     Serial.println("Vibration ended.");
//   }
// }


// //------Golden code------




// Don't know if this got uploaded or not

// #include <Arduino.h>
// #include <Servo.h>

// #define VIBRATION_SENSOR A5
// #define GAS_SENSOR A0
// #define LED 13
// #define BUZZER 12
// #define SERVO_PIN 9
// #define RELAY_PIN 5

// #define RELAY_ON LOW
// #define RELAY_OFF HIGH

// #define ON 1
// #define OFF 0

// int present_condition = 0;
// int previous_condition = 0;

// bool quakeOngoing = false;
// bool servoMoved = false;

// Servo doorServo;

// // Function to activate solenoid latch twice
// void activateSolenoidLatch(int times) {
//   for (int i = 0; i < times; i++) {
//     digitalWrite(RELAY_PIN, RELAY_ON);
//     delay(500);
//     digitalWrite(RELAY_PIN, RELAY_OFF);
//     delay(500);
//   }
// }

// void setup() {
//   Serial.begin(9600);
//   pinMode(VIBRATION_SENSOR, INPUT);
//   pinMode(LED, OUTPUT);
//   pinMode(BUZZER, OUTPUT);
//   pinMode(RELAY_PIN, OUTPUT);

//   digitalWrite(RELAY_PIN, RELAY_OFF); // Initial state

//   doorServo.attach(SERVO_PIN);
//   doorServo.write(0); // Initial closed position
//   delay(500); // Stabilize
//   Serial.println("Setup complete.");
// }

// void loop() {
//   previous_condition = present_condition;
//   present_condition = digitalRead(VIBRATION_SENSOR);

//   if (present_condition == HIGH) {
//     if (!quakeOngoing) {
//       quakeOngoing = true;

//       // 🔁 Updated: Rotate servo only once
//       if (!servoMoved) {
//         doorServo.write(180);
//         servoMoved = true;
//         Serial.println("Servo rotated to 180°.");
//       }

//       activateSolenoidLatch(2); // Trigger latch twice for aftershocks

//       Serial.println("Vibration detected.");
//     }

//     digitalWrite(LED, ON);
//     digitalWrite(BUZZER, ON);
//   } else {
//     digitalWrite(LED, OFF);
//     digitalWrite(BUZZER, OFF);
//     quakeOngoing = false;
//   }
// }





// All together code


#include <Arduino.h>
#include <Servo.h>

#define VIBRATION_SENSOR A5
#define GAS_SENSOR A0
#define LED 13
#define BUZZER 12
#define SERVO_PIN 9
#define RELAY_LATCH 5   // Relay 1 - Solenoid Latch
#define RELAY_BULB 4    // Relay 2 - Bulb Shutoff

#define RELAY_ON LOW
#define RELAY_OFF HIGH

#define ON 1
#define OFF 0

int present_condition = 0;
int previous_condition = 0;

bool quakeOngoing = false;
bool servoMoved = false;

Servo doorServo;

// Function to activate solenoid latch (in/out)
void activateSolenoidLatch(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(RELAY_LATCH, RELAY_ON);
    delay(500);
    digitalWrite(RELAY_LATCH, RELAY_OFF);
    delay(500);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(VIBRATION_SENSOR, INPUT);
  pinMode(GAS_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RELAY_LATCH, OUTPUT);
  pinMode(RELAY_BULB, OUTPUT);

  // Initial states
  digitalWrite(RELAY_LATCH, RELAY_OFF); // Latch off
  digitalWrite(RELAY_BULB, RELAY_ON);   // Bulb initially ON (connected to external AC)

  doorServo.attach(SERVO_PIN);
  doorServo.write(0); // Initial closed position
  delay(500);
  Serial.println("System ready.");
}

void loop() {
  // Earthquake detection
  previous_condition = present_condition;
  present_condition = digitalRead(VIBRATION_SENSOR);

  if (present_condition == HIGH) {
    if (!quakeOngoing) {
      quakeOngoing = true;

      // Open servo only once
      if (!servoMoved) {
        doorServo.write(180);
        servoMoved = true;
        Serial.println("Servo opened to 180°.");
      }

      activateSolenoidLatch(2); // Solenoid latch triggers twice

      digitalWrite(RELAY_BULB, RELAY_OFF); // Turn off bulb
      Serial.println("⚠️ Earthquake detected! Power shut off.");
    }

    digitalWrite(LED, ON);
    digitalWrite(BUZZER, ON);
  } else {
    quakeOngoing = false;
    digitalWrite(LED, OFF);
    digitalWrite(BUZZER, OFF);
  }

  // Gas sensor reading (MQ-2)
  int gasValue = analogRead(GAS_SENSOR);
  int gasPercent = map(gasValue, 0, 1023, 0, 100); // serial monitor 

  Serial.print("Gas Concentration: ");
  Serial.print(gasPercent);
  Serial.println("%");

  delay(1000); // Slow down loop to make serial output readable
}

