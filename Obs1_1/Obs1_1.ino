/* mototrL1,motorL2 and motorR1,motorR2
 *sonicLtrig,sonicLecho and sonicFtrig,sonicFecho and sonicRtrig,sonicRecho
 */
 // Test by AP
 //
#define sonicLtrig 2
#define sonicLecho 3
#define sonicFtrig 4
#define sonicFecho 5
#define sonicRtrig 6
#define sonicRecho 7

#define motorL1 8
#define motorL2 9
#define motorR1 10
#define motorR2 11


void setup()
{
  
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  
  Serial.begin(9600);
  
  pinMode(sonicLtrig, OUTPUT);
  pinMode(sonicLecho, INPUT);
  
  pinMode(sonicFtrig, OUTPUT);
  pinMode(sonicFecho, INPUT);
  
  pinMode(sonicRtrig, OUTPUT);
  pinMode(sonicRecho, INPUT);
}


void loop()
{
  
  //sonicF
  float distF;
  distF=distCalc(sonicFtrig, sonicFecho); //sends to the distCalc function
  
  //###USE ONLY ONE U-SENSOR, and rotate  
  
  //sonicL
  float distL;
  distL=distCalc(sonicLtrig, sonicLecho);
  
  
  //###USE ONLY ONE U-SENSOR, and rotate
  
  //sonicR
  float distR;
  distR=distCalc(sonicRtrig, sonicRecho);
  
  
  
  if(distF<10 && distL>10 && distR>10)
  {
    //forward
    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
  }
  
  // supply from 1 to 2 implies forward
  // supply from 2 to 1 implies backward
  if(distF<10 && distL<10 && distR<10)  
  {
    back=false
    //backward
       
    do
    {
      digitalWrite(motorL1, LOW);
      digitalWrite(motorL2, HIGH);
      digitalWrite(motorR1, LOW);
      digitalWrite(motorR2, HIGH);
      delay(400); 
     
    }while(distL<10 && distR<10);
    
    // turn away to some direction now how do we know which direction?
    
    do{
      
      //choose a direction to turn!!
      
      /*
   
      digitalWrite(motorL1, LOW);
      digitalWrite(motorL2, LOW);
      digitalWrite(motorR1, HIGH);
      digitalWrite(motorR2, LOW);
      delay(300);
    }while(distF<10);//caliberate
   
    */
    
  }
  
  //bang straight on
  if(distF<10 && distL>10 && distR>10)
  {
    do{
      
      //choose a direction to turn!!
      /*
      
      digitalWrite(motorL1, LOW);
      digitalWrite(motorL2, LOW);
      digitalWrite(motorR1, HIGH);
      digitalWrite(motorR2, LOW);
      delay(300);
    }while(distF<10);//caliberate
    */
  }    
  
  
  
  //diagonal right corners
  if(distF<10 && distL>10 && distR<10)
  {
    do{
      digitalWrite(motorL1, LOW);
      digitalWrite(motorL2, LOW);
      digitalWrite(motorR1, HIGH);
      digitalWrite(motorR2, LOW);
      delay(300);
    }while(distF<10);//caliberate
  }    
  
  //diagonal left corner
  if(distF<10 && distL<10 && distR>10)
  {
    do{
      digitalWrite(motorL1, HIGH);
      digitalWrite(motorL2, LOW);
      digitalWrite(motorR1, LOW);
      digitalWrite(motorR2, LOW);
      delay(300);
    }while(distF<10);//caliberate
  
  }
  
  
  delay(300);//0.3 sec delay = frequency of readings refereshing
  
  
  
  
  
  
}



/////accept which sensor!!!


float distCalc(trig, echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);//time between two ulrasonic burst of pulses
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trig, LOW);
  
  float time,distance;
  time=pulseIn(echo, HIGH); //gives time in microsec
  distance=time/58;// 2d=vt where v=342.8 and t is got in microsec
  return distance;
}
