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
init_lut(field_struct *p_field_data)
{
  int lines = 0;
  int cols = 0;
  int k = 0;
  int j = 0;

  lines = (*p_field_data).maxy / YBLOCKD + 1;
  cols = (*p_field_data).maxx / XBLOCKD + 1;

  for(k = 0; k < lines; k++) {
    for(j = 0; j < cols; j++) {
      (*p_field_data).field_lut[k][j] = 0;
    }
  }
}
