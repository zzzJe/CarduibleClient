#ifndef REGULAR_CONTROL_HPP
#define REGULAR_CONTROL_HPP

#include "Pin.hpp"

/// NOTE:
/// toggle logging functionality for regular mode
/// value should be 0 or 1
#define REGULAR_LOG 0
/// NOTE:
/// speed of regular mode
/// value should be 0 ~ 255
#define DEFAULT_V 250

extern int customV;

void forward(int v);
void backward(int v);
void turnleft(int v);
void turnright(int v);
void stay();

void handleRegularControl(char directive);

#endif
