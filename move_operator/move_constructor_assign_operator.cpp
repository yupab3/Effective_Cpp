#include <iostream>
#include <utility>

class Buffer {
    int* data;
    size_t size;
public:
    Buffer(size_t n) : data(new int[n]), size(n) {
        for (size_t i = 0; i < n; ++i) data[i] = i;
        std::cout << "Buffer constructed, size = " << size << "\n";
    }

    // 이동 생성자
    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;   // 원본은 해제 (소유권 이전)
        other.size = 0;
        std::cout << "Buffer moved!\n";
    }
    
    // 이동 할당 연산자
    Buffer& operator=(Buffer&& other) noexcept {
        std::cout << "Moved (assign)\n";
        if (this != &other) {
            delete[] data;            // 기존 리소스 해제
            data = other.data;        // 소유권 이전
            size = other.size;
            other.data = nullptr;     // 원본 초기화
            other.size = 0;
        }
        return *this;
    }

    ~Buffer() {
        delete[] data;
        if (size > 0)
            std::cout << "Buffer destroyed, size = " << size << "\n";
    }

    void print() const {
        if (!data) {
            std::cout << "(empty)\n";
            return;
        }
        for (size_t i = 0; i < size; ++i)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    Buffer buf1(5);           // 원본
    buf1.print();

    // rvalue 참조 변수 선언 & 초기화 (아직 buf1 유지)
    Buffer&& buf2 = std::move(buf1);
    // 이동 생성자 호출 (이때 buf1 해제됨)
    Buffer buf3 = std::move(buf1);

    std::cout << "buf1 after move: ";
    buf1.print();             // 원본은 해제되어 (empty)

    std::cout << "buf2 after move: ";
    buf2.print();             // 단순 rvalue 레퍼런스 (여전히 데이터 유지)
    
    std::cout << "buf3 after move: ";
    buf3.print();			  // 이동 생성자로 만들어진 객체 (데이터 유지)

    Buffer a(10);
    Buffer b(5);

    std::cout << "bf a : ";
    a.print();
    std::cout << "bf b : ";
    b.print();
    // 이동 할당 연산자 호출!
    b = std::move(a);

    std::cout << "af a : ";
    a.print();
    std::cout << "af b : ";
    b.print();

    return 0;
}