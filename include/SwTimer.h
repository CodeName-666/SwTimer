/*
 * SwTimer.h
 *
 *  Created on: 28.02.2018
 *      Author: AP02
 */

#ifndef SWTIMER_H
#define SWTIMER_H

#if defined(ARDUINO)
#include "Arduino.h"

#define GET_TIME() millis()



#else
#include "stdint.h"

#define GET_TIME()      

#endif


class SwTimer
{
   public:
 
      SwTimer(uint32_t time, boolean timer_enable = true);
      virtual ~SwTimer();
      void start(void);
      void setTime(uint32_t time);
      void restart(uint32_t time = 0);
      void enable(void);
      void disable(void);
      boolean isRunning(void) {return m_timerRunning;}
      boolean isEnabled(void) {return m_timerEnabled;}
      boolean isExeeded(void);


   private:
      uint32_t m_time;
      uint32_t m_currentTime;
      boolean m_timerRunning;
      boolean m_timerEnabled;
      boolean m_timerExeeded;


};

#endif /*_SWTIMER_H_ */
