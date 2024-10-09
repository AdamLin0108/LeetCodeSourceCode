class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s = 0;
        double avg = 0;
        double sum = 0;
        vector<double> result;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            // when i met index k means i is in the end of the window
            // so calculate the avg 
            if(i >= k - 1){
                avg = sum / k;
                result.push_back(avg);
                
                // Substrate the first of value in window
                sum -= nums[s];
                // move the start value to next
                s++;
            }
            
        }

        // max_element returns an iterator pointing to the largest element in the container
        //(e.g., a std::vector), not the value itself.
        // * is used to access the value pointed to by a pointer or an iterator
        return *max_element(result.begin(), result.end());
    }
};