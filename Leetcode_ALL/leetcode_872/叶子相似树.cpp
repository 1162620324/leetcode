#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<int> getLeaf(TreeNode* root){
    vector<int> res;
    if(!root) return res;

    stack<TreeNode*> st;
    while(root || !st.empty()){
        while(root){
            st.push(root);
            if(!root->left && !root->right) res.push_back(root->val);
            root = root -> left;
        }
        root = st.top(); st.pop();
        root = root -> right;
    }
    return res;
}

bool leafSimilar(TreeNode* root1, TreeNode* root2){
    vector<int> leaf1 = getLeaf(root1);
    vector<int> leaf2 = getLeaf(root2);

    if(leaf1.size() != leaf2.size()) return false;
    for(int i = 0; i < leaf1.size(); i ++){
        if(leaf1[i] != leaf2[i]) return false;
    }
    return true;
}

int main(){

}