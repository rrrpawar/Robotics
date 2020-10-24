#include <Servo.h> // The Servo library allows Arduino to control servo motors
Servo myservoA;  
Servo myservoB;
Servo myservoC;
Servo myservoD;
Servo myservoE;
Servo myservoF;

// Define and initialize variables
int i,pos,myspeed;
int sea,seb,sec,sed,see,sef;


void setup() 
{ 
  
  myservoA.attach(3); // Waist Joint (A): Port 3
  myservoB.attach(5); // Upper Arm Joint (B): Port 5
  myservoC.attach(6); // Forearm Joint (C): Port 6
  myservoD.attach(9); // Rotation of Forearm Joint (D): Port 9
  myservoE.attach(10); // Wrist Joint (E): Port 10
  myservoF.attach(11); // Rotation of Wrist Joint (F): Port 11

  // Control joints
  myservoA.write(66);
  myservoB.write(90);
  myservoC.write(50);
  myservoD.write(90);
  myservoE.write(120);
  myservoF.write(90);

}

void loop() 
{
   sea=myservoA.read();
   seb=myservoB.read();
   sec=myservoC.read();
   sed=myservoD.read();
   see=myservoE.read();
   sef=myservoF.read();
   
   myspeed=1000; // higher value <---> slower
   for(pos=0;pos<=myspeed;pos+=1)
   { 
    myservoA.write(int(map(pos,1,myspeed,sea,66)));
    myservoB.write(int(map(pos,1,myspeed,seb,90)));
    myservoC.write(int(map(pos,1,myspeed,sec,40)));
    myservoD.write(int(map(pos,1,myspeed,sed,90)));
    myservoE.write(int(map(pos,1,myspeed,see,120)));
    myservoF.write(int(map(pos,1,myspeed,sef,90)));    
    delay(1);
   }
   delay(2000); // delay 2s
   
   // Read current servo positions
   sea=myservoA.read();
   seb=myservoB.read();
   sec=myservoC.read();
   sed=myservoD.read();
   see=myservoE.read();
   sef=myservoF.read();
   
   
   for(pos=0;pos<=myspeed;pos+=1)
   { 
    myservoC.write(int(map(pos,1,myspeed,sec,80)));
    delay(1);
   }
  delay(2000);

   sea=myservoA.read();
   seb=myservoB.read();
   sec=myservoC.read();
   sed=myservoD.read();
   see=myservoE.read();
   sef=myservoF.read();
  for(pos=0;pos<=myspeed;pos+=1)
   { 
    myservoA.write(int(map(pos,1,myspeed,sea,120)));   
    delay(1);
   }
  delay(2000);
  
  for(pos=0;pos<=myspeed;pos+=1)
   {
    myservoC.write(int(map(pos,1,myspeed,80,40)));
    delay(1);
   }
   delay(2000);
   
   for(pos=0;pos<=myspeed;pos+=1)
   { 
    myservoC.write(int(map(pos,1,myspeed,40,80)));
    delay(1);
   }
  delay(2000);
  
   sea=myservoA.read();
   seb=myservoB.read();
   sec=myservoC.read();
   sed=myservoD.read();
   see=myservoE.read();
   sef=myservoF.read();
  for(pos=0;pos<=myspeed;pos+=1)
   { 
    myservoA.write(int(map(pos,1,myspeed,120,66)));
    delay(1);
   }
  delay(2000);

  for(pos=0;pos<=myspeed;pos+=1)
   {
    myservoC.write(int(map(pos,1,myspeed,80,40)));
    delay(1);
   }
   delay(2000);

   for(pos=0;pos<=myspeed;pos+=1)
   {
    myservoC.write(int(map(pos,1,myspeed,40,80)));
    delay(1);
   }
  delay(2000);
  
   sea=myservoA.read();
   seb=myservoB.read();
   sec=myservoC.read();
   sed=myservoD.read();
   see=myservoE.read();
   sef=myservoF.read();
  for(pos=0;pos<=myspeed;pos+=1)
   {
    myservoA.write(int(map(pos,1,myspeed,66,50))); 
    delay(1);
   }
  delay(2000);
}
