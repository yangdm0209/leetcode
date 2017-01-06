// Source : https://leetcode.com/problems/3sum/
// Author : daming
// Date   : 2017-01-06

/*************************************************************************************** 
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c 
 * = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 * 
 ***************************************************************************************/

ass Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++){
            int target = -nums[i];
            int smaller = i + 1;
            int bigger = len -  1;
            while (smaller < bigger){
                int sum = nums[smaller] + nums[bigger];
                if (target == sum){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[smaller]);
                    temp.push_back(nums[bigger]);
                    res.push_back(temp);
                    
                    // ignore duplicates number 2
                    while (smaller < bigger && nums[smaller] == temp[1])
                        smaller++;
                    // ignore duplicates number 3
                    while (smaller < bigger && nums[bigger] == temp[2])
                        bigger--;
                }
                else if (target > sum) smaller++;
                else bigger--;
            }
            // ignore duplicates number 1
            while (i + 1 < len && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};
