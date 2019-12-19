class Solution {
  public:
    int getUglyNumber(int n) {
        vector<int> q(1, 1);
        int i = 0, j = 0, k = 0;
        while (--n) {
            int t = min(q[i] * 2, min(q[j] * 3, q[k] * 5));
            q.push_back(t);
            if (q[i] * 2 == t) {
                i++;
            }
            if (q[j] * 3 == t) {
                j++;
            }
            if (q[k] * 5 == t) {
                k++;
            }
        }
        return q.back();
    }
};
