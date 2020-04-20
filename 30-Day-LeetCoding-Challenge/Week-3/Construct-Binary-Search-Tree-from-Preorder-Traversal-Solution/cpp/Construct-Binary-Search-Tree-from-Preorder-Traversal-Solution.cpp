class Solution {
public:
    TreeNode* construct(int pl, int pr, int il, int ir, vector<int>& preorder, vector<int>& inorder){
        TreeNode* root = new TreeNode(preorder[pl]);
        if (pl == pr) return root;
        
        int pos = -1;
        for (int i = il; i <= ir; i++)
            if (inorder[i] == preorder[pl]){
                pos = i;
                break;
            }
        
        int len = pos - il;
        if (len > 0)
            root->left = construct(pl+1, pl + len, il, pos-1, preorder, inorder);
        
        int len2 = ir - pos;
        if (len2 > 0)
            root->right = construct(pl + len + 1, pl + len + len2, pos+1, ir, preorder, inorder);
            
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        for (auto t: preorder) inorder.push_back(t);
        sort(inorder.begin(), inorder.end());
        int n = preorder.size();
        return construct(0, n-1, 0, n-1, preorder, inorder);
    }
};