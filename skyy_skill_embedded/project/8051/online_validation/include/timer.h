#ifndef _timer_h_
#define _timer_h_

extern volatile unsigned int counter;

void config_25msec(void);

void overflow_check(void);

#endif