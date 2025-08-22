#include <iostream>

using namespace std;

int main() {
    string str1 = "hello";
    string &&str2 = std::move(str1);
    str2[0] = 'd';
    cout << "str1 : " << str1 << '\n';
    cout << "str2 : " << str2 << '\n';
    int a = 30;
    int &&b = std::move(a);
    ++b;
    cout << a << b << '\n';
    return 0;
}