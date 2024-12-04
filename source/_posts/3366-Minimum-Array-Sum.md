---
title: 3366. Minimum Array Sum
categories: Leetcode
date: 2024-12-03 21:28:18
tags:
    - Array
    - Dynamic Programming
---

[3366. Minimum Array Sum](https://leetcode.com/problems/minimum-array-sum/description/)

## Description

You are given an integer array `nums` and three integers `k`, `op1`, and `op2`.

You can perform the following operations on `nums`:

- **Operation 1** : Choose an index `i` and divide `nums[i]` by 2, **rounding up**  to the nearest whole number. You can perform this operation at most `op1` times, and not more than **once**  per index.
- **Operation 2** : Choose an index `i` and subtract `k` from `nums[i]`, but only if `nums[i]` is greater than or equal to `k`. You can perform this operation at most `op2` times, and not more than **once**  per index.

**Note:**  Both operations can be applied to the same index, but at most once each.

Return the **minimum**  possible **sum**  of all elements in `nums` after performing any number of operations.

**Example 1:**

```bash
Input: nums = [2,8,3,19,3], k = 3, op1 = 1, op2 = 1

Output: 23
```

Explanation:

- Apply Operation 2 to `nums[1] = 8`, making `nums[1] = 5`.
- Apply Operation 1 to `nums[3] = 19`, making `nums[3] = 10`.
- The resulting array becomes `[2, 5, 3, 10, 3]`, which has the minimum possible sum of 23 after applying the operations.

**Example 2:**

```bash
Input: nums = [2,4,3], k = 3, op1 = 2, op2 = 1

Output: 3
```

Explanation:

- Apply Operation 1 to `nums[0] = 2`, making `nums[0] = 1`.
- Apply Operation 1 to `nums[1] = 4`, making `nums[1] = 2`.
- Apply Operation 2 to `nums[2] = 3`, making `nums[2] = 0`.
- The resulting array becomes `[1, 2, 0]`, which has the minimum possible sum of 3 after applying the operations.

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 10^5`
- `0 <= k <= 10^5`
- `0 <= op1, op2 <= nums.length`

## Hints/Notes

- 2024/12/04
- [0x3F's solution](https://leetcode.cn/problems/minimum-array-sum/solutions/2998867/jiao-ni-yi-bu-bu-si-kao-dpcong-ji-yi-hua-0pc5/)
- Weekly Contest 425

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<vector<int>>> dp;
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        dp.resize(n, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        int res = dfs(0, nums, k, op1, op2);
        return res;
    }

    int dfs(int index, vector<int>& nums, int k, int op1, int op2) {
        if (index == nums.size()) {
            return 0;
        }
        if (dp[index][op1][op2] != -1) {
            return dp[index][op1][op2];
        }
        int res = dfs(index + 1, nums, k, op1, op2) + nums[index];
        if (nums[index] >= 2 * k - 1) {
            if (op1) {
                res = min(res, dfs(index + 1, nums, k, op1 - 1, op2) + (nums[index] + 1) / 2);
            }
            if (op2) {
                res = min(res, dfs(index + 1, nums, k, op1, op2 - 1) + nums[index] - k);
            }
            if (op1 && op2) {
                res = min(res, dfs(index + 1, nums, k, op1 - 1, op2 - 1) + (nums[index] + 1) / 2 - k);
            }
        } else if (nums[index] >= k) {
            if (op1) {
                res = min(res, dfs(index + 1, nums, k, op1 - 1, op2) + (nums[index] + 1) / 2);
            }
            if (op2) {
                res = min(res, dfs(index + 1, nums, k, op1, op2 - 1) + nums[index] - k);
            }
            if (op1 && op2) {
                res = min(res, dfs(index + 1, nums, k, op1 - 1, op2 - 1) + (nums[index] - k + 1) / 2);
            }
        } else {
            if (op1) {
                res = min(res, dfs(index + 1, nums, k, op1 - 1, op2) + (nums[index] + 1) / 2);
            }
        }
        dp[index][op1][op2] = res;
        return res;
    }
};
```
