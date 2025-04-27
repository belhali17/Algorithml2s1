#include <iostream>
using namespace std;
class MyClass {
public:
static int staticVar;
static void staticFunction() {
cout << "Static Variable: " << staticVar << endl;
}
};
// Definition of the static variable
int MyClass::staticVar = 42;
int main() {
MyClass::staticFunction();  // Call static function without creating an object
return 0;
}
