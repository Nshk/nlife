#include <curses.h>
#include "global.h"
#include <string.h>
#include <stdlib.h>

int
load_unit_ffile(interface_struct *p_inter_data)
{
  int x, y;
  int oy = (LINES - (*p_inter_data).maxy * 1) / 2;
  int ox = (COLS - (*p_inter_data).maxx * 2) / 2;
  char filename[40];
  char line[100];
  char whait_t = 0;
  int max_lenght = 0;
  int lines = 0;
  int lenght = 0;
  int line_n = 0;
  int flag = 0;
  FILE *fp;

  curs_set(1);
  echo();
  init_pair(4, COLOR_WHITE, COLOR_BLUE);
  attron(COLOR_PAIR(4));
  mvprintw((*p_inter_data).maxy + oy, ox, "Load from file:         ");
  mvgetnstr((*p_inter_data).maxy + oy, ox + 16 , filename, 39);

  if(fp = fopen(filename, "r")) {
    while (fgets(line, 100, fp)) {
      lenght = (strlen(line)) - 1;
      if(lenght > max_lenght)
	max_lenght = lenght;
      lines++;
    }
    (*p_inter_data).lp_data.loaded_pattern = (char**) malloc(lines * sizeof(char*));

    for (x = 0; x < lines; x++) {
      (*p_inter_data).lp_data.loaded_pattern[x] = (char*) malloc(max_lenght * sizeof(char));
      if((*p_inter_data).lp_data.loaded_pattern[x] == NULL)
	exit (EXIT_FAILURE);
    }

    for (y = 0; y < lines; y++)
      for (x = 0; x < max_lenght; x++)
	(*p_inter_data).lp_data.loaded_pattern[y][x] = 0;

    rewind(fp);

    line_n = 0;
    while (fgets(line, 100, fp)) {
      lenght = strlen(line) - 1;
      for (x = 0; x < lenght; x++)
	if (line[x] == 'X')
	  (*p_inter_data).lp_data.loaded_pattern[line_n][x] = 1; 
      line_n++;
    }

    (*p_inter_data).lp_data.maxx = max_lenght;
    (*p_inter_data).lp_data.maxy = lines;

    whait_t = 0;
    flag = 1;
  } else {
  mvprintw((*p_inter_data).maxy + oy, ox, "File not found!                 ");
  whait_t = 1;
  }

  attroff(COLOR_PAIR(4));
  refresh();
  curs_set(0);
  sleep(whait_t);
  noecho();
  return flag;
}
