#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    int get_sum_x(int x) {
        int s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    int get_sum(pair<int, int> pos) {
        return get_sum_x(pos.first) + get_sum_x(pos.second);
    }

    int movingCount(int threshold, int rows, int cols) {
        if (!rows || !cols) {
            return 0;
        }

        vector<vector<bool>> v(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
        int res = 0;
        while (!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            if (get_sum(pos) > threshold || v[pos.first][pos.second]) {
                continue;
            }
            v[pos.first][pos.second] = true;
            ++res;
            for (int i = 0; i < 4; ++i) {
                int x = pos.first + dx[i], y = pos.second + dy[i];
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    q.push({x, y});
                }
            }
        }

        return res;
    }
};

void test_case_1() {
    int k = 7, m = 4, n = 5;
    int ans = 20;
    int res = Solution().movingCount(k, m, n);
    assert(res == ans);
}

void test_case_2() {
    int k = 18, m = 40, n = 40;
    int ans = 1484;
    int res = Solution().movingCount(k, m, n);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
