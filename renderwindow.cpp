#include "renderwindow.h"
#include "imgui/imgui.h"

RenderWindow::RenderWindow()
: Window("RenderWindow")
{

}

void RenderWindow::update()
{
    if (begin())
    {
        ImGui::Text("Render Area");
        end();
    }    
}