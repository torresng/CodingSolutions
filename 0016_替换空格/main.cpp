#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string replaceSpaces(string &str) {
        string res;
        for (auto c : str) {
            if (c == ' ') {
                res += "%20";
            } else {
                res += c;
            }
        }
        return res;
    }
};

void test_case_1() {
    string str = "We are happy.";
    string ans = "We%20are%20happy.";
    string res = Solution().replaceSpaces(str);
    assert(ans.compare(res) == 0);
}

int main(void) {
    test_case_1();

    return 0;
}
