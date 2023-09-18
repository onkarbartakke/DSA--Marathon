#include "dellDesktopBuilder.hpp"
#include<iostream>

using namespace std;

void DellDesktopBuilder::buildMonitor()
{
    deskstop->setMonitor("Dell Monitor");
}

void DellDesktopBuilder::buildKeyboard()
{
    deskstop->setKeyboard("Dell Keyboard");
}

void DellDesktopBuilder::buildMouse()
{
    deskstop->setMouse("Dell Mouse");
}

void DellDesktopBuilder::buildMotherboard()
{
    deskstop->setMotherBoard("Dell Motherboard");
}

void DellDesktopBuilder::buildProcessor()
{
    deskstop->setProcessor("Dell Processor");
}

void DellDesktopBuilder::buildRam()
{
    deskstop->setRam("Dell Ram");
}

void DellDesktopBuilder::buildSpeaker()
{
    deskstop->setSpeaker("Dell Speaker");
}