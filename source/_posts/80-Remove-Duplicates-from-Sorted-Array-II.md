---
title: 80. Remove Duplicates from Sorted Array II
categories: Leetcode
date: 2025-03-13 15:24:51
tags:
    - Array
    - Two Pointers
---

[80. Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/)

## Description

Given an integer array `nums` sorted in **non-decreasing order** , remove some duplicates <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">**in-place** </a> such that each unique element appears **at most twice** . The **relative order**  of the elements should be kept the **same** .

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the **first part**  of the array `nums`. More formally, if there are `k` elements after removing the duplicates, then the first `k` elements of `nums`should hold the final result. It does not matter what you leave beyond the first`k`elements.

Return `k` after placing the final result in the first `k` slots of `nums`.

Do **not**  allocate extra space for another array. You must do this by **modifying the input array <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a>**  with O(1) extra memory.

**Custom Judge:**

The judge will test your solution with the following code:

```bash
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be **accepted** .

**Example 1:**

```bash
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:**

```bash
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in **non-decreasing**  order.

## Hints/Notes

- 2025/03/03 Q1
- stack or two pointers
- [0x3F's solution](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/solutions/3060042/yong-zhan-si-kao-yuan-di-shi-xian-python-zw8l/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), curIndex = 0;
        for (int i = 0; i < n; ) {
            int start = i;
            while (i < n && nums[i] == nums[start]) {
                i++;
            }
            int diff = min(i - start, 2);
            for (; diff > 0; diff--) {
                nums[curIndex++] = nums[start];
            }
        }
        return curIndex;
    }
};
```
