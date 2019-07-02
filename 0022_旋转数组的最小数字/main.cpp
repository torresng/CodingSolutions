#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }

        int n = nums.size() - 1;
        while (n > 0 && nums[n] == nums[0]) {
            --n;
        }
        if (nums[0] <= nums[n]) {
            return nums[0];
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[0]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

void test_case_1() {
    vector<int> nums{2, 2, 2, 0, 1};
    assert(Solution().findMin(nums) == 0);
}

void test_case_2() {
    vector<int> nums{};
    assert(Solution().findMin(nums) == -1);
}

int main(void) {
    test_case_1();
    test_case_2();

    return 0;
}
