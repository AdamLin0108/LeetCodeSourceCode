#include <stack>
#include <string>

class Solution {
public:
   bool isValid(std::string s) {
	    std::stack<char> container;
       for (int i = 0; i < s.length(); ++i)
       {
           if (s[i] == '(' || s[i] == '{' || s[i] == '[')
           {
               container.push(s[i]);
           }
           else if (s[i] == ')')
           {
               if (i == 0 || container.empty() || container.top() != '(')
               {
                   return false;
               }
               container.pop();
           }
           else if (s[i] == '}')
           {
               if (i == 0 || container.empty() || container.top() != '{')
               {
                   return false;
               }
               container.pop();
           }
           else if (s[i] == ']')
           {
               if (i == 0 || container.empty() || container.top() != '[')
               {
                   return false;
               }
               container.pop();
           }

       }
       return container.empty();
   }
};
