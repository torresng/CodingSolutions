class Solution {
  public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    void insert(int num) {
        max_heap.push(num);
        if (min_heap.size() && max_heap.top() > min_heap.top()) {
            auto maxv = max_heap.top(), minv = min_heap.top();
            max_heap.pop(), min_heap.pop();
            max_heap.push(minv), min_heap.push(maxv);
        }
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double getMedian() {
        if (max_heap.size() + min_heap.size() & 1) {
            return max_heap.top();
        }
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};
