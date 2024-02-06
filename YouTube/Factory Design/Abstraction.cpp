#include <iostream>
using namespace std;

class Shape
{
public:
    // A pure virtual function makes the class abstract.
    virtual double area() = 0;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override
    {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape
{
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override
    {
        return side * side;
    }
};

int main()
{
    Circle circle(5);
    Square square(4);

    cout << "Circle Area: " << circle.area() << endl;
    cout << "Square Area: " << square.area() << endl;

    return 0;
}
