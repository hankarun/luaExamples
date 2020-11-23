#pragma once
#include "window.h"

class RenderWindow : public Window
{
    public:
    RenderWindow();
    virtual void update() override;
    private:
    int counter = 0;
};