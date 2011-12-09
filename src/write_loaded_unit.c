#include "global.h"

void
write_loaded_unit(int absolute_x, int absolute_y, interface_struct *p_inter_data, field_struct *p_field_data)
{
  int x, y, l_x, l_y;
  int maxy = (*p_field_data).maxy;
  int maxx = (*p_field_data).maxx;
  int l_maxx = (*p_inter_data).lp_data.maxx;
  int l_maxy = (*p_inter_data).lp_data.maxy;
  if((*p_inter_data).lp_data.rotation == 0) {
    for (y = absolute_y, l_y = 0; y < maxy && l_y < l_maxy; y++, l_y++)
      for (x = absolute_x, l_x = 0; x < maxx && l_x < l_maxx; x++, l_x++)
	if((*p_inter_data).lp_data.loaded_pattern[l_y][l_x] == 1) {
	  if((*p_field_data).current_field[y][x] == 0)
	    lut_up(x, y, p_field_data);
	  (*p_field_data).current_field[y][x] = 1;
	  
	}
  } else if((*p_inter_data).lp_data.rotation == 1) {
    for(y = absolute_y, l_y = 0; y < maxy && l_y < (*p_inter_data).lp_data.maxx; ++y, ++l_y) {
      for(x = absolute_x, l_x = (*p_inter_data).lp_data.maxy -1;
	  x < maxx && l_x >= 0; ++x, --l_x) {
	if((*p_inter_data).lp_data.loaded_pattern[l_x][l_y] == 1) {
	  if((*p_field_data).current_field[y][x] == 0)
	    lut_up(x, y, p_field_data);
	  (*p_field_data).current_field[y][x] = 1;
	}
      }
    }
  } else if((*p_inter_data).lp_data.rotation == 2) {
    for(y = absolute_y, l_y = (*p_inter_data).lp_data.maxy - 1;
	y < maxy && l_y >= 0;
	++y, --l_y) {
      for(x = absolute_x, l_x = (*p_inter_data).lp_data.maxx -1;
	  x < maxx && l_x >= 0; ++x, --l_x) {
	if((*p_inter_data).lp_data.loaded_pattern[l_y][l_x] == 1) {
	  if((*p_field_data).current_field[y][x] == 0)
	    lut_up(x, y, p_field_data);
	  (*p_field_data).current_field[y][x] = 1;
	}
      }
    }
  } else if((*p_inter_data).lp_data.rotation == 3) {
    for(y = absolute_y, l_y = (*p_inter_data).lp_data.maxx - 1;
	y < maxy && l_y >= 0;
	++y, --l_y) {
      for(x = absolute_x, l_x = 0; x < maxx && l_x < (*p_inter_data).lp_data.maxy; ++x, ++l_x) {
	if((*p_inter_data).lp_data.loaded_pattern[l_x][l_y] == 1) {
	  if((*p_field_data).current_field[y][x] == 0)
	    lut_up(x, y, p_field_data);
	  (*p_field_data).current_field[y][x] = 1;
	}
      }
    }
  }

}
	
