#include <iostream>
using namespace std;

class stack {
    int size;
    int top;
    int *arr;
    public:
    static int counter;
    stack();
    //copy constructor:
    stack(stack&);
    ~stack();
    int getTop() { return top; }
    int pop();
    void push(int);
    void display();
    stack& operator =(stack&);
    int& operator [](int);
};

int stack::counter = 0;


int main() {
    stack s1;
    s1.push(3);
    s1.push(5);
    s1.push(3);

    stack s2(s1);

    stack s3;
    s3 = s2;

    cout<<"s2 array = ";
    s2.display();
    cout<<"after assign s3 = s2 ,s3 = ";
    s3.display();

    cout<<"s3[1] = "<<s3[1]<<endl;

    s3[2] = 4;
    cout<<"after assign s3[2] = 4 , s3 =";
    s2.display();

    cout<<endl<<endl;
    return 0;
}



stack::stack() {
    size=10;
    arr = new int[10];
    top = 0;
    counter++;
}

//copy constructor:
stack::stack(stack& x){
    this->top = x.top;
    this->size = x.size;
    this->arr = new int[this->size];

    for(int i=0; i<x.top; i++){
        this->arr[i]=x.arr[i];
    }
}

void stack::push(int val) {
    if (top == size) {
        cout << "Stack is full ......." << endl;
        return;
    }
    arr[top] = val;
    top++;
}

int stack::pop(){
    if (!top) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    top--;
    return arr[top];
}

void stack::display() {
    cout<<"{";
    for (int i = 0; i < top-1; i++)
        cout << arr[i] << ", ";
    cout<<arr[top-1]<<"}"<<endl;
}

stack::~stack() {
    delete[] arr;
    counter--;
    cout << "We set the array's location free" << endl;
}

stack& stack::operator =(stack& s){
    delete[] arr;
    top = s.top;
    size = s.size;
    arr = new int[size];
    for(int i=0; i<s.top; i++){
        arr[i] = s.arr[i];
    }
    return *this;
}

int& stack::operator [](int idx){
    if(idx >= top){
        throw out_of_range("Index out of bounds!");
    }
    return arr[idx];
}

