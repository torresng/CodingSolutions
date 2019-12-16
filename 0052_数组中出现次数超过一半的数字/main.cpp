class Solution {
  public:
    int moreThanHalfNum_Solution(vector<int> &nums) {
        int cnt = 0, val = -1;
        for (auto x : nums) {
            if (!cnt) {
                val = x, cnt = 1;
            } else {
                if (x == val) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }
        return val;
    }
};
