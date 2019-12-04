#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int n, m;
    vector<vector<int>> f;

    bool isMatch(string s, string p) {
        n = s.size(), m = p.size();
        f = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        return dp(0, 0, s, p);
    }

    bool dp(int x, int y, string &s, string &p) {
        if (f[x][y] != -1) {
            return f[x][y];
        }
        if (y == m) {
            return f[x][y] = x == n;
        }
        bool first_match = x < n && (p[y] == '.' || s[x] == p[y]);
        if (y + 1 < m && p[y + 1] == '*') {
            f[x][y] = dp(x, y + 2, s, p) || (first_match && dp(x + 1, y, s, p));
        } else {
            f[x][y] = first_match && dp(x + 1, y + 1, s, p);
        }
        return f[x][y];
    }
};

void test_case_1() {
    string s = "aa";
    string p = "a*";
    bool ans = true;

    bool res = Solution().isMatch(s, p);
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
