#include <iostream>

using namespace std;

class Solution {
  public:
    int NumberOf1(int n) {
        int res = 0;
        while (n) {
            ++res;
            n = (n - 1) & n;
        }
        return res;
    }

    /*
  int NumberOf1(int n) {
      unsigned _n = n;
      int res = 0;
      while (_n) {
          res += _n & 1;
          _n = _n >> 1;
      }
      return res;
  }
  */
};

void test_case_1() {
    int n = 9;
    int ans = 2;
    int res = Solution().NumberOf1(n);
    assert(res == ans);
}

void test_case_2() {
    int n = -2;
    int ans = 31;
    int res = Solution().NumberOf1(n);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
