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
#define XBLOCKD 15
#define YBLOCKD 15
#define MAXX 1000
#define MAXY 1000

typedef struct {
  char **current_field;
  int **field_lut;
  int maxx;
  int maxy;
  int generation;
} field_struct;


typedef struct {
  int maxx;
  int maxy;
  char **loaded_pattern;
  int rotation;
  int flip;
} lp_struct;


typedef struct {
  int maxx;
  int maxy;
  int offset_x;
  int offset_y;
  int curs_x;
  int curs_y;
  lp_struct lp_data;
} interface_struct;

int
make_field(field_struct *p_field_data);

int
do_move(int m, interface_struct *p_inter_data);

void
do_win_move(int m, interface_struct *p_inter_data, field_struct *p_field_data);

void
draw_field(interface_struct *p_inter_data, field_struct *p_field_data);

int
draw_loaded_unit(interface_struct *p_inter_data);

void
init_field(field_struct *p_field_data);

void
life_cycle(field_struct *p_field_data);

int 
load_unit_ffile(interface_struct *p_inter_data);

void
unload_unit(interface_struct *p_inter_data);

void
write_loaded_unit(int absolute_x, int absolute_y, interface_struct *p_inter_data, field_struct *p_field_data);

void
make_field_lut(field_struct *p_field_data);

void
init_lut(field_struct *p_field_data);

void
lut_up(int x, int y, field_struct *p_field_data);

void
lut_down(int x, int y, field_struct *p_field_data);
