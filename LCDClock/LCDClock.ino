#include<LiquidCrystal.h>

//LiquidCrystal(rs, enable, d4, d5, d6, d7) to assign pins. Always in descending order!! 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// initial Time display is h:m:s PM
int hr = 10;
int mins = 11;
int sec = 0;
int flag=1; //1 for PM, -1 for AM



void setup()
{
  lcd.begin(16, 2);// Tells micro controller we're using 16x2 LCD 
}

void loop()
{
  // Update LCD Display
  // Print TIME in Hour, Min, Sec + AM/PM
  lcd.setCursor(0,0);//lcd.setCursor(coloumn , row) to set cursor where desired
  lcd.print("Time ");
  if(hr<10)lcd.print("0");//So LCD always displays 2 digits( 01 instead of 1)
  lcd.print(hr);
  lcd.print(":");
  if(mins<10)lcd.print("0");
  lcd.print(mins);
  lcd.print(":");
  if(sec<10)lcd.print("0");
  lcd.print(sec);

  //Setting AM and PM
  if(flag==-1) lcd.print(" AM");
  if(flag==1) lcd.print(" PM");
 
  //lcd.setCursor(0,1);// for Line 2
 
 
 
  //Delay so statements below execute every 1 second
  delay(987);//used delay(987) instead of delay(1000) to try and account for time taken to execute loop

 
  // this method of measuring time is not accurate



  // Calculate TIME in Hour, Min, Sec + AM/PM
  sec = sec + 1; //increment sec. counting
  
  //Add 1 to mins and restart sec to 0 every 60 sec
  if(sec==60)
  {
    sec = 0;
    mins += 1;
  }
  
  //Add 1 to hr and restart mins to 0 every 60 mins
  if(mins==60)
  {
    mins = 0;
    hr+=1;
  }
  
  //At 12:00:00 change PM/AM
  if(hr==12 && mins==0 && sec==0)
  {
    flag *= -1;
  }
  
  //Change hr from 13 to 1
  if(hr==13){
    hr = 1;
  }
}  
