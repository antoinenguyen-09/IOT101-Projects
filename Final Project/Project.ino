// include the library code:
#include <LiquidCrystal.h>
#include <IRremote.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
unsigned long key_value = 0;
const unsigned int TRIG_PIN=9;
const unsigned int ECHO_PIN=10;
const unsigned int BAUD_RATE=9600;



void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
}

void loop() {
  // set the cursor to (0,0):
  lcd.setCursor(0, 0);

  // set the cursor to (16,1):
  lcd.setCursor(16, 1);
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
      lcd.println("error");
      lcd.clear();
   } 
  else{
      lcd.clear();
      lcd.print("distance:");
      lcd.print(distance);
  }
  
  if (irrecv.decode(&results))
  {
      if (results.value == 0XFFFFFFFF)
        results.value = key_value;
        lcd.setCursor(0, 0);
        lcd.clear();
         
        switch(results.value){
          case 0xFFA25D:          
          lcd.print("CH-");
          break;
          case 0xFF629D:
          lcd.print("CH");
          break;
          case 0xFFE21D:
          lcd.print("CH+");
          break;
          case 0xFF22DD:
          lcd.print("|<<"); break; case 0xFF02FD: lcd.print(">>|");
          break ;  
          case 0xFFC23D:
          lcd.print(">|");
          break ;               
          case 0xFFE01F:
          lcd.print("-");
          break ;  
          case 0xFFA857:
          lcd.print("+");
          break ;  
          case 0xFF906F:
          lcd.print("EQ");
          break ;  
          case 0xFF6897:
          lcd.print("0");
          break ;  
          case 0xFF9867:
          lcd.print("100+");
          break ;
          case 0xFFB04F:
          lcd.print("200+");
          break ;
          case 0xFF30CF:
          lcd.print("1");
          break ;
          case 0xFF18E7:
          lcd.print("2");
          break ;
          case 0xFF7A85:
          lcd.print("3");
          break ;
          case 0xFF10EF:
          lcd.print("4");
          break ;
          case 0xFF38C7:
          lcd.print("5");
          break ;
          case 0xFF5AA5:
          lcd.print("6");
          break ;
          case 0xFF42BD:
          lcd.print("7");
          break ;
          case 0xFF4AB5:
          lcd.print("8");
          break ;
          case 0xFF52AD:
          lcd.print("9");
          break ;                   
        }
        key_value = results.value;
        irrecv.resume();             // waits 15ms for the servo to reach the position
  }
  delay(2000);

  } 
