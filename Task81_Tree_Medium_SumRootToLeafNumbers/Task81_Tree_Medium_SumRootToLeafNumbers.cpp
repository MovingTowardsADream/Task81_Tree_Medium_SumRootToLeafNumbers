/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        MovingTree(root, 0);
        return sum;
    }
    void MovingTree(TreeNode* node, int count) {
        if (node == nullptr) return;
        count = count * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            sum += count;
        }
        MovingTree(node->left, count);
        count /= 10;
        count = count * 10 + node->val;
        MovingTree(node->right, count);
    }
};