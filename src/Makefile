#Nlife Makefile
#Copyright (C) 2011 Davide Andrian <nasohk@sixbit.org>
#This file is part of Nlife.
#    Nlife is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Nlife is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Nlife.  If not, see <http://www.gnu.org/licenses/>.

SRCS = do_move.c do_win_move.c make_field.c draw_field.c  init_field.c life_cycle.c load_unit_ffile.c draw_loaded_unit.c unload_unit.c write_loaded_unit.c lut_up.c lut_down.c init_lut.c make_field_lut.c main.c
INC = global.h
PRGNAME = nlife
DBPRGNAME = debug
CFLAGS += -lcurses

$(PRGNAME): $(SRCS) $(INC)
	$(CC) -o $(PRGNAME) $(SRCS) $(CFLAGS)

$(DBPRGNAME): $(SRCS) $(INC)
	$(CC) -g -pg $(SRCS) $(INC) -o $(DBPRGNAME) $(CFLAGS)

.PHONY : all clean

clean : 
	rm $(PRGNAME) ; rm $(DBPRGNAME)

