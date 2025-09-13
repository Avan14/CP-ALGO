#include <iostream>
using namespace std;


class A {
    public:
    void show() {
        cout << "Class A show function called" << endl;
    }
};


// inheritance example
class B  : public A {
public:
    void display() {
        cout << "Class B display function called" << endl;
    }
    // no need to redefine show() here, B inherits it from A
};

// composition example
class C {
private:
    A a; // C has an instance of A
public:
    void show() {
        a.show(); // C uses A's functionality
    }
    void display() {
        cout << "Class C display function called" << endl;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    B b;
    b.show();    // inherited from A
    b.display(); // defined in B
    C c;
    c.show();    // uses A's functionality
    c.display(); // defined in C

    return 0;
}