class Solution {
  public:
    vector<vector<int>> findContinuousSequence(int sum) {
        vector<vector<int>> res;
        for (int i = 1, j = 1, s = 1; i <= sum; i++) {
            while (s < sum) {
                s += ++j;
            }
            if (s == sum && j - i > 0) {
                vector<int> line;
                for (int k = i; k <= j; k++) {
                    line.push_back(k);
                }
                res.push_back(line);
            }
            s -= i;
        }
        return res;
    }
};
