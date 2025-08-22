#include <iostream>

using namespace std;

// object2의 선언만 직접 적어줌 (헤더 대신)
class object2 {
public:
    object2();
    int getX();
private:
    int x;
};

// 함수 선언도 직접 extern처럼 적어줌
object2& getObj2();

class object1 {
public:
    object1(object2 ob2) { cout << "create object2 with " << ob2.getX() << '\n'; };
};

int main() {
    static object1 ob1(getObj2());
    return 0;
}