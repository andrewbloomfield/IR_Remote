#include <IRremote.h> 
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int RECV_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
lcd.begin(16, 2);
lcd.print("IR Decoder");

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))

{ 
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print(results.value, HEX);

    lcd.setCursor(0, 1);
    switch (results.decode_type) {
    default:
    case UNKNOWN:      lcd.print("UNKNOWN");       break ;
    case NEC:          lcd.print("NEC");           break ;
    case SONY:         lcd.print("SONY");          break ;
    case RC5:          lcd.print("RC5");           break ;
    case RC6:          lcd.print("RC6");           break ;
    case DISH:         lcd.print("DISH");          break ;
    case SHARP:        lcd.print("SHARP");         break ;
    case JVC:          lcd.print("JVC");           break ;
    case SANYO:        lcd.print("SANYO");         break ;
    case MITSUBISHI:   lcd.print("MITSUBISHI");    break ;
    case SAMSUNG:      lcd.print("SAMSUNG");       break ;
    case LG:           lcd.print("LG");            break ;
    case WHYNTER:      lcd.print("WHYNTER");       break ;
    case AIWA_RC_T501: lcd.print("AIWA_RC_T501");  break ;
    case PANASONIC:    lcd.print("PANASONIC");     break ;
    case DENON:        lcd.print("Denon");         break ;
  }

  lcd.print(" "),lcd.print(results.bits),lcd.print(" Bits");

     
     Serial.println(results.value, HEX);
     irrecv.resume(); // Receive the next value

} 
 delay(300);

}
