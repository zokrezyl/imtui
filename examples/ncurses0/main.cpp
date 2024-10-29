#include "imtui/imtui.h"

#include "imtui/imtui-impl-xcurses.h"

#include "imtui-demo.h"

int main() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  auto screen = ImTui_ImplXcurses_Init(true);
  ImTui_ImplText_Init();

  bool demo = true;
  int nframes = 0;
  float fval = 1.23f;

  while (true) {
    ImTui_ImplXcurses_NewFrame();
    ImTui_ImplText_NewFrame();

    ImGui::NewFrame();

    ImGui::SetNextWindowPos(ImVec2(4, 27), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(50.0, 10.0), ImGuiCond_Once);
    ImGui::Begin("Hello, world!");
    ImGui::Text("NFrames = %d", nframes++);
    ImGui::Text("Mouse Pos : x = %g, y = %g", ImGui::GetIO().MousePos.x,
                ImGui::GetIO().MousePos.y);
    ImGui::Text("Time per frame %.3f ms/frame (%.1f FPS)",
                1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::Text("Float:");
    ImGui::SameLine();
    ImGui::SliderFloat("##float", &fval, 0.0f, 10.0f);

#ifndef __EMSCRIPTEN__
    ImGui::Text("%s", "");
    if (ImGui::Button("Exit program", {ImGui::GetContentRegionAvail().x, 2})) {
      break;
    }
#endif

    ImGui::End();

    ImTui::ShowDemoWindow(&demo);

    ImGui::Render();

    ImTui_ImplText_RenderDrawData(ImGui::GetDrawData(), screen);
    ImTui_ImplXcurses_DrawScreen();
  }

  ImTui_ImplText_Shutdown();
  ImTui_ImplXcurses_Shutdown();

  return 0;
}
