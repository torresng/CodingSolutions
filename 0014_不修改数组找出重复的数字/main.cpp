#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    int duplicateInArray(vector<int> &nums) {
        int n = nums.size();
        int l = 1, r = n - 1;

        while (l < r) {
            int mid = (l + r) >> 1;
            int count = 0;
            for (auto x : nums) {
                count += (x >= l && x <= mid);
            }
            if (count > mid - l + 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};

void test_case_1() {
    vector<int> nums{2, 3, 5, 4, 3, 2, 6, 7};
    set<int> s{2, 3};
    int res = Solution().duplicateInArray(nums);
    assert(s.find(res) != s.end());
}

void test_case_2() {
    vector<int> nums{8,  6,  24, 19, 13, 12, 26, 8,  19, 18, 3,
                     21, 4,  18, 26, 16, 3,  20, 17, 9,  24, 9,
                     6,  21, 7,  15, 17, 22, 2,  23, 4};
    set<int> s{3, 4, 6, 8, 9, 17, 18, 19, 21, 24, 26};
    int res = Solution().duplicateInArray(nums);
    assert(s.find(res) != s.end());
}

int main(void) {
    test_case_1();
    test_case_2();

    return 0;
}
