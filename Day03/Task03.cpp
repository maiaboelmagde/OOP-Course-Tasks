//standalone viewContent function (passing by Reference)
#include <iostream>
using namespace std;

class stack {
    int size;
    int top;
    int* arr;
    public:
    static int counter;


    stack() {
        arr = new int[10];
        size=10;
        top = 0;
        counter++;
    }

    int getTop() { return top; }

    int pop() {
        if (!top) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        top--;
        return arr[top];
    }

    void push(int val) {
        if (top == size) {
            cout << "Stack is full ......." << endl;
            return;
        }
        arr[top] = val;
        top++;
    }

    void sum(int num) {
        for (int i = 0; i < top; i++)
            arr[i] += num;
    }

    void sum(stack s) {
        if (s.top != this->top) {
            cout << "Both stacks should contain the same number of elements, not " << s.top << " & " << this->top << endl;
            return;
        }
        for (int i = 0; i < top; i++)
            this->arr[i] += s.arr[i];
    }

    void display() {
        for (int i = 0; i < top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~stack() {
        delete[] arr;
        counter--;
        cout << "We freed the array's location" << endl;
    }

    friend void viewStack(stack& local_s);
};

int stack::counter = 0;

void viewStack(stack& local_s);

int main() {
    stack s1;
    cout<<"Counter after 1st object on main equals : "<<stack::counter<<endl;
    s1.push(3);
    s1.push(5);
    s1.push(3);
    s1.display();
    viewStack(s1);
    cout<<"arr after the function"<<endl;
    s1.display(); // they printed as a rubbish


    return 0;
}


void viewStack(stack& local_s){

    int num = local_s.getTop();
    cout<<"arr inside the function"<<endl;
    for(int i=0;i<num;i++){
        cout<<local_s.arr[i]<<" ";
    }
    cout<<endl;
}
