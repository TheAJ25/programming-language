#include <iostream>
using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int operations = 0;

        // Work backwards from target to startValue
        while (target > startValue) {
            // If target is even, we divide by 2
            if (target % 2 == 0) {
                target /= 2;
            } 
            // If target is odd, increment to make it even
            else {
                target += 1;
            }
            operations++;
        }

        // After target <= startValue, just subtract the difference
        operations += (startValue - target);

        return operations;
    }
};

int main() {
    Solution solution;
    
    int startValue, target;
    
    // Input start value and target value
    cout << "Enter start value: ";
    cin >> startValue;
    cout << "Enter target value: ";
    cin >> target;
    
    // Calculate the minimum operations required
    int result = solution.brokenCalc(startValue, target);
    
    // Output the result
    cout << "Minimum operations: " << result << endl;
    
    return 0;
}
