#ifndef HPDESKSTOPBUILDER_HPP
#define HPDESKSTOPBUILDER_HPP

#include "desktopBuilder.hpp"

class HpDesktopBuilder : public DesktopBuilder
{
    void buildMonitor();
    void buildKeyboard();
    void buildMouse();
    void buildProcessor();
    void buildRam();
    void buildSpeaker();
    void buildMotherboard();
};
#endif