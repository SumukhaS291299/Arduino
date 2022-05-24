#include <Adafruit_NeoPixel.h>
String cmd = "";
#define PIN            2
#include<String.h>

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      12

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 250; // delay for half a second

void setup()
{
  pixels.begin(); // This initializes the NeoPixel library.

  Serial.println("Commands");

  Serial.println("Neo pixel input 3");

  Serial.println("A(All Same)<Number 2-1>(Percentage of light)(000)(000)(000 colour config) Ex A5A123456789 ");
  Serial.println("S(Special)<(000)(000)(000 colour config start point)> <(0)(0)(0)> adders Ex S123456789123 ");

  for (int i = 0; i < NUMPIXELS; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(200); // Delay for a period of time (in milliseconds).
  }
  delay(100);
  for (int i = 0; i < NUMPIXELS; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(200); // Delay for a period of time (in milliseconds).
  }
  delay(100);
  for (int i = 0; i < NUMPIXELS; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 0, 255)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(200); // Delay for a period of time (in milliseconds).
  }

  Serial.begin(9600);
  Serial.println("Initilization done");

  delay(1000);
  Serial.println("Please provide the command $");
}


void loop()
{
  // Take input for each led
  // commands init for all use A or a
  // use of numbers with A will provide the brightness of the led (Available values 2,3,4,5,6,7,8,9,1 => 20%,30%...90%,100%)
  // delay in each pixel can be shown after the number representation
  // Rotating Led will be assigned R r S s (Rotating)
  // Auto-Spin palatte is also defined as S
  // Colour has to be 3 digits each specfied as 002 110 430
  // Powerful (All colour selection) All colour itteration

  // At end Show all at once or animate ? (Will decide what to do ?)

  // C or c for clear all
  // Example A 5 A 255,000,000 -> 6 led lit with red
  // Example A 5 E 255,000,000 Each input colour saparately (To be implemented)
  // Exapmle S (000)(000)(000) 1 2 3 => Implies start range of colours 123 represents adders in each
  //func to set command

  cmd = Serial.readString();    // Reads the Serial data as string

  Serial.println(" Command recieved : "); Serial.println(cmd);
  // A5A(000)(000)(000)
  if (cmd.startsWith("C") || cmd.startsWith("c")) {
    Serial.println("Clear all");
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();
      delay(100);
    }
  }
  //P
  if (cmd.startsWith("P") || cmd.startsWith("p")) {
    int a = 0, b = 0, c = 0;
    while (a <= 255 || b <= 255 || c <= 255) {
      for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(a, b, c));
        pixels.show();
        Serial.println(a);
        Serial.print(b);
        Serial.print(c);
        delay(10);
      }
      if (a < 255) {
        a = a + 1;
      }
      if (a >= 255 && b < 255) {
        b = b + 1;
      }
      if (b >= 255 && c < 255) {
        c = c + 1;
      }
      if (a >= 255 && b >= 255 && c >= 255 ) {
        break;
      }
    }
  }
  if (cmd.startsWith("a") || cmd.startsWith("A")) {
    Serial.println("All Led Selected");
    int level = cmd.substring(1, 2).toInt();
    Serial.println(level);
    int set;
    if (level == 1) {
      set = NUMPIXELS;
    }
    else {
      set = (level * NUMPIXELS) / 10;
    }
    Serial.println("The number of led will light = ");
    Serial.print(set);
    if (cmd.substring(2, 3) == "A" || cmd.substring(2, 3) == "a") {
      for (int i = 0; i < set; i++) {
        pixels.setPixelColor(i, pixels.Color(cmd.substring(3, 6).toInt(), cmd.substring(6, 9).toInt(), cmd.substring(9, 12).toInt()));
        pixels.show();
        delay(100);
      }
    }
  }
  //S000000000123
  if (cmd.startsWith("S")) {
    int c1 = cmd.substring(1, 4).toInt();
    int c2 = cmd.substring(4, 7).toInt();
    int c3 = cmd.substring(7, 10).toInt();
    while (c1 <= 255 || c2 <= 255 || c3 <= 255) {
      for (int i = 0; i < NUMPIXELS; i++) {
        Serial.println(c1);
        Serial.println(c2);
        Serial.println(c3);
        pixels.setPixelColor(i, pixels.Color(c1, c2, c3));
        pixels.show();
        delay(100);
      }
      if (c1 < 255) {
        c1 = c1 + cmd.substring(10, 11).toInt();
      }
      if (c2 < 255) {
        c2 = c2 + cmd.substring(11, 12).toInt();
      }
      if (c3 < 255) {
        c3 = c3 + cmd.substring(12, 13).toInt();
      }
      if (c1 >= 255 && c2 >= 255 && c3 >= 255 ) {
        break;
      }
    }
    for (int i = 0; i < NUMPIXELS; i++)
    {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(0, 0, 255)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(200); // Delay for a period of time (in milliseconds).
    }
    for (int i = NUMPIXELS; i > 0; i--)
    {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(200); // Delay for a period of time (in milliseconds).
    }
  }


}
