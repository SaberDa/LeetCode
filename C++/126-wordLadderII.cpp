#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Key Observations:
// 1. The dictionary actually implicitly gives a maze where two words are connected if they can transform to each other by the rules. 
//    So the problem is actually to find all shortest path from begin to end
// 2. Use two-end BFS to search next transformed words from either direction based on whichever direction has fewer options to transform to next word in ladder.
//    This avoid the scenario where the arr way too mant path from one end, but only a few paths could reach the other end at the last moment.
// 3. This problem can be decoupled into two sub-questions:
//      a) build mapNextWords to find all next transformed dictionary words for each word
//          (we only need to build the map enough to only cover all shortest paths. This can be guaranteed by BFS on graph with no weight on edges)
//      b) build all shortest ladders using the map mapNextWords. This can be done by standard back tracking

// word dictionary
unordered_set<string> dict;

// mapNextWord[w]: set of all w's possible next words in dictionary
// The "next" is always in start -> end direction
unordered_map<string, unordered_set<string>> mapNextWords;

// all shortest ladders
vector<vector<string>> ladders;

/**
 * Build mapNextWords recursively using two-end BFS
 * Note: each recursion dose exactly 1 transform distance from either start or end direction
 * @param  {unordered_set<string>} layer1 : 
 * @param  {unordered_set<string>} layer2 : 
 * @param  {bool} isForward               : 
 */
void buildMapNextWords(unordered_set<string>& layer1, unordered_set<string>& layer2, bool isForward) {
    if (layer1.empty()) {
        return;
    }
    
    // always BFS from the smaller layer side
    if (layer1.size() > layer2.size()) {
        swap(layer1, layer2);
        isForward = !isForward;
    }

    // remove used words from dict
    for (auto& w : layer1) {
        dict.erase(w);
    }
    for (auto& w : layer2) {
        dict.erase(w);
    }

    // next layer of layer1 by word transform
    unordered_set<string> nextLayer;

    bool shortest_ladder_found = false;

    // transform each word in layer1
    for (auto w : layer1) {
        string origW = w;
        for (int i = 0; i < w.size(); i++) {
            char origCh = w[i];
            for (char c = 'a'; c <= 'z'; c++) {
                // transform word w
                w[i] = c;       

                // keep current->next always on start->end direction
                string curWord = origW;
                string nxtWord = w;
                if (!isForward) {
                    swap(curWord, nxtWord);
                }
                
                // next layer of layer1 meets layer2: shortest path found
                if (layer2.count(w)) {
                    shortest_ladder_found = true;
                    mapNextWords[curWord].insert(nxtWord);
                }

                // next layer of layer1 didn't meet layer2, but still in dict, so keep going
                else if (dict.count(w)) {
                    nextLayer.insert(w);
                    mapNextWords[curWord].insert(nxtWord);
                }
            }
            w[i] = origCh;
        }
    }

    //recursively build map if not done
    if (!shortest_ladder_found) {
        buildMapNextWords(nextLayer, layer2, isForward);
    }
}

/**
 * Build add shortest ladders using back tracking
 * 
 * @param  {string} curWord        : current word in ladder
 * @param  {string} endWord        : end word in ladder
 * @param  {vector<string>} ladder : current ladder in building process
 */
void buildLadders(string curWord, string endWord, vector<string>& ladder) {
    // if current word reaches end, current ladder is done
    if (curWord == endWord) {
        ladders.push_back(ladder);
        return;
    }    

    // try all next word options and append to current ladder
    for (auto& w : mapNextWords[curWord]) {
        ladder.push_back(w);
        buildLadders(w, endWord, ladder);
        ladder.pop_back();
    }
}

int main() {

    vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
    string beginWord = "hit";
    string endWord = "cog";

    dict = unordered_set<string>(wordList.begin(), wordList.end());

    if (!dict.count(endWord)) {
        return 0;
    }

    // initialize two layers for two-end BFS
    unordered_set<string> forwardLayer({beginWord});
    unordered_set<string> backwardLayer({endWord});

    // sub-problem 1: build next word map
    buildMapNextWords(forwardLayer, backwardLayer, true);

    // sub-problem 2: build ladders
    vector<string> ladder({beginWord});
    buildLadders(beginWord, endWord, ladder);

    for (int i = 0; i < ladders.size(); i++) {
        for (int j = 0; j < ladders[0].size(); j++) {
            cout << ladders[i][j] << " ";
        }
        cout << " " << endl;
    }

    return 0;
}