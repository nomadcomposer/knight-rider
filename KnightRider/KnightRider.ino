int dataPin = 9;
int latchPin = 10;
int clockPin = 11;
int dt = 100;

byte j;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (j=0x80;j>0x01;j/=0x02) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, j);
    digitalWrite(latchPin, HIGH);
    delay(dt);
  }

  for (j=0x01;j<0x80;j*=0x02) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, j);
    digitalWrite(latchPin, HIGH);
    delay(dt);
  }
  
}
