#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        size_t position = str1.find(str2);
		int lenStr1 = str1.length();
		int lenStr2 = str2.length();
		int pos;

        if(position == string::npos){
            return "";
        }
        else{
			pos = __gcd(lenStr1, lenStr2);
			return str1.substr(position, pos);
        }
    }
};
