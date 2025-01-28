---
title: 1868. Product of Two Run-Length Encoded Arrays
categories: Leetcode
date: 2025-01-28 17:14:14
tags:
    - Array
    - Two Pointers
---

[1868. Product of Two Run-Length Encoded Arrays](https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

**Run-length encoding**  is a compression algorithm that allows for an integer array `nums` with many segments of **consecutive repeated**  numbers to be represented by a (generally smaller) 2D array `encoded`. Each encoded[i] = [val<sub>i</sub>, freq<sub>i</sub>] describes the `i^th` segment of repeated numbers in `nums` where val<sub>i</sub> is the value that is repeated freq<sub>i</sub> times.

- For example, `nums = [1,1,1,2,2,2,2,2]` is represented by the **run-length encoded**  array `encoded = [[1,3],[2,5]]`. Another way to read this is "three `1`'s followed by five `2`'s".

The **product**  of two run-length encoded arrays `encoded1` and `encoded2` can be calculated using the following steps:

- **Expand**  both `encoded1` and `encoded2` into the full arrays `nums1` and `nums2` respectively.
- Create a new array `prodNums` of length `nums1.length` and set `prodNums[i] = nums1[i] * nums2[i]`.
- **Compress**  `prodNums` into a run-length encoded array and return it.

You are given two **run-length encoded**  arrays `encoded1` and `encoded2` representing full arrays `nums1` and `nums2` respectively. Both `nums1` and `nums2` have the **same length** . Each encoded1[i] = [val<sub>i</sub>, freq<sub>i</sub>] describes the `i^th` segment of `nums1`, and each encoded2[j] = [val<sub>j</sub>, freq<sub>j</sub>] describes the `j^th` segment of `nums2`.

Return <i>the **product**  of </i>`encoded1` and `encoded2`.

**Note:**  Compression should be done such that the run-length encoded array has the **minimum**  possible length.

**Example 1:**

```bash
Input: encoded1 = [[1,3],[2,3]], encoded2 = [[6,3],[3,3]]
Output: [[6,6]]
Explanation: encoded1 expands to [1,1,1,2,2,2] and encoded2 expands to [6,6,6,3,3,3].
prodNums = [6,6,6,6,6,6], which is compressed into the run-length encoded array [[6,6]].
```

**Example 2:**

```bash
Input: encoded1 = [[1,3],[2,1],[3,2]], encoded2 = [[2,3],[3,3]]
Output: [[2,3],[6,1],[9,2]]
Explanation: encoded1 expands to [1,1,1,2,3,3] and encoded2 expands to [2,2,2,3,3,3].
prodNums = [2,2,2,6,9,9], which is compressed into the run-length encoded array [[2,3],[6,1],[9,2]].
```

**Constraints:**

- `1 <= encoded1.length, encoded2.length <= 10^5`
- `encoded1[i].length == 2`
- `encoded2[j].length == 2`
- `1 <= val<sub>i</sub>, freq<sub>i</sub> <= 10^4` for each `encoded1[i]`.
- `1 <= val<sub>j</sub>, freq<sub>j</sub> <= 10^4` for each `encoded2[j]`.
- The full arrays that `encoded1` and `encoded2` represent are the same length.

## Hints/Notes

- 2025/01/28
- two pointers
- [Good solution](https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/solutions/1228261/python3-clean-two-pointers-solution/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < encoded1.size()) {
            int val1 = encoded1[i][0], freq1 = encoded1[i][1];
            int val2 = encoded2[j][0], freq2 = encoded2[j][1];
            int freq = min(freq1, freq2);
            int val = val1 * val2;
            if (!res.empty() && res.back()[0] == val) {
                res.back()[1] += freq;
            } else {
                res.push_back({val, freq});
            }
            encoded1[i][1] -= freq;
            encoded2[j][1] -= freq;
            if (!encoded1[i][1]) {
                i++;
            }
            if (!encoded2[j][1]) {
                j++;
            }
        }
        return res;
    }
};
```
