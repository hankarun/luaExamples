#include "window.h"
#include "imgui/imgui.h"

bool Window::begin()
{
    return ImGui::Begin(name.c_str(), &show);
}
void Window::end()
{
    ImGui::End();
}