#include "xcurses.h"
#include <notcurses/notcurses.h>

static struct notcurses *nc = NULL;

int xcurses_init() {
  struct notcurses_options options = {0};
  nc = notcurses_init(&options, NULL);
  return nc ? OK : ERR;
}

int xcurses_end() {
  if (nc) {
    notcurses_stop(nc);
    nc = NULL;
  }
  return OK;
}

XWindow *xcurses_newwin(int nlines, int ncols, int begin_y, int begin_x) {
  struct ncplane_options nopts = {
      .y = begin_y,
      .x = begin_x,
      .rows = nlines,
      .cols = ncols,
  };
  return (XWindow *)ncplane_create(notcurses_stdplane(nc), &nopts);
}

int xcurses_delwin(XWindow *win) {
  return ncplane_destroy((struct ncplane *)win);
}

int xcurses_wrefresh(XWindow *win) { return notcurses_render(nc); }

int xcurses_wclear(XWindow *win) {
  return ncplane_erase((struct ncplane *)win);
}

int xcurses_mvwprintw(XWindow *win, int y, int x, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  ncplane_cursor_move_yx((struct ncplane *)win, y, x);
  int ret = ncplane_vprintf((struct ncplane *)win, fmt, args);
  va_end(args);
  return ret;
}

int xcurses_getch() {
  struct ncinput ni;
  return notcurses_get(nc, NULL, &ni);
}

int xcurses_keypad(XWindow *win, int bf) {
  // Notcurses handles input differently, so this might be a no-op
  return OK;
}

int xcurses_init_pair(short pair, short f, short b) {
  // Notcurses uses a different color model, map colors manually
  return OK;
}

int xcurses_attron(int attrs) {
  // Map ncurses attributes to notcurses styles
  return OK;
}

int xcurses_attroff(int attrs) {
  // Map ncurses attributes to notcurses styles
  return OK;
}

int xcurses_curs_set(int visibility) {
  // Map ncurses cursor visibility to notcurses
  return OK;
}
