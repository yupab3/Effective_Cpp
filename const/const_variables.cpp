#include <iostream>

using namespace std;

int main() {
    const int cv1 = 1;
    const int cv2 = 2;
    // const int b; -> 초기화 해야 사용 가능

    const int *p = &cv1;
    // *p = 2; 값에 대해 상수화 되었기 때문에 불가능
    // 이는 int const *p 또한 마찬가지이다.
    p = &cv2; // 가능, 포인터에 대해서는 상수화 되어있지 않다.
    
    
    // int * const cp = &a;
    // 가리키는 대상이 int가 아닌 const int이기 때문에 불가능

    int b = 2;
    int c = 4;
    int * const cp = &b;
    *cp = 3; // 가능
    // cp = &c; 포인터에 대해 상수화 되었기 때문에 불가능
    
    const int * const cvcp = &cv1;
    // 얘는 가리키는 주소, 주소의 값 모두 변경 불가능

    return 0;
}