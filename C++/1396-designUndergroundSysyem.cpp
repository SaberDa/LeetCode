#include <unordered_map>
#include <vector>

using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> mp;
    unordered_map<string, unordered_map<string, int>> times;
    unordered_map<string, unordered_map<string, int>> check;


    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        check[stationName][mp[id].first] += t - mp[id].second;
        times[stationName][mp[id].first]++;
    }

    double getAverageTime(string startStation, string endStation) {
        return (double)check[endStation][startStation] / times[endStation][startStation];
    }
};