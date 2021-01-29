/* count-0-9.ino
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

 

#include <arduino-7-segment-display-ctl.h>

void setup() {
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
}

void loop() {
  _2x7SegmentDisplay display{5, 2, 6, 8, 7, 3, 4, true};
  
  for(int i = 0; i<100; i++) {
  	display.Set(i);
  	for (int i = 0; i < 100; i++){
  		display.Update();
      delay(10);
  	}
  	if ( i == 99)
  		i = 0;
  }
}
