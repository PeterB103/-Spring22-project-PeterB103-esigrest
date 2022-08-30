/*
 * Project File: Time of Flight Sensor
 * Names: Peter and Eleanor
 * Date: 6/2/2022
 * 
 * Description: This file contains the implementation of the 
 * time of flight sensor library. This library reads the distance
 * using the I2C bus. It is an adaptation of Larry Bank's (a previous 
 * CS107E student) version of Polulu's Arduino Library at 
 * https://github.com/pololu/vl53l0x-arduino (see LICENSE.txt for more info)
 *
 */
#include "i2c.h"

#ifndef _TOFLIB_H_
#define _TOFLIB_H_

//
// Copyright (c) 2017 Larry Bank
// email: bitbank@pobox.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

//
// Read the model and revision of the
// tof sensor
//
int tofGetModel(int *model, int *revision);

//
// Read the current distance in mm
//
int tofReadDistance(void);

//
// Opens a file system handle to the I2C device
// sets the device continous capture mode
//
int tofInit(int iChan, int iAddr, int bLongRange);

#endif // _TOFLIB_H

