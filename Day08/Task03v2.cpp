// handling << in file

#include <iostream>
#include <fstream>
using namespace std;

class ComplexClass{
    float real;
    float img;

public:
    ComplexClass();
    ComplexClass(float, float);

    ~ComplexClass();

    float getReal()  { return real; }
    float getImg()  { return img; }

    void setReal(float real_num) { real = real_num; }
    void setImg(float img_num) { img = img_num; }

    void sum( ComplexClass, ComplexClass);


    ComplexClass operator +(ComplexClass);
    ComplexClass operator -(ComplexClass);
    ComplexClass operator *(ComplexClass);
    ComplexClass operator /(ComplexClass);

    ComplexClass operator ++();
    ComplexClass operator ++(int);
    ComplexClass operator --();
    ComplexClass operator --(int);


    bool operator<(ComplexClass);
    bool operator>(ComplexClass);
    bool operator==(ComplexClass);
    bool operator<=(ComplexClass);
    bool operator>=(ComplexClass);
    bool operator!=(ComplexClass);

    ComplexClass operator = (ComplexClass);

    ComplexClass operator += (ComplexClass);
    ComplexClass operator -= (ComplexClass);
    ComplexClass operator *= (ComplexClass);
    ComplexClass operator /= (ComplexClass);

    ComplexClass operator += (float);
    ComplexClass operator -= (float);
    ComplexClass operator *= (float);
    ComplexClass operator /= (float);


    operator float();
    operator int();

    void Display();

    friend ostream& operator <<(ostream&,ComplexClass& c);
    friend istream& operator >>(istream&, ComplexClass& c);
};

int main() {
    ComplexClass c1, c2;

     cout << "Enter real and imaginary parts of c1: ";
    cin >> c1; // Use overloaded >> operator
    cout << "Enter real and imaginary parts of c2: ";
    cin >> c2;


    ofstream outFile("complex_numbers.txt"); // Open a file in write mode
    if (outFile.is_open()) {
        outFile << c1 << endl; // Use overloaded << operator
        outFile << c2 << endl;
        outFile.close(); // Close the file
    } else {
        cout << "Error opening file for writing." << endl;
    }


    return 0;
}

ComplexClass::ComplexClass() {
    real = 0;
    img = 0;
}

ComplexClass::ComplexClass(float x, float y = 0) {
    real = x;
    img = y;
}

ComplexClass::~ComplexClass() {

}

void ComplexClass::sum( ComplexClass c1,  ComplexClass c2) {
    real = c1.real + c2.real;
    img = c1.img + c2.img;
}


void ComplexClass::Display() {
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

ComplexClass ComplexClass::operator +(ComplexClass c){
    ComplexClass res;
    res.real = real+c.real;
    res.img = img + c.img;
    return res;
}

ComplexClass ComplexClass::operator -(ComplexClass c){
    ComplexClass res;
    res.real = real - c.real;
    res.img = img - c.img;
    return res;
}

ComplexClass ComplexClass::operator *(ComplexClass c){
    ComplexClass res;
    res.real = real*c.real;
    res.img = img * c.img;
    return res;
}

ComplexClass ComplexClass::operator /(ComplexClass c){
    if(c.real == 0 || c.img == 0){
        cout<<"ERROR: we can't divide on 0"<<endl;
        return ComplexClass(0,0);
    }
    ComplexClass res;
    res.real = real/c.real;
    res.img = img / c.img;
    return res;
}


ComplexClass ComplexClass::operator ++(){
    real++;
    return *this;
}

ComplexClass ComplexClass::operator ++(int){
    ComplexClass temp = *this;
    real++;
    return temp;
}

ComplexClass ComplexClass::operator --(){
    real--;
    return *this;
}

ComplexClass ComplexClass::operator --(int){
    ComplexClass temp = *this;
    real--;
    return temp;
}


bool ComplexClass::operator<(ComplexClass c){
    bool flag = 0;
    if(real < c.real  || (real == c.real && img < c.img)) flag = 1;

    return flag;
}
bool ComplexClass::operator>(ComplexClass c){
    bool flag = 0;
    if(real > c.real  || (real == c.real && img > c.img)) flag = 1;

    return flag;
}
bool ComplexClass::operator ==(ComplexClass c){
    return((real == c.real) && (img == c.img)) ;
}
bool ComplexClass::operator<=(ComplexClass c){
    bool flag = 0;
    if(real < c.real  || (real == c.real && img <= c.img)) flag = 1;

    return flag;
}
bool ComplexClass::operator>=(ComplexClass c){
    bool flag = 0;
    if(real > c.real  || (real == c.real && img >= c.img)) flag = 1;

    return flag;
}
bool ComplexClass::operator!=(ComplexClass c){
    return (real != c.real || img != c.img);
}




ComplexClass ComplexClass::operator = (ComplexClass c){
    real= c.real;
    img=c.img;
    return *this;
}

ComplexClass ComplexClass::operator += (ComplexClass c){
    real+=c.real;
    img+=c.img;
    return *this;
}
ComplexClass ComplexClass::operator -= (ComplexClass c){
    real-=c.real;
    img-=c.img;
    return *this;
}
ComplexClass ComplexClass::operator *= (ComplexClass c){
    real*=c.real;
    img*=c.img;
    return *this;
}
ComplexClass ComplexClass::operator /= (ComplexClass c){
    if(c.real == 0 || c.img == 0){
        cout<<"ERROR: we can't divide on 0"<<endl;
        return ComplexClass(0,0);
    }
    real+=c.real;
    img+=c.img;
    return *this;
}



ComplexClass ComplexClass::operator += (float num){
    real += num;
    return *this;
}

ComplexClass ComplexClass::operator -= (float num){
    real -= num;
    return *this;
}
ComplexClass ComplexClass::operator *= (float num){
    real *= num;
    return *this;
}
ComplexClass ComplexClass::operator /= (float num){
    if(num == 0){
        cout<<"ERROR: we can't divide by 0"<<endl;
        return ComplexClass(0,0);
    }
    real /= num;
    return *this;
}



 ComplexClass::operator float(){
    return real;
 }

ComplexClass::operator int(){
return (int)real;
}


ostream& operator <<(ostream& mySt,ComplexClass& c){

    mySt<<"("<<c.real<<" +i"<<c.img<<")"<<endl;
    return mySt;
}
istream& operator >>(istream& mySt, ComplexClass& c){
    mySt>>c.real>>c.img;
    return mySt;
}
