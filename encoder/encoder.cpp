/* 
* encoder.h
*
* Created: 01.05.2019
* Author: Woocheck
*/

#include "/home/user/workspace_Wheeled_robot/Wheeled_robot_2/wiringPi/wiringPi/wiringPi.h"
#include "/home/user/workspace_Wheeled_robot/Wheeled_robot_2/wiringPi/wiringPi/softPwm.h"
#include "../pin_settings.h"

#include "./encoder.h"
#include "../dcMotor/DCmotor.h"

void Encoder::readDistance()
{
  int currentStatusPinA = digitalRead (pinA);
  if((previousStatusPinA == LOW) && currentStatusPinA==HIGH)
  {
    int statusPinB = digitalRead (pinB);
    if(statusPinB == LOW && rotationDirection == Direction::forward )
    {
      rotationDirection == Direction::backward;
    }
    else if(statusPinB == HIGH && rotationDirection == Direction::backward )
    {
      rotationDirection == Direction::forward;
    }
  }
  previousStatusPinA = currentStatusPinA;

  if(rotationDirection == Direction::forward)  
    numberOfPulses++;
  else  
    numberOfPulses--;

}

int Encoder::getNumeberOfPulses()
{
  return numberOfPulses;
};
