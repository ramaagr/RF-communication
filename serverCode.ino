#include <SPI.h>
#include <RF24.h>
RF24 radio(6, 5); // Set CE and CSN pins

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL); // Set the same address as the sender
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    // Read the incoming data
    byte imageData[32];
    size_t dataSize = sizeof(imageData);

    radio.read(&imageData, dataSize);
    Serial.println("Received image data:");

    for (size_t i = 0; i < dataSize; i++) {
      Serial.print(imageData[i], STR);
      Serial.print(" ");
    }

    Serial.println();
  }

  // Add any additional code for main program
}