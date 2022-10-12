#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int value)
    {
        key = value;
        left = right = NULL;
    }
};

int widthOfBinaryTree(TreeNode *root)
{
    if(root == NULL)
        return 0;
    int w = 0;
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty())
    {
        int cnt = q.size();
        w = max(w,cnt);
        for(int i = 0; i < cnt; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
    return w;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(10);
    root->right = new TreeNode(15);
    root->left->right = new TreeNode(20);
    root->left->right->right= new TreeNode(30);

    cout << widthOfBinaryTree(root) << '\n';

    return 0;
}
