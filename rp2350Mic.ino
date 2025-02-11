/*
   Mono analog microphone example using electret mike on A0
   Run using the Arduino Serial Plotter to see waveform.
   Released to the Public Domain by Earle F. Philhower, III

   Wire the mike's VCC to 3.3V on the Pico, connect the mike's
   GND to a convenient Pico GND, and then connect mike OUT to A0
*/
// Green led = GP25
#include <ADCInput.h>
#define ledbuildIN A25;
int lpnum;

ADCInput mike(A0);
// For stereo/dual mikes, could use this line instead
//ADCInput(A0, A1);
// v Reset, v Boot, ^ Reset, ^ Boot = UF2 boot
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(2400);
  Serial.println("Rasberry Pi Pico 2 RP2350-Plus");
  mike.begin(8000);
  lpnum = 1;
 // while (1) {
  //  Serial.printf("%d\n", mike.read());
    // For stereo/dual mikes, use this line instead
    //   Serial.printf("%d %d\n", mike.read(), mike.read());
 // }
}

void loop() {
  lpnum++;
  digitalWrite(LED_BUILTIN, HIGH);  delay(250);
  Serial.write("ADC from microphone = ");
  Serial.printf("%d\n", mike.read());
// For stereo/dual mikes, use this line instead
  // Serial.printf("%d %d\n", mike.read(), mike.read());
  Serial.write("loop ");  Serial.write(lpnum);
  Serial.write(13);  Serial.write(10);
  digitalWrite(LED_BUILTIN, LOW);   delay(250);
}
