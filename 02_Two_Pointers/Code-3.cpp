// 3 Sum
// https://leetcode.com/problems/3sum/

vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin() , nums.end());
       set<vector<int>> ans ;
       for(int i = 0 ; i<nums.size()-2 ; i++){
           int k = nums.size()-1 ;
           int j = i+1 ;
           while(j < k){
               if(nums[i] + nums[j] + nums[k] == 0){
                   ans.insert({nums[i] , nums[j] , nums[k]});
                   k-- ;
                   j++ ;
               }else if(nums[i] + nums[j] + nums[k] > 0){
                   k-- ;
               }else{
                   j++ ;
               }
           }
       } 
       vector<vector<int>> sol ;
       for(auto it : ans){
           sol.push_back(it);
       }
       return sol;
    }