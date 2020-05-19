#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std; 

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            pair<int, int> temp;
            temp.first = points[i][0];
            temp.second = points[i][1];
            int sum = pow(temp.first, 2) + pow(temp.second, 2);
            pq.push(make_pair(sum, temp));
            if (pq.size() > K) {
                pq.pop();
            }
        }
        while (pq.size() > 0) {
            pair<int, pair<int, int>> temp = pq.top();
            pq.pop();
            vector<int> cur;
            cur.push_back(temp.second.first);
            cur.push_back(temp.second.second);
            res.push_back(cur);
            cur.clear();
        }
        return res;
}