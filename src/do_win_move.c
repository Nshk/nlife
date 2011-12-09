#include "global.h"

int
do_win_move(int m, interface_struct *p_inter_data, field_struct *p_field_data)
{
  int d[4][2] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};
  int n_win_x = (*p_inter_data).offset_x + d[m][0];
  int n_win_y = (*p_inter_data).offset_y + d[m][1];

  if(n_win_x < 0 || n_win_x >= (*p_field_data).maxx - (*p_inter_data).maxx || n_win_y < 0 || n_win_y >= (*p_field_data).maxy - (*p_inter_data).maxy)
    return 0;
  
  (*p_inter_data).offset_x = n_win_x;
  (*p_inter_data).offset_y = n_win_y;
  
  return 1;
}
