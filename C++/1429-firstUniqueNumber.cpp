class FirstUnique {
public:

    unordered_multiset<int> st;
    queue<int> q;

    FirstUnique(vector<int>& nums) {
        for (auto x : nums) add(x);
    }
    
    int showFirstUnique() {
        while (q.size() && st.count(q.front()) > 1) q.pop();
        return q.size() ? q.front() : -1;
    }
    
    void add(int value) {
        if (st.count(value) > 1) return;
        if (!st.count(value)) q.push(value);
        st.insert(value);
    }
};