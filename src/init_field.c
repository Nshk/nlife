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
init_field(field_struct *p_field_data)
{
  int maxx = (*p_field_data).maxx;
  int maxy = (*p_field_data).maxy;
  int x, y;
  for(y = 0; y < maxy; ++y)
    for(x = 0; x < maxx; ++x) {
      (*p_field_data).current_field[y][x] = 0;
#ifdef OLD
      (*p_field_data).old_field[y][x] = 0;
#endif
    }
}
