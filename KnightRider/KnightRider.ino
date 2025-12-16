int dataPin = 9;
int latchPin = 10;
int clockPin = 11;

byte LED1s = 0x02;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED1s);
  digitalWrite(latchPin, HIGH);
}