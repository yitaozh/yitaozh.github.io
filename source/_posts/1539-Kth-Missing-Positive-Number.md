---
title: 1539. Kth Missing Positive Number
categories: Leetcode
date: 2025-01-23 12:28:51
tags:
    - Array
    - Binary Search
---

[1539. Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given an array `arr` of positive integers sorted in a **strictly increasing order** , and an integer `k`.

Return the `k^th` **positive**  integer that is **missing**  from this array.

**Example 1:**

```bash
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5^thmissing positive integer is 9.
```

**Example 2:**

```bash
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2^nd missing positive integer is 6.
```

**Constraints:**

- `1 <= arr.length <= 1000`
- `1 <= arr[i] <= 1000`
- `1 <= k <= 1000`
- `arr[i] < arr[j]` for `1 <= i < j <= arr.length`

**Follow up:**

Could you solve this problem in less than O(n) complexity?

## Hints/Notes

- 2025/01/23
- [Leetcode solution](https://leetcode.com/problems/kth-missing-positive-number/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

O(log(n)) solution:

```C++
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // for each index of arr, there are arr[idx] - idx - 1 numbers skipped before this number
        // for idx < left, skipped <= k is always true
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int skipped = arr[mid] - mid - 1;
            if (skipped >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // right = left - 1
        return left ? k - (arr[right] - right - 1) + arr[right] : k;
    }
};
```

O(n) solution:

```C++
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int num : arr) {
            if (num <= k) {
                k++;
            } else {
                break;
            }
        }
        return k;
    }
};
```
