#include <vector>
#include <set>

using namespace std;

class ExamRoom {
private:
    set<int> s;
    int N = 0;
public:
    ExamRoom(int N) {
        this->N = N;
    }

    int seat() {
        if (s.empty()) {
            s.insert(0);
            return 0;
        } else if (s.size() == 1) {
            int pos = *s.begin() < N /2 ? N - 1 : 0;
            s.insert(pos);
            return pos;
        } else {
            int dis = -1, res = -1;
            if (!s.count(0)) {
                dis = *s.begin() - 1;
                res = 0;
            }

            auto p1 = s.begin();
            auto p2 = p1;
            p2++;
            while (p2 != s.end()) {
                int pos = (*p1 + *p2) / 2;
                int d = min(pos - *p1, *p2 - pos) - 1;
                if (d > dis) {
                    dis = d;
                    res = pos;
                }
                p1++, p2++;
            }

            if (!s.count(N - 1)) {
                auto e = s.end();
                e--;
                int d = N - 1 - *e - 1;
                if (d > dis) {
                    dis = d;
                    res = N - 1;
                }
            }
            s.insert(res);
            return res;
        }
    }

    void leave(int p) {
        s.erase(p);
    }

};