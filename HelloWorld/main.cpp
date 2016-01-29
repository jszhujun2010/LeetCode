#include <iostream>

using namespace std;

struct base {
    //virtual void print() { cout << "base!" << endl;}
    virtual void print() { cout << "base!" << endl;}
};

struct derived: base {
//    virtual void print() {cout << "derived!" << endl;}
    void print() {cout << "derived!" << endl;}
};

void doit(base &b) {
    b.print();
}

int main()
{
    base b = base();
    derived d = derived();
    base c = derived();
    doit(b);
    doit(d);
    doit(c);
//    cout << "Hello world!" << endl;
    return 0;
}
