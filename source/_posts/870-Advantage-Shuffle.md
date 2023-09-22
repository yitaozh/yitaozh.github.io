---
title: 870. Advantage Shuffle
categories: Leetcode
date: 2023-01-31 13:02:24
tags:
    - Array
    - Two Pointers
    - Greedy
    - Sorting
---

# [870\. Advantage Shuffle](https://leetcode.com/problems/advantage-shuffle/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

You are given two integer arrays `nums1` and `nums2` both of the same length. The **advantage** of `nums1` with respect to `nums2` is the number of indices `i` for which `nums1[i] > nums2[i]`.

Return _any permutation of_ `nums1` _that maximizes its **advantage** with respect to_ `nums2`.

**Example 1:**

```text
Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
Output: [2,11,7,15]
```

**Example 2:**

```text
Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
Output: [24,32,8,12]
```

**Constraints:**

* 1 <= nums1.length <= 10<sup>5</sup>
* `nums2.length == nums1.length`
* 0 <= nums1[i], nums2[i] <= 10<sup>9</sup>

## Hints/Notes

* Use priority queue for nums2, also we need to record the index for each value
* Need to allocate a new res vector for return, nums1 records sorted array

```C++
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        return vector<int>();
    }
}
```

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        auto cmp = [](const pair<int, int> lhs, const pair<int, int> rhs) {
            return lhs.second < rhs.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < nums2.size(); i++) {
            pq.push({i, nums2[i]});
        }
        sort(nums1.begin(), nums1.end());
        int left = 0, right = nums1.size() - 1;
        vector<int> res(nums1.size(), 0);
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            if (top.second >= nums1[right]) {
                res[top.first] = nums1[left++];
            } else {
                res[top.first] = nums1[right--];
            }
        }
        return res;
    }
};
```
