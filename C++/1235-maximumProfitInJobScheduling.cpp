class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        map<int, int> time;
        unordered_map<int, vector<pair<int, int>>> jobs;
        int res = 0;
        for (int i = 0; i < startTime.size(); i++) {
            time[startTime[i]] = 0;
            jobs[startTime[i]].push_back({endTime[i], profit[i]});
        }
        for (auto it = time.rbegin(); it != time.rend(); it++) {
            for (auto x : jobs[it->first]) {
                auto it = time.lower_bound(x.first);
                res = max(res, (it == time.end() ? 0 : it->second) + x.second);
            }
            it->second = res;
        }
        return res;
    }
};