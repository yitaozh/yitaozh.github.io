---
title: 3152. Special Array II
categories: Leetcode
date: 2024-05-23 11:39:03
tags:
    - Array
    - Binary Search
    - Prefix Sum
---

[3152. Special Array II](https://leetcode.com/problems/special-array-ii/description/)

An array is considered **special**  if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer `nums` and a 2D integer matrix `queries`, where for queries[i] = [from<sub>i</sub>, to<sub>i</sub>] your task is to check that subarray nums[from<sub>i</sub>..to<sub>i</sub>] is **special**  or not.

Return an array of booleans `answer` such that `answer[i]` is `true` if nums[from<sub>i</sub>..to<sub>i</sub>] is special.

**Example 1:**

```bash
Input: nums = [3,4,1,2,6], queries = [[0,4]]

Output: [false]

Explanation:

The subarray is `[3,4,1,2,6]`. 2 and 6 are both even.
```

**Example 2:**

```bash
Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]

Output: [false,true]

Explanation:

- The subarray is `[4,3,1]`. 3 and 1 are both odd. So the answer to this query is `false`.
- The subarray is `[1,6]`. There is only one pair: `(1,6)` and it contains numbers with different parity. So the answer to this query is `true`.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
- `1 <= queries.length <= 10^5`
- `queries[i].length == 2`
- `0 <= queries[i][0] <= queries[i][1] <= nums.length - 1`

## Hints/Notes

- Weekly contest 398

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<int> preSum(nums.size(), 0);
        for (int i = 0; i < nums.size() - 1; i++) {
            if ((nums[i] % 2) ^ (nums[i + 1] % 2)) {
                preSum[i + 1] = preSum[i];
            } else {
                preSum[i + 1] = preSum[i] + 1;
            }
        }
        vector<bool> res;
        for (auto query : queries) {
            int from = query[0];
            int to = query[1];
            if (from == to) {
                res.push_back(true);
                continue;
            }
            if (preSum[to] > preSum[from]) {
                res.push_back(false);
            } else {
                res.push_back(true);
            }
        }
        return res;
    }
};
```
