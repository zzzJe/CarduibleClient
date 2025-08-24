[![Arduino](https://img.shields.io/badge/Arduino-00979D.svg?logo=arduino&logoColor=white)](https://www.arduino.cc/)  

# Arduino Car for Carduible

## How to Change Pin

> In [`Pin.hpp`](Pin.hpp)

default values are:

| name | value |
| :- | :- |
| `RightMotorH` | 3 |
| `RightMotorL` | 5 |
| `LeftMotorH` | 9 |
| `LeftMotorL` | 6 |

To change, observe the current motor behavior and infer how to swap between these values.

## How to Change Speed

> In [`RegularControl.hpp`](RegularControl.hpp). Only affect regular mode.

Change the value of `DEFAULT_V`. Note that `DEFAULT_V` should be in the range of 0~255.

> In [`RacingControl.hpp`](RacingControl.hpp). Only affect racing mode.

Change the value of `MAX_SPEED`. Note that `MAX_SPEED` should be in the range of 0~255.

## How to Open/Close Debug Log

> In [`RegularControl.hpp`](RegularControl.hpp). Only affect regular mode.

Change the value of `REGULAR_LOG`. Note that `REGULAR_LOG` should be 0 or 1.

> In [`RacingControl.hpp`](RacingControl.hpp). Only affect racing mode.

Change the value of `RACING_LOG`. Note that `RACING_LOG` should be 0 or 1.
