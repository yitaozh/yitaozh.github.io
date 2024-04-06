---
title: 167. Two Sum II - Input Array Is Sorted
categories: Leetcode
date: 2023-01-19 15:01:30
tags:
    - Array
    - Two Pointers
    - Binary Search
---

[167\. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/)

Given a **1-indexed** array of integers `numbers` that is already **_sorted in non-decreasing order_**, find two numbers such that they add up to a specific `target` number. Let these two numbers be numbers[index<sub>1</sub>] and numbers[index<sub>2</sub>] where 1 <= index<sub>1</sub> < index<sub>2</sub> <= numbers.length.

Return _the indices of the two numbers,_ index<sub>1</sub> _and_ index<sub>2</sub>_, **added by one** as an integer array_ [index<sub>1</sub>, index<sub>2</sub>] _of length 2._

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

**Example 1:**

```bash
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9\. Therefore, index1 = 1, index2 = 2\. We return [1, 2].
```

**Example 2:**

```bash
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6\. Therefore index1 = 1, index2 = 3\. We return [1, 3].
```

**Example 3:**

```bash
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1\. Therefore index1 = 1, index2 = 2\. We return [1, 2].
```

**Constraints:**

* 2 <= numbers.length <= 3 * 10<sup>4</sup>
* `-1000 <= numbers[i] <= 1000`
* `numbers` is sorted in **non-decreasing order**.
* `-1000 <= target <= 1000`
* The tests are generated such that there is **exactly one solution**.

## Hints/Notes

* It's very like binary search

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            }
        }
        return {-1, -1};
    }
};
```
