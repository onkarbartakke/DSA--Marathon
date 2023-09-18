#ifndef DESKTOPBUILDER_HPP
#define DESKTOPBUILDER_HPP

#include "desktop.hpp"

class DesktopBuilder
{
    protected:
    Deskstop *deskstop;
    public:
    DesktopBuilder()
    {
        deskstop = new Deskstop();
    }
    
    virtual void buildMonitor() = 0;
    virtual void buildKeyboard() = 0;
    virtual void buildMouse() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildRam() = 0;
    virtual void buildSpeaker() = 0;
    virtual void buildMotherboard() = 0;
    virtual Deskstop* getDesktop()
    {
        return deskstop;
    }

};
#endif