#include <iostream>
using namespace std;


template<class T>
class stack {
    int size;
    int top;
    T *arr;
    public:
    static int counter;
    stack();
    //copy constructor:
    stack(stack&);
    ~stack();
    int getTop() { return top; }
    T pop();
    void push(T);
    void display();
    stack& operator =(stack&);
    //int& operator [](int);
};
template<class T>
int stack<T>::counter = 0;


int main() {
    stack<int> s1;
    s1.push(3);
    s1.push(5);
    s1.push(3);

    stack<int> s2(s1);

    stack<int> s3;
    s3 = s2;

    cout<<"s2 array = ";
    s2.display();
    cout<<"after assign s3 = s2 ,s3 = ";
    s3.display();
    cout<<"Number of int stacks = "<<stack<int>::counter<<endl;

    cout<<endl<<endl;

    //char stack ................
    stack<char> s;
    s.push('a');
    stack<char> sc2(s);
    sc2.display();
    cout<<"Number of char stacks = "<<stack<char>::counter<<endl;

    return 0;
}


template<class T>
stack<T>::stack() {
    size=10;
    arr = new T[10];
    top = 0;
    counter++;
}

//copy constructor:
template<class T>
stack<T>::stack(stack& x){
    this->top = x.top;
    this->size = x.size;
    this->arr = new T[this->size];

    for(int i=0; i<x.top; i++){
        this->arr[i]=x.arr[i];
    }
    counter++;
}

template<class T>
void stack<T>::push(T val) {
    if (top == size) {
        cout << "Stack is full ......." << endl;
        return;
    }
    arr[top] = val;
    top++;
}

template<class T>
T stack<T>::pop(){
    if (!top) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    top--;
    return arr[top];
}

template<class T>
void stack<T>::display() {
    cout<<"{";
    for (int i = 0; i < top-1; i++)
        cout << arr[i] << ", ";
    cout<<arr[top-1]<<"}"<<endl;
}

template<class T>
stack<T>::~stack() {
    delete[] arr;
    counter--;
}

template<class T>
stack<T>& stack<T>::operator =(stack<T>& s){
    delete[] arr;
    top = s.top;
    size = s.size;
    arr = new T[size];
    for(int i=0; i<s.top; i++){
        arr[i] = s.arr[i];
    }
    return *this;
}

/*
template<class T>
T& stack<T>::operator [](int idx){
    if(idx >= top){
        throw out_of_range("Index out of bounds!");
    }
    return arr[idx];
}
*/
