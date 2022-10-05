//Hacktoberfest 2022

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/


class Solution {
public:
   void dfs(TreeNode* root, vector<int>& ans){
        if(!root) return;
        
		//Inorder (between left, right traversal)
        if(root->left) dfs(root->left, ans);
		ans.push_back(root->val);
        if(root->right) dfs(root->right, ans);
		
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        dfs(root, ans);
        return ans;
    }
};


/*
Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
*/
