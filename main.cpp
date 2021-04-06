#include <iostream>

using namespace std;

class B {
    int b;
public:
    B(int b) : b(b) {}

    virtual ~B() {

    }

    void show_B() {
        cout << "Class B:" << endl;
        cout << "show_b()" << endl
             << "B::b = " << b << endl << endl;
    }
};

class B2 {
    int b2;
public:
    B2(int b2) : b2(b2) {}

    virtual ~B2() {

    }

    void show_B2() {
        cout << "Class B2:" << endl;
        cout << "show_b2()" << endl
             << "B2::b2 = " << b2 << endl << endl;
    }
};

class D1 : public B {
    int d1;
public:
    D1(int b, int d1) : B(b), d1(d1) {}

    virtual ~D1() {

    }

    void show_D1() {
        cout << "Class D1:" << endl;
        show_B();
        cout << "show_D1()" << endl
             << "D1::d1 = " << d1 << endl << endl;
    }

};

class D2 : private D1 {
    int d2;
public:
    D2(int b, int d1, int d2) : D1(b, d1), d2(d2) {}

    virtual ~D2() {

    }

    void show_D2() {
        cout << "Class D1:" << endl;
        show_D1();
        cout << "show_D2()" << endl
             << "D2::d2 = " << d2 << endl << endl;
    }
};

class D3 : public D2, private B2 {
    int d3;
public:
    D3(int b, int d1, int d2, int b2, int d3) : D2(b, d1, d2), B2(b2), d3(d3) {}

    virtual ~D3() {

    }

    void show_D3() {
        cout << "Class D3:" << endl;
        show_D2();
        show_B2();
        cout << "show_D3()" << endl
             << "D3::d3 = " << d3 << endl << endl;
    }
};

int main() {

    B o0(111);
    cout << "B o0(111);" << endl;
    cout << "sizeOf(B) = "<< sizeof(B) << endl;
    cout << endl << " class B hierarchy: "<< endl;
    o0.show_B();

    B2 o1(222);
    cout << "B o1(222);" << endl;
    cout << "sizeOf(B2) = "<< sizeof(B2) << endl;
    cout << endl << " class B2 hierarchy: "<< endl;
    o1.show_B2();

    D1 o2(111, 333);
    cout << "D1 o2(111, 333);" << endl;
    cout << "sizeOf(D1) = "<< sizeof(D1) << endl;
    cout << endl << " class D1 hierarchy: "<< endl;
    o2.show_D1();

    D2 o3(111, 333, 444);
    cout << "D2 o3(111, 333, 444);" << endl;
    cout << "sizeOf(D2) = "<< sizeof(D2) << endl;
    cout << endl << " class D2 hierarchy: "<< endl;
    o3.show_D2();

    D3 o4(111, 333, 444, 222, 555);
    cout << "D3 o4(111, 333, 444, 222, 555);" << endl;
    cout << "sizeOf(D3) = "<< sizeof(D3) << endl;
    cout << endl << " class D3 hierarchy: "<< endl;
    o4.show_D3();

}
