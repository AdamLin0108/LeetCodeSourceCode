#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string r;

        while(i < word1.length() && j < word2.length()){
            r.push_back(word1[i]);
            r.push_back(word2[j]);

            i++;
            j++;
        }

        if (i < word1.length()){
            r += word1.substr(i);
        }
        
        if (j < word2.length()){
            r += word2.substr(j);
        }
        return r;
    }
};