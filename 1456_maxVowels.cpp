#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     int maxVowels(string s, int k) {
//         int temp = 0, max = 0, start = 0, end = start + k - 1;
//         string s2;
//         for(int i = 0; i < s.size(); i++){
//             s2 = s.substr(start, k);
            
//             if(i >= k - 1){
//                 for(int j = 0; j < k; j++){
//                     if(isVowel(s2[j])){
//                         temp++;
//                     }
//                     if(temp > max){
//                         max = temp;
//                     }
//                 }
//                 temp = 0;
//                 start++;
//             }
//         }
//         return max;
//     }

//     bool isVowel(char c){
//         return c == 'a' || c == 'e'|| c == 'i'|| c == 'o' || c == 'u';
//     }
// };

// Time Limit Exceeded
// 103 / 107 testcases passed
// submitted at Oct 09, 2024 20:18

class Solution {
public:
    int maxVowels(string s, int k) {
        int temp = 0, res = 0, ptrL = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                temp++;
            }

            if(i - ptrL + 1 > k){
                if(isVowel(s[ptrL])){
                    temp--;
                }
                ptrL++;
            }
            res = max(temp, res);
        } 
        return res;
    }

    bool isVowel(char c){
        return c == 'a' || c == 'e'|| c == 'i'|| c == 'o' || c == 'u';
    }
};

int main(){
    //string s = "aeiou";
    string s = "abciiidef";
    int k = 3;
    Solution sol;
    int result = sol.maxVowels(s, k);
    cout << result;
    return 0;
}