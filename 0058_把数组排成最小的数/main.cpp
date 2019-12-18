class Solution {
  public:
    static bool cmp(int a, int b) {
        auto as = to_string(a), bs = to_string(b);
        return as + bs < bs + as;
    }

    string printMinNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res;
        for (auto x : nums) {
            res += to_string(x);
        }
        return res;
    }
};
