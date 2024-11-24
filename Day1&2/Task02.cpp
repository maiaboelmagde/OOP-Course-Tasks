//Overloading sum & substraction

#include <iostream>

using namespace std;

class ComplexClass {
    int real;
    int img;

public:

    int getReal(){ return real; }
    int getImg(){ return img; }

    void setReal(int real_num) { real = real_num; }
    void setImg(int img_num) { img = img_num; }

    void sum(ComplexClass c1, ComplexClass c2) {
        cout<<"sum(ComplexClass,ComplexClass)"<<endl;
        real = c1.real + c2.real;
        img = c1.img + c2.img;
    }
    void sum(ComplexClass c1, int c2) {
        cout<<"sum(ComplexClass,int)"<<endl;
        real = c1.real + c2;
        img = c1.img;
    }
    void sum(int c1, ComplexClass c2) {
        cout<<"sum(int,ComplexClass)"<<endl;
        real = c1 + c2.real;
        img = c2.img;
    }
    void sum(ComplexClass c1, ComplexClass c2, ComplexClass c3) {
        cout<<"sum(ComplexClass,ComplexClass,ComplexClass)"<<endl;
        real = c1.real + c2.real + c3.real;
        img = c1.img + c2.img+ c3.img;
    }
    void substract(ComplexClass c1, ComplexClass c2) {
        cout<<"substract(ComplexClass,ComplexClass)"<<endl;
        real = c1.real - c2.real;
        img = c1.img - c2.img;
    }

     void substract(ComplexClass c1, int c2) {
        cout<<"substract(ComplexClass,int)"<<endl;
        real = c1.real - c2;
        img = c1.img;
    }
    void substract(int c1, ComplexClass c2) {
        cout<<"substract(int,ComplexClass)"<<endl;
        real = c1 - c2.real;
        img = c2.img;
    }
    void substract(ComplexClass c1, ComplexClass c2, ComplexClass c3) {
        cout<<"substract(ComplexClass,ComplexClass,ComplexClass)"<<endl;
        real = c1.real - c2.real - c3.real;
        img = c1.img - c2.img - c3.img;
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

int main()
{
    cout<<"//Overloading sum & substraction"<<endl;
     ComplexClass c1, c3, c4, resultClass;
     c1.setReal(0);
     c1.setImg(0);
    c3.setReal(3);
    c3.setImg(3);
    c4.setReal(4);
    c4.setImg(5);

    cout<<"sum(ComplexClass,ComplexClass)"<<endl;
    resultClass.sum(c3, c4);
    resultClass.Display();

    cout<<"sum(ComplexClass,int)"<<endl;
    resultClass.sum(c3, 4);
    resultClass.Display();

    cout<<"sum(int,ComplexClass)"<<endl;
    resultClass.sum(3, c4);
    resultClass.Display();

    cout<<"sum(ComplexClass,ComplexClass,ComplexClass)"<<endl;
    resultClass.sum(c3, c4,c1);
    resultClass.Display();


    resultClass.substract(c3, c4);
    cout << "Class substract: ";
    resultClass.Display();

    return 0;
}
