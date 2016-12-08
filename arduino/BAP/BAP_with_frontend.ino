/////////Ball and Plate///////////////////////////////
/*
BALL AND PLATE PID CONTROL
*/
//////////////////////////////////////////////////////
///Libraries///
#include <stdint.h>
#include <SPI.h>
#include <Wire.h>
#include<Servo.h>
#include "PID_v1.h"
#include "TouchScreen.h"
// Definitions TOUCH PINS
#define YP A0 //0
#define XM A1 //1
#define YM 3  //3
#define XP 4 //4
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
int buttonPushCounter = 1;   // counter for the number of button presses
int lastButtonState = 0;     // previous state of the button
int flag , flagZ ;

float xVal , yVal ;
int cCount=0;
int flagC=0;
int flagK=0;
float kk=0;
int fl=0;
double l =0.00;
unsigned int noTouchCount = 0; //viariable for noTouch
double  k=0;
// PID values
double SetpointX, InputX, OutputX; //for X
double SetpointY, InputY, OutputY; //for Y
//
int Modulo;
long lastcas=0;
// servos variables
Servo servoX; //X axis
Servo servoY; //Y axis

uint16_t homeX = 550;            // raw data value for center of touchscreen
uint16_t homeY = 550;            // raw data value for center of touchscreen             

float convertX = 151.0 / 955.0;  // converts raw x values to mm. found through manual calibration
float convertY = 91.0 / 927.0;   // converts raw y values to mm. found through manual calibration

unsigned long serialTime; //this will help us know when to talk with processing

/////TIME SAMPLE
int Ts =20;
unsigned long Stable=0; 
//PID const
float KpX = 0.45;                                                     
float KiX = 0.01;                                                      
float KdX = 0.1;

float KpY = 0.30;                                                       
float KiY = 0.02;                                                      
float KdY = 0.10;
long cas=0; 
//INIT PID
PID myPIDX(&InputX, &OutputX, &SetpointX, KpX, KiX, KdX, DIRECT);
PID myPIDY(&InputY, &OutputY, &SetpointY, KpY,KiY,KdY, DIRECT);

int arrX[5] = {90,90,90,90,90};
int arrY[5] = {90,90,90,90,90};
int counter = 0;

void setup()
{
  servoX.attach(9);
  servoY.attach(10);
  OutputX=90;
  OutputY=90;
  servoX.write(OutputX);
  servoY.write(OutputY);
  
  Serial.begin(9600);
  //INIT OF TOUSCHSCREEN
   TSPoint p = ts.getPoint();
  InputX=200;
  InputY=150;
  //INIT SETPOINT
  SetpointX=200;
  SetpointY=150;
  //// Make plate flat
  servoX.attach(9); 
  servoY.attach(10);
  servoX.write(OutputX);
  servoY.write(OutputY);
  
  //Zapnutie PID
  myPIDX.SetMode(AUTOMATIC);
  myPIDX.SetOutputLimits(30, 150);
  myPIDY.SetMode(AUTOMATIC);
  myPIDY.SetOutputLimits(30, 150);
  // TIME SAMPLE
  myPIDY.SetSampleTime(Ts); 
  myPIDX.SetSampleTime(Ts);  
  /////

  
 
  ///
 }
 
void loop()
{
  while(Stable<100) //REGULATION LOOP
  {
   TSPoint p = ts.getPoint();   //measure pressure on plate

      //setDesiredPosition();  
      noTouchCount = 0;  
      InputX  = map(p.x,115,960,0,400);
      InputY = map(p.y,150,910,0,300);

       //Serial.println(p.x);
      if(p.x == 0|| p.y>1000)
      {
        //Serial.println( "girdi");
        OutputX = 90;
        OutputY = 90;
      }else{
          myPIDX.Compute();  //action control X compute
          myPIDY.Compute(); //   action control  Y compute  

          Serial.print(InputX);   Serial.print(",");  Serial.print(InputY);  Serial.print("\n");
    
          OutputX = abs(180 - OutputX);
          delay(30);
      }
        if((InputX>SetpointX-4 && InputX<SetpointX+4 && InputY>SetpointY-3 && InputY<SetpointY+3))//if ball is close to setpoint
        {
           Stable=Stable+1; //increment STABLE
           //OutputX = 90;
           //OutputY = 90;
           //SetpointX +=100;
           //Serial.println(SetpointX);
                       
        }
          
/*         if(InputX == SetpointX && InputY == SetpointY  ) //if ball isnt close to setpoint
        {
          Stable=Stable+1; //increment STABLE
             OutputX = 90;
             OutputY = 90;
             //SetpointX +=100;
             //Serial.println(SetpointX);
        }
*/
      arrX[counter] = OutputX;
      arrY[counter] = OutputY;
      if(counter==4)
        counter=0;
      else
        counter++;

  servoX.write(averageX());//control
  servoY.write(averageY());//control 

  //send-receive with processing if it's time
  if(millis()>serialTime)
  {
    SerialReceiveY();
    SerialSendY();
    serialTime+=100;
  }
  
  //servoX.write(OutputX);//control
  //servoY.write(OutputY);//control 
  //Serial.print(Input1);   Serial.print(",");  Serial.print(Output1);  Serial.print("\n");
     
  }////END OF REGULATION LOOP///

  servoX.detach();//detach servos
  servoY.detach();
  
 ///KONTROLA STABILITY////
 while(Stable==100)//if is stable
 { //still measure actual postiion
    TSPoint p = ts.getPoint();
    InputX  = map(p.x,115,960,0,400);
    InputY = map(p.y,150,910,0,300);
    
    if(InputX<SetpointX-4 || InputX>SetpointX+4 || InputY>SetpointY+3 || InputY<SetpointY-3  ) //if ball isnt close to setpoint
    {
      servoX.attach(9); //again attach servos
      servoY.attach(10);
      Stable=0; //change STABLE state
    }
    
   
    
  }//end of STABLE LOOP
}//loop end

