#include "global.h"

void
do_win_move(int m, interface_struct *p_inter_data, field_struct *p_field_data)
{
  int d[4][2] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};
  int n_win_x = (*p_inter_data).offset_x + d[m][0];
  int n_win_y = (*p_inter_data).offset_y + d[m][1];
  
  /*Skip the first and last line and raw */
  if ((n_win_x >= 1 && n_win_x <= ((*p_field_data).maxx - 1) - (*p_inter_data).maxx)
      || (n_win_x >= 1 && n_win_x < (*p_inter_data).offset_x)) {
    (*p_inter_data).offset_x = n_win_x;
  }
  if ((n_win_y >= 1 && n_win_y <= ((*p_field_data).maxy - 1) - (*p_inter_data).maxy) 
      || (n_win_y >= 1 && n_win_y < (*p_inter_data).offset_y)){
    (*p_inter_data).offset_y = n_win_y;
  }
}
