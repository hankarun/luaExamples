#include "demowindow.h"
#include "imgui/imgui.h"

DemoWindow::DemoWindow()
: Window("Demo Window")
{

}

void DemoWindow::update()
{
    ImGui::ShowDemoWindow(nullptr); 
}