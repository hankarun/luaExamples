#pragma once
#include "window.h"
#include <vector>

class ImGuiUIManager {
    public:
        void update();
        void addWindow(Window* newWin);
    private:
        void showDockSpace(bool* p_open);
        void drawViewMenu();
    private:
        std::vector<Window*> windows;
};