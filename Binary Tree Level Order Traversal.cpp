#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        // If the root is NULL, return an empty result
        if (root == NULL) {
            return ans;
        }
        
        // Use a queue to perform BFS
        queue<TreeNode*> q;
        q.push(root);

        // Loop until the queue is empty
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Push left child to the queue
                if (node->left != NULL) {
                    q.push(node->left);
                }
                
                // Push right child to the queue
                if (node->right != NULL) {
                    q.push(node->right);
                }
                
                // Add the current node's value to the level list
                level.push_back(node->val);
            }
            
            // Add the current level to the result
            ans.push_back(level);
        }
        
        return ans;
    }
};

// Helper function to insert nodes in the binary tree
TreeNode* insertLevelOrder(vector<int>& arr, int i, int n) {
    TreeNode* root = nullptr;
    if (i < n && arr[i] != -1) {
        root = new TreeNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

// Helper function to print the level order traversal
void printLevelOrder(vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    // Input array representation of the binary tree (-1 represents NULL node)
    vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};
    
    // Create the binary tree from the input array
    TreeNode* root = insertLevelOrder(nodes, 0, nodes.size());

    // Get the level order traversal result
    vector<vector<int>> result = solution.levelOrder(root);

    // Output the level order traversal
    cout << "Level Order Traversal:" << endl;
    printLevelOrder(result);

    return 0;
}
