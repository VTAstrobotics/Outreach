/*
  TINY ROBOT CODE FOR OUTREACH!!!
  This code allows the tiny robot to choose between different
  motions. We have circle where the robot moves in a circle,
  square where it moves in a square, and then another motion 
  where it moves forward, spins, then returns to its original position. 

  Lastly, for any kid who wants to try, there is a custom method
  that can be tweaked to do different movements.

  If anyone wants a new movement added, create a method and have it in 
  the loop. 

  To switch between movements, comment out the ones not taking place 
  and uncomment out the movements you want to do in the loop. 
*/

// Motor driver pins (adjust if wired differently)
// Motor A is left and Motor B is right!
// IN1 and IN3 is forward for left right respectively
// IN2 and IN4 is backward for left right respectively
int IN1 = 2;
int IN2 = 3;
int ENA = 9;  // PWM pin for Motor A
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
  /* Circle movement: */
  //circle();

  /* Square movement - note!! It's kinda off but I tried my best */
  //square();

  /* Forward, spin, back. Lowkey kinda a circular square motion... */
  //forward_spin_back();

  /* zigzags */
  zigzag();
  /* Custom - anything!*/
  //custom();
}

void square() {
  // IN1 and IN3 is forward for left right respectively
  // IN2 and IN4 is backward for left right respectively
  // A is left, B is right
  for (int i = 0; i < 4; i++) {
    straight(100);
    delay(1000);
    stop();
    delay(1000);
    r_turn(100);
    delay(650);
    stop();
    delay(1000);
  }
}

/* 
  spins forward then goes back 
*/
void forward_spin_back() 
{
  straight(100);
  delay(1000);
  circle();
  delay(1000);
  straight(100);
}

/*
  zigzags
*/
void zigzag() 
{
  straight(100);
  delay(1000);
  r_turn(100);
  delay(600);
  straight(100);
  delay(1000);
  l_turn(100);
  delay(600);
}

/* 
  you can code whatever movements you want 
  The methods that can be used are below. NOTE 
  the speed range is 0 - 255: 

  delay(1000) - waits 1 second
  r_forward(speed) - moves the right motor
  l_forward(speed) - moves the left motor
  r_backward(speed) - moves right motor backward
  l_backward(speed) - moves left motor backward
  straight(speed) - moves the whole thing straight
  r_turn(speed) - turns right
  l_turn(speed) - turns left
*/
void custom() 
{
  //code here!


}


/*
 The robot moves in a circular motion continuously. 
*/
void circle() {
  // left motor forward with speed 200
  l_forward(200);

  //right motor stationary
  digitalWrite(IN3, LOW);  // right motor
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200);
}

/* 
  moves straight
*/
void straight(int speed) {
  //left
  l_forward(speed);

  //right
  r_forward(speed);
}

/*
  left motor moves forward
*/
void l_forward(int speed) {
  digitalWrite(IN1, HIGH);  // left motor
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);
}

/*
  right motor moves forward
*/
void r_forward(int speed) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speed);
}

/*
  left motor moves backward
*/
void l_backward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed);
}

/*
  right motor moves backward
*/
void r_backward(int speed) {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, speed);
}

/*
  right turn
*/
void r_turn(int speed) {
  //left forward
  l_forward(speed);

  //right backward
  r_backward(speed);
}

/*
  left turn
*/
void l_turn(int speed) {
  //left backward
  l_backward(speed);

  //right forward
  r_forward(speed);
}

/*
  stops
*/
void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}