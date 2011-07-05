/*
 * Copyright 2010 by Jeremy Blum	 <jeremy@makerbot.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include "LightShow.hh"

//Arduino I2C Libraries
#include "Wire.hh"

#include <util/atomic.h>

TwoWire  MaxM; //I2C Interface

//Initiate the I2C Connection
void initI2C()
{
    MaxM.begin();
}

//A Simple Randomly Fading Lightshow
void runLightShowSlice()
{

    MaxM.beginTransmission(0x09);
    MaxM.send('o');
    MaxM.endTransmission();
    MaxM.beginTransmission(0x09);
    MaxM.send('n');
    MaxM.send(0xff);
    MaxM.send(0xff);
    MaxM.send(0xff);
    //MaxM.send('p');
    //MaxM.send(0x0B);    //Play Script 11
    //MaxM.send(0x00);    //Repeat Forever
    //MaxM.send(0x00);    //Start at beginning
    MaxM.endTransmission();
}
