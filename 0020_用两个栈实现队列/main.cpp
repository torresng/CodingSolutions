#include <iostream>
#include <vector>

using namespace std;

class MyQueue {
  public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { stack1.push_back(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stack2.empty()) {
            copy(stack1, stack2);
        }
        int res = stack2.back();
        stack2.pop_back();
        return res;
    }

    /** Get the front element. */
    int peek() {
        if (stack2.empty()) {
            copy(stack1, stack2);
        }
        int res = stack2.back();
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return stack1.empty() && stack2.empty(); }

  private:
    vector<int> stack1, stack2;

    void copy(vector<int> &stack1, vector<int> &stack2) {
        while (!stack1.empty()) {
            stack2.push_back(stack1.back());
            stack1.pop_back();
        }
    }
};

void test_case_1() {
    MyQueue queue = MyQueue();

    queue.push(1);
    queue.push(2);
    int x = queue.peek(); // returns 1
    assert(x == 1);
    x = queue.pop(); // returns 1
    assert(x == 1);
    bool b = queue.empty(); // returns false
    assert(b == false);
}

int main(void) {
    test_case_1();

    return 0;
}
