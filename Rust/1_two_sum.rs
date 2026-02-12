/*
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/
Difficulty: Easy

Given an array of integers nums and an integer target, return indices of the 
two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may 
not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists.

Time Complexity: O(n)
Space Complexity: O(n)
*/

use std::collections::HashMap;

struct Solution;

impl Solution {
    /// Hash map approach to find two numbers that sum to target.
    /// Store each number and its index as we iterate through the array.
    /// For each number, check if (target - current number) exists in the map.
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut num_map: HashMap<i32, i32> = HashMap::new();
        
        for (i, &num) in nums.iter().enumerate() {
            let complement = target - num;
            if let Some(&idx) = num_map.get(&complement) {
                return vec![idx, i as i32];
            }
            num_map.insert(num, i as i32);
        }
        
        vec![]
    }
}
