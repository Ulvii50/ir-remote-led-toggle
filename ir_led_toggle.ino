#include <IRremote.h>

int recv_pin = 2;
int ledPin = 5;
int state = 0;

IRrecv recv(recv_pin);
decode_results results;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  recv.enableIRIn();
}

void loop(){
  if (recv.decode(&results)) {
    Serial.println(results.value);
    if (results.value) {
      state = !state;
      digitalWrite(ledPin, state);
    }
    recv.resume();
  }
}
