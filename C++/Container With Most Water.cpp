#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        long long maxarea = 0;

        // Use two pointers, left starting from the beginning, right from the end
        while (left < right) {
            // Calculate the area between the two lines using the smaller height
            long long area = min(height[left], height[right]) * (right - left);
            maxarea = max(area, maxarea);

            // Move the pointer pointing to the shorter line towards the center
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxarea;
    }
};

int main() {
    Solution solution;
    vector<int> heights;

    int n, input;
    
    // Input the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;
    
    // Input the heights of the containers
    cout << "Enter the heights: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        heights.push_back(input);
    }

    // Calculate the maximum area that can be contained
    int result = solution.maxArea(heights);

    // Output the result
    cout << "Maximum area: " << result << endl;

    return 0;
}
