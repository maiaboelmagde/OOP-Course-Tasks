#include <iostream>
using namespace std;
class  Shape{
protected:
    float d1,d2;
public:
    Shape(){d1=0; d2=0;}
    Shape(float f){d1=d2=f;}
    Shape(float di1,float di2){d1=di1;d2=di2;}
    void setd1(int d){ d1=d;}
    void setd2(int d){ d2=d;}
    float getd1(){ return d1;}
    float getd2(){ return d2;}
    float calcArea(){return 0.0;}


};
class Rect :public Shape{
 public:
     Rect(){}
     Rect(float l,float w):Shape(l,w){}
     float calcArea(){ return d1*d2;}
 };

class Square :protected Rect{
 public:
     Square(float l):Rect(l,l){}
     float calcArea(){ return d1*d2;}
     void setl(int l){d1=d2=l;}
 };

class Circle :protected Shape {
 public:
     Circle(){}
     Circle(float r):Shape(r){}
     float calcArea(){ return d1*d2*3.14;}
     void setR(int r){ d1=d2=r;}
     float getR(){return d1;}
 };
    class Triangle :public Shape {
 public:
     Triangle(){}
     Triangle(float b, float h):Shape(b,h){}
     float calcArea(){ return d1*d2*0.5;}
 };
int main()
{
    Rect r (3,4);
    cout<<"area of circle " <<r.calcArea()<<endl;
    Square s(3);
    cout<<"area of square " <<s.calcArea()<<endl;

    cout<<"area of square after modified" <<s.calcArea()<<endl;
    Triangle t(4,3);
    cout<<"area of Triangle " <<t.calcArea()<<endl;

    return 0;
}
