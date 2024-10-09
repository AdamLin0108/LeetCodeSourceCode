class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int ptrL = 0;
        int ptrR = height.size() - 1;
        int maxArea = 0;
        int curArea = 0;
        int width = ptrR - ptrL;
        int minValue = 0;

        while (ptrL < ptrR) {
            minValue = std::min(height[ptrL], height[ptrR]);
            width = ptrR - ptrL;

            if (height[ptrL] <= height[ptrR]) {
                //ptrL shorter than ptrR
                curArea = minValue * width;
                ptrL++;
            }
            else {
                curArea = minValue * width;
                ptrR--;
            }

            if (curArea >= maxArea) {
                maxArea = curArea;
            }

        }

        return maxArea;
    }
};