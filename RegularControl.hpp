#ifndef REGULAR_CONTROL_HPP
#define REGULAR_CONTROL_HPP

#include "Pin.hpp"

#define REGULAR_LOG 0

#define DEFAULT_V 250
extern int customV;

void forward(int v);
void backward(int v);
void turnleft(int v);
void turnright(int v);
void stay();

void handleRegularControl(char directive);

#endif
