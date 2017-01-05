// Source : https://leetcode.com/problems/two-sum
// Author : daming
// Date   : 2017-01-05

/*************************************************************************************** 
 *
 * Given an array of integers, return indices of the two numbers such that they add up 
 * to a specific target.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * UPDATE (2016/2/13):
 * The return format had been changed to zero-based indices. Please read the above 
 * updated description carefully.
 * 
 ***************************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dump;
        vector<int> ret;
        for (int i=0; i < nums.size(); i++) {
            if (dump.find(target - nums[i]) != dump.end()) {
                ret.push_back(dump[target - nums[i]]);
                ret.push_back(i);
                break;
            }else {
                dump[nums[i]] = i;
            }
        }
        return ret;
    }
};
