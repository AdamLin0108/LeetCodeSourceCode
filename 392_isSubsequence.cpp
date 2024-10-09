class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptrS = 0;
        int ptrT = 0;

        while (ptrT < t.length()) {
            if (s[ptrS] == t[ptrT]) {
                ptrS++;
            }
            ptrT++;
        }

        return ptrS == s.length();
    }
};