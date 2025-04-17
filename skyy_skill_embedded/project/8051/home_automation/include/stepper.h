#ifndef _stepper_h_
#define _stepper_h_
#include<delay.h>
#include<reg51.h>

#define STEPPER_PORT P0



void stepper_forward();

void stepper_backward();

void reset_stepper_count();

#endif