#ifndef DESKTOP_HPP
#define DESKTOP_HPP


using namespace std;

#include<string>


class Deskstop
{
    string monitor;
    string keyboard;
    string mouse;
    string speaker;
    string ram;
    string processor;
    string motherBoard;

    public:
    void setMonitor(string pMonitor);
    void setKeyboard(string pKeyboard);
    void setMouse(string pMouse);
    void setSpeaker(string pSpeaker);
    void setRam(string pRam);
    void setProcessor(string pProcessor);
    void setMotherBoard(string pMotherBoard);
    void showSpecs();
};

#endif