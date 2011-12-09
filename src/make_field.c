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
#include <stdlib.h>
#include "global.h"

int
make_field(field_struct *p_field_data)
{
  int maxx = (*p_field_data).maxx;
  int maxy = (*p_field_data).maxy;
  int k;
  (*p_field_data).current_field = (char**) malloc(maxy * sizeof(char*));
  if((*p_field_data).current_field == 0)
    exit(EXIT_FAILURE);

  for(k = 0; k < maxy; k++) {
    (*p_field_data).current_field[k] = (char*) malloc(maxx * sizeof(char));
    if((*p_field_data).current_field[k] == 0)
      exit(EXIT_FAILURE);
  }

 return 0;
}
