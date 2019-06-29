#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    int duplicateInArray(vector<int> &nums) {
        int n = nums.size();
        for (auto x : nums) {
            if (x < 0 || x >= n) {
                return -1;
            }
        }
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
            if (nums[i] != i && nums[i] == nums[nums[i]]) {
                return nums[i];
            }
        }
        return -1;
    }
};

void test_case_1() {
    vector<int> nums{2, 3, 5, 4, 3, 2, 6, 7};
    set<int> ans{2, 3};
    int res = Solution().duplicateInArray(nums);
    assert(ans.find(res) != ans.end());
}

int main(void) {
    test_case_1();

    return 0;
}
