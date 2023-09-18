#ifndef DELLDESKSTOPBUILDER_HPP
#define DELLDESKSTOPBUILDER_HPP

#include "desktopBuilder.hpp"

class DellDesktopBuilder : public DesktopBuilder
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