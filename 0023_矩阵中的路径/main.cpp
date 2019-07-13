#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool hasPath(vector<vector<char>> &matrix, string str) {
        for (int i = 0; i < (int)matrix.size(); ++i) {
            for (int j = 0; j < (int)matrix[0].size(); ++j) {
                if (dfs(matrix, i, j, str, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

  private:
    bool dfs(vector<vector<char>> &matrix, int x, int y, string &str, int k) {
        if (matrix[x][y] != str[k]) {
            return false;
        }
        if ((int)str.size() - 1 == k) {
            return true;
        }
        char t = matrix[x][y];
        matrix[x][y] = '*';
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < (int)matrix.size() && b >= 0 &&
                b < (int)matrix[0].size()) {
                if (dfs(matrix, a, b, str, k + 1)) {
                    return true;
                }
            }
        }
        matrix[x][y] = t;
        return false;
    }
};

void test_case_1() {
    vector<vector<char>> matrix{
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string str = "BCCE";
    bool res = Solution().hasPath(matrix, str);
    assert(res == true);
}

void test_case_2() {
    vector<vector<char>> matrix{
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string str = "ASAE";
    bool res = Solution().hasPath(matrix, str);
    assert(res == false);
}

void test_case_3() {
    vector<vector<char>> matrix{{'a'}};
    string str = "a";
    bool res = Solution().hasPath(matrix, str);
    assert(res == true);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
