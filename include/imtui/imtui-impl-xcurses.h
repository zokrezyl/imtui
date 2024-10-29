/*! \file imtui-impl-ncurses.h
 *  \brief Enter description here.
 */

#pragma once

#include "imtui/xcurses.h"

namespace ImTui {
struct TScreen;
}

// the interface below allows the user to decide when the application is active
// or not this can be used to reduce the redraw rate, and thus the CPU usage,
// when suitable for example - there is no user input, or the displayed content
// hasn't changed significantly

// fps_active - specify the redraw rate when the application is active
// fps_idle - specify the redraw rate when the application is not active
ImTui::TScreen *ImTui_ImplXcurses_Init(bool mouseSupport,
                                       float fps_active = 60.0,
                                       float fps_idle = -1.0,
                                       XWindow *window = nullptr);

void ImTui_ImplXcurses_Shutdown();

// returns true if there is any user input from the keyboard/mouse
bool ImTui_ImplXcurses_NewFrame();

// active - specify which redraw rate to use: fps_active or fps_idle
void ImTui_ImplXcurses_DrawScreen(bool active = true);

bool ImTui_ImplXcurses_ProcessEvent();
