class Solution {
  public:
    bool isContinuous(vector<int> numbers) {
        if (numbers.empty()) {
            return false;
        }
        sort(numbers.begin(), numbers.end());
        int k = 0;
        while (!numbers[k]) {
            k++;
        }
        for (int i = k + 1; i < numbers.size(); i++) {
            if (numbers[i] == numbers[i - 1]) {
                return false;
            }
        }
        return numbers.back() - numbers[k] <= 4;
    }
};
