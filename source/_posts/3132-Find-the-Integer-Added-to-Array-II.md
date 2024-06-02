---
title: 3132. Find the Integer Added to Array II
categories: Leetcode
date: 2024-05-17 11:33:59
tags:
    - Array
    - Two Pointers
    - Sorting
    - Enumeration
---

[3132. Find the Integer Added to Array II](https://leetcode.com/problems/find-the-integer-added-to-array-ii/description/)

## Description

You are given two integer arrays `nums1` and `nums2`.

From `nums1` two elements have been removed, and all other elements have been increased (or decreased in the case of negative) by an integer, represented by the variable `x`.

As a result, `nums1` becomes **equal**  to `nums2`. Two arrays are considered **equal**  when they contain the same integers with the same frequencies.

Return the **minimum**  possible integer `x` that achieves this equivalence.

**Example 1:**

```bash
Input: nums1 = [4,20,16,12,8], nums2 = [14,18,10]

Output: -2

Explanation:

After removing elements at indices `[0,4]` and adding -2, `nums1` becomes `[18,14,10]`.
```

**Example 2:**

```bash
Input: nums1 = [3,5,5,3], nums2 = [7,7]

Output: 2

Explanation:

After removing elements at indices `[0,3]` and adding 2, `nums1` becomes `[7,7]`.
```

**Constraints:**

- `3 <= nums1.length <= 200`
- `nums2.length == nums1.length - 2`
- `0 <= nums1[i], nums2[i] <= 1000`
- The test cases are generated in a way that there is an integer `x` such that `nums1` can become equal to `nums2` by removing two elements and adding `x` to each element of `nums1`.

## Hints/Notes

- Weekly contest 395
- we can only check the 3 minium values of nums1

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        unordered_map<int, int> m1, m2;
        int size1 = nums1.size(), size2 = nums2.size(), sum1 = 0, sum2 = 0;
        for (int i = 0; i < size1; i++) {
            int val = nums1[i];
            m1[val]++;
            sum1 += val;
        }
        for (int i = 0; i < size2; i++) {
            int val = nums2[i];
            m2[val]++;
            sum2 += val;
        }
        for (int i = 0; i < size1; i++) {
            for (int j = i + 1; j < size1; j++) {
                sum1 = sum1 - nums1[i] - nums1[j];
                m1[nums1[i]]--;
                m1[nums1[j]]--;
                if ((sum2 - sum1) % size2 != 0) {
                    sum1 = sum1 + nums1[i] + nums1[j];
                    m1[nums1[i]]++;
                    m1[nums1[j]]++;
                    continue;
                }
                int k = (sum2 - sum1) / size2;
                bool found = true;
                for (auto it : m2) {
                    int val = it.first;
                    int freq = it.second;
                    if (m1[val - k] != freq) {
                        // cout << nums1[i] << " " << nums1[j] << " wrong: " << val << endl;
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return k;
                }
                sum1 = sum1 + nums1[i] + nums1[j];
                m1[nums1[i]]++;
                m1[nums1[j]]++;
            }
        }
        return -1;
    }
};
```
