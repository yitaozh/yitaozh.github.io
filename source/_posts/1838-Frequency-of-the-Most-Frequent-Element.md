---
title: 1838. Frequency of the Most Frequent Element
categories: Leetcode
date: 2025-03-22 03:09:10
tags:
    - Array
    - Binary Search
    - Greedy
    - Sliding Window
    - Sorting
    - Prefix Sum
---

[1838. Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/)

## Description

The **frequency**  of an element is the number of times it occurs in an array.

You are given an integer array `nums` and an integer `k`. In one operation, you can choose an index of `nums` and increment the element at that index by `1`.

Return the **maximum possible frequency**  of an element after performing **at most**  `k` operations.

**Example 1:**

```bash
Input: nums = [1,2,4], k = 5
Output: 3**
Explanation:**  Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.```

**Example 2:**

```bash
Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
```

**Example 3:**

```bash
Input: nums = [3,9,6], k = 2
Output: 1
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
- `1 <= k <= 10^5`

## Hints/Notes

- 2025/02/26 Q3
- preSum + sliding window
- [Leetcode solution](https://leetcode.com/problems/frequency-of-the-most-frequent-element/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        ranges::sort(nums);
        long sum = 0;
        int res = 0, n = nums.size(), left = 0, right = 0;
        while(right < n) {
            long target = (long)nums[right] * (right - left + 1);
            sum += nums[right];
            long diff = target - sum;
            while (diff > k) {
                diff -= (nums[right] - nums[left]);
                sum -= nums[left++];
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
```
