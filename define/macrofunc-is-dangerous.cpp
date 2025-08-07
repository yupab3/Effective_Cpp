#include <iostream>

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

void    f(int trgt) {
    std::cout << "in function scope, trgt : " << trgt << '\n';
}

int main() {
    int a = 5, b = 0;

    CALL_WITH_MAX(++a, b);
    CALL_WITH_MAX(++a, b + 10);
    std::cout << "in main scope, a : " << a << '\n';
    return 0;
}