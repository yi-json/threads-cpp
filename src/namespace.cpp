#include <iostream>
using std::cout;
using std::endl;
using std::string;

namespace namespace1 {
    int age = 25;
    string name = "json";
}

namespace namespace2 {
    int age = 26;
}

int main()
{
   cout << namespace2::age << endl;
   cout << namespace1::name << endl;
}