#include <iostream>

using namespace std;

class Test {
public:
    Test(const string& str) : text(str){}
    const char& operator[](std::size_t position) const // 상수 버전 메서드
    {
        cout << "const\n";
        cout << "a";
        cout << "b";
        cout << "c";
        return text[position];
    }
    char& operator[](std::size_t position) // 비상수 버전 메서드
    {
        // cout << "non-const\n";
        // cout << "a";
        // cout << "b";
        // cout << "c";
        // return text[position];
        return const_cast<char&>(static_cast<const Test&>(*this)[position]);
    }
private:
    string text;
};

int main() {
    Test T1("T1");
    const Test T2("T2");

    cout << T1[1] << '\n';
    cout << T2[1] << '\n';
    return 0;
}