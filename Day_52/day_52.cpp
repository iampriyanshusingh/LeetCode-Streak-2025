// Assuming TreeNode is already defined elsewhere in the project, no need to redefine it
class FindElements {
    private:
        unordered_set<int> recovered_values;  // Set to store recovered node values.
    
        // Helper function to recover the tree
        void recover(TreeNode* node, int val) {
            if (!node) return;
            node->val = val;  // Recover current node's value
            
            // Add the value to the set
            recovered_values.insert(val);
            
            // Recursively recover left and right children
            if (node->left) recover(node->left, 2 * val + 1);  // Left child
            if (node->right) recover(node->right, 2 * val + 2);  // Right child
        }
    
    public:
        // Constructor that recovers the tree from the contaminated root
        FindElements(TreeNode* root) {
            if (root) {
                root->val = 0;  // The root value is always 0 after recovery
                recover(root, 0);
            }
        }
        
        // Method to find if a target value exists in the recovered tree
        bool find(int target) {
            return recovered_values.count(target) > 0;
        }
    };