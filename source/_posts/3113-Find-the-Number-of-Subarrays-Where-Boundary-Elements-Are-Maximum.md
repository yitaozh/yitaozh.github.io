---
title: 3113. Find the Number of Subarrays Where Boundary Elements Are Maximum
categories: Leetcode
date: 2024-05-08 14:15:09
tags:
    - Array
    - Binary Search
    - Stack
    - Monotonic Stack
---

[3113. Find the Number of Subarrays Where Boundary Elements Are Maximum](https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/)

## Description

You are given an array of **positive**  integers `nums`.

Return the number of subarrays of `nums`, where the **first**  and the **last**  elements of the subarray are equal to the **largest**  element in the subarray.

**Example 1:**

```bash
Input: nums = [1,4,3,3,2]

Output: 6

Explanation:

There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:

- subarray `[**1** ,4,3,3,2]`, with its largest element 1. The first element is 1 and the last element is also 1.
- subarray `[1,**4** ,3,3,2]`, with its largest element 4. The first element is 4 and the last element is also 4.
- subarray `[1,4,**3** ,3,2]`, with its largest element 3. The first element is 3 and the last element is also 3.
- subarray `[1,4,3,**3** ,2]`, with its largest element 3. The first element is 3 and the last element is also 3.
- subarray `[1,4,3,3,**2** ]`, with its largest element 2. The first element is 2 and the last element is also 2.
- subarray `[1,4,**3,3** ,2]`, with its largest element 3. The first element is 3 and the last element is also 3.

Hence, we return 6.
```

**Example 2:**

```bash
Input: nums = [3,3,3]

Output: 6

Explanation:

There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:

- subarray `[**3** ,3,3]`, with its largest element 3. The first element is 3 and the last element is also 3.
- subarray `[3,**3** ,3]`, with its largest element 3. The first element is 3 and the last element is also 3.
- subarray `[3,3,**3** ]`, with its largest element 3. The first element is 3 and the last element is also 3.
- subarray `[**3,3** ,3]`, with its largest element 3. The first element is 3 and the last element is also 3.
- subarray `[3,**3,3** ]`, with its largest element 3. The first element is 3 and the last element is also 3.
- subarray `[**3,3,3** ]`, with its largest element 3. The first element is 3 and the last element is also 3.

Hence, we return 6.
```

**Example 3:**

```bash
Input: nums = [1]

Output: 1

Explanation:

There is a single subarray of `nums` which is `[**1** ]`, with its largest element 1. The first element is 1 and the last element is also 1.

Hence, we return 1.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`

## Hints/Notes

- monotonic stack/max stack

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long res = nums.size();
        int left = 0, right = 0;
        deque<pair<int, long>> q;
        while (right < nums.size()) {
            while (!q.empty() && nums[right] > q.back().first) {
                q.pop_back();
            }
            if (!q.empty() && nums[right] == q.back().first) {
                long count = q.back().second;
                q.pop_back();
                res += count;
                q.push_back({nums[right], count + 1});
            } else {
                q.push_back({nums[right], 1});
            }
            right++;
        }
        return res;
    }
};
```
