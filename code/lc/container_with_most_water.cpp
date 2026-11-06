/*

Notice that you may not slant the container. 
Create a constraint that the height of the container is bounded by min valeu of the choosen values

Find two points: indicate possible use of two pointers

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_volume = 0;
        size_t l=0;
        size_t r=height.size()-1;

        while (l<r) {
            int x_factor = r-l;
            int y_factor = min(height[l], height[r]);
            max_volume = max(max_volume, x_factor*y_factor);

            height[l] > height[r] ? --r : ++l;
        }

        return max_volume;
    }
};
