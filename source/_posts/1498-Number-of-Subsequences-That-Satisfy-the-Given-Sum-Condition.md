---
title: 1498. Number of Subsequences That Satisfy the Given Sum Condition
categories: Leetcode
date: 2025-02-22 16:19:06
tags:
    - Array
    - Two Pointers
    - Binary Search
    - Sorting
---

[1498. Number of Subsequences That Satisfy the Given Sum Condition](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given an array of integers `nums` and an integer `target`.

Return the number of **non-empty**  subsequences of `nums` such that the sum of the minimum and maximum element on it is less or equal to `target`. Since the answer may be too large, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
```

**Example 2:**

```bash
Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
```

**Example 3:**

```bash
Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^6`
- `1 <= target <= 10^6`

## Hints/Notes

- 2025/02/15
- two pointers
- [Leetcode solution](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> exp(n, 1);
        for (int i = 1; i < n; i++) {
            exp[i] = (long)exp[i - 1] * 2 % MOD;
        }
        ranges::sort(nums);
        int left = 0, right = nums.size() - 1, res = 0;
        for (int i = 0; i <= right; i++) {
            while (right >= i && nums[i] + nums[right] > target) {
                right--;
            }
            if (right < i) {
                break;
            }
            res = (long(res) + exp[right - i]) % MOD;
        }
        return res;
    }
};
```
