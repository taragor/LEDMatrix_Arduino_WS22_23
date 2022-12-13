#include <Arduino.h>



#include <DFRobot_RGBMatrix.h> // Hardware-specific library
#include <Wire.h>
#define OE    9
#define LAT   10
#define CLK   11
#define A     A0
#define B     A1
#define C     A2
#define D     A3
#define E     A4
#define WIDTH 64
#define HIGH  64


int a=0;
int b=16;
DFRobot_RGBMatrix matrix(A, B, C, D, E, CLK, LAT, OE, false, WIDTH, HIGH);

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello Matrix.");
  matrix.begin();
  // fill the screen with 'black'
  matrix.setTextSize(1);     // size 1 == 8 pixels high
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  delay(500);
}

void loop()
{  byte i;
  if(a<=-64)
{a=64;
  }
  if(b<=-48)
{b=80;
  }
  matrix.fillScreen(0);//clear the screen
  matrix.setTextSize(2);//Set as 16*16 pixel
  matrix.setCursor(15, a);    // start at top left, with 8 pixel of spacing
  matrix.setTextColor(matrix.Color333(4, 0, 4));//
  matrix.println("DFR");//
  matrix.setTextSize(1);//Set as 8*8 pixel
  matrix.setCursor(12, b);
  matrix.println("DFROBOT");
  matrix.setTextSize(1);
  matrix.print("Let's joinhands witheach otherto create a future");
  delay(600);
  a=a-6;
  b=b-6;
}
