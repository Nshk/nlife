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
do_move(int m, interface_struct *p_inter_data)
{
  int d[4][2] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};
  int n_curs_x = (*p_inter_data).curs_x + d[m][0];
  int n_curs_y = (*p_inter_data).curs_y + d[m][1];
  int maxx =     (*p_inter_data).maxx;
  int maxy =     (*p_inter_data).maxy;

  if(n_curs_x < 0 || n_curs_x >= maxx || n_curs_y < 0 || n_curs_y >= maxy) {
    ;
  } else {
    (*p_inter_data).curs_x = n_curs_x;
    (*p_inter_data).curs_y = n_curs_y;
  }
}
