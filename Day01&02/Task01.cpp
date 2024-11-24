//differance between struct and class :

#include <iostream>
using namespace std;

struct ComplexStruct {
    int real;
    int img;

    void sum( ComplexStruct c1,  ComplexStruct c2) {
        real = c1.real + c2.real;
        img = c1.img + c2.img;
    }

    void substract( ComplexStruct c1,  ComplexStruct c2) {
        real = c1.real - c2.real;
        img = c1.img - c2.img;
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

class ComplexClass {
    int real;
    int img;

public:
    int getReal(){ return real; }
    int getImg(){ return img; }

    void setReal(int real_num) { real = real_num; }
    void setImg(int img_num) { img = img_num; }

    void sum(ComplexClass c1, ComplexClass c2) {
        real = c1.real + c2.real;
        img = c1.img + c2.img;
    }

    void substract(ComplexClass c1, ComplexClass c2) {
        real = c1.real - c2.real;
        img = c1.img - c2.img;
    }

    void Display() {
        if (img > 0)
            cout << real << " + " << img << "i" << endl;
        else if (img < 0)
            cout << real << " - " << -img << "i" << endl;
        else
            cout << real << endl;
    }
};

int main() {
    ComplexStruct c1, c2, resultStruct;
    c1.real=3;
    c1.img=3;
    c2.real=4;
    c2.img=5;
    resultStruct.sum(c1, c2);
    cout << "Struct Sum: ";
    resultStruct.Display();

    resultStruct.substract(c1, c2);
    cout << "Struct substract: ";
    resultStruct.Display();

    ComplexClass c3, c4, resultClass;
    c3.setReal(3);
    c3.setImg(3);
    c4.setReal(4);
    c4.setImg(5);
    resultClass.sum(c3, c4);
    cout << "Class Sum: ";
    resultClass.Display();

    resultClass.substract(c3, c4);
    cout << "Class substract: ";
    resultClass.Display();

    return 0;
}
