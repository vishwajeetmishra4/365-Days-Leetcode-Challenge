// Day 28 of 365 Days coding Challange.(2nd Month)

// Problem Number-513 : Find Bottem Left Tree Value.

// Code Goes From Here.

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int leftmostValue = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            leftmostValue = q.front()->val;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return leftmostValue;
    }
};
