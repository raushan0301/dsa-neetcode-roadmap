// Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.


// brute force approach o(n^2)
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    return true;
                }
            }
        }return false;
    }
};

// optimal unordered set approach  hashing 0(n)
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_set<int> seen;
       for(int i=0; i<nums.size(); i++){
        if(seen.count(nums[i]))return true;
        seen.insert(nums[i]);
       }
    return false;
    }
};