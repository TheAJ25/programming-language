#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    
private:
    // Helper function to check if the string has any duplicate characters
    bool freq(string str) {
        int count[26] = {0};
        for (auto i : str) {
            count[i - 'a']++;
            // If any character appears more than once, return true
            if (count[i - 'a'] > 1) {
                return true;
            }
        }
        return false;
    }

public:
    bool buddyStrings(string s, string goal) {
        // If lengths of the two strings are not the same, return false
        if (s.length() != goal.length()) {
            return false;
        }

        // Case 1: If the strings are equal, check if there's any duplicate character
        if (s == goal) {
            // If any character is repeated, we can swap two of them and the string will remain the same
            if (freq(s)) {
                return true;
            }
            return false;
        }

        // Case 2: When the strings are different, find all the positions where they differ
        vector<int> vec;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                vec.push_back(i);
            }
        }

        // If the number of differences is not exactly 2, return false
        if (vec.size() != 2) {
            return false;
        }

        // Swap the two differing characters and check if they match
        swap(s[vec[0]], s[vec[1]]);
        
        // If after swapping, the strings become equal, return true
        if (s == goal) {
            return true;
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    
    string s, goal;
    
    // Input strings s and goal
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string goal: ";
    cin >> goal;
    
    // Check if s and goal are buddy strings
    bool result = solution.buddyStrings(s, goal);
    
    // Output the result
    if (result) {
        cout << "The strings are buddy strings." << endl;
    } else {
        cout << "The strings are not buddy strings." << endl;
    }

    return 0;
}
