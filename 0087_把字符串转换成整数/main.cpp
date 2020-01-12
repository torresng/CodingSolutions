class Solution {
  public:
    int strToInt(string str) {
        int k = 0;
        while (k < str.size() && str[k] == ' ') {
            k++;
        }
        long long number = 0;
        bool is_minus = false;
        if (str[k] == '+') {
            k++;
        } else if (str[k] == '-') {
            k++, is_minus = true;
        }
        while (k < str.size() && str[k] >= '0' && str[k] <= '9') {
            number = number * 10 + str[k] - '0';
            k++;
        }
        if (is_minus) {
            number *= -1;
        }
        if (number > INT_MAX) {
            number = INT_MAX;
        }
        if (number < INT_MIN) {
            number = INT_MIN;
        }
        return (int)number;
    }
};
