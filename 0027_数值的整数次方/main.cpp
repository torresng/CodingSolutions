#include <iostream>

class Solution {
  public:
    double Power(double base, int exponent) {
        double res = 1;
        for (int i = 0; i < abs(exponent); ++i) {
            res *= base;
        }
        if (exponent < 0) {
            res = 1/res;
        }
        return res;
    }
};

void test_case_1() {
    double base = 10;
    int exponent = 2;
    double ans = 100;
    double res = Solution().Power(base, exponent);
    assert(res == ans);
}

void test_case_2() {
    double base = 10;
    int exponent = -2;
    double ans = 0.01;
    double res = Solution().Power(base, exponent);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
