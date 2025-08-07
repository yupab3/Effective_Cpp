#include <iostream>

template<typename T, typename F>
inline void callWithMax(const T& a, const T& b, F f)
{
    f(a > b ? a : b);
}

void    f(int trgt) {
    std::cout << "func scope, trgt : " << trgt << '\n';
}

int main()
{
    int a = 5, b = 0;
    callWithMax(++a, b, f);
    callWithMax(++a, b + 10, f);
    std::cout << "main scope, a : " << a << '\n';
    return 0;
}