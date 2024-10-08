#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int ptrL = 0, ptrR = 0;
        string words;
        vector<string> v;

        while (ptrR <= s.size()) {
            while (ptrL < s.size() && isEmpty(s[ptrL])){
                ptrL++;
            }
            ptrR = ptrL;
            
            while (ptrR < s.size() && !isEmpty(s[ptrR])){
                ptrR++;
            }

            if (ptrL < s.size()){
                words = s.substr(ptrL, ptrR - ptrL);
                v.push_back(words);
            }

            ptrL = ptrR + 1;

        }
        
        reverse(v.begin(), v.end());

        ostringstream oss;
        for (size_t i = 0; i < v.size(); ++i) {
            if (i > 0) oss << " ";
            oss << v[i];
        }

        string res = oss.str();
        return res;
    }

    bool isEmpty(char c) {
        return c == ' ';
    }
};

int main()
{
    Solution sol;
    std::string s = "the sky is blue";
    s = sol.reverseWords(s);

    std::cout << s << std::endl;

    return 0;
} 