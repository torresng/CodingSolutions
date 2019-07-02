#include <iostream>

using namespace std;

class Solution {
  public:
    // O(n)
    int Fibonacci(int n) {
        int a = 0, b = 1;
        while (n--) {
            int c = a + b;
            a = b, b = c;
        }
        return a;
    }

    // 還有O(logn)的做法，建議去了解下
    // https://www.acwing.com/blog/content/25/
};

void test_case_1() {
    int n = 5;
    assert(Solution().Fibonacci(n) == 5);
}

int main(void) {
    test_case_1();

    return 0;
}
