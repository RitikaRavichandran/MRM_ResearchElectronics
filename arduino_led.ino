//code

//pins connected
const int  button = 2; 
const int led1 = 3;
const int led2 = 5;
const int led3 = 6; 

//button push count
int buttoncount = 0;
int buttonstate = 0;         
int lastbuttonstate = 0;     

void setup() {
 pinMode(button, INPUT);
 pinMode(led1, INPUT);
 pinMode(led2, INPUT);
pinMode(led3, INPUT);
 pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);

 Serial.begin(9600);
}


void loop()
{
  //button counting
 buttonstate = digitalRead(button);

 if (buttonstate != lastbuttonstate) 
 {
   if (buttonstate == HIGH) 
   {
     buttoncount++;
     Serial.println("on");
     Serial.print("number of times button is pushed: ");
     Serial.println(buttoncount);
   } else 
   {
     Serial.println("off");
   }
   delay(1000);
 }
 lastbuttonstate = buttonstate;

 //case1: leds are off
 if (buttoncount == 0) 
 {
   digitalWrite(led1, 0);
   digitalWrite(led2, 0);
   digitalWrite(led3, 0);
 }
  //case2: fade in and fade out
 if (buttoncount == 1)
 {
 digitalWrite(led1, 255);
   digitalWrite(led2, 255);
   digitalWrite(led3, 255);
   delay(1100);
   digitalWrite(led1, 0);
   digitalWrite(led2,0);
   digitalWrite(led3,0);
   delay(1000); 
 }
  //case3: blinking
 else if (buttoncount == 2) 
 {
   digitalWrite(led1, HIGH);
   digitalWrite(led2, HIGH);
   digitalWrite(led3, HIGH);

   delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
   delay(300);
 } 
  //case4: 3-bit counter
 else if (buttoncount == 3) 
 {
for(int i=0;i<=7;i++)
 {
  if(i==0 || i==2 || i==4 || i==6)
  {
   digitalWrite(led1,LOW);  
  }
         else
  {
   digitalWrite(led1,HIGH);
  }
  if(i==2 || i==3 || i==6 || i==7)
  {
   digitalWrite(led2,HIGH);  
  }
  else
  {
   digitalWrite(led2,LOW);
  }
  if(i>3)
  {
   digitalWrite(led3,HIGH);  
  }
  else
  {
   digitalWrite(led3,LOW);
  }

  delay(1500);      
 }
   buttoncount = 0;
 }
 }

//end
