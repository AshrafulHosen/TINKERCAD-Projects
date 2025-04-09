#include <Wire.h>

#include <Keypad.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

long first=0;
long second=0;
double total=0;

char customkey;
const byte rows=4;
const byte cols=4;

char keys[rows][cols]=
{
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

byte rowpins={7,6,5,4};
byte colpins={3,2,1,0};

//initalize the instance of class newkeypad
Keypad customkeypad=Keypad(makeKeymap(keys),rowpins,colpins,rows,cols);

void setup()
{
  lcd.begin(16,2);    //start lcd
  for(int i=0;i<=3;i++)
  lcd.setCursor(0,0);
    lcd.print("Calculator");
    lcd.setCursor(0,1);
    lcd.print("Enter numbers");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
}

void loop()
{
  customkey=customkeypad.getKey();
  switch(customkey)
  {
   case '0' ... '9':
    lcd.setCursor(0,0);
    first=first*10+(customkey - '0');
    lcdd.print(first);
    break;
    
   case '+':
    first=(total!=0 ? total:first);
    lcd.print('+');
    second=SecondNumber();
    total=first+second;
    lcd.setCursor(0,3);
    lcd.print(total);
    first=0,second=0;
    break;
    
   case '-':
    first=(total!=0 ? total:first);
    lcd.print('-');
    second=SecondNumber();
    total=first-second;
    lcd.setCursor(0,3);
    lcd.print(total);
    first=0,second=0;
    break;
    
   case '*':
    first=(total!=0 ? total:first);
    lcd.print('*');
    second=SecondNumber();
    total=first*second;
    lcd.setCursor(0,3);
    lcd.print(total);
    first=0,second=0;
    break;
    
   case '/':
    first=(total!=0 ? total:first);
    lcd.print('/');
    second=SecondNumber();
    total=first/second;
    lcd.setCursor(0,3);
    
    second==0 ? lcd.print("Invalid") : total = (float)first / (float)second;
    
    lcd.print(total);
    first=0,second=0;
    break;
    
   case 'C':
    total=0;
    lcd.clear();
    break;
  }
}

long SecondNumber()
{
  while(1)
  {
    customkey=customkeypad.getkey();
    
    if(customkey >='0' && customkey <= '9')
    {
      second=second*10+(customkey - '0');
      lcd.setCursor(7,0);
      
      lcd.print(second);
    }
    
    if(customkey== '=') break;  //return second
  }
  return second;
}