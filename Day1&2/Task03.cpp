#include <iostream>
using namespace std;

class ComplexClass {
    int real;
    int img;

public:
    ComplexClass() {
        cout << "Default constructor" << endl;
        real = 0;
        img = 0;
    }

    ComplexClass(int x, int y = 0) {
        cout << "(int,int) constructor" << endl;
        real = x;
        img = y;
    }

    ~ComplexClass() {
        cout << "I'm Destructor" << endl;
    }

    int getReal()  { return real; }
    int getImg()  { return img; }

    void setReal(int real_num) { real = real_num; }
    void setImg(int img_num) { img = img_num; }

    void sum( ComplexClass c1,  ComplexClass c2) {
        real = c1.real + c2.real;
        img = c1.img + c2.img;
    }

    void Display() const {

        if (real != 0 && img > 0)
            cout << real << " + " << img << "i" << endl;
        else if (real!=0 && img < 0)
            cout << real << " - " << -img << "i" << endl;
        else if(real==0 && img!=0){
            cout<<img<<"i"<<endl;
        }
        else
            cout << real << endl;
    }
};

int main() {
    ComplexClass c2;
    ComplexClass c3(3);
    ComplexClass c4(6, 6);

    c2.sum(c3, c4);
    c2.Display();

    return 0;
}
