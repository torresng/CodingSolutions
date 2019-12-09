class Solution {
  public:
    bool isNumber(string s) {
        int i = 0, j = s.size();
        while (i <= j && s[i] == ' ') {
            i++;
        }
        while (i <= j && s[j] == ' ') {
            j--;
        }
        if (i > j) {
            return false;
        }

        s = s.substr(i, j - i + 1);
        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }
        if (s.empty() || (s[0] == '.' && s.size() == 1)) {
            return false;
        } // +, -, .

        int dot = 0, e = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9')
                ;
            else if (s[i] == '.') {
                dot++;
                if (dot > 1 || e) {
                    return false;
                } // 2312.12312.123, 123e12312.2321
            } else if (s[i] == 'e' || s[i] == 'E') {
                e++;
                if (!i || i + 1 == s.size() || e > 1 ||
                    s[i - 1] == '.' && i == 1) {
                    return false;
                } // e12312321, 123123e, 123e123312e
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    if (i + 2 == s.size()) {
                        return false;
                    } // 12321e+
                    i++;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};
