---
title: 3158. Find the XOR of Numbers Which Appear Twice
categories: Leetcode
date: 2024-05-28 23:35:46
tags:
    - Array
    - Hash Table
    - Bit Manipulation
---

[3158. Find the XOR of Numbers Which Appear Twice](https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/description/)

You are given an array `nums`, where each number in the array appears **either**  once or twice.

Return the bitwise `XOR` of all the numbers that appear twice in the array, or 0 if no number appears twice.

**Example 1:**

```bash
Input: nums = [1,2,1,3]

Output: 1

Explanation:

The only number that appears twice in`nums`is 1.
```

**Example 2:**

```bash
Input: nums = [1,2,3]

Output: 0

Explanation:

No number appears twice in`nums`.
```

**Example 3:**

```bash
Input: nums = [1,2,2,1]

Output: 3

Explanation:

Numbers 1 and 2 appeared twice. `1 XOR 2 == 3`.
```

**Constraints:**

- `1 <= nums.length <= 50`
- `1 <= nums[i] <= 50`
- Each number in `nums` appears either once or twice.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        int res = 0;
        bool set = false;
        for (auto it : m) {
            if (it.second == 2) {
                if (!set) {
                    set = true;
                    res = it.first;
                } else {
                    res ^= it.first;
                }
            }
        }
        return res;
    }
};
```
