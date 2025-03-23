---
title: 1664. Ways to Make a Fair Array
categories: Leetcode
date: 2025-03-22 22:21:13
tags:
    - Array
    - Prefix Sum
---

[1664. Ways to Make a Fair Array](https://leetcode.com/problems/ways-to-make-a-fair-array/description/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Description

You are given an integer array`nums`. You can choose **exactly one**  index (**0-indexed** ) and remove the element. Notice that the index of the elements may change after the removal.

For example, if `nums = [6,1,7,4,1]`:

- Choosing to remove index `1` results in `nums = [6,7,4,1]`.
- Choosing to remove index `2` results in `nums = [6,1,4,1]`.
- Choosing to remove index `4` results in `nums = [6,1,7,4]`.

An array is **fair**  if the sum of the odd-indexed values equals the sum of the even-indexed values.

Return the **number**  of indices that you could choose such that after the removal, `nums` is **fair** .

**Example 1:**

```bash
Input: nums = [2,1,6,4]
Output: 1
Explanation:
Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
```

**Example 2:**

```bash
Input: nums = [1,1,1]
Output: 3
Explanation:You can remove any index and the remaining array is fair.
```

**Example 3:**

```bash
Input: nums = [1,2,3]
Output: 0
Explanation:You cannot make a fair array after removing any index.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`

## Hints/Notes

- 2025/03/15 Q2
- preSum
- [Leetcode solution](https://leetcode.cn/problems/ways-to-make-a-fair-array/solutions/2078340/sheng-cheng-ping-heng-shu-zu-de-fang-an-0mkaj/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> preSumOdd = {0}, preSumEven = {0};
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                preSumOdd.push_back(preSumOdd.back() + nums[i]);
                preSumEven.push_back(preSumEven.back());
            } else {
                preSumEven.push_back(preSumEven.back() + nums[i]);
                preSumOdd.push_back(preSumOdd.back());
            }
        }
        int res = 0, total_odd = (n + 1) / 2, total_even = n - total_odd;
        for (int i = 0; i < n; i++) {
            int previousEven = preSumEven[i], previousOdd = preSumOdd[i];
            int nextEven = preSumOdd[n] - preSumOdd[i + 1], nextOdd = preSumEven[n] - preSumEven[i + 1];
            if (previousEven + nextEven == previousOdd + nextOdd) {
                res++;
            }

        }
        return res;
    }
};
```
