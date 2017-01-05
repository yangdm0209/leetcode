// Source : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author : daming
// Date   : 2017-01-05

/*************************************************************************************** 
 *
 * Given an array of integers that is already sorted in ascending order, find two 
 * numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up 
 * to the target, where index1 must be less than index2. Please note that your returned 
 * answers (both index1 and index2) are not zero-based.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 * 
 ***************************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int bigger = numbers.size() - 1;
        int smaller = 0;
        int temp;
        vector<int> ret;
        while (smaller < bigger) {
            temp = numbers[smaller] + numbers[bigger];
            if (temp == target) {
                ret.push_back(smaller+1);
                ret.push_back(bigger+1);
                break;
            } else if (temp > target) {
                bigger--;
            } else {
                smaller++;
            }
        }
        return ret;
    }
	
	/*************************************************************************************** 
	* Fix the first element A[0] and do binary search on the remaining n-1 elements. 
	* If cannot find any element which equals target-A[0], Try A[1]. That is, fix A[1] and 
	* do binary search on A[2]~A[n-1]. Continue this process until we have the last two elements 
	*
	* Does this gives a time complexity lg(n-1) + lg(n-2) + ... + lg(1) ~ O(lg(n!)) ~ O(nlgn). 
	* So it is less efficient than the O(n) solution
	***************************************************************************************/
	vector<int> twoSumII(vector<int> &numbers, int target) {
    if(numbers.empty()) return {};
    for(int i=0; i<numbers.size()-1; i++) {
        int start=i+1;
		int end=numbers.size()-1;
		int gap=target-numbers[i];
        while(start <= end) {
            int m = start+(end-start)/2;
            if(numbers[m] == gap) return {i+1,m+1};
            else if(numbers[m] > gap) end=m-1;
            else start=m+1;
        }
    }
}
};
