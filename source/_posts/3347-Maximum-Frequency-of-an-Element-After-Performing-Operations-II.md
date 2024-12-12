---
title: 3347. Maximum Frequency of an Element After Performing Operations II
categories: Leetcode
date: 2024-11-21 22:42:55
tags:
    - Array
    - Binary Search
    - Sliding Window
    - Sorting
    - Prefix Sum
---

[3347. Maximum Frequency of an Element After Performing Operations II](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/)

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

- Adding 0 to `nums[1]`, after which `nums` becomes `[1, 4, 5]`.
- Adding -1 to `nums[2]`, after which `nums` becomes `[1, 4, 4]`.

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
- `1 <= nums[i] <= 10^9`
- `0 <= k <= 10^9`
- `0 <= numOperations <= nums.length`

## Hints/Notes

- 2024/11/11
- diff array or sliding window
- [0x3F's solution]( https://leetcode.cn/problems/maximum-frequency-of-an-element-after-performing-operations-ii/solution/liang-chong-fang-fa-chai-fen-hua-dong-ch-7buy/)(checked)
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

sliding window:

```C++
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        int cur = 0, res = 0;
        auto left = m.begin(), right = m.begin();
        for (auto i = m.begin(); i != m.end(); i++) {
            while (left->first + k < i->first) {
                cur -= left->second;
                left++;
            }
            while (right != m.end() && right->first <= i->first + k) {
                cur += right->second;
                right++;
            }
            res = max(res, i->second + min(cur - i->second, numOperations));

        }
        if (res >= numOperations) {
            return res;
        }

        // the sliding window case
        cur = 0, left = m.begin(), right = m.begin();
        while (right != m.end()) {
            cur += right->second;
            while (left->first < right->first - 2 * k) {
                cur -= left->second;
                left++;
            }
            res = max(res, cur);
            right++;
        }
        return min(res, numOperations);
    }
};
```
