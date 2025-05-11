---
title: 2488. Count Subarrays With Median K
categories: Leetcode
date: 2025-05-10 23:32:09
tags:
    - Array
    - Hash Table
    - Prefix Sum
---

[2488. Count Subarrays With Median K](https://leetcode.com/problems/count-subarrays-with-median-k/description/?envType=company&envId=confluent&favoriteSlug=confluent-all)

## Description

You are given an array <code>nums</code> of size <code>n</code> consisting of **distinct** integers from <code>1</code> to <code>n</code> and a positive integer <code>k</code>.

Return the number of non-empty subarrays in <code>nums</code> that have a **median**  equal to <code>k</code>.

**Note** :

- The median of an array is the **middle** element after sorting the array in **ascending** order. If the array is of even length, the median is the **left** middle element.

- For example, the median of <code>[2,3,1,4]</code> is <code>2</code>, and the median of <code>[8,4,3,5,1]</code> is <code>4</code>.

- A subarray is a contiguous part of an array.

**Example 1:**

```bash
Input: nums = [3,2,1,4,5], k = 4
Output: 3
Explanation: The subarrays that have a median equal to 4 are: [4], [4,5] and [1,4,5].
```

**Example 2:**

```bash
Input: nums = [2,3,1], k = 3
Output: 1
Explanation: [3] is the only subarray that has a median equal to 3.
```

**Constraints:**

- <code>n == nums.length</code>
- <code>1 <= n <= 10^5</code>
- <code>1 <= nums[i], k <= n</code>
- The integers in <code>nums</code> are distinct.

## Hints/Notes

- 2025/05/02 Q1
- preSum
- [0x3F's solution](https://leetcode.cn/problems/count-subarrays-with-median-k/solutions/1993439/deng-jie-zhuan-huan-pythonjavacgo-by-end-5w11/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int pos = find(nums.begin(), nums.end(), k) - nums.begin(), n = nums.size();
        unordered_map<int, int> count{{0, 1}};
        for (int i = pos - 1, x = 0; i >= 0; --i) {
            x += nums[i] < k ? 1 : -1;
            ++count[x];
        }
        int ans = count[0] + count[-1];
        for (int i = pos + 1, x = 0; i < n; i++) {
            x += nums[i] > k ? 1 : -1;
            ans += count[x] + count[x - 1];
        }
        return ans;
    }
};
```
