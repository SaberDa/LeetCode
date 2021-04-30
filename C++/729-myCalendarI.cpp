class treeNode {
private:
    int _start, _end;
    treeNode *_left, *_right;
public:
    treeNode(int start, int end) : _start(start), _end(end), _left(NULL), _right(NULL) {}
    int getStart() {return _start;}
    int getEnd() {return _end;}
    treeNode *getLeft() {return _left;}
    treeNode *getRight() {return _right;}
    void setLeft(treeNode *left) {_left = left;}
    void setRight(treeNode *right) {_right = right;}
};

class MyCalendar {
public:

    treeNode *root;

    MyCalendar() {
        root = NULL;
    }
    
    bool buildTree(treeNode *root, int start, int end) {
        if (root->getStart() <= start && root->getEnd() >= start ||
            root->getStart() >= start && root->getStart() <= end) {
                return false;
        }
        if (start < root->getStart()) {
            if (root->getLeft() == NULL) {
                treeNode *left = new treeNode(start, end);
                root->setLeft(left);
                return true;
            }
            return buildTree(root->getLeft(), start, end);
        }
        if (start > root->getStart()) {
            if (root->getRight() == NULL) {
                treeNode *right = new treeNode(start, end);
                root->setRight(right);
                return true;
            }
            return buildTree(root->getRight(), start, end);
        }
        return true;
    }

    bool book(int start, int end) {
        if (root == NULL) {
            root = new treeNode(start, end - 1);
            return true;
        }
        return buildTree(root, start, end - 1);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */