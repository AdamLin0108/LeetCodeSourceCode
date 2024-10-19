#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for(auto var : asteroids){
            bool explode = false;
            // A collision can occur only when a left-moving asteroid (var < 0) meets a right-moving asteroid (stk.top() > 0).
            while(!stk.empty() && var < 0 && stk.top() > 0){
                if(stk.top() < -var){
                    stk.pop();
                    continue;
                } else if(stk.top() == -var){
                    stk.pop();
                    explode = true;
                    break;
                } else {
                    explode = true;
                    break;
                }
            }
            if(!explode){
                stk.push(var);
            }
        }
        
        vector<int> res(stk.size());
        for(int i = stk.size()-1; i >= 0; --i){
            res[i] = stk.top();
            stk.pop();
        }
        return res;
    }
};


int main(){
    Solution sol;
    vector<int> asteroids = {-2,-1,1,2};
    sol.asteroidCollision(asteroids);
    return 0;
}

/*
stk.top() < -var:
Explanation: The right-moving asteroid on the stack is smaller than the left-moving asteroid (|stk.top()| < |var|).
Action: The right-moving asteroid is destroyed (stk.pop()).
continue;: Loop continues to check for further possible collisions with other right-moving asteroids on the stack.
stk.top() == -var:
Explanation: Both asteroids are of equal size (|stk.top()| == |var|).
Action: Both asteroids are destroyed.
stk.pop();: Remove the right-moving asteroid from the stack.
destroyed = true;: Mark the current left-moving asteroid as destroyed.
break;: Exit the while loop since the current asteroid is destroyed.
else:
Explanation: The right-moving asteroid on the stack is larger than the left-moving asteroid (|stk.top()| > |var|).
Action: The left-moving asteroid is destroyed (destroyed = true;).
break;: Exit the while loop since the current asteroid is destroyed.
*/