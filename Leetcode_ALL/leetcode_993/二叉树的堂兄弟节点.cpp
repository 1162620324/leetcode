#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool getDepth(TreeNode* root, int x, int& dx)
{
    if (root -> val == x) return true;
    else 
    {
        if(root->left && getDepth(root->left, x, dx))
        {
            dx ++;
            return true;
        }
        else if(root->right && getDepth(root->right, x, dx))
        {
            dx ++;
            return true;
        }
    }
}

bool isSibling(TreeNode* root, int x, int y)
{
    if(!root->left && !root->right) return false;
    if(root->left && root->right)
        if((root->right->val == x && root->left->val == y)
            || (root->left->val == x && root->right->val == y))
            return true;
    bool flag1 = false, flag2 = false;
    if(root->left) flag1 = isSibling(root->left, x, y);
    if(root->right) flag2 = isSibling(root->right,x, y);
    return flag1 || flag2;
}

bool isCousins(TreeNode * root, int x, int y)
{
    int dx = 0, dy = 0;
    getDepth(root, x, dx);
    getDepth(root, y, dy);
    if (!isSibling(root, x, y) && dx == dy) return true;
    else return false;
}

int main()
{

}