#ifndef DESKTOPDIRECTOR_HPP
#define DESKTOPDIRECTOR_HPP

#include "desktopBuilder.hpp"

class DesktopDirector
{
    private:
    DesktopBuilder* desktopBuilder;
    public:
    DesktopDirector(DesktopBuilder* pdesktopBuilder)
    {
        desktopBuilder = pdesktopBuilder;
    }

    Deskstop* getDesktop()
    {
        return desktopBuilder->getDesktop();
    }

    Deskstop* buildDesktop()
    {
        desktopBuilder->buildMonitor();
        desktopBuilder->buildKeyboard();
        desktopBuilder->buildMotherboard();
        desktopBuilder->buildMouse();
        desktopBuilder->buildProcessor();
        desktopBuilder->buildRam();
        desktopBuilder->buildSpeaker();

        return desktopBuilder->getDesktop();
    }
};

#endif