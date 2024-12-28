---
title: 128. Longest Consecutive Sequence
categories: Leetcode
date: 2024-12-28 17:10:45
tags:
    - Array
    - Hash Table
    - Union Find
---

[128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in `O(n)` time.

**Example 1:**

```bash
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore its length is 4.
```

**Example 2:**

```bash
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

**Constraints:**

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Hints/Notes

- 2024/12/28
- sort or set
- [0x3F's solution](https://leetcode.cn/problems/longest-consecutive-sequence/solutions/3005726/ha-xi-biao-on-zuo-fa-pythonjavacgojsrust-whop/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int x : s) {
            if (s.contains(x - 1)) {
                continue;
            }
            int y = x + 1;
            while (s.contains(y)) {
                y++;
            }
            res = max(res, y - x);
        }
        return res;
    }
};
```

Sort solution:

```C++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ranges::sort(nums);
        int res = 0, cur = 0, curVal = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == curVal) {
                continue;
            }
            if (nums[i] == curVal + 1) {
                curVal++;
                cur++;
            } else {
                res = max(res, cur);
                curVal = nums[i];
                cur = 1;
            }
        }
        res = max(res, cur);
        return res;
    }
};
```
