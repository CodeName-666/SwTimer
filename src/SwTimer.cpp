/*
 * SwTimer.cpp
 *
 *  Created on: 28.02.2018
 *      Author: AP02
 */

#include "SwTimer.h"

SwTimer::SwTimer() : _time(0),
                     _timerRunning(false),
                     _timerEnabled(false),
                     _timerExeeded(false)
{

}

SwTimer::SwTimer(boolean activationStatus) : _time(0),
                                              _timerRunning(false),
                                              _timerEnabled(activationStatus),
                                              _timerExeeded(false)
{

}


SwTimer::SwTimer(boolean activationStatus, uint32_t time) : _time(time),
                                                          _timerRunning(false),
                                                          _timerEnabled(activationStatus),
                                                          _timerExeeded(false)
{

}

SwTimer::~SwTimer()
{
   // TODO Auto-generated destructor stub
}



void SwTimer::start(void)
{
   if(_timerRunning == false && _timerEnabled == true)
   {
      _currentTime = millis() + _time;
      _timerRunning = true;
   }
   return;
}


boolean SwTimer::isExeeded(void)
{
   if(_timerRunning == true && _timerEnabled == true)
   {
      if(millis() >= _currentTime)
      {
         _timerExeeded = true;
         _timerRunning = false;
      }
   }
   return _timerExeeded;
}


void SwTimer::enable(void)
{
   _timerEnabled = true;
   _timerExeeded = false;
   return;
}

void SwTimer::disable(void)
{
   _timerEnabled = false;
   _timerExeeded = false;
   return;
}

void SwTimer::restart(uint32_t time)
{
   this->setTime(time);
   this->enable();
   this->start();
}

void SwTimer::setTime(uint32_t time)
{
   if(time > 0)
   {
      _time = time;
   }
   return;
}
