#include "imtui/xcurses.h"
#include <ncurses.h>
#include <stdlib.h>

void wlog(const char *format, ...) {
  return;
  // Switch back to the normal screen
  printf("\033[?1049l");

  // Print the message to stderr
  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);

  // Wait for a key press
  fprintf(stderr, "Press any key to continue...\n\r");
  getchar(); // Blocking wait for a key press

  // Switch back to the alternate screen
  printf("\033[?1049h");
}

int xcurses_init() {
  printf("\033[?1049h\033[H");
  wlog("xcurses_init() called\n");
  initscr();
  wlog("xcurses_init() initscr() called\n");
  use_default_colors();
  wlog("xcurses_init() use_default_colors() called\n");
  start_color();
  wlog("xcurses_init() start_color() called\n");
  cbreak();
  wlog("xcurses_init() cbreak() called\n");
  noecho();
  wlog("xcurses_init() noecho() called\n");
  curs_set(0);
  wlog("xcurses_init() curs_set(0) called\n");

  return OK;
}

XWindow *xcurses_stdscr() {
  if (stdscr == NULL) {
    wlog("xcurses_stdscr() stdscr is NULL, initializing ncurses\n");
    xcurses_init();
    return NULL;
  }
  if (stdscr == NULL) {
    wlog("xcurses_stdscr() failed to initialize, exiting\n");
    exit(1);
    return NULL;
  }

  nodelay(stdscr, TRUE);
  wlog("xcurses_stdscr() nodelay(stdscr, TRUE) called\n");
  wtimeout(stdscr, 0);
  wlog("xcurses_stdscr() wtimeout(stdscr, 0) called\n");
  set_escdelay(25);
  wlog("xcurses_stdscr() set_escdelay(25) called\n");
  keypad(stdscr, true);
  wlog("xcurses_stdscr() keypad(stdscr, true) called\n");

  wlog("xcurses_stdscr() returning stdscr\n");
  return (XWindow *)stdscr;
}

int xcurses_end() {
  int end = endwin();
  fprintf(stderr, "xcurses_end() called\n");
  return end;
}

/*
XWindow *xcurses_newwin(int nlines, int ncols, int begin_y, int begin_x) {
  return (XWindow *)newwin(nlines, ncols, begin_y, begin_x);
}

int xcurses_delwin(XWindow *win) { return delwin((WINDOW *)win); }

int xcurses_wrefresh(XWindow *win) { return wrefresh((WINDOW *)win); }

int xcurses_wclear(XWindow *win) { return wclear((WINDOW *)win); }

int xcurses_mvwprintw(XWindow *win, int y, int x, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int ret = mvwprintw((WINDOW *)win, y, x, fmt, args);
  va_end(args);
  return ret;
}

int xcurses_getch() { return getch(); }
int xcurses_ungetch(int ch) { return ungetch(ch); }
int xcurses_wgetch(XWindow *win) { return wgetch(win); }

int xcurses_keypad(XWindow *win, int bf) { return keypad((WINDOW *)win, bf); }

int xcurses_init_pair(short pair, short f, short b) {
  return init_pair(pair, f, b);
}

int xcurses_attron(int attrs) { return attron(attrs); }

int xcurses_attroff(int attrs) { return attroff(attrs); }

int xcurses_curs_set(int visibility) { return curs_set(visibility); }

int xcurses_getmaxyx(XWindow *win, int y, int x) {
  getmaxyx((WINDOW *)win, y, x);
  return OK;
}

int xcurses_addstr(const char *str) { return addstr(str); }

*/
