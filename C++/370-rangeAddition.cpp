// solution 1
/*
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        
        if (length == 0) {
            return res;
        }
        
        for (int i = 0; i < updates.size(); i++) {
            int startIndex = updates[i][0];
            int endIndex = updates[i][1];
            int inc = updates[i][2];
            cout << startIndex << " " << endIndex << " " << inc << endl;
            
            for (int j = startIndex; j <= endIndex; j++) {
                res[j] += inc;
            }
        }
        
        return res;
    }
};
*/

// solution 2
// use math
// first step: 
//     res[startIndex] += val
// second step:
//     res[endIndex + 1] -= val
// third step:
//     update res[i] += res[i-1]
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        
        if (length == 0) {
            return res;
        }
        
        for (auto update : updates) {
            int startIndex = update[0];
            int endIndex = update[1];
            int inc = update[2];
            res[startIndex] += inc;
            if (endIndex + 1 < length) {
                res[endIndex + 1] -= inc;
            }
        }
        
        partial_sum(res.begin(), res.end(), res.begin());
        
        return res;
    }
}; 
