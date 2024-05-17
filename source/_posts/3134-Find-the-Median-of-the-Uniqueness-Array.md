---
title: 3134. Find the Median of the Uniqueness Array
categories: Leetcode
date: 2024-05-17 11:37:53
tags:
    - Array
    - Hash Table
    - Binary Search
    - Sliding Window
---

[3134. Find the Median of the Uniqueness Array](https://leetcode.com/problems/find-the-median-of-the-uniqueness-array/description/)

You are given two integers `n` and `x`. You have to construct an array of **positive**  integers `nums` of size `n` where for every `0 <= i < n - 1`, `nums[i + 1]` is **greater than**  `nums[i]`, and the result of the bitwise `AND` operation between all elements of `nums` is `x`.

Return the **minimum**  possible value of `nums[n - 1]`.

**Example 1:**

```bash
Input: n = 3, x = 4

Output: 6

Explanation:

`nums` can be `[4,5,6]` and its last element is 6.
```

**Example 2:**

```bash
Input: n = 2, x = 7

Output: 15

Explanation:

`nums` can be `[7,15]` and its last element is 15.
```

**Constraints:**

- `1 <= n, x <= 10^8`

## Hints/Notes

- binary search

## Solution

Language: **C++**

```C++
class Solution {
public:
    map<int, int> m;

    int medianOfUniquenessArray(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);
        }
        int left = 1, right = s.size(), size = nums.size();
        long target = ((long)size * (size + 1) / 2 + 1) / 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, nums) >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    long check(int numUnique, vector<int>& nums) {
        if (m.contains(numUnique)) {
            return m[numUnique];
        }
        int left = 0, right = 0;
        long res = 0;
        unordered_map<int, int> m;
        while (right < nums.size()) {
            m[nums[right++]]++;
            while (m.size() > numUnique && left < right) {
                m[nums[left]]--;
                if (m[nums[left]] == 0) {
                    m.erase(nums[left]);
                }
                left++;
            }
            res += right - left;
        }
        m[numUnique] = res;
        return res;
    }
};
```
