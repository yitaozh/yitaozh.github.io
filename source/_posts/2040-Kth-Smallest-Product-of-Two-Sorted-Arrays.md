---
title: 2040. Kth Smallest Product of Two Sorted Arrays
categories: Leetcode
date: 2025-04-14 03:20:34
tags:
    - Array
    - Binary Search
---

[2040. Kth Smallest Product of Two Sorted Arrays](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

Given two **sorted 0-indexed**  integer arrays `nums1` and `nums2` as well as an integer `k`, return the `k^th` (**1-based** ) smallest product of `nums1[i] * nums2[j]` where `0 <= i < nums1.length` and `0 <= j < nums2.length`.

**Example 1:**

```bash
Input: nums1 = [2,5], nums2 = [3,4], k = 2
Output: 8
Explanation: The 2 smallest products are:
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
The 2^nd smallest product is 8.
```

**Example 2:**

```bash
Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
Output: 0
Explanation: The 6 smallest products are:
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
The 6^th smallest product is 0.
```

**Example 3:**

```bash
Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
Output: -6
Explanation: The 3 smallest products are:
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
The 3^rd smallest product is -6.
```

**Constraints:**

- `1 <= nums1.length, nums2.length <= 5 * 10^4`
- `-10^5 <= nums1[i], nums2[j] <= 10^5`
- `1 <= k <= nums1.length * nums2.length`
- `nums1` and `nums2` are sorted.

## Hints/Notes

- 2025/04/11 Q2
- binary search
- [Good solution](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/solutions/5874613/c-detailed-explanation-binary-search-counting/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size(), n2 = nums2.size();
        long long low = -1e10 - 1, high = 1e10 + 1;
        while (low + 1 < high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(mid, nums1, nums2, k)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return high;
    }

    bool isPossible(long long x, vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size(), n2 = nums2.size();
        long long count = 0;
        for (int i = 0; i < n1; i++) {
            if (nums1[i] < 0) {
                long long rem = ceil((double)x / nums1[i]);
                int idx = lower_bound(nums2.begin(), nums2.end(), rem) - nums2.begin();
                count += (n2 - idx);
            } else if (nums1[i] > 0) {
                long long rem = floor((double)x / nums1[i]);
                int ind = upper_bound(nums2.begin(), nums2.end(), rem) -nums2.begin();
                count += ind;
            } else {
                if (x >= 0) {
                    count += n2;
                }
            }
            if (count >= k) {
                return true;
            }
        }
        return count >= k;
    }
};
```
