#include <iostream>

class Solution {
  public:
    int maxProductAfterCutting(int length) {
        if (length < 3) {
            return (length - 1) * 1;
        }

        int sum = 1;
        if (length % 3 == 1) {
            sum *= 4;
            length -= 4;
        }
        if (length % 3 == 2) {
            sum *= 2;
            length -= 2;
        }
        while (length) {
            sum *= 3;
            length -= 3;
        }
        return sum;
    }
};

void test_case_1() {
    int length = 8;
    int ans = 18;
    int res = Solution().maxProductAfterCutting(length);
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
