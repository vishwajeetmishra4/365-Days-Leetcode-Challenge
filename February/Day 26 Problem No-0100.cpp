// Day 26 of 365 Days Coding Challange.(2nd Month)

// Problem Number-100-Same Tree.

// Code Goes From Here.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        } else {
            return p->val == q->val &&
                   isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        }
    }
};
