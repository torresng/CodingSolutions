#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool searchArray(vector<vector<int>> array, int target) {
        if (array.empty() || array[0].empty()) {
            return false;
        }

        int n = array.size(), m = array[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (array[i][j] == target) {
                return true;
            }
            if (array[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        return false;
    }
};

void test_case_1() {
    vector<vector<int>> array{
        {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    assert(Solution().searchArray(array, 7) == true);
}

void test_case_2() {
    vector<vector<int>> array{
        {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    assert(Solution().searchArray(array, 5) == false);
}

void test_case_3() {
    vector<vector<int>> array{
        {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    assert(Solution().searchArray(array, 0) == false);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
