// For temperature readings
#include<Wire.h>
#include <LiquidCrystal.h>
#include "Adafruit_HTU21DF.h"
#include "pitches.h"

/*
 * Temperature and Humidity Sensor Related
 */
Adafruit_HTU21DF tempSensor = Adafruit_HTU21DF();

/*
 * LCD Display Related
 */
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*
 * Sonar Related
 */
const int pingPin = 7; // location of Sonar

/*
 * Speaker Related
 */
const int speakerRedPin = 9; // location of red speaker wire

/*
 * Notes for the classic Mario Song
 */
int marioMelody[] = 
{
  NOTE_E4, NOTE_E4, REST, NOTE_E4, 
  REST, NOTE_C4, NOTE_E4, REST,
  NOTE_G4, REST, REST, NOTE_G3, REST,
  
  NOTE_C4, REST, REST, NOTE_G3,
  REST, NOTE_E3, REST,
  REST, NOTE_A3, REST, NOTE_B3,   
  REST, NOTE_AS3, NOTE_A3, REST,
  
  NOTE_G3, NOTE_E4, NOTE_G4,
  NOTE_A4, REST, NOTE_F4, NOTE_G4, 
  REST, NOTE_E4, REST, NOTE_C4, 
  NOTE_D4, NOTE_B3, REST
};

int marioNotes[] =
{
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 2, 4, 2, 2,
  
  4, 4, 4, 4,
  2, 4, 4,
  4, 4, 4, 4,  
  4, 4, 4, 4,
  
  4, 2, 4,
  4, 4, 4, 4,
  4, 4, 4, 4, 
  4, 4, 2
};

const int arrayElements = sizeof(marioNotes)/sizeof(marioNotes[0]);

/*
 * General Variables
 */
 const int closeDistance = 30; // the number of cm before the alarm goes off

// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin (A5 on UNO)
// Connect SDA to I2C data pin (A4 on UNO)

long temperatureSensor()
{
  return tempSensor.readTemperature();
  
//  Serial.print("Temp: ");
//  Serial.print(tempSensor.readTemperature());
//  Serial.print(" C Humidity: ");
//  Serial.print(tempSensor.readHumidity());
//  delay(150);
}

long rangeSensor()
{
  long duration, cm;

  // an initial LOW pulse beforehand to ensure a clean HIGH pulse
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the attained time to distance
  cm = microsecondsToCentimeters(duration);

  return cm;

//  lcd.print(" Distance: ");
//  lcd.print(cm);
//  lcd.print("cm ");
//  Serial.print("Distance: ");
//  Serial.print(cm);
//  Serial.print("cm");
//  Serial.println();

//  delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

/*
 * Draws out some special characters
 */
byte p20[8]
{
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};

byte p40[8]
{
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

byte p60[8]
{
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,  
};

byte p80[8]
{
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
};

byte p100[8]
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

/*
 * Draws out the degrees character
 */
byte degree[8]
{
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
};

void displayText()
{
  lcd.print("Sample Text");

  lcd.createChar(0, p20);
  lcd.createChar(1, p40);
  lcd.createChar(2, p60);
  lcd.createChar(3, p80);
  lcd.createChar(4, p100);
}

void clearTheLine()
{
  lcd.print("                ");
}

void playDistanceWarningTone()
{
  // iterates over the notes of the melody
  for(int thisNote = 0; thisNote < arrayElements; ++thisNote)
  {
    /*
     * to calculate the note duration, take one second
     * divided by the note type.
     * e.g. quarter note = 1000 / 4, eighth note = 1000 / 8 etc
     */

     int noteDuration = 100 / marioNotes[thisNote];
     tone(speakerRedPin, marioMelody[thisNote], noteDuration);

     /*
      * to distinguish the notes, set a minimum time between them.
      * the note's duration + 30% works well
      */

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing
      noTone(speakerRedPin);
  }
}

void setup() 
{
  // initialize serial communication
  Serial.begin(9600);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

//  lcd.print("Temperature Sensor Test");
  Serial.println("Temperature Sensor Test");

  if(!tempSensor.begin())
  {
    lcd.print("Temperature Sensor Not Found!");
//    Serial.println("Temperature Sensor Not Found :(");
    while(1);
  }
  else
  {
//    lcd.print("Sensor Success");
    Serial.println("Temperature Sensor Found!");
  }
}

void loop() 
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);

  long temp = temperatureSensor();
  long distance = rangeSensor();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
//  delay(500);

  lcd.setCursor(0, 1);
//  lcd.autoscroll();

  if(distance <= closeDistance)
  {
    lcd.print("TOO CLOSE!  ");
    playDistanceWarningTone();
  }
  else
  {
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm  ");
  }
//  delay(500);
  // turn off automatic scrolling
//  lcd.noAutoscroll();

  // clears screen for the next loop
//  lcd.clear();  
}
