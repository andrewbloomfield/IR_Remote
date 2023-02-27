#include <IRremote.h>


IRsend irsend;
int toggle;
int codeValue;
const int buttonPin =3;

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT);
  toggle = 1;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
  for(int i = 1; i<3; i++) {
    irsend.sendNEC(0x20DFD02F, 32);    //LG Source select
    delay(40);
    irsend.sendNEC(0xFECA35, 32); //Tecknika TV Source select
    delay(40);
    irsend.sendSAMSUNG(0xE0E0807F, 32); //Samung TV Source select
    delay(40);
    irsend.sendRC5(0x878, 12); //Celcus TV Source select
    delay(40);  
  }
  }
  
  else {
  for(int i = 1; i<3; i++) {
    irsend.sendNEC(0x20DF10EF, 32);    //LG On Off
    delay(40);
    irsend.sendNEC(0xFE50AF, 32); //Tecknika TV On Off
    delay(40);
    irsend.sendSAMSUNG(0xE0E040BF, 32); //Samung TV On Off
    delay(40);
    irsend.sendRC5(0x84C, 12); //Celcus TV On Off
    delay(40);
  }
  }
  delay(2000);
}
