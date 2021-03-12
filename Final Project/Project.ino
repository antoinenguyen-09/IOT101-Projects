// include the library code:
#include <LiquidCrystal.h>
#include <IRremote.h>
#include <stdbool.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int RECV_PIN = 7;
float sinVal;
int toneVal;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
unsigned long key_value = 0;
const unsigned int TRIG_PIN = 9;
const unsigned int ECHO_PIN = 10;
const unsigned int BAUD_RATE = 9600;

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  lcd.cursor();
}

void print_input_digit(int value, int count)
{
  lcd.setCursor(count - 1, 0);
  lcd.print(value);
}

int input_number(String command)
{
  int num[2] = {0, 0};
  int count, number, value;
  while(true)
  {   
    alert();
    count = 11, number = 0, value = -1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(command);
    //Input number
    while(true)
    { 
      if(alert()){
        lcd.setCursor(0, 0);
        lcd.print(command);
        num[0]=0;
        num[1]=0;
        count=11;
        number=0;
      };
      
      if(irrecv.decode(&results))
      {
        Serial.println(results.value, HEX);
        if(results.value == 0xFF6897) //0 
        {
          value = 0;
          ++count;
          if(count-11 <= 2)
          {
            print_input_digit(value, count);
            num[count-11 - 1] = value;
          }
        }
        else if(results.value == 0xFF30CF) //1
        {
          value = 1;
          ++count;
          if(count-11 <= 2)
          {
            print_input_digit(value, count);
            num[count -11- 1] = value;
          }
        }
        else if(results.value == 0xFF18E7) //2
        {
          value = 2;
          ++count;
          if(count-11 <= 2)
          {
            print_input_digit(value, count);
            num[count -11- 1] = value;
          }
        }
        else if(results.value == 0xFF7A85) //3
        {
          value = 3;
          ++count;
          if(count-11 <= 2)
          {
            print_input_digit(value, count);
            num[count -11- 1] = value;
          }
        }
        else if(results.value == 0xFF10EF) //4
        {
          value = 4;
          ++count;
          if(count-11 <= 2)
          {
            print_input_digit(value, count);
            num[count -11- 1] = value;
          }
        }
        else if(results.value == 0xFF38C7) //5
        {
          value = 5;
          ++count;
          if(count-11 <= 2)
          {
            print_input_digit(value, count);
            num[count -11- 1] = value;
          }
        }
        else if(results.value == 0xFF5AA5) //6
        {
          value = 6;
          ++count;
          if(count-11 <= 2)
          {
            print_input_digit(value, count);
            num[count -11- 1] = value;
          }
        }
        else if(results.value == 0xFF42BD) //7
        {
          value = 7;
          ++count;
          if(count-11 <= 2)
          {
            print_input_digit(value, count);
            num[count -11- 1] = value;
          }
        }
        else if(results.value == 0xFF4AB5) //8
        {
          value = 8;
          ++count;
          if(count -11<= 2)
          {
            print_input_digit(value, count);
            num[count -11- 1] = value;
          }
        }
        else if(results.value == 0xFF52AD) //9
        {
          value = 9;
          ++count;
          if(count-11 <= 2)
          {
            print_input_digit(value, count);
            num[count -11- 1] = value;
          }
        }
        else if(results.value == 0xFFA857) //enter
        {
          irrecv.resume();
          lcd.clear();
          break;
        }
        irrecv.resume();
      }
    }
    if(count-11 == 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("No code");
      delay(1000);
      continue;
    }
    else if(count-11 >= 2)
    {
      number = num[0] * 10 + num[1];
    }
//    Serial.println(number);
    //Validate the input number
    break;
  }
  return number;
}

bool alert() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration / 29 / 2;
  if (duration == 0) {
    lcd.println("no pulse");
    lcd.clear();
    return false;
  }
  else if (distance <= 5) {
    digitalWrite(6, HIGH);
    int melody[] = {

      NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
    };

    // note durations: 4 = quarter note, 8 = eighth note, etc.:
    int noteDurations[] = {

      4, 8, 8, 4, 4, 4, 4, 4
    };

    for (int thisNote = 0; thisNote < 8; thisNote++) {

      int noteDuration = 1000 / noteDurations[thisNote];

      tone(8, melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;

      delay(pauseBetweenNotes);

      // stop the tone playing:

      noTone(8);
      lcd.clear();
      lcd.print("STAY AWAY!");
    }
    delay(3000);
    lcd.clear();
    digitalWrite(6, LOW);
    return true;
  }
}
void loop() {

  // set the display to automatically scroll:
  lcd.noAutoscroll();
  alert();
  int Min=0,Max=50;
  int code = input_number("Enter code:");
  if(code < Min || code > Max)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Wrong Code!");
      delay(2000);
    }
    else{
      lcd.print("PLACE ");
      lcd.print(code);
      lcd.print(" SUCCESS");
      delay(1000);
    }

  alert();
  irrecv.resume();
  delay(100);
}
