class object2 {
public:
    // object2(){ this->x = 2; };
    // int getX(){return x;};
    object2();
    int getX();
private:
    int x;
};

object2::object2(): x(2) {}
int object2::getX() { return x; }

object2&    getObj2() {
    static object2 ob2;
    return ob2;
}