class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int planted = 0;
        // Use the case could be [0,0,0] n=2
        // Add zeros to the beginning and end of the flowerbed to simplify boundary conditions
        // This helps handle edge cases uniformly without extra checks for the first and last elements
		flowerbed.insert(flowerbed.begin(), 0);
		flowerbed.push_back(0);
		
        // Iterate through the flowerbed to check where flowers can be planted
		for(int i = 1; i < flowerbed.size()-1; ++i){
            // If the current spot and its neighbors are empty, plant a flower here
            // We check flowerbed[i-1], flowerbed[i], and flowerbed[i+1] to ensure it's safe to plant
			if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
				n--;
			}
		}
		if(planted < n){
			return false;
		} else{
			return true;
		}
    }
};