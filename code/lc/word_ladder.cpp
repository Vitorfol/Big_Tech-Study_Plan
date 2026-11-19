#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        wordSet.erase(beginWord);
        
        while (!q.empty()) {
            auto [currentWord, level] = q.front();
            q.pop();
            
            if (currentWord == endWord) {
                return level;
            }
            
            for (int i = 0; i < currentWord.size(); ++i) {
                char originalChar = currentWord[i];
                
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) continue;
                    
                    currentWord[i] = c;
                    
                    if (wordSet.find(currentWord) != wordSet.end()) {
                        q.push({currentWord, level + 1});
                        wordSet.erase(currentWord);
                    }
                }
                
                currentWord[i] = originalChar;
            }
        }
        
        return 0;
    }
};
