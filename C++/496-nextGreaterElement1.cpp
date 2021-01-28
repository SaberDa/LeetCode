class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> mp;
        stack<int> s;
        for (auto x : nums2) {
            while (!s.empty() && s.top() < x) {
                mp[s.top()] = x;
                s.pop();
            }
            s.push(x);
        }
        for (auto &x : nums1) x = mp.count(x) ? mp[x] : -1;
        return nums1;
    }
};
