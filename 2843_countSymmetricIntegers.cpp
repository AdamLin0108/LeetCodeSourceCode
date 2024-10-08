#include <iostream>
#include <string>
#include <list>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        list<int> container;
        int left;
        int right;

        for (int i = low; i <= high; i++) {
            left = 0;
            right = 0;
            string s = to_string(i);
            int size = s.size();
            int index = size / 2;

            if (size % 2 != 0)
                continue;

            for (int a = 0; a < size; ++a) {
                if (a < index)
                    left += stoi(string(1, s[a]));
                else
                    right += stoi(string(1, s[a]));
            }

            if (left == right) {
                container.push_back(i);
            }
        }
        return container.size();
    }
};

