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
#include <time.h>
#include <curses.h>
#include "global.h"

int
main(int argc, char *argv[])
{
  field_struct field_data;
  interface_struct inter_data;
  field_struct *p_field_data;
  interface_struct *p_inter_data;
  int end_input = 0;
  int fbreak = 1;
  int absolute_x = 0;
  int absolute_y = 0;
  int quit = 0;
  int c;
  int x_dimension;
  int y_dimension;
  int unit_loaded = 0;

  void set_win(interface_struct *p_inter_data, int x_dim, int y_dim);

  field_data.generation = 0;

  if(argc == 3) {
    x_dimension = atoi(argv[1]) + 1;
    y_dimension = atoi(argv[2]) + 1;
    if(x_dimension < XBLOCKD || x_dimension > MAXX || 
       y_dimension < YBLOCKD || y_dimension > MAXY) {
      fprintf(stderr, "\nDimensions not permitted. min x: %d, max x: %d, min y: %d, max y: %d\n", XBLOCKD, MAXX, YBLOCKD, MAXY);
      exit(EXIT_FAILURE);
    }
  } else {
      fprintf(stderr, "\n Al least 2 argument neaded. ex: nlife XDIM YDIM\n");
      exit(EXIT_FAILURE);
  }

  initscr();

  p_field_data = &field_data;
  p_inter_data = &inter_data;

  set_win(p_inter_data, x_dimension, y_dimension);
  field_data.maxx = x_dimension;
  field_data.maxy = y_dimension;
  
  inter_data.offset_x = ((x_dimension - 1) - inter_data.maxx) / 2;
  inter_data.offset_y = ((y_dimension - 1) - inter_data.maxy) / 2;

  start_color();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  cbreak();
  make_field(p_field_data);
  init_field(p_field_data);
  make_field_lut(p_field_data);
  init_lut(p_field_data);

  draw_field(p_inter_data, p_field_data);
  refresh();

  while(!quit) {
    c = getch();
    int res = -1;
    switch(c) {
    case KEY_UP:    res = do_move(1, p_inter_data); break;
    case KEY_DOWN:  res = do_move(0, p_inter_data); break;
    case KEY_LEFT:  res = do_move(3, p_inter_data); break;
    case KEY_RIGHT: res = do_move(2, p_inter_data); break;
    case 'w':       res = do_win_move(1, p_inter_data, p_field_data);
      break;
    case 's':       res = do_win_move(0, p_inter_data, p_field_data);
      break;
    case 'a':       res = do_win_move(3, p_inter_data, p_field_data);
      break;
    case 'd':       res = do_win_move(2, p_inter_data, p_field_data);
      break;
    case ' ':
      absolute_x = inter_data.curs_x + inter_data.offset_x;
      absolute_y = inter_data.curs_y + inter_data.offset_y;
      if(unit_loaded) {
	write_loaded_unit(absolute_x, absolute_y, p_inter_data, p_field_data);
	unload_unit(p_inter_data);
	unit_loaded = 0;
      } else if(field_data.current_field[absolute_y][absolute_x] < 1) {
	field_data.current_field[absolute_y][absolute_x] = 1;
	lut_up(absolute_x, absolute_y, p_field_data);
      } else {
	field_data.current_field[absolute_y][absolute_x] = 0;
	lut_down(absolute_x, absolute_y, p_field_data);
      }
      break;
    case 'l': 
      if(unit_loaded) {
	unload_unit(p_inter_data);
	unit_loaded = 1;
      }
      unit_loaded = load_unit_ffile(p_inter_data);
      (*p_inter_data).lp_data.rotation = 0;
      break;
    case 'R': if(unit_loaded)
	(*p_inter_data).lp_data.rotation++; break;
    case 'C': init_field(p_field_data); break;
    case 'r': life_cycle(p_field_data); field_data.generation++; break;
    case 'p': 
      if (fbreak) {
	nodelay(stdscr, TRUE);
	fbreak = 0;
      } else {
	nodelay(stdscr, FALSE);
	fbreak = 1;
      } break;
    case 'Q': quit = 1; break;
    case KEY_RESIZE: 
      set_win(p_inter_data, x_dimension, y_dimension);
      break;
    default: life_cycle(p_field_data); field_data.generation++; break;
    }    
    draw_field(p_inter_data, p_field_data);

    if (unit_loaded)
      draw_loaded_unit(p_inter_data);

    flushinp;
    refresh();
  }

  endwin();
  free(field_data.current_field);
  return 0;
}

void set_win(interface_struct *p_inter_data, int x_dim, int y_dim)
{
  if(x_dim <= COLS / 2 - 1) {
    (*p_inter_data).maxx = x_dim - 1;
  } else {
    (*p_inter_data).maxx = COLS / 2 - 1;
  }
  if(y_dim <= LINES - 2) {
    (*p_inter_data).maxy = y_dim - 2;
  } else {
    (*p_inter_data).maxy = LINES - 2;
  }
  (*p_inter_data).curs_x = (*p_inter_data).maxx / 2;
  (*p_inter_data).curs_y = (*p_inter_data).maxy / 2;
}
