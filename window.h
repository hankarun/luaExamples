#pragma once
#include <string>

class Window
{
public:
        Window(std::string name) : name(name) {}
        ~Window() = default;
        
        virtual void update() {}
        const char* getName() const { return name.c_str(); }
        bool isVisible() const { return show;}
        void setVisible(bool value) { show = value;}
protected:
    virtual bool begin();
    void end();

private:
    std::string name;
    bool show = false;
};