#include <iostream> 
#include <stack>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
		string result;
		
		for(char c : s){
			if(!st.empty() && c == '*'){
				st.pop();
			} else {
				st.push(c);
			}
		}
		
		int n = st.size();
		// Reverse
		for(int i = 0; i < n; ++i){
			if(!st.empty()) {
				result.push_back(st.top());
				st.pop();
			} else {
				result = "";
			}
		}

		reverse(result.begin(), result.end());
		return result;
    }
};

int main()
{
    Solution sol;
	// string s = "leet**cod*e"; //"lecoe"
	string s = "erase*****";
	string result = sol.removeStars(s);
	cout << result << endl;
}