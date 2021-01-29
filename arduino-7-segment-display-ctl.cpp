/* arduino-7-segment-display-ctl.cpp
 *
 * Copyright 2021 Dominik Rzecki
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

 

#include "arduino-7-segment-display-ctl.h"

_7SegmentDisplay::_7SegmentDisplay(byte a, byte b, byte c, byte d, byte e, byte f, byte g, bool lowDriven){
	sd7_pins[0] = a;
	sd7_pins[1] = b;
	sd7_pins[2] = c;
	sd7_pins[3] = d;
	sd7_pins[4] = e;
	sd7_pins[5] = f;
	sd7_pins[6] = g;
	sd7_lowDriven = lowDriven;
	setPins();
}

_7SegmentDisplay::_7SegmentDisplay(byte pins[7]){
	for(int i = 0; i<7; i++){
		sd7_pins[i] = pins[i];
	}
	setPins();
}

void _7SegmentDisplay::TurnOff(){
	if(sd7_lowDriven){
		for(int i = 0; i<7; i++){
			digitalWrite(sd7_pins[i], HIGH);
		}
	} else {
		for(int i = 0; i<7; i++){
			digitalWrite(sd7_pins[i], LOW);
		}
	}
}

void _7SegmentDisplay::Display(int num){
	if(sd7_lowDriven){
		for(int i = 0; i<7; i++){
			digitalWrite(sd7_pins[i], !sd7_num[num][i]);
		}
	} else {
		for(int i = 0; i<7; i++){
			digitalWrite(sd7_pins[i], sd7_num[num][i]);
		}
	}
}

void _7SegmentDisplay::setPins(){
	for(int i = 0; i<7; i++){
		pinMode(sd7_pins[i], OUTPUT);
	}
}

_2x7SegmentDisplay::_2x7SegmentDisplay(byte a, byte b, byte c, byte d, byte e, byte f, byte g, bool lowDriven)
	:_7SegmentDisplay{a, b, c, d, e, f, g, lowDriven}
{}

void _2x7SegmentDisplay::Update(){
	if(m_num != -1){
		m_digit[0] = (m_num < 10)? 0 : m_num/10;
		m_digit[1] = m_num%10;
	}
  
	digitalWrite(13 - m_whichDigit, HIGH);
	digitalWrite(13 - !m_whichDigit, LOW);

	Display(m_digit[m_whichDigit]);

	m_whichDigit = !m_whichDigit;
}
