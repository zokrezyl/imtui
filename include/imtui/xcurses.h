#pragma once

#ifndef XCURSES_H
#define XCURSES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct XWindow XWindow;

// Initialize the library
int xcurses_init();

// End the library session
int xcurses_end();

// Create a new window
XWindow *xcurses_newwin(int nlines, int ncols, int begin_y, int begin_x);

// Delete a window
int xcurses_delwin(XWindow *win);

// Refresh the window
int xcurses_wrefresh(XWindow *win);

// Clear the window
int xcurses_wclear(XWindow *win);

// Print formatted string at a specific location
int xcurses_mvwprintw(XWindow *win, int y, int x, const char *fmt, ...);

// Get a character from the user
int xcurses_getch();

// Enable keypad input
int xcurses_keypad(XWindow *win, int bf);

// Enable or disable echo
int xcurses_echo();
int xcurses_noecho();

// Initialize color pairs
int xcurses_start_color();
int xcurses_init_pair(short pair, short f, short b);

// Set attributes
int xcurses_attron(int attrs);
int xcurses_attroff(int attrs);

// Set cursor visibility
int xcurses_curs_set(int visibility);

#ifdef __cplusplus
}
#endif

#endif // XCURSES_H
