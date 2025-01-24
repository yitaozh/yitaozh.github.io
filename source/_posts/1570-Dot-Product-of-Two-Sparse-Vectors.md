---
title: 1570. Dot Product of Two Sparse Vectors
categories: Leetcode
date: 2025-01-24 15:54:05
tags:
    - Array
    - Hash Table
    - Two Pointers
    - Design
---

[1570. Dot Product of Two Sparse Vectors](https://leetcode.com/problems/dot-product-of-two-sparse-vectors/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given two sparse vectors, compute their dot product.

Implement class `SparseVector`:

- `SparseVector(nums)`Initializes the object with the vector `nums`
- `dotProduct(vec)`Compute the dot product between the instance of SparseVector and `vec`

A **sparse vector**  is a vector that has mostly zero values, you should store the sparse vector**efficiently** and compute the dot product between two SparseVector.

**Follow up:** What if only one of the vectors is sparse?

**Example 1:**

```bash
Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
```

**Example 2:**

```bash
Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
Output: 0
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
```

**Example 3:**

```bash
Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
Output: 6
```

**Constraints:**

- `n == nums1.length == nums2.length`
- `1 <= n <= 10^5`
- `0 <= nums1[i], nums2[i]<= 100`

## Hints/Notes

- 2025/01/24
- pairs of index and value
- [Leetcode solution](https://leetcode.com/problems/dot-product-of-two-sparse-vectors/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class SparseVector {
public:
    vector<pair<int, int>> vals;

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                vals.push_back({i, nums[i]});
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        auto vals2 = vec.getValues();
        int m = vals.size(), n = vals2.size(), i = 0, j = 0;
        while (i < m && j < n) {
            if (vals[i].first == vals2[j].first) {
                res += vals[i++].second * vals2[j++].second;
            } else if (vals[i].first > vals2[j].first) {
                j++;
            } else {
                i++;
            }
        }
        return res;
    }

    vector<pair<int, int>> getValues() {
        return vals;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
```
