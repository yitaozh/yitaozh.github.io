---
title: 3194. Minimum Average of Smallest and Largest Elements
categories: Leetcode
date: 2024-06-27 23:34:44
tags:
    - Array
    - Two Pointers
    - Sorting
---

[3194. Minimum Average of Smallest and Largest Elements](https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/description/)

## Description

You have an array of floating point numbers `averages` which is initially empty. You are given an array `nums` of `n` integers where `n` is even.

You repeat the following procedure `n / 2` times:

- Remove the **smallest** element, `minElement`, and the **largest** element `maxElement`,from `nums`.
- Add `(minElement + maxElement) / 2` to `averages`.

Return the **minimum**  element in `averages`.

**Example 1:**

```bash
Input: nums = [7,8,3,4,15,13,4,1]

Output: 5.5
```

Explanation:

<table><tbody><tr><th>step</th><th>nums</th><th>averages</th></tr><tr><td>0</td><td>[7,8,3,4,15,13,4,1]</td><td>[]</td></tr><tr><td>1</td><td>[7,8,3,4,13,4]</td><td>[8]</td></tr><tr><td>2</td><td>[7,8,4,4]</td><td>[8,8]</td></tr><tr><td>3</td><td>[7,4]</td><td>[8,8,6]</td></tr><tr><td>4</td><td>[]</td><td>[8,8,6,5.5]</td></tr></tbody></table>
The smallest element of averages, 5.5, is returned.

**Example 2:**

```bash
Input: nums = [1,9,8,3,10,5]

Output: 5.5
```

Explanation:

<table><tbody><tr><th>step</th><th>nums</th><th>averages</th></tr><tr><td>0</td><td>[1,9,8,3,10,5]</td><td>[]</td></tr><tr><td>1</td><td>[9,8,3,5]</td><td>[5.5]</td></tr><tr><td>2</td><td>[8,5]</td><td>[5.5,6]</td></tr><tr><td>3</td><td>[]</td><td>[5.5,6,6.5]</td></tr></tbody></table>

**Example 3:**

```bash
Input: nums = [1,2,3,7,8,9]

Output: 5.0
```

Explanation:

<table><tbody><tr><th>step</th><th>nums</th><th>averages</th></tr><tr><td>0</td><td>[1,2,3,7,8,9]</td><td>[]</td></tr><tr><td>1</td><td>[2,3,7,8]</td><td>[5]</td></tr><tr><td>2</td><td>[3,7]</td><td>[5,5]</td></tr><tr><td>3</td><td>[]</td><td>[5,5,5]</td></tr></tbody></table>

**Constraints:**

- `2 <= n == nums.length <= 50`
- `n` is even.
- `1 <= nums[i] <= 50`

## Hints/Notes

- Weekly Contest 403

## Solution

Language: **C++**

```C++
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        double res = INT_MAX;
        while (left < right) {
            res = min((nums[left] + nums[right]) * 1.0 / 2, res);
            left++;
            right--;
        }
        return res;
    }
};
```
