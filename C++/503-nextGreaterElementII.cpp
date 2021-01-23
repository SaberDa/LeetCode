class Solution {
public:

    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (q.empty() || nums[i] > q.back()) q.push_back(nums[i]);
            while (!st.empty() && nums[i] > nums[st.top()]) {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            while (!q.empty() && nums[st.top()] >= q.front()) q.pop_front();
            if (!q.empty()) res[st.top()] = q.front();
            st.pop();
        }
        return res;
    }

};