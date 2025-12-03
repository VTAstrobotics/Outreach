 // Motor driver pins (adjust if wired differently)
int IN1 = 2;
int IN2 = 3;
int ENA = 9;   // PWM pin for Motor A
int IN3 = 4;
int IN4 = 5;
int ENB = 10;  // PWM pin for Motor B

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

}

void loop() {
  //Circle movement: 
  // Forward
  digitalWrite(IN1, HIGH); // left motor 
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);

  digitalWrite(IN3, LOW); // right motor 
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200);

  //Square movement


  //Forward, spin, back

  //Custom????



 
}