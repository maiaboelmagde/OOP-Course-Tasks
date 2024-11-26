#include <iostream>
#include <graphics.h>

using namespace std;

class Point{
    int x,y;
public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
    Point(Point& p){x = p.x; y = p.y;}

    void setPoint(Point& p){
        x = p.x;
        y = p.y;
    }
    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}
    int getX(){return x;}
    int getY(){return y;}
};


class Circle{
    Point centre;
    int redius;
public:
    Circle():centre(){redius = 0;}
    Circle(int x, int y, int redius):centre(x,y){this->redius = redius;}

    setX(int x){ centre.setX(x) ;}
    sety(int y){centre.setY(y);}
    setCentre(int x,int y){centre.setX(x); centre.setY(y);}
    setCentreXY(Point p){centre.setPoint(p);}
    setRedius(int r){redius = r;}

    getX(){return centre.getX();}
    getY(){return centre.getY();}
    int getRedius(){return redius;}

    copyCircle(Circle c){
        setCentre(c.centre.getX(), c.centre.getY());
        redius = c.redius;
    }

    void Draw(){
        circle(centre.getX(),centre.getY(),redius);
    }
};

class Rect{
    Point UL;
    Point LR;
public:
    Rect():UL(),LR(){}
    Rect(int x1, int y1, int x2, int y2):UL(x1,y1),LR(x2,y2){}
    void setULX(int x){UL.setX(x);}
    void setULY(int y){UL.setY(y);}
    void setLRX(int x){LR.setX(x);}
    void setLRY(int y){LR.setY(y);}
    void setUL(Point p){UL.setPoint(p);}
    void setLR(Point p){LR.setPoint(p);}

    void getUL(int& x,int& y){x = UL.getX(); y = UL.getY();}
    void getLR(int& x,int& y){x=LR.getX(); y=LR.getY();}

    void Draw(){
        rectangle(UL.getX(), UL.getY(), LR.getX(), LR.getY());
    }
};

class Line{
    Point startPoint;
    Point endPoint;
public:
    Line():startPoint(),endPoint(){}
    Line(int x1, int y1, int x2, int y2):startPoint(x1, y1),endPoint(x2, y2){}
    void copyLine(Line l){
        startPoint.setX(l.startPoint.getX());
        startPoint.setY(l.startPoint.getY());
        endPoint.setX(l.endPoint.getX());
        endPoint.setY(l.endPoint.getY());
    }


    void setStartX(int x){startPoint.setX(x);}
    void setStartY(int y){startPoint.setY(y);}
    void setEndX(int x){endPoint.setX(x);}
    void setEndY(int y){endPoint.setY(y);}
    void setStart(Point p){startPoint.setPoint(p);}
    void setEnd(Point p){endPoint.setPoint(p);}

    void getEnd(int& x,int& y){x = endPoint.getX(); y = endPoint.getY();}
    void getStart(int& x,int& y){x = startPoint.getX(); y = startPoint.getY();}

    void Draw(){
        line(startPoint.getX(), startPoint.getY(), endPoint.getX(), endPoint.getY());
    }
};

class Picture{
    Line* lp;
    Circle* cp;
    Rect* rp;
    int ln,cn,rn;
public:
    Picture(){
        lp = NULL;
        cp = NULL;
        rp = NULL;
        ln = 0;
        cp = 0;
        rp = 0;
    }

    Picture(Circle* c, int cn, Rect* rect, int rn, Line* l, int ln){
        cp = c;
        this->cn = cn;
        rp = rect;
        this->rn= rn;
        lp = l;
        this->ln = ln;
    }

    void display(){
        for(int i = 0; i < cn ; i++) cp[i].Draw();
        for(int i = 0; i < rn ; i++) rp[i].Draw();
        for(int i = 0; i < ln ; i++) lp[i].Draw();
    }
};


int main()
{
    initgraph();
    setcolor(9);
    Circle myCircle(200, 150, 50);
    myCircle.Draw();

    Circle myCircle2(300, 150, 50);
    myCircle2.Draw();

    Rect myRect(200, 300, 300, 250);
    myRect.Draw();

    Line myLine1(170, 110, 230, 118);
    myLine1.Draw();
    Line myLine2(280, 118, 330, 110);
    myLine2.Draw();


    Line lArr[2];
    lArr[0].copyLine(*(new Line(370, 110, 430, 118)));
    lArr[1].copyLine(*(new Line(480, 118, 530, 110)));
    Circle cArr[2] = {(*(new Circle(400, 150, 50))),(*(new Circle(500, 150, 50)))};
    //cArr[0].copyCircle(*(new Circle(400, 150, 50)));
    //cArr[1].copyCircle(*(new Circle(500, 150, 50)));
    Rect r2(400, 300, 500, 250);
    Picture pic(cArr, 2, &r2, 1, lArr, 2);
    pic.display();
    return 0;
}
