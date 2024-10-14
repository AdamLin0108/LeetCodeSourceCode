// This function takes two integer arrays, nums1 and nums2, and returns two lists:
// The first list contains elements present in nums1 but not in nums2,
// and the second list contains elements present in nums2 but not in nums1.
// It uses unordered sets to quickly determine the unique elements in each list
// and to efficiently check the presence of elements in the other list.
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> unorderNums1(nums1.begin(), nums1.end());  // Store unique elements of nums1
        unordered_set<int> unorderNums2(nums2.begin(), nums2.end());  // Store unique elements of nums2
        vector<vector<int>> result(2);  // Initialize result vector to store two lists

        // Iterate over nums1 and add elements to result[0] if not found in nums2
        for(int num : unorderNums1){
            if(unorderNums2.find(num) == unorderNums2.end()){
                result[0].push_back(num);
            }
        }

        // Iterate over nums2 and add elements to result[1] if not found in nums1
        for(int num : unorderNums2){
            if(unorderNums1.find(num) == unorderNums1.end()){
                result[1].push_back(num);
            }
        }

        return result;  // Return the result containing both difference lists
    }
};


#include <unordered_set>
#include <vector>
using namespace std;

// This function demonstrates multiple operations with unordered_set
void manipulateSet() {
    unordered_set<int> mySet;
    
    // Insert elements into the unordered_set
    mySet.insert(10);  // Inserts 10
    mySet.insert(20);  // Inserts 20
    
    // Check if an element exists in the set
    if (mySet.find(20) != mySet.end()) {
        // Element 20 exists in the set
    }
    
    // Erase an element from the set
    mySet.erase(10);  // Removes 10 from the set

    // Insert elements using emplace for efficiency (avoids extra copying)
    mySet.emplace(30);  // Adds 30

    /*
    效率：emplace() 避免了不必要的對象創建，而 insert() 可能會創建並拷貝/移動對象。
    適用場景：如果對象已經存在，使用 insert() 會更合適；而當你想要直接在容器內構造對象時，emplace() 是更好的選擇。
    */
    // class MyClass {
    //     public:
    //         MyClass(int x) { /* 構造函數 */ }
    //     };

    //     unordered_set<MyClass> mySet;
    //     // 使用 emplace，直接在集合中構造對象
    //     mySet.emplace(10);

    //     // 使用 insert，創建一個臨時的 MyClass 對象，然後插入其副本
    //     mySet.insert(MyClass(10));
    
    // Bulk insert elements from a vector
    vector<int> nums = {1, 2, 3, 4, 5};
    mySet.insert(nums.begin(), nums.end());  // Inserts elements from nums into the set

    // Count checks if an element is present (returns 1 if present, 0 if absent)
    if (mySet.count(20)) {
        // Element 20 exists
    }

    // Get the size of the set
    size_t setSize = mySet.size();  // Returns the size of the set

    // Iterate through the set
    for (const auto& elem : mySet) {
        // Prints each element in the set
        cout << elem << " ";
    }

    // Clear all elements in the set
    mySet.clear();  // Empties the set
    
    // Swap contents of two unordered_sets
    unordered_set<int> set1 = {1, 2, 3};
    unordered_set<int> set2 = {4, 5, 6};
    set1.swap(set2);  // Swaps elements between set1 and set2
    
}

