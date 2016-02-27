
#include <TimedAction.h>
#include <Arduino.h>
#include "DualMC33926MotorShield.h"
#include "Robomower.h"

void parseRxCommand(Cmd_t* rx_cmd, Hbt_t* rx_hbt, BladeCmd_t* rx_blade_cmd);
void serialEvent();
void stopIfFault();
void setBladeMotors();
void checkHB();
void sendHB();
void checkCurrent();

//TimedAction HBcheck = TimedAction(500,checkHB);
//TimedAction HBsend = TimedAction(500,sendHB);
//TimedAction CurrentCheck = TimedAction(250,checkCurrent);

void setup()
{
  Serial.begin(9600);
  delay(5);
  Serial.println("Dual MC33926 Motor Shield");
  
  md.init();  //Initialize motors
  
  //pinMode(BLADEMOWER1PIN, OUTPUT); 
  //pinMode(BLADEMOWER2PIN, OUTPUT);
  
  //digitalWrite(BLADEMOWER1PIN,LOW);
  //digitalWrite(BLADEMOWER2PIN,LOW);
  
  rxBladeCmd.cmd = 0;
  rxCmd.lspd = 200;
  rxCmd.rspd = 200;
  //spd = 0;
  bufSize = 0;
  bufSize = 0;
  bufPos = 0;
  
  HBcounter = 0;
}

void loop()
{
  boolean HB = false;
 
  //parseRxCommand(&rxCmd, &rxHbt, &rxBladeCmd);
  
  //HBcheck.check();   //Triggers every 500 ms
  
  //HBsend.check();  //Triggers every 500 ms
  
  //CurrentCheck.check();  //Triggers every 250 ms
  
  //setBladeMotors();
  
  md.setM1Speed(rxCmd.lspd);
  
  //stopIfFault();
    
  md.setM2Speed(rxCmd.rspd);
  //stopIfFault();
 

  delay(100);
 
}

void parseRxCommand(Cmd_t* cmdPtr, Hbt_t* hbtPtr, BladeCmd_t* bladePtr)
{ 
  int rspd,lspd = 0;
  unsigned char nextChar;
  unsigned char tempChar;
  int index;
  unsigned char cmdBuf[6];
  int cmdBufSize = 6;
  int i = 0;
  
  index = bufPos;
  
  if(index < bufSize)
  {
    nextChar = rxBuffer[index];  

    //Check for heartbeat message
    if(nextChar == 0xDE)
    {
        tempChar = rxBuffer[index+1];
        if(tempChar == 0xAD)
        {
          
          if(rxBuffer[index+2] == 0xA1)
          {
            memcpy(hbtPtr, (rxBuffer + index), sizeof(Hbt_t));
            index += sizeof(Hbt_t);
            //DEBUG
            /*
                  Serial.println(" ");
                  Serial.println(hbtPtr->header1, HEX);
                  Serial.println(hbtPtr->header2, HEX);
                  Serial.println(hbtPtr->hb, HEX);
                  Serial.println(hbtPtr->time);
                  Serial.println("End");
            */
            //DEBUG END 
          }
          
          //Check for Motor Command
          else if(((bufSize-index) >= sizeof(Cmd_t)) && (rxBuffer[index+2] == 0xFC))
          {
            memcpy(cmdPtr, (rxBuffer + index), sizeof(Cmd_t));
            index += sizeof(Cmd_t);
            //DEBUG    
            /*
                  Serial.println(cmdPtr->header1, HEX);
                  Serial.println(cmdPtr->header2, HEX);
                  Serial.println(cmdPtr->header3, HEX);
                  Serial.println(cmdPtr->rspd, HEX);
                  Serial.println(cmdPtr->lspd, HEX);
                  Serial.println("End");
            */
            //DEBUG END
          }
          else if(rxBuffer[index+2] == 0xBB)
          {
            memcpy(bladePtr, (rxBuffer + index), sizeof(BladeCmd_t));
            index += sizeof(BladeCmd_t);
            //DEBUG
            /*
                  Serial.println(" ");
                  Serial.println(bladePtr->header1, HEX);
                  Serial.println(bladePtr->header2, HEX);
                  Serial.println(bladePtr->header3, HEX);
                  Serial.println(bladePtr->cmd, HEX);
                  Serial.println("End");
            */
            //DEBUG END 
          }         
        }
     }      
     //Find the beginning of the next message
     else if(nextChar != 0xDE)
     {
        while((nextChar != 0xDE) && (index < bufSize))
        {
          index += 1;
          nextChar = rxBuffer[index];
        }    
      }
      bufPos = index;
  }
}

//This runs each time loop completes
//Purpose: Read the UART line and dump everything into a circular
//  buffer
void serialEvent() {
  while (Serial.available()) 
  {
    // get the new byte:
    unsigned char inChar = (unsigned char)Serial.read(); 
    // add it to the buffer:
    if(bufSize < maxBufSize)
    {
      *(rxBuffer+bufSize) = inChar;
      bufSize += sizeof(char);
    } 
    else
    {
      *(rxBuffer) = inChar;
      bufSize = sizeof(unsigned char);
      bufPos = 0;
    }


  }
  
    //DEBUG
    Serial.println(" ");
    for(int i=bufPos;i<bufSize;i=i+sizeof(char))
    {
      
      Serial.print((char)(*(rxBuffer+i))); 
      //Serial.println(sizeof(char));
    }
  
    //END DEBUG  
    Serial.println("End Buffer");
}

void checkHB()
{
   if((rxHbt.header1 == 0xDE) && (rxHbt.header2 == 0xAD) && (rxHbt.hb == 0xA1))
     {
       rxHbt.hb = 0;  //Reset heartbeat flag
       HBcounter = 0;  //Reset the counter
     }
   else
     {
       HBcounter += 1;
     }
}

void sendHB()
{
  if(HBcounter == 0)
  {
    Serial.write(0xDE);
    Serial.write(0xAD);
    Serial.write(0xA1);
  }
  else if(HBcounter > 2)
  {
    rxCmd.lspd = 0;
    rxCmd.rspd = 0;
  }  
    
}

void setBladeMotors()
{
    if(rxBladeCmd.cmd == 1)
  {
    digitalWrite(BLADEMOWER1PIN, HIGH);
    digitalWrite(BLADEMOWER2PIN, HIGH);
  }
  else
  {
    digitalWrite(BLADEMOWER1PIN,LOW);
    digitalWrite(BLADEMOWER2PIN,LOW);
  }
}

void checkCurrent()
{
  float M1current;
  float M2current;
  unsigned int M1curRead;
  unsigned int M2curRead;
  
  M1curRead = md.getM1CurrentMilliamps();
  M2curRead = md.getM2CurrentMilliamps();
  
  M1current = (float)M1curRead/525;
  M2current = (float)M2curRead/525;
  
  if((M1current > CURRENTLIMIT) || (M2current > CURRENTLIMIT))
  {
    rxCmd.lspd = 0;
    rxCmd.rspd = 0;
  }
  
  //Send current message
  Serial.write(0xDE);
  Serial.write(0xAD);
  Serial.write(0xC1);
  Serial.write(highByte(M1curRead));
  Serial.write(lowByte(M1curRead));
  Serial.write(highByte(M2curRead));
  Serial.write(lowByte(M2curRead));
}

void stopIfFault()
{
  if (md.getFault())
  {
    Serial.println("fault");
    while(1);
  }
}


