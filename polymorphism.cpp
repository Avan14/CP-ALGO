#include <iostream>
using namespace std;

// function overloading

class Mathops
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
    double add(double a, double b)
    {
        return a + b;
    }
};

// operator overloading

class Complex
{
public:
    int real, img;
    Complex(int r = 0, int i = 0) : real(r), img(i) {}

    Complex operator+(const Complex &c)
    {
        return Complex(this->real + c.real, this->img + c.img);
    }
};

// run time poly

class Base
{
public:
    void print()
    {
        cout << "base print \n";
    }
    virtual void display()
    {
        cout << "display function of the base class \n";
    }
};

class Derived : public Base
{
public:
    void print()
    {
        cout << "derives print \n";
    }
    void display() override
    {
        cout << "display function of the derives class \n";
    }
};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Complex c1(3, 4), c2(1, 2);
    // Complex c3 = c1 + c2; // uses overloaded +
    // cout << c3.real << " + " << c3.img << "i" << endl;
    
   Base * ptr ;
   Derived d;
   ptr = &d;

   ptr -> print();
   ptr -> display();

    return 0;
}