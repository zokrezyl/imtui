#ifndef XCURSES_H
#define XCURSES_H

#define USE_NCURSES
#ifdef USE_NCURSES
#include <ncurses.h>
#define XWindow WINDOW
#else
typedef struct XWindow XWindow;
#include <notcurses/notcurses.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef USE_NCURSES
#define XCURSES_ERR ERR
#define XCURSES_KEY_MOUSE KEY_MOUSE
#define XCURSES_KEY_BACKSPACE KEY_BACKSPACE
#define XCURSES_KEY_DC KEY_DC
#define XCURSES_KEY_LEFT KEY_LEFT
#define XCURSES_KEY_RIGHT KEY_RIGHT
#define XCURSES_KEY_UP KEY_UP
#define XCURSES_KEY_DOWN KEY_DOWN
#define XCURSES_COLOR_PAIR COLOR_PAIR

#define xcurses_wrefresh wrefresh

// Clear the window
#define xcurses_wclear wclear

// Pr#define formatted string at a specific location
#define xcurses_mvwprintw mvwprintw

#define xcurses_addstr addstr

// Get a character from the user
#define xcurses_getch getch

#define xcurses_wgetch wgetch

// Enable keypad input
#define xcurses_keypad keypad

// Enable or disable echo
#define xcurses_echo echo
#define xcurses_noecho noecho

// Initialize color pairs
#define xcurses_init_pair init_pair

// Set attributes
#define xcurses_attron attron
#define xcurses_attroff attroff

// Set cursor visibility
#define xcurses_curs_set curs_set

// Additional constants and functions
#define xcurses_ungetch ungetch
#define xcurses_getmaxyx getmaxyx
#define xcurses_color_pair color_pair

#else

// Create a new window
// XWindow *xcurses_ newwin(int nlines, int ncols, int begin_y, int begin_x);

// Delete a window
// int xcurses_ delwin(XWindow *win);

// Refresh the window
int xcurses_wrefresh(XWindow *win);

// Clear the window
int xcurses_wclear(XWindow *win);

// Print formatted string at a specific location
int xcurses_mvwprintw(XWindow *win, int y, int x, const char *fmt, ...);

int xcurses_addstr(const char *str);

// Get a character from the user
int xcurses_getch();

int xcurses_wgetch(XWindow *win);

// Enable keypad input
int xcurses_keypad(XWindow *win, int bf);

// Enable or disable echo
int xcurses_echo();
int xcurses_noecho();

// Initialize color pairs
int xcurses_init_pair(short pair, short f, short b);

// Set attributes
int xcurses_attron(int attrs);
int xcurses_attroff(int attrs);

// Set cursor visibility
int xcurses_curs_set(int visibility);

// Additional constants and functions
int xcurses_ungetch(int ch);
int xcurses_getmaxyx(XWindow *win, int y, int x);
int xcurses_color_pair(int pair);

#endif // USE_NCURSES
//
XWindow *xcurses_stdscr();
// Initialize the library
// int xcurses_init();

// End the library session
int xcurses_end();

#ifdef __cplusplus
}
#endif
#endif // XCURSES_H
