#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        
        // If the length of palindrome is 1, it is impossible to break it
        if (n == 1) {
            return "";
        }
        
        // Traverse the first half of the string
        for (int i = 0; i < n / 2; i++) {
            // Replace the first non-'a' character with 'a'
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        // If all characters in the first half are 'a', change the last character to 'b'
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};

int main() {
    Solution solution;
    string input;
    
    // Input palindrome string
    cout << "Enter a palindrome: ";
    cin >> input;
    
    // Get the result after breaking the palindrome
    string result = solution.breakPalindrome(input);
    
    // Output the result
    if (result.empty()) {
        cout << "It's impossible to break the palindrome.\n";
    } else {
        cout << "Modified palindrome: " << result << endl;
    }
    
    return 0;
}
