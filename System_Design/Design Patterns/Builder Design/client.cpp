#include<iostream>
#include "dellDesktopBuilder.hpp"
#include "hpDesktopBuilder.hpp"
#include "desktopDirector.hpp"

int main()
{
    DellDesktopBuilder* dellDesktopBuilder = new DellDesktopBuilder();
    HpDesktopBuilder* hpDesktopBuilder = new HpDesktopBuilder();

    DesktopDirector* director1 = new DesktopDirector(dellDesktopBuilder);
    DesktopDirector* director2 = new DesktopDirector(hpDesktopBuilder);

    Deskstop* deskstop1 = director1->buildDesktop();
    Deskstop* deskstop2 = director2->buildDesktop();


    deskstop1->showSpecs();
    deskstop2->showSpecs();

}