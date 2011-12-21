/*********************************************************************
Copyright (C) 2011 Davide Andrian <nasohk@sixbit.org>

This file is part of Nlife.
    Nlife is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Nlife is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Nlife.  If not, see <http://www.gnu.org/licenses/>.
**********************************************************************/
#include "global.h"

void
life_cycle(field_struct *p_field_data)
{
  int x, y;
  int maxx = (*p_field_data).maxx;
  int maxy = (*p_field_data).maxy;

  int lut_lines = 0;
  int lut_cols = 0;
  int line = 0;
  int col = 0;

  lut_lines = (*p_field_data).maxy / YBLOCKD + 1;
  lut_cols = (*p_field_data).maxx / XBLOCKD + 1;

  /*robaccia per evitare il bordo sup-sin XD*/
 
  for(line = 0; line < 1; line++) {
    for(col = 0; col < 1; col++) {
     if((*p_field_data).field_lut[0][0] > 0) {
	
	for(y = 1; y < YBLOCKD; ++y) {
	  for(x = 1; x < XBLOCKD; ++x) {
	    if((*p_field_data).current_field[y][x] % 10 != 0) {
	      
	      (*p_field_data).current_field[y - 1][x - 1] += 10;
	      
	      (*p_field_data).current_field[y][x - 1] += 10;
	      
	      (*p_field_data).current_field[y + 1][x - 1] += 10;
	      
	      (*p_field_data).current_field[y + 1][x] += 10;
	      
	      (*p_field_data).current_field[y + 1][x + 1] += 10;
	      
	      (*p_field_data).current_field[y][x + 1] += 10;
	      
	      (*p_field_data).current_field[y - 1][x + 1] += 10;
	      
	      (*p_field_data).current_field[y - 1][x] += 10;
	    }
	  }
	}
      }
    }
  }
  for(line = 0; line < 1; line++) {
    for(col = 1; col < lut_cols; col++) {
     if((*p_field_data).field_lut[line][col] > 0) {
	
	for(y = 1; y < YBLOCKD; ++y) {
	  for(x = col * XBLOCKD; x < col * XBLOCKD + XBLOCKD && x < maxx - 1; ++x) {
	    if((*p_field_data).current_field[y][x] % 10 != 0) {
	      
	      (*p_field_data).current_field[y - 1][x - 1] += 10;
	      
	      (*p_field_data).current_field[y][x - 1] += 10;
	      
	      (*p_field_data).current_field[y + 1][x - 1] += 10;
	      
	      (*p_field_data).current_field[y + 1][x] += 10;
	      
	      (*p_field_data).current_field[y + 1][x + 1] += 10;
	      
	      (*p_field_data).current_field[y][x + 1] += 10;
	      
	      (*p_field_data).current_field[y - 1][x + 1] += 10;
	      
	      (*p_field_data).current_field[y - 1][x] += 10;
	    }
	  }
	}
      }
    }
  }
for(line = 1; line < lut_lines; line++) {
  col = 0;
  if((*p_field_data).field_lut[line][col] > 0) {
    
    for(y = line * YBLOCKD; y < line * YBLOCKD + YBLOCKD && y < maxy - 1; ++y) {
      for(x = 1; x < XBLOCKD; ++x) {
	if((*p_field_data).current_field[y][x] % 10 != 0) {
	  
	  (*p_field_data).current_field[y - 1][x - 1] += 10;
	  
	  (*p_field_data).current_field[y][x - 1] += 10;
	  
	  (*p_field_data).current_field[y + 1][x - 1] += 10;
	  
	  (*p_field_data).current_field[y + 1][x] += 10;
	  
	  (*p_field_data).current_field[y + 1][x + 1] += 10;
	  
	  (*p_field_data).current_field[y][x + 1] += 10;
	  
	  (*p_field_data).current_field[y - 1][x + 1] += 10;
	      
	  (*p_field_data).current_field[y - 1][x] += 10;
	}
      }
    }
  }
 }
 

  for(line = 1; line < lut_lines; line++) {
    for(col = 1; col < lut_cols; col++) {
      if((*p_field_data).field_lut[line][col] > 0) {
	
	for(y = line * YBLOCKD; y < maxy -1 && y < (line * YBLOCKD + YBLOCKD); ++y) {
	  for(x = col * XBLOCKD; x < maxx -1 && x < (col * XBLOCKD + XBLOCKD); ++x) {
	    if((*p_field_data).current_field[y][x] % 10 != 0) {
	      
	      (*p_field_data).current_field[y - 1][x - 1] += 10;
	      
	      (*p_field_data).current_field[y][x - 1] += 10;
	      
	      (*p_field_data).current_field[y + 1][x - 1] += 10;
	      
	      (*p_field_data).current_field[y + 1][x] += 10;
	      
	      (*p_field_data).current_field[y + 1][x + 1] += 10;
	      
	      (*p_field_data).current_field[y][x + 1] += 10;
	      
	      (*p_field_data).current_field[y - 1][x + 1] += 10;
	      
	      (*p_field_data).current_field[y - 1][x] += 10;
	    }
	  }
	}
      }
    }
  }

  init_lut(p_field_data);

  for(y = 0; y < maxy; ++y) {
    for(x = 0; x < maxx; ++x) {
      
      if((*p_field_data).current_field[y][x] == 21 || 
	 (*p_field_data).current_field[y][x] == 31 ||
	 (*p_field_data).current_field[y][x] == 30) {
	(*p_field_data).current_field[y][x] = 1;
	lut_up(x, y, p_field_data);
      } else {
	(*p_field_data).current_field[y][x] = 0;
      }
      
    }
  }
      
}
