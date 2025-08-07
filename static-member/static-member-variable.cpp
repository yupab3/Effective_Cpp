#include <iostream>

class InitClass {
public:
    int getValue();
private:
    static const int value = 2;
};

int    InitClass::getValue() {
    return value;
}

class DeclareClass {
public:
    int getValue();
private:
    static const int num;
};

int    DeclareClass::getValue() {
    return num;
}

const int DeclareClass::num = 1;
const int InitClass::value;

int main() {
    InitClass nc;
    DeclareClass dc;
    std::cout << "InitClass value  : " << nc.getValue() << '\n';
    std::cout << "DeclareClass num : " << dc.getValue() << '\n';
    // std::cout << "InitClass value  : " << InitClass::value << '\n';
    // std::cout << "DeclareClass num : " << DeclareClass::num << '\n';
    return 0;
}