class Solution {
public:
    std::string reverseVowels(std::string s) {
        int ptrL = 0;
        int ptrR = s.length() - 1;
        int temp;
        char l = s[ptrL];
        char r = s[ptrR];

        while (ptrL < ptrR) {
            if (isVowel(s[ptrL]) && isVowel(s[ptrR])) {
                // if both is vowel swap them, and pointer move to next
                temp = s[ptrL];
                s[ptrL] = s[ptrR];
                s[ptrR] = temp;
                ptrL++;
                ptrR--;
            }
            else {
                // if Left isVowel do not move
                if (isVowel(s[ptrL]) && !isVowel(s[ptrR])) {
                    ptrR--;
                }
                // if Right isVowel do not move
                if (!isVowel(s[ptrL]) && isVowel(s[ptrR])) {
                    ptrL++;
                }
                // if Left and Right isVowel move to next
                if (!isVowel(s[ptrL]) && !isVowel(s[ptrR])) {
                    ptrL++;
                    ptrR--;
                }
            }
        }
        return s;
    }

    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
        else {
            return false;
        }
    }
};