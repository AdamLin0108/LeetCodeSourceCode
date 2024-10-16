class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Create frequency maps for both strings
        unordered_map<char, int> freq1, freq2;
        // Create sets to hold unique characters from both strings
        unordered_set<char> set1, set2;
        // Vectors to store frequency counts of characters
        vector<int> freqValue1, freqValue2;

        // If the lengths of the strings are different, they can't be close
        if(word1.size() != word2.size()) return false;

        // Fill frequency map and unique character set for word1
        for(char c : word1) {
            freq1[c]++;         // Count frequency of each character
            set1.insert(c);      // Insert unique characters into the set
        }

        // Fill frequency map and unique character set for word2
        for(char c : word2) {
            freq2[c]++;         // Count frequency of each character
            set2.insert(c);      // Insert unique characters into the set
        }

        // If the sets of unique characters are not the same, return false
        if(set1 != set2) return false;

        // Extract the frequency counts from the frequency maps of word1
        for(auto& it : freq1) {
            freqValue1.push_back(it.second);   // Store frequency of each character
        }
        
        // Extract the frequency counts from the frequency maps of word2
        for(auto& it : freq2) {
            freqValue2.push_back(it.second);   // Store frequency of each character
        }

        // Sort both frequency vectors to compare them
        sort(freqValue1.begin(), freqValue1.end());
        sort(freqValue2.begin(), freqValue2.end());

        // Return true if sorted frequency values are the same, false otherwise
        return freqValue1 == freqValue2;
    }
};


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // If the lengths of the strings are different, return false early
        if (word1.size() != word2.size()) return false;
        
        // Arrays to store frequency of each character (26 letters)
        int freq1[26] = {0}, freq2[26] = {0};
        // Boolean arrays to store presence of characters in the strings
        bool set1[26] = {0}, set2[26] = {0};

        // Fill frequency and presence arrays for word1
        for (char c : word1) {
            freq1[c - 'a']++;    // Increment the frequency of character
            set1[c - 'a'] = true; // Mark character as present
        }

        // Fill frequency and presence arrays for word2
        for (char c : word2) {
            freq2[c - 'a']++;    // Increment the frequency of character
            set2[c - 'a'] = true; // Mark character as present
        }

        // If the unique characters (presence arrays) don't match, return false
        for (int i = 0; i < 26; i++) {
            if (set1[i] != set2[i]) return false;
        }

        // Sort frequency arrays to check if the frequency distributions match
        sort(freq1, freq1 + 26);
        sort(freq2, freq2 + 26);

        // Check if the sorted frequency arrays are the same
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) return false;
        }

        // If all checks passed, the strings are close
        return true;
    }
};
/*
Time Complexity:
Filling the frequency and presence arrays: O(n), where n is the length of the strings.
Sorting the frequency arrays: O(26 log 26), which is constant time due to the fixed size of the arrays.
Comparing the arrays: O(26), which is constant time.
Overall, the time complexity is O(n), where n is the length of the input strings.

Space Complexity:
We only use fixed-size arrays (of size 26), so the space complexity is O(1) (constant space).
*/