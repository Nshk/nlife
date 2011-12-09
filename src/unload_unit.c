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

void
unload_unit(interface_struct *p_inter_data)
{
  int x, y;
  for (y = 0; y < (*p_inter_data).lp_data.maxy; y++)
    free((*p_inter_data).lp_data.loaded_pattern[y]);

  free((*p_inter_data).lp_data.loaded_pattern);
  (*p_inter_data).lp_data.maxx = 0;
  (*p_inter_data).lp_data.maxy = 0;
}
