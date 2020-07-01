#include <vector>
#include <queue>

using namespace std;

class ZigzagIterator {
private:
    

    queue<int> cur;
    
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        while (!v1.empty() && !v2.empty()) {
            cur.push(v1[0]);
            v1.erase(v1.begin());
            cur.push(v2[0]);
            v2.erase(v2.begin());
        }
        while (!v1.empty()) {
            cur.push(v1[0]);
            v1.erase(v1.begin());
        }
        while (!v2.empty()) {
            cur.push(v2[0]);
            v2.erase(v2.begin());
        }
    }

    int next() {
        int res = cur.front();
        cur.pop();
        return res;
    }

    bool hasNext() {
        return !cur.empty();
    }
};