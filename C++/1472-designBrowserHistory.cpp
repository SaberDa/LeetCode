class BrowserHistory {
public:

    deque<string> url;
    int i = 0;

    BrowserHistory(string homepage) {
        url.push_back(homepage);
    }
    
    void visit(string next) {
        while (i) {
            url.pop_front();
            i--;
        }
        url.push_front(next);
    }
    
    string back(int steps) {
        while (steps-- && i + 1 < url.size()) {
            i++;
        }
        return url[i];
    }
    
    string forward(int steps) {
        while (steps-- && i - 1 >= 0) {
            i--;
        }
        return url[i];
    }
};