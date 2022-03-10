/*
 * SwTimer.h
 *
 *  Created on: 28.02.2018
 *      Author: AP02
 */

#ifndef _SWTIMER_H_
#define _SWTIMER_H_
#include "Software/SoftwareConfig.h"

#if defined(SW_TIMER_ENABLE)

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class SwTimer
{
   public:
      SwTimer();
      SwTimer(boolean activationStatus);
      SwTimer(boolean activationStatus, uint32_t time);
      virtual ~SwTimer();
      void start(void);
      void setTime(uint32_t time);
      void restart(uint32_t time = 0);
      void enable(void);
      void disable(void);
      boolean isRunning(void) {return _timerRunning;}
      boolean isEnabled(void) {return _timerEnabled;}
      boolean isExeeded(void);


   private:
      uint32_t _time;
      uint32_t _currentTime;
      boolean _timerRunning;
      boolean _timerEnabled;
      boolean _timerExeeded;


};

#endif
#endif /*_SWTIMER_H_ */
