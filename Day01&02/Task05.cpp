#include <iostream>
using namespace std;

class stack {
    int size;
    int top;
    int arr[10];

public:
    stack() {
        size=10;
        top = 0;
    }

    int getSize() { return top; }

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
        cout << "Your value " << val << " has been added :)" << endl;
    }

    void sum(int num) {
        for (int i = 0; i < top; i++)
            arr[i] += num;
    }

    void sum(stack& s) {
        if (s.getSize() != this->top) {
            cout << "Both stacks should contain the same number of elements, not " << s.getSize() << " & " << this->top << endl;
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
        cout << "We freed the array's location" << endl;
    }
};

int main() {
    stack s1;
    s1.push(3);
    s1.push(5);
    s1.display();
    s1.sum(3);
    s1.display();

    stack s2;
    s2.push(9);
    s2.push(5);
    s2.push(1);
    s2.display();
    s2.sum(s1);
    s2.pop();
    s2.display();
    s1.display();
    s2.sum(s1);
    s2.display();

    return 0;
}
