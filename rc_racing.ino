int IN1 = 11;
int IN2 = 10;
int IN3 = 9;
int IN4 = 8;
int ENA = 5;  
int ENB = 6; 
int ledPin = 13;

char command; 

void setup() {
 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(ledPin,OUTPUT);
  Serial.println("Bluetooth Device is ready to pair");

  Serial.begin(9600);  
}

void loop() {
 
  if (Serial.available() > 0) {
    command = Serial.read();  

    switch (command) {
      case 'F': 
        moveForward(255);
        digitalWrite(ledPin, HIGH);
        Serial.println("LED ON"); 
        break;

      case 'B': 
        moveBackward(255);
        break;

      case 'L':
        turnLeft(200);  
        break;

      case 'R':  
        turnRight(200);  
        break;

      case 'S': 
        stopMotors();
        break;

      default:
        stopMotors();  
        break;
    }
  }
}


void moveForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);  
  analogWrite(ENB, speed);  
}

void moveBackward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnLeft(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnRight(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);  
  analogWrite(ENB, 0);  
}