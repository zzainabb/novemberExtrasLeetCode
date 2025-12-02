#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordSet.end());
        if (!wordSet.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({ beginWord, 1 });

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            for (int i = 0; i < word.size(); i++) {
                string next = word;

                for (char c = 'a'; c <= 'z'; c++) {
                    next[i] = c;

                    if (next == endWord)
                        return steps + 1;

                    if (wordSet.count(next)) {
                        q.push({ next, steps + 1 });
                        wordSet.erase(next);
                    }
                }
            }
        }

        return 0;
    }
};
