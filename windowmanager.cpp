#include "windowmanager.h"
#include "imgui/imgui.h"

void ImGuiUIManager::update()
{
    bool showDockSpace_ = true;
    showDockSpace(&showDockSpace_);

    for (auto i = 0; i < windows.size(); i++)
    {
        if (windows[i]->isVisible())
            windows[i]->update();
    }
}
 
void ImGuiUIManager::addWindow(Window* newWin)
{
    windows.push_back(newWin);
}

void ImGuiUIManager::drawViewMenu()
{
    for(auto& w : windows)
    {
        bool visible = w->isVisible();
        if (ImGui::Checkbox(w->getName(), &visible))
            w->setVisible(visible);
    }
        
}

void ImGuiUIManager::showDockSpace(bool* p_open)
{
    static bool opt_fullscreen_persistant = true;
    bool opt_fullscreen = opt_fullscreen_persistant;
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if (opt_fullscreen)
    {
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }

    // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background 
    // and handle the pass-thru hole, so we ask Begin() to not render a background.
    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;

    // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
    // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
    // all active windows docked into it will lose their parent and become undocked.
    // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
    // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("###DockSpace", p_open, window_flags);
    ImGui::Text("Toolbar area");
    ImGui::PopStyleVar();

    ImGui::BeginMainMenuBar();
    if (ImGui::BeginMenu("File"))
    {
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Edit"))
    {
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("View"))
    {
        drawViewMenu();
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Help"))
    {
        ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();

    if (opt_fullscreen)
        ImGui::PopStyleVar(2);

    // DockSpace
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }
    else
    {
        //ShowDockingDisabledMessage();
    }


    ImGui::End();
}