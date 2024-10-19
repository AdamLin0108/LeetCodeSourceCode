//https://www.youtube.com/watch?v=qB0zZpBJlh8

class Solution {
public:
    string decodeString(string s) {
        stack<string> stk; // Initialize a stack to store characters, numbers, and intermediate results

        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ']'){
                // If the current character is not ']', push it onto the stack
                stk.push(string(1, s[i]));
            } else {
                // When we encounter a ']', we need to decode the substring inside the brackets
                string substr = "";
                // Pop characters until we find the matching '['
                while(stk.top() != "["){
                    substr = stk.top() + substr; // Build the substring in correct order
                    stk.pop();
                }
                stk.pop(); // Remove the '[' from the stack

                // Now, we need to find the number (could be more than one digit) before the '['
                string k = "";
                while(!stk.empty() && isdigit(stk.top()[0])){
                    k = stk.top() + k; // Build the number in correct order
                    stk.pop();
                }
                int num = stoi(k); // Convert the string number to an integer

                // Repeat the substring 'num' times
                string repeatedStr = "";
                for(int j = 0; j < num; ++j){
                    repeatedStr += substr;
                }
                // Push the repeated substring back onto the stack
                stk.push(repeatedStr);
            }
        }

        // Build the final result from the stack
        string res = "";
        while(!stk.empty()){
            res = stk.top() + res; // Build the result in correct order
            stk.pop();
        }
        return res; // Return the decoded string
    }
};

// Recursive solution 
class Solution {
public:
    int i = 0; // Class member to keep track of index

    string decode(string& s) {
        string result = "";
        int num = 0;
        while (i < s.size()) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                i++;
            } else if (c == '[') {
                i++; // Move past '['
                string decoded = decode(s);
                // Repeat and append
                while (num > 0) {
                    result += decoded;
                    num--;
                }
                num = 0;
            } else if (c == ']') {
                i++; // Move past ']'
                return result;
            } else {
                result += c;
                i++;
            }
        }
        return result;
    }

    string decodeString(string s) {
        i = 0; // Reset index before starting
        return decode(s);
    }
};
/*
decode("3[a2[c]]", 0)
|
+-- decode("3[a2[c]]", 2)
    |
    +-- decode("3[a2[c]]", 5)
    |   - 返回 ("c", 7)
    - 返回 ("acc", 8)
- 返回 ("accaccacc", 8)

*/