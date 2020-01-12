class Solution {
  public:
    vector<int> multiply(const vector<int> &A) {
        if (A.empty()) {
            return vector<int>();
        }
        int n = A.size();
        vector<int> B(n);
        for (int i = 0, p = 1; i < n; i++) {
            B[i] = p;
            p *= A[i];
        }
        for (int i = n - 1, p = 1; i >= 0; i--) {
            B[i] *= p;
            p *= A[i];
        }
        return B;
    }
};
