# DSA_QUE
class Solution {
public:
    void permutehelper(vector<int>& nums,int i,vector<vector<int>> &result){
        //base case 
        if(i>=nums.size()){
            result.push_back(nums);
            return;
        }

        //swapping
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);

            //rec call
            permutehelper(nums,i+1,result);

            //back tracking
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutehelper(nums,0,result);
        return result;
    }
};
