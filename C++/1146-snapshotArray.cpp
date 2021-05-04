class SnapshotArray {
private:
    vector<unordered_map<int, int>> mp = {{}};
public:
    SnapshotArray(int length) {}

    void set(int index, int val) {
        mp[mp.size() - 1][index] = val;
    }

    int snap() {
        mp.push_back({});
        return mp.size() - 2;
    }

    int get(int index, int snap_id) {
        for (int i = snap_id; i >= 0; i--) {
            if (mp[i].count(index)) return mp[i][index];
        }
        return 0;
    }
};