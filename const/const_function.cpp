#include <iostream>

using namespace std;

class testConst {
public:
    testConst(){};
    void func(){
        ++val;
        cout << "call non-const func\n";
    };
    void func() const {
        // ++val; 불가능!!
        val2 = 2;
        int *val3 = const_cast<int*>(&val);
        *val3 = 4;
        cout << "mutable int val2 : " << val2 << ", const_casted pointer val3 : " << *val3 << '\n';
        cout << "call const func\n";
    };
    void normalFunc() {
        cout << "only non-const classes can call me!!\n";
    }
private:
    int val;
    mutable int val2;
};

// void    printABD() const { << 일반 함수는 const 한정자 사용 불가!

// }

void    printABC() {
    cout << "ABC\n";
    return ;
}

int main() {
    // 일반 함수를 호출한 예시
    printABC();

    testConst tc;
    const testConst ctc;

    tc.func();
    ctc.func();
    tc.normalFunc();
    // ctc.normalFunc(); 호출 불가능!!
    return 0;
}