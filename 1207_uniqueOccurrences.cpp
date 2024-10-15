class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> umap; // Map to store frequency of each element in arr
        set<int> frequency; // Set to store unique frequencies

        // Count the frequency of each element in arr
        for(int i = 0; i < arr.size(); ++i){
            umap[arr[i]]++;
        }
        // Example: arr = [1,2,2,1,1,3] -> umap = {{1, 3}, {2, 2}, {3, 1}}

        // Check if all frequencies are unique
        for(auto it : umap){
            // Check if the frequency already exists in the set
            if(frequency.find(it.second) != frequency.end()){
                // If the frequency already exists, it means the occurrences are not unique
                // frequency.find(value) searches the set for the given value.
                //If the value is found, it returns an iterator pointing to that element.
                //If the value is not found, it returns frequency.end(), which is a special iterator indicating the end of the set.
                return false; // Return false since we found a duplicate frequency
            } 
            frequency.insert(it.second); // Insert frequency into set
        }

        return true; // All frequencies are unique
    }
};
/*
The variable it is actually an instance of std::pair<const int, int> because umap is an unordered_map<int, int>. Each element in an unordered map is stored as a key-value pair, where the key is of type int and the value is also of type int. Therefore, it represents a pair consisting of key and value.

For std::pair, you can access:

it.first which gives you the key.
it.second which gives you the value (in this case, the frequency of the element).
*/