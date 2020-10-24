#include <Servo.h>  
Servo myservoA;  
Servo myservoB;
Servo myservoC;
Servo myservoD;
Servo myservoE;
Servo myservoF;
int i,pos,myspeed,myshow;
int sea,seb,sec,sed,see,sef;
static int v=0;

String mycommand="";  //Receive commands from serial ports #auto：auto run   #com：computer serial control     #stop：stop status
static int mycomflag=2; // #auto：2   , #com： 1      #stop：0  


void myservosetup()  //Initialize the servo motors
{
   sea=myservoA.read();
   seb=myservoB.read();
   sec=myservoC.read();
   sed=myservoD.read();
   see=myservoE.read();
   sef=myservoF.read();
   
   myspeed=500;
   for(pos=0;pos<=myspeed;pos+=1)
   {
    myservoA.write(int(map(pos,1,myspeed,sea,66)));
    myservoB.write(int(map(pos,1,myspeed,seb,90)));
    myservoC.write(int(map(pos,1,myspeed,sec,50)));
    myservoD.write(int(map(pos,1,myspeed,sed,90)));
    myservoE.write(int(map(pos,1,myspeed,see,120)));
    myservoF.write(int(map(pos,1,myspeed,sef,90)));
    delay(1);
   }
}

void setup() 
{ 
  pinMode(13,INPUT); // Configures the specified pin to behave either as an input or an output.
  pinMode(12,INPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial.println("Hello!");
  myshow=0;
  mycomflag=2; // Robot arm default status: 2 auto
  myservoA.attach(3);  // Upper Arm Joint (B): Port 3
  myservoB.attach(5); // Waist Joint (A): Port 5
  myservoC.attach(6); // Forearm Joint (C): Port 6
  myservoD.attach(9); // Rotation of Forearm Joint (D): Port 9
  myservoE.attach(10); // Wrist Joint (E): Port 10
  myservoF.attach(11); // Rotation of Wrist Joint (F): Port 11
  
  myservoA.write(66);
  myservoB.write(90);
  myservoC.write(50);
  myservoD.write(90);
  myservoE.write(120);
  myservoF.write(90);

}

void loop() 
{ 
  while (Serial.available()>0)  
    {
        mycommand += char(Serial.read());

        delay(2);
    }
    if (mycommand.length() > 0)
    {
        if(mycommand=="#auto")
        {
          mycomflag=2;
          Serial.println("auto station");
          mycommand="";
        }
        if(mycommand=="#com")
        {
          mycomflag=1;
          Serial.println("computer control station");
          mycommand="";
          myservosetup();
        }
        if(mycommand=="#stop")
        {
          mycomflag=0;
          Serial.println("stop station");
          mycommand="";
        }
        
    }
  
  
  if(mycomflag==1)  //if com 1
  {      
 
   for(int m=0;m<mycommand.length();m++) 
  {
    char ch = mycommand[m];   // Receive command from serial ports
    switch(ch)
    {
      case '0'...'9':
      v = v*10 + ch - '0';   // Convert characters to decimal
      break;
      
      case 'a':   //if data received is 85a ---> motor A
      if(v >= 5 || v <= 175 ) myservoA.write(v); // Set the angle command to servo motor A from 0~180 degree (85a means 85 degree)
      v = 0;
      break;

      case 'b':   //if data received is 90b ---> motor B

      myservoB.write(v);   //Set the angle command to servo motor B from 0~180 degree (90b means 90 degree) 
      v = 0;
      break;
      case 'c':   
      if(v >= 20 ) myservoC.write(v);   
      v = 0;
      break;
      case 'd':  
      myservoD.write(v);   
      v = 0;
      break;
      case 'e':  
      myservoE.write(v);   
      v = 0;
      break;
      case 'f':  
      myservoF.write(v);   
      v = 0;
      break;
    }
   
    }  
   mycommand="";
  }  // end if(mycomflag=1)
  
  if(mycomflag==2)  //if auto 2 
  {    
   delay(3000); 
   //Serial.println("auto station"); 
   myservosetup();
   myspeed=500;
    for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoA.write(int(map(pos,1,myspeed,66,90))); // turn A from 66 to 90 degrees
    myservoB.write(int(map(pos,1,myspeed,90,40))); // turn B from 90 to 40 degrees
    delay(1);                       
  }
   delay(1000);
   myspeed=500;
  for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoC.write(int(map(pos,1,myspeed,50,65)));
    myservoD.write(int(map(pos,1,myspeed,90,170)));
    myservoE.write(int(map(pos,1,myspeed,90,5))); 
    delay(1);                       
   }
  myspeed=1000;
  for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoB.write(int(map(pos,1,myspeed,40,70)));
    myservoC.write(int(map(pos,1,myspeed,65,50)));
    delay(1);                       
   }
   myspeed=500;
  for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoC.write(int(map(pos,1,myspeed,50,45))); 
    myservoD.write(int(map(pos,1,myspeed,170,90)));
    myservoE.write(int(map(pos,1,myspeed,5,27)));
    myservoF.write(int(map(pos,1,myspeed,90,40)));
    delay(1);                       
   }
   myspeed=1000;
  for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoA.write(int(map(pos,1,myspeed,90,140))); 
    myservoF.write(int(map(pos,1,myspeed,40,130)));    
    delay(1);                       
   }  
    myspeed=500;
    for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoA.write(int(map(pos,1,myspeed,140,90))); 
    myservoC.write(int(map(pos,1,myspeed,45,50)));  
    myservoB.write(int(map(pos,1,myspeed,70,50))); 
    myservoE.write(int(map(pos,1,myspeed,27,120))); 
    delay(1);                       
  } 
  }
  
  if(mycomflag==0) //if stop 0
  {
   myservosetup();
  }
}
