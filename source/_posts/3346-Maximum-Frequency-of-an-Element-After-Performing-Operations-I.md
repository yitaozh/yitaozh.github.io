---
title: 3346. Maximum Frequency of an Element After Performing Operations I
categories: Leetcode
date: 2024-11-21 22:35:24
tags:
    - Array
    - Binary Search
    - Sliding Window
    - Sorting
    - Prefix Sum
---

[3346. Maximum Frequency of an Element After Performing Operations I](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/)

## Description

You are given an integer array `nums` and two integers `k` and `numOperations`.

You must perform an **operation**  `numOperations` times on `nums`, where in each operation you:

- Select an index `i` that was **not**  selected in any previous operations.
- Add an integer in the range `[-k, k]` to `nums[i]`.

Return the **maximum**  possible frequency of any element in `nums` after performing the **operations** .

**Example 1:**

```bash
Input: nums = [1,4,5], k = 1, numOperations = 2

Output: 2
```

Explanation:

We can achieve a maximum frequency of two by:

- Adding 0 to `nums[1]`. `nums` becomes `[1, 4, 5]`.
- Adding -1 to `nums[2]`. `nums` becomes `[1, 4, 4]`.

**Example 2:**

```bash
Input: nums = [5,11,20,20], k = 5, numOperations = 1

Output: 2
```

Explanation:

We can achieve a maximum frequency of two by:

- Adding 0 to `nums[1]`.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
- `0 <= k <= 10^5`
- `0 <= numOperations <= nums.length`

## Hints/Notes

- 2024/11/10
- [0x3F's solution](https://leetcode.cn/problems/maximum-frequency-of-an-element-after-performing-operations-i/solution/liang-chong-fang-fa-chai-fen-hua-dong-ch-spm9/)(checked)
- Biweekly Contest 143

## Solution

Language: **C++**

diff array:

```C++
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> count;
        map<int, int> diff;
        for (int num : nums) {
            count[num]++;
            diff[num];
            diff[num - k] += 1;
            diff[num + k + 1] -= 1;
        }
        int res = 0, cur = 0;
        for (auto it = diff.begin(); it != diff.end(); it++) {
            cur += it->second;
            res = max(res, count[it->first] + min(numOperations, cur - count[it->first]));
        }
        return res;
    }
};
```
