// Day 27 of 365 Days Coding Challange.(2nd Month).

// Problem Number - 543- Diameter of Binary Tree.

// Code Goes From Here.

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        calculateDiameter(root, maxDiameter);
        return maxDiameter;
    }

private:
    int calculateDiameter(TreeNode* root, int& maxDiameter) {
        if (root == nullptr)
            return 0;

        int leftDepth = calculateDiameter(root->left, maxDiameter);
        int rightDepth = calculateDiameter(root->right, maxDiameter);

        maxDiameter = max(maxDiameter, leftDepth + rightDepth);

        return 1 + max(leftDepth, rightDepth);
    }
};
