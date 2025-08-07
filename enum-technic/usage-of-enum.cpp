#include <iostream>

class ArrClass {
public:
    void    setArr(int idx, int val);
    int     getArr(int idx);
private:
    enum { ArrSize = 3 };

    int arr[ArrSize];
};

void    ArrClass::setArr(int idx, int val) {
    if (idx >= ArrSize) return ;
    arr[idx] = val;
}

int    ArrClass::getArr(int idx) {
    if (idx >= ArrSize) return 0;
    return arr[idx];
}

int main() {
    ArrClass ac;
    ac.setArr(0, 2);
    ac.setArr(1, 4);
    std::cout << "arr[0] : " << ac.getArr(0) << ", arr[1] : " << ac.getArr(1) << ", arr[2] : " << ac.getArr(2) << '\n';
    return 0;
}