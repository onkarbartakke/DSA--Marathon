#include "HpDesktopBuilder.hpp"
#include<iostream>

using namespace std;

void HpDesktopBuilder::buildMonitor()
{
    deskstop->setMonitor("Hp Monitor");
}

void HpDesktopBuilder::buildKeyboard()
{
    deskstop->setKeyboard("Hp Keyboard");
}

void HpDesktopBuilder::buildMouse()
{
    deskstop->setMouse("Hp Mouse");
}

void HpDesktopBuilder::buildMotherboard()
{
    deskstop->setMotherBoard("Hp Motherboard");
}

void HpDesktopBuilder::buildProcessor()
{
    deskstop->setProcessor("Hp Processor");
}

void HpDesktopBuilder::buildRam()
{
    deskstop->setRam("Hp Ram");
}

void HpDesktopBuilder::buildSpeaker()
{
    deskstop->setSpeaker("Hp Speaker");
}