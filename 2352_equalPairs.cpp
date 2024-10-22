class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // Map to store the frequency of each row vector
        map<vector<int>, int> freq;
        int count = 0;          // Initialize the count of equal row-column pairs
        int n = grid.size();    // Get the size of the grid (number of rows/columns)
        
        // Build the frequency map for all row vectors
        for(int i = 0; i < n; ++i){
            vector<int> temp;
            // Collect the elements of the i-th row
            for(int j = 0; j < n; ++j){
                temp.push_back(grid[i][j]);
            }
            // Increment the frequency count for this row vector
            freq[temp]++;
        }

        // Iterate over all columns to find matching row vectors
        for(int i = 0; i < n; ++i){
            vector<int> temp;
            // Collect the elements of the i-th column
            for(int j = 0; j < n; ++j){
                temp.push_back(grid[j][i]);
            }
            // Add the frequency of this column vector if it matches any row vector
            count += freq[temp];
        }
        // Return the total number of equal row and column pairs
        return count;
    }
};

/*
Diagram Explanation:

Let's consider an example grid to visualize how the algorithm works.

Example Grid:

grid = [
    [1, 2, 3],
    [2, 3, 1],
    [3, 1, 2]
]

Visualization:

     C0 C1 C2          Columns
    +---------+
R0  | 1  2  3 |       R0: [1, 2, 3]
R1  | 2  3  1 |       R1: [2, 3, 1]
R2  | 3  1  2 |       R2: [3, 1, 2]
    +---------+

Columns extracted:

- C0: [1, 2, 3]
- C1: [2, 3, 1]
- C2: [3, 1, 2]

Algorithm Steps:

1. **Store Row Frequencies:**

   - For each row in the grid, store its frequency in a map.

