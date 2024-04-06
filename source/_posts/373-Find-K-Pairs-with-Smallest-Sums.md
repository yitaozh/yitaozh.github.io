---
title: 373. Find K Pairs with Smallest Sums
categories: Leetcode
date: 2023-10-12 00:20:12
tags:
    - Array
    - Heap (Priority Queue)
---

[373\. Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//)

You are given two integer arrays `nums1` and `nums2` sorted in **non-decreasing order** and an integer `k`.

Define a pair `(u, v)` which consists of one element from the first array and one element from the second array.

Return _the_ `k` _pairs_ (u<sub>1</sub>, v<sub>1</sub>), (u<sub>2</sub>, v<sub>2</sub>), ..., (u<sub>k</sub>, v<sub>k</sub>) _with the smallest sums_.

**Example 1:**

```bash
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
```

**Example 2:**

```bash
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
```

**Example 3:**

```bash
Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
```

**Constraints:**

* 1 <= nums1.length, nums2.length <= 10<sup>5</sup>
* -10<sup>9</sup> <= nums1[i], nums2[i] <= 10<sup>9</sup>
* `nums1` and `nums2` both are sorted in **non-decreasing order**.
* 1 <= k <= 10<sup>4</sup>

## Hints/Notes

* Priority queue
* Don't think about moving 2 needles together, pair the first item in 1st list with all items in the 2nd list

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1 = nums1.size(), size2 = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < size1; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }
        vector<vector<int>> res;
        while (k > 0 && !pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();
            int i1 = top[1];
            int i2 = top[2];
            res.push_back({nums1[i1], nums2[i2]});
            if (i2 < size2 - 1) {
                i2++;
                pq.push({nums1[i1] + nums2[i2], i1, i2});
            }
            k--;
        }
        return res;
    }
};
```
