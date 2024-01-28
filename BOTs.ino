#include <SPI.h>
#include <RF24.h>

RF24 radio(6, 5); // Set CE and CSN pins

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(0xF0F0F0F0E1LL); // Set the receiving address on the node
}

void loop() {
  // image capturing code

  byte imageData[] = {'C','A','1','4','F','K','L'};
  size_t dataSize = sizeof(imageData);

  // Sends the image data
  radio.write(&imageData, dataSize);

  Serial.println("Image sent successfully!%d");
  Serial.println(dataSize);
  delay(1250);
}
