#include "desktop.hpp"
#include<iostream>

using namespace std;

void Deskstop::setMonitor(string pMonitor)
{
    this->monitor = pMonitor;
}

void Deskstop::setKeyboard(string pKeyboard)
{
    this->keyboard = pKeyboard;
}

void Deskstop::setMotherBoard(string pMotherBoard)
{
    this->motherBoard = pMotherBoard;
}

void Deskstop::setMouse(string pMouse)
{
    this->mouse = pMouse;
}

void Deskstop::setProcessor(string pProcessor)
{
    this->processor = pProcessor;
}

void Deskstop::setRam(string pRam)
{
    this->ram = pRam;
}

void Deskstop::setSpeaker(string pSpeaker)
{
    this->speaker = pSpeaker;
}

void Deskstop::showSpecs()
{
    cout<<"--------------------------------------\n";
    cout<<"Monitor : "<<this->monitor<<"\n";
    cout<<"Keyboard : "<<this->keyboard<<"\n";
    cout<<"mouse : "<<this->mouse<<"\n";
    cout<<"Motherboard : "<<this->motherBoard<<"\n";
    cout<<"Processor : "<<this->processor<<"\n";
    cout<<"Ram : "<<this->ram<<"\n";
    cout<<"Speaker : "<<this->speaker<<"\n";
    cout<<"--------------------------------------\n";
}


