/*
 * SwTimer.cpp
 *
 *  Created on: 28.02.2018
 *      Author: AP02
 */

#include "SwTimer.h"

SwTimer::SwTimer(uint32_t time, boolean timer_enable = true) : m_time(time),
                                                          m_timerRunning(false),
                                                          m_timerEnabled(timer_enable),
                                                          m_timerExeeded(false)
{

}

SwTimer::~SwTimer()
{
   // TODO Auto-generated destructor stub
}



void SwTimer::start(void)
{
   if(m_timerRunning == false && m_timerEnabled == true)
   {
      m_currentTime = GET_TIME() + m_time;
      m_timerRunning = true;
   }
   return;
}


boolean SwTimer::isExeeded(void)
{
   if(m_timerRunning == true && m_timerEnabled == true)
   {
      if(GET_TIME() >= m_currentTime)
      {
         m_timerExeeded = true;
         m_timerRunning = false;
      }
   }
   return m_timerExeeded;
}


void SwTimer::enable(void)
{
   m_timerEnabled = true;
   m_timerExeeded = false;
   return;
}

void SwTimer::disable(void)
{
   m_timerEnabled = false;
   m_timerExeeded = false;
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
      m_time = time;
   }
   return;
}
