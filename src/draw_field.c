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
#include <curses.h>
#include "global.h"

void
draw_field(interface_struct *p_inter_data, field_struct *p_field_data)
{
  int x, y;
  int oy = (LINES - (*p_inter_data).maxy * 1) / 2;
  int ox = (COLS - (*p_inter_data).maxx * 2) / 2;
  char p;

  init_pair(1, COLOR_BLACK, COLOR_GREEN);
  init_pair(2, COLOR_WHITE, COLOR_RED);
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  init_pair(4, COLOR_WHITE, COLOR_BLUE);
  clear();

  attron(COLOR_PAIR(4));
  
  for(x = 0; x < (*p_inter_data).maxx; x++) {
    mvprintw(oy - 1, ox + x * 2 , "  ");
    mvprintw((*p_inter_data).maxy + oy, ox + x * 2, "  ");
  }

  mvprintw(oy - 1, ox, "Win x: %d Win y: %d",
	   (*p_inter_data).offset_x, (*p_inter_data).offset_y);
  
  attroff(COLOR_PAIR(4));
  for(y = 0; y < (*p_inter_data).maxy; ++y) {
      for(x = 0; x < (*p_inter_data).maxx; ++x) {
	if ((y + (*p_inter_data).offset_y) < (*p_field_data).maxx
	    && (x + (*p_inter_data).offset_x) < (*p_field_data).maxy) {
	  p = (*p_field_data).current_field[y + (*p_inter_data).offset_y][x + (*p_inter_data).offset_x];
	}
	if(x == (*p_inter_data).curs_x && y == (*p_inter_data).curs_y) {
	  p += 2;
	}  
	if(p) {
	  attron(COLOR_PAIR(p));
	  mvprintw(oy + y * 1,     ox + x * 2, "||");
	  attroff(COLOR_PAIR(p));
	}
      }
  }
  attron(COLOR_PAIR(4));
  mvprintw((*p_inter_data).maxy + oy, ox, "Generation: %d", (*p_field_data).generation);
  attroff(COLOR_PAIR(4));
}
