/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // size 会随着队列的变化 因此需要将队列大小先计算出来。
class Solution {
    public:
        int minDepth(TreeNode* root) {
            queue<TreeNode*> node_queue;
            if(!root) return 0;
            node_queue.push(root);
            int ans = 1;
           
            while(!node_queue.empty()){
                int size = node_queue.size();
                for(int i = 0; i < size; i++){
                    auto node = node_queue.front();
                    node_queue.pop();
                    if(!node->left && !node->right){
                        return ans;
                    }else{
                        if(node->left) node_queue.push(node->left);
                        if(node->right) node_queue.push(node->right);
                    }
                    
                }
                ans++;
                
            }
            return ans;
        }
    };