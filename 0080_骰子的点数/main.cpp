class Solution {
  public:
    vector<int> numberOfDice(int n) {
        vector<vector<int>> f(n + 1, vector<int>(n * 6 + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i * 6; j++) {
                for (int k = 1; k <= min(j, 6); k++) {
                    f[i][j] += f[i - 1][j - k];
                }
            }
        }
        vector<int> res;
        for (int i = n; i <= n * 6; i++) {
            res.push_back(f[n][i]);
        }
        return res;
    }
};
