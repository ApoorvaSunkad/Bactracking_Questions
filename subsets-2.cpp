/*
Given an integer array nums that may contain duplicates, return all possible 
subsets(the power set).

The solution set must not contain duplicate subsets. Return the solution 
in any order.


Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//T.C = O(2^N LogN)

void getAllSubsets(vector<int>&nums,vector<int>&res, int i, vector<vector<int>>&allSubsets){
        if(i>=nums.size()){
            allSubsets.push_back(res);
            return;
        }

        res.push_back(nums[i]);

        getAllSubsets(nums,res,i+1,allSubsets);
        res.pop_back();

        int idx = i+1;
        while(idx<nums.size()&&nums[idx]==nums[idx-1]){
            idx++;
        }
        getAllSubsets(nums,res,idx,allSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());//sort

        vector<vector<int>> allSubsets;

        vector<int> res;

        getAllSubsets(nums,res,0,allSubsets);

        return allSubsets;
    }