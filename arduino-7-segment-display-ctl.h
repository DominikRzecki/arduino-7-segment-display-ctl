/* arduino-7-segment-display-ctl.h
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

#ifndef _7_SEGMENT_DISPLAY
#define _7_SEGMENT_DISPLAY

#include <Arduino.h>

class _7SegmentDisplay{
  public:
    _7SegmentDisplay(byte a, byte b, byte c, byte d, byte e, byte f, byte g, bool lowDriven = false);

    _7SegmentDisplay(byte pins[7]);

    void TurnOff();
    void Display(int num);
    
  protected:
  
    void setPins();
    
    byte sd7_pins[7];
    bool sd7_lowDriven;
    const bool sd7_num[10][7]{
      {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},  //0
      {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},      //1
      {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},   //2
      {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},   //3
      {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},    //4
      {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},   //5
      {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},  //6
      {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},     //7
      {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}, //8
      {HIGH, HIGH, HIGH, HIGH, LOW , HIGH, HIGH}   //9
    };
};

class _2x7SegmentDisplay : private _7SegmentDisplay {
  public:
    _2x7SegmentDisplay(byte a, byte b, byte c, byte d, byte e, byte f, byte g, bool lowDriven = false);

    inline void Set(int num){
      m_num = num;
    }

    void Update();
    
  private:
    bool m_whichDigit = 0;
    int m_num;
    short int m_digit[2];
};

#endif //_7_SEGMENT_DISPLAY
