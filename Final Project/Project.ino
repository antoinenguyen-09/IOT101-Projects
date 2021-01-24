// include the library code:
#include <LiquidCrystal.h>
#include <IRremote.h>
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
const unsigned int TRIG_PIN=9;
const unsigned int ECHO_PIN=10;
const unsigned int BAUD_RATE=9600;
int NUM_ROWS = 2;
int NUM_COLUMNS = 16;

enum Buttons {
  NONE,
  BUTTON_1,
  BUTTON_2,
  BUTTON_3,
  BUTTON_4,
  BUTTON_5,
  BUTTON_6,
  BUTTON_7,
  BUTTON_8,
  BUTTON_9,
  BUTTON_NEXT,
  BUTTON_PREV,
  BUTTON_CLEAR
};
struct code_button_pair {
  unsigned long code;
  int button;
};
int button = NONE;
int cycle = 0;

int row = 0;
int column = 0;
const code_button_pair code_mapping[] {
  {0xFF30CF,BUTTON_1},
  { 0xFF18E7, BUTTON_2 },
  { 0xFF7A85, BUTTON_3 },
  { 0xFF10EF, BUTTON_4 },
  { 0xFF38C7, BUTTON_5 },
  { 0xFF5AA5, BUTTON_6 },
  { 0xFF42BD, BUTTON_7 },
  { 0xFF4AB5, BUTTON_8 },
  { 0xFF52AD, BUTTON_9 },
  { 0xFF906F, BUTTON_NEXT },
  { 0xFFE01F, BUTTON_PREV },
  { 0xFFA25D, BUTTON_CLEAR }
};


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
void updateState() {
  int code_mapping_size = sizeof(code_mapping) / sizeof(code_button_pair);
  for (int i = 0; i < code_mapping_size; ++i) {
    if (results.value == code_mapping[i].code) {
      if (button == code_mapping[i].button) {
        if (button != BUTTON_7 && button != BUTTON_9) {
          cycle = (cycle + 1) % 3;
        } else {
          cycle = (cycle + 1) % 4;
        }
      } else {
        button = code_mapping[i].button;
        cycle = 0;
      }
    }
  }
}

int mod(int a, int b) {
    int r = a % b;
    return r < 0 ? r + b : r;
}
void decodeState() {
  switch (button) {
     case BUTTON_1:
      lcd.print((char)('1' + cycle));
      break;
    case BUTTON_2:
      lcd.print((char)('2' + cycle));
      break;
    case BUTTON_3:
      lcd.print((char)('3' + cycle)); 
      break;
    case BUTTON_4:
      lcd.print((char)('4' + cycle));
      break;
    case BUTTON_5:
      lcd.print((char)('5' + cycle));
      break;
    case BUTTON_6:
      lcd.print((char)('6' + cycle));
      break;
    case BUTTON_7:
      lcd.print((char)('7' + cycle));
      break;
    case BUTTON_8:
      lcd.print((char)('8' + cycle));
      break;
    case BUTTON_9:
      lcd.print((char)('9' + cycle));
      break;
    case BUTTON_NEXT:
      column = mod((column + 1), NUM_COLUMNS);
      if (column == 0) 
        row = mod((row + 1), NUM_ROWS);
      break;
    case BUTTON_PREV:
      column = mod((column - 1), NUM_COLUMNS);
      if (column == 15) 
        row = mod((row - 1), NUM_ROWS);
      break;
    case BUTTON_CLEAR:
      lcd.print(' ');
      break;
    default:
      break;
  }
  lcd.setCursor(column, row);
}

void loop() {

  // set the display to automatically scroll:
lcd.noAutoscroll();
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

 unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int distance= duration/29/2;
 if(duration==0){
      lcd.println("no pulse");
      lcd.clear();
   } 
  else if(distance<=5){
    digitalWrite(6, HIGH);   
    int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};
   
     for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(8);
          lcd.clear();
      lcd.print("distance:");
      lcd.print(distance);
      lcd.print("cm");

  } 
          delay(3000);
      lcd.clear();
  }
  digitalWrite(6, LOW);
  
  int stop=-1; // > 0 nhap so vao
  
  key_value=results.value;
  if(irrecv.decode(&results)){
    if (key_value == 0xFF22DD ){ // == TEST
      Serial.println(stop);
      lcd.print("Enter Code:");
      stop=1;
      irrecv.resume();
    }  
  }
  
  while(stop>0){  //fix lai
  if (irrecv.decode(&results)) {

    updateState();
    decodeState();
    irrecv.resume();
    }
        if (results.value==0xFFA25D ){
     
      lcd.clear();
      irrecv.resume();
      Serial.println(stop);
       stop=-1;
      }
  }
  Serial.println(stop);
  delay(100);
  }            // bat lai ko dc
