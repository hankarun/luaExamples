#pragma once
#include "window.h"

class TestWindow : public Window
{
    public:
    TestWindow();
    
    virtual void update() override;

    float* getClearColor() { return color;}
    private:
    float f;
    float color[4] = {0.45f, 0.55f, 0.60f, 1.00f};
    int counter = 0;
};