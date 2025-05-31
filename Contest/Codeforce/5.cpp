#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        queue <TreeNode*> q1;
        queue <TreeNode*> q2;
        q1.push(root1);
        q1.push(root2);
        while(!q1.empty() and !q2.empty()){
            auto node1 = q1.front();
            auto node2 = q2.front();
            q1.pop();
            q2.pop();
            if(node1 == NULL or node2 == NULL){
                if(node1 != node2) return false;
                continue;
            }
            if(node1 -> val != node2 -> val) return false;
            q1.push(node1 -> left);
            q1.push(node1 -> right);

            q2.push(node2 -> left);
            q2.push(node2 -> right);
        }
        return true;
    }
};