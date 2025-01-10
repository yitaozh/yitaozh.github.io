---
title: 3397. Maximum Number of Distinct Elements After Operations
categories: Leetcode
date: 2025-01-10 01:08:08
tags:
    - Array
    - Greedy
    - Sorting
---

[3397. Maximum Number of Distinct Elements After Operations](https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/)

## Description

You are given an integer array `nums` and an integer `k`.

You are allowed to perform the following **operation**  on each element of the array **at most**  once:

- Add an integer in the range `[-k, k]` to the element.

Return the **maximum**  possible number of **distinct**  elements in `nums` after performing the **operations** .

**Example 1:**

```bash
Input: nums = [1,2,2,3,3,4], k = 2

Output: 6
```

Explanation:

`nums` changes to `[-1, 0, 1, 2, 3, 4]` after performing operations on the first four elements.

**Example 2:**

```bash
Input: nums = [4,4,4,4], k = 1

Output: 3
```

Explanation:

By adding -1 to `nums[0]` and 1 to `nums[1]`, `nums` changes to `[3, 5, 4, 4]`.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `0 <= k <= 10^9`

## Hints/Notes

- 2025/01/10
- sorting
- [0x3F's solution](https://leetcode.cn/problems/maximum-number-of-distinct-elements-after-operations/solutions/3027034/cong-xiao-dao-da-tan-xin-pythonjavacgo-b-n023/)(checked)
- Weekly Contest 429

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        unordered_set<int> count;
        ranges::sort(nums);
        int n = nums.size(), prev = INT_MIN;
        for (int i = 0; i < n; i++) {
            int min_val = nums[i] - k, max_val = nums[i] + k;
            for (int j = max(min_val, prev); j <= max_val; j++) {
                if (!count.contains(j)) {
                    count.insert(j);
                    prev = j + 1;
                    break;
                }
            }
        }
        return count.size();
    }
};
```
