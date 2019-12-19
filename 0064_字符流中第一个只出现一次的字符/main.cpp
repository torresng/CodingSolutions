class Solution {
  public:
    unordered_map<char, int> count;
    queue<char> q;

    // Insert one char from stringstream
    void insert(char ch) {
        if (++count[ch] > 1) {
            while (q.size() && count[q.front()] > 1) {
                q.pop();
            }
        } else {
            q.push(ch);
        }
    }
    // return the first appearence once char in current stringstream
    char firstAppearingOnce() {
        if (q.empty()) {
            return '#';
        } else {
            return q.front();
        }
    }
};
