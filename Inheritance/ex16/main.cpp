#include <iostream>
using namespace std;

class Base {
public:
    static void display() {
        cout << "Base class static function." << endl;
    }
};

class Derived : public Base {
public:
    static void display() {
        cout << "Derived class static function." << endl;
    }
};

int main() {
    Base::display();     // Calls Base class function
    Derived::display();  // Calls Derived class function

    return 0;
}
