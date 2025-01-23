---
title: 347. Top K Frequent Elements
categories: Leetcode
date: 2023-11-06 22:58:50
tags:
    - Array
    - Hash Table
    - Divide and Conquer
    - Sorting
    - Heap (Priority Queue)
    - Bucket Sort
    - Counting
    - Quickselect
---

[347\. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Bucket Sort](https://leetcode.com/tag/https://leetcode.com/tag/bucket-sort//), [Counting](https://leetcode.com/tag/https://leetcode.com/tag/counting//), [Quickselect](https://leetcode.com/tag/https://leetcode.com/tag/quickselect//)

Given an integer array `nums` and an integer `k`, return _the_ `k` _most frequent elements_. You may return the answer in **any order**.

**Example 1:**

```bash
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

**Example 2:**

```bash
Input: nums = [1], k = 1
Output: [1]
```

**Constraints:**

* 1 <= nums.length <= 10<sup>5</sup>
* -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>
* `k` is in the range `[1, the number of unique elements in the array]`.
* It is **guaranteed** that the answer is **unique**.

**Follow up:** Your algorithm's time complexity must be better than `O(n log n)`, where n is the array's size.

## Hints/Notes

* 2023/10/18
* priority queue
* [Leetcode solution](https://leetcode.com/problems/top-k-frequent-elements/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (auto it : m) {
            int num = it.first;
            int freq = it.second;
            pq.push({freq, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            auto pair = pq.top();
            pq.pop();
            res.push_back(pair[1]);
        }
        return res;
    }
};
```
