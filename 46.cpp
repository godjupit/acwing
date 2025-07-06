#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
     
        int path[100];
        int n;
        bool st[100];
        vector<vector<int>> ans;
    
    void dfs(vector<int> &nums, int num){
            
            if(num == nums.size()){
                vector<int> a;
                for(int i = 0; i < nums.size(); i++){
                    a.push_back(path[i]);
                }
                ans.push_back(a);  
            }
    
            for(int i = 0; i < nums.size(); i++){
                if(!st[i]){
                    path[num] = nums[i];
                    st[i] = true;
                    dfs(nums,num+1);
                    st[i] = false;
                }
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            int size  = nums.size();
            dfs(nums,0);
            return ans;
    
        }
    };