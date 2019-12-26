class Solution {
  public:
    int getMissingNumber(vector<int> &nums) {
        int n = nums.size() + 1;
        int res = (n - 1) * n / 2;
        for (auto x : nums) {
            res -= x;
        }
        return res;
    }
};
