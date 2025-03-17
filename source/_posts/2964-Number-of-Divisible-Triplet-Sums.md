---
title: 2964. Number of Divisible Triplet Sums
categories: Leetcode
date: 2025-03-17 00:58:40
tags:
    - Array
    - Hash Table
---

[2964. Number of Divisible Triplet Sums](https://leetcode.com/problems/number-of-divisible-triplet-sums/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Description

Given a **0-indexed**  integer array `nums` and an integer `d`, return the number of triplets `(i, j, k)` such that `i < j < k` and `(nums[i] + nums[j] + nums[k]) % d == 0`.

**Example 1:**

```bash
Input: nums = [3,3,4,7,8], d = 5
Output: 3
Explanation: The triplets which are divisible by 5 are: (0, 1, 2), (0, 2, 4), (1, 2, 4).
It can be shown that no other triplet is divisible by 5. Hence, the answer is 3.
```

**Example 2:**

```bash
Input: nums = [3,3,3,3], d = 3
Output: 4
Explanation: Any triplet chosen here has a sum of 9, which is divisible by 3. Hence, the answer is the total number of triplets which is 4.
```

**Example 3:**

```bash
Input: nums = [3,3,3,3], d = 6
Output: 0
Explanation: Any triplet chosen here has a sum of 9, which is not divisible by 6. Hence, the answer is 0.
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 10^9`
- `1 <= d <= 10^9`

## Hints/Notes

- 2025/02/12 Q3
- Hash Table
- No solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        int n = nums.size();
        // so we have one number, which is nums[i] fixed
        // to make the 3 numbers sum mod by d
        // that means nums[j] + nums[k] % d = d - nums[i]
        int res = 0;
        for (int i = 0; i < n; i++) {
            int target = (d - nums[i] % d) % d;
            vector<int> count(d, 0);
            for (int j = i + 1; j < n; j++) {
                // prev + nums[j] % d == target
                // prev % d = (target - nums[j] % d + d) % d
                int prev = (target - nums[j] % d + d) % d;
                res += count[prev];
                count[nums[j] % d]++;
            }
        }
        return res;
    }
};
```
