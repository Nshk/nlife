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

int
draw_loaded_unit(interface_struct *p_inter_data)
{  
  int x, y;
  int lu_x = 0;
  int lu_y = 0;
  int oy = (LINES - (*p_inter_data).maxy * 1) / 2;
  int ox = (COLS - (*p_inter_data).maxx * 2) / 2;
  int curs_x = (*p_inter_data).curs_x;
  int curs_y = (*p_inter_data).curs_y;
  char p;

  init_pair(4, COLOR_WHITE, COLOR_BLUE);
  (*p_inter_data).lp_data.rotation =   (*p_inter_data).lp_data.rotation % 4;

  attron(COLOR_PAIR(4));

  if((*p_inter_data).lp_data.rotation == 0) {
    for(y = curs_y, lu_y = 0; y < (*p_inter_data).maxy && lu_y < (*p_inter_data).lp_data.maxy; ++y, ++lu_y) {
      for(x = curs_x, lu_x = 0; x < (*p_inter_data).maxx && lu_x < (*p_inter_data).lp_data.maxx; ++x, ++lu_x) {
	if((*p_inter_data).lp_data.loaded_pattern[lu_y][lu_x] == 1) {
	  mvprintw(oy + y * 1, ox + x * 2, "  ");
	}
      }
    }
  } else if((*p_inter_data).lp_data.rotation == 1) {
    for(y = curs_y, lu_y = 0; y < (*p_inter_data).maxy && lu_y < (*p_inter_data).lp_data.maxx; ++y, ++lu_y) {
      for(x = curs_x, lu_x = (*p_inter_data).lp_data.maxy -1;
	  x < (*p_inter_data).maxx && lu_x >= 0; ++x, --lu_x) {
	if((*p_inter_data).lp_data.loaded_pattern[lu_x][lu_y] == 1) {
	  mvprintw(oy + y * 1, ox + x * 2, "  ");
	}
      }
    }
  } else if((*p_inter_data).lp_data.rotation == 2) {
    for(y = curs_y, lu_y = (*p_inter_data).lp_data.maxy - 1;
	y < (*p_inter_data).maxy && lu_y >= 0;
	++y, --lu_y) {
      for(x = curs_x, lu_x = (*p_inter_data).lp_data.maxx -1;
	  x < (*p_inter_data).maxx && lu_x >= 0; ++x, --lu_x) {
	if((*p_inter_data).lp_data.loaded_pattern[lu_y][lu_x] == 1) {
	  mvprintw(oy + y * 1, ox + x * 2, "  ");
	}
      }
    }
  } else if((*p_inter_data).lp_data.rotation == 3) {
    for(y = curs_y, lu_y = (*p_inter_data).lp_data.maxx - 1;
	y < (*p_inter_data).maxy && lu_y >= 0;
	++y, --lu_y) {
      for(x = curs_x, lu_x = 0; x < (*p_inter_data).maxx && lu_x < (*p_inter_data).lp_data.maxy; ++x, ++lu_x) {
	if((*p_inter_data).lp_data.loaded_pattern[lu_x][lu_y] == 1) {
	  mvprintw(oy + y * 1, ox + x * 2, "  ");
	}
      }
    }
  }

  attroff(COLOR_PAIR(4));
  refresh();
  return 0;
}