////////////////////////Functions////////////////// 
///// DESIRED POSITION

int averageX(){
  return (arrX[0] + arrX[1] + arrX[2] + arrX[3] +arrX[4]) / 5;
}

int averageY(){
  return (arrY[0] + arrY[1] + arrY[2] + arrY[3] +arrY[4]) / 5;
}

/********************************************
 * Serial Communication functions / helpers
 ********************************************/


union {                // This Data structure lets
  byte asBytes[24];    // us take the byte array
  float asFloat[6];    // sent from processing and
}                      // easily convert it to a
foo;                   // float array



// getting float values from processing into the arduino
// was no small task.  the way this program does it is
// as follows:
//  * a float takes up 4 bytes.  in processing, convert
//    the array of floats we want to send, into an array
//    of bytes.
//  * send the bytes to the arduino
//  * use a data structure known as a union to convert
//    the array of bytes back into an array of floats

//  the bytes coming from the arduino follow the following
//  format:
//  0: 0=Manual, 1=Auto, else = ? error ?
//  1: 0=Direct, 1=Reverse, else = ? error ?
//  2-5: float setpoint
//  6-9: float input
//  10-13: float output  
//  14-17: float P_Param
//  18-21: float I_Param
//  22-245: float D_Param
void SerialReceiveY()
{

  // read the bytes sent from Processing
  int index=0;
  byte Auto_Man = -1;
  byte Direct_Reverse = -1;
  while(Serial.available()&&index<26)
  {
    if(index==0) Auto_Man = Serial.read();
    else if(index==1) Direct_Reverse = Serial.read();
    else foo.asBytes[index-2] = Serial.read();
    index++;
  } 
  
  // if the information we got was in the correct format, 
  // read it into the system
  if(index==26  && (Auto_Man==0 || Auto_Man==1)&& (Direct_Reverse==0 || Direct_Reverse==1))
  {
    SetpointY=double(foo.asFloat[0]);
    //Input=double(foo.asFloat[1]);       // * the user has the ability to send the 
                                          //   value of "Input"  in most cases (as 
                                          //   in this one) this is not needed.
    if(Auto_Man==0)                       // * only change the output if we are in 
    {                                     //   manual mode.  otherwise we'll get an
      OutputY=double(foo.asFloat[2]);      //   output blip, then the controller will 
    }                                     //   overwrite.
    
    double p, i, d;                       // * read in and set the controller tunings
    p = double(foo.asFloat[3]);           //
    i = double(foo.asFloat[4]);           //
    d = double(foo.asFloat[5]);           //
    myPIDY.SetTunings(p, i, d);            //
    
    if(Auto_Man==0) myPIDY.SetMode(MANUAL);// * set the controller mode
    else myPIDY.SetMode(AUTOMATIC);             //
    
    if(Direct_Reverse==0) myPIDY.SetControllerDirection(DIRECT);// * set the controller Direction
    else myPIDY.SetControllerDirection(REVERSE);          //
  }
  Serial.flush();                         // * clear any random data from the serial buffer
}

// unlike our tiny microprocessor, the processing ap
// has no problem converting strings into floats, so
// we can just send strings.  much easier than getting
// floats from processing to here no?
void SerialSendY()
{
  Serial.print("PID ");
  Serial.print(SetpointY);   
  Serial.print(" ");
  Serial.print(InputY);   
  Serial.print(" ");
  Serial.print(OutputY);   
  Serial.print(" ");
  Serial.print(myPIDY.GetKp());   
  Serial.print(" ");
  Serial.print(myPIDY.GetKi());   
  Serial.print(" ");
  Serial.print(myPIDY.GetKd());   
  Serial.print(" ");
  if(myPIDY.GetMode()==AUTOMATIC) Serial.print("Automatic");
  else Serial.print("Manual");  
  Serial.print(" ");
  if(myPIDY.GetDirection()==DIRECT) Serial.println("Direct");
  else Serial.println("Reverse");
}

