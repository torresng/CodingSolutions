class Solution {
  public:
    vector<int> findNumsAppearOnce(vector<int> &nums) {
        int sum = 0;
        for (auto x : nums) {
            sum ^= x;
        }
        int k = 0;
        while (!(sum >> k & 1)) {
            k++;
        }
        int first = 0;
        for (auto x : nums) {
            if (x >> k & 1) {
                first ^= x;
            }
        }
        return vector<int>({first, sum ^ first});
    }
};
