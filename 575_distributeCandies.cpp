#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
   int distributeCandies(vector<int>& candyType) {
       unordered_set<int> myunordered_set(candyType.begin(), candyType.end());
       int rawN = candyType.size();
       int unorderedN = myunordered_set.size();
       return min(rawN / 2, unorderedN);

       /*
       if(rawN / 2 > unorderedN){
           return unorderedN;
       }
       else{
           return rawN / 2;
       }
       */
   }
};