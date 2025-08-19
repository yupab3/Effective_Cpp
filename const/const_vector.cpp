#include <iostream>
#include <vector>

using namespace std;

// const vector의 활용 방안 중 하나, 출력만 하고 변경할 일이 없을 때 사용한다.
// 일반적인 const 변수와 활용법이 비슷하다.
void    printVector(const vector<int> &v) {
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << '\n';
}

int main() {
    vector<int> a;
    const vector<int> b;
    
    a.push_back(1);
    // b.push_back(1); vector 컨테이너에 대한 변경(값 추가) 불가!
    // b.erase(1); vector 컨테이너에 대한 변경(값 삭제) 불가!
    // 위 2개는 const로 인해 template 특수화가 불가능 하여 수행할 수 없는 케이스

    // 아래 1개는 const 메서드 자체가 없는 케이스
    // b.clear(); clear의 경우 아예

    // 이유는 다르지만 안된다는 사실은 같다. ㅋㅋ
    a.push_back(3);
    a.push_back(2);
    vector<int>::iterator it = a.begin();
    cout << "bf : ";
    printVector(a);
    ++it;
    *it = 2;
    ++it;
    *it = 3;
    cout << "af : ";
    printVector(a);
    vector<int>::const_iterator cit1 = a.begin();
    // *cit1 = 2; 불가능! 왜 그럴까?
    // const_iterator는 내부적으로 operator*가 rvalue를 반환하도록 되어있다. 자세한 내용은 아래 사진에!
    vector<int>::const_iterator cit2;
    cit2 = a.begin(); 
    // const처럼 동작하지만, 실제로 const 한정자가 변수에 붙은 것이 아니므로 나중에 초기화 가능!
    // cit2에 저장되는 이터레이터는 변경도 가능!! 값이 아니라 이터레이터만 변경이 가능한 것임에 주의

    vector<const int> cv;
    cv.push_back(1);
    cv.push_back(3);
    cv.push_back(2);
    vector<const int>::iterator ciit = cv.begin();
    // *ciit = 3; 내부적으로 템플릿이 const int로 추론되었기 때문에 값 변경이 불가능하다!
    cv.erase(ciit); // 하지만 삭제는 가능하다. 벡터 자체는 const가 아니기 때문!!
    return 0;
}