---
title: 658. Find K Closest Elements
categories: Leetcode
date: 2023-12-01 21:56:02
tags:
    - Array
    - Two Pointers
    - Binary Search
    - Sliding Window
    - Sorting
    - Heap (Priority Queue)
---

[658\. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Two Pointers](https://leetcode.com/tag/https://leetcode.com/tag/two-pointers//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Sliding Window](https://leetcode.com/tag/https://leetcode.com/tag/sliding-window//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//)

Given a **sorted** integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.

An integer `a` is closer to `x` than an integer `b` if:

* `|a - x| < |b - x|`, or
* `|a - x| == |b - x|` and `a < b`

**Example 1:**

```bash
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
```

**Example 2:**

```bash
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
```

**Constraints:**

* `1 <= k <= arr.length`
* 1 <= arr.length <= 10<sup>4</sup>
* `arr` is sorted in **ascending** order.
* -10<sup>4</sup> <= arr[i], x <= 10<sup>4</sup>

## Hints/Notes

* 2023/11/16
* since we need the smaller index, find the left boundary
* [Leetcode solution](https://leetcode.com/problems/find-k-closest-elements/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = findLeft(arr, x);
        int left = index - 1, right = index;
        list<int> res;
        while (k > 0) {
            if (left < 0) {
                res.push_back(arr[right++]);
            } else if (right == arr.size()) {
                res.push_front(arr[left--]);
            } else {
                int ldelta = abs(arr[left] - x);
                int rdelta = abs(arr[right] - x);
                if (ldelta <= rdelta) {
                    res.push_front(arr[left--]);
                } else {
                    res.push_back(arr[right++]);
                }
            }
            k--;
        }
        return vector<int>(res.begin(), res.end());
    }

    int findLeft(vector<int>& arr, int x) {
        int left = 0, right = arr.size();
        // left - 1 < x
        // right >= x
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (arr[mid] == x) {
                right = mid;
            } else if (arr[mid] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
```
