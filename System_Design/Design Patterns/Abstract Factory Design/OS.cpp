#include<iostream>

using namespace std;

class IButton
{
    public:
    virtual void press() = 0;
};

class MacButton : public IButton
{
    public:
    void press()
    {
        cout<<"Mac Button Pressed\n";
    }
};

class WinButton : public IButton
{
    public:
    void press()
    {
        cout<<"Win Button Pressed\n";
    }
};

class ITextBox
{
    public:
    virtual void showText() = 0;
};

class MacTextBox : public ITextBox
{
    public:
    void showText()
    {
        cout<<"Showing Mac TextBox\n";
    }
};

class WinTextBox : public ITextBox
{
    public:
    void showText()
    {
        cout<<"Showing Win TextBox\n";
    }
};

class IFactory
{
    public:
    virtual IButton* CreateButton() = 0;
    virtual ITextBox* CreateTextBox() = 0;
    
};

class MacFactory : public IFactory
{
    public:
    IButton* CreateButton()
    {
        return new MacButton();
    }

    ITextBox* CreateTextBox()
    {
        return new MacTextBox();
    }
};

class WinFactory : public IFactory
{
    public:
    IButton* CreateButton()
    {
        return new WinButton();
    }

    ITextBox* CreateTextBox()
    {
        return new  WinTextBox();
    }
};

class GUIAbstractFactory
{
    public:
    static IFactory* CreateFactory(string osType)
    {
        if(osType == "MAC")
            return new MacFactory();
        else if(osType == "WIN")
            return new WinFactory();
        else
            return new MacFactory();
    }
    
};


int main()
{
    cout<<"Enter your machine OS : ";
    string osType;
    cin>>osType;

    IFactory *fact = GUIAbstractFactory::CreateFactory(osType);

    IButton *button = fact->CreateButton();
    button->press();

    ITextBox* textBox = fact->CreateTextBox();
    textBox->showText();

}