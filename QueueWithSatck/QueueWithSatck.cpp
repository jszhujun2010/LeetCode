#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    // Push element x to the back of queue.
    void push(int x) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.pop();
    }

    // Get the front element.
    int peek(void) {
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return stack1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    Queue q = Queue();
    q.push(1);
    q.push(2);

}
