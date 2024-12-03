---
title: 3354. Make Array Elements Equal to Zero
categories: Leetcode
date: 2024-12-03 17:18:51
tags:
    - Array
    - Simulation
    - Prefix Sum
---

[3354. Make Array Elements Equal to Zero](https://leetcode.com/problems/make-array-elements-equal-to-zero/description/)

## Description

You are given an integer array `nums`.

Start by selecting a starting position `curr` such that `nums[curr] == 0`, and choose a movement **direction**  ofeither left or right.

After that, you repeat the following process:

- If `curr` is out of the range `[0, n - 1]`, this process ends.
- If `nums[curr] == 0`, move in the current direction by **incrementing**  `curr` if you are moving right, or **decrementing**  `curr` if you are moving left.
- Else if `nums[curr] > 0`:

  - Decrement `nums[curr]` by 1.
  - **Reverse** your movement direction (left becomes right and vice versa).
  - Take a step in your new direction.

A selection of the initial position `curr` and movement direction is considered **valid**  if every element in `nums` becomes 0 by the end of the process.

Return the number of possible **valid**  selections.

**Example 1:**

```bash
Input: nums = [1,0,2,0,3]

Output: 2
```

Explanation:

The only possible valid selections are the following:

- Choose `curr = 3`, and a movement direction to the left.

  - [1,0,2,**0**,3] -> [1,0,**2**,0,3] -> [1,0,1,**0**,3] -> [1,0,1,0,**3**] -> [1,0,1,**0**,2] -> [1,0,**1**,0,2] -> [1,0,0,**0**,2] -> [1,0,0,0,**2**] -> [1,0,0,**0**,1] -> [1,0,**0**,0,1] -> [1,**0**,0,0,1] -> [**1**,0,0,0,1] -> [0,**0**,0,0,1] -> [0,0,**0**,0,1] -> [0,0,0,**0**,1] -> [0,0,0,0,**1**] -> [0,0,0,0,0].

- Choose `curr = 3`, and a movement direction to the right.

  - [1,0,2,**0**,3] -> [1,0,2,0,**3**] -> [1,0,2,**0**,2] -> [1,0,**2**,0,2] -> [1,0,1,**0**,2] -> [1,0,1,0,**2**] -> [1,0,1,**0**,1] -> [1,0,**1**,0,1] -> [1,0,0,**0**,1] -> [1,0,0,0,**1**] -> [1,0,0,**0**,0] -> [1,0,**0**,0,0] -> [1,**0**,0,0,0] -> [**1**,0,0,0,0] -> [0,0,0,0,0].

**Example 2:**

```bash
Input: nums = [2,3,4,0,4,1,0]

Output: 0
```

Explanation:

There are no possible valid selections.

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`
- There is at least one element `i` where `nums[i] == 0`.

## Hints/Notes

- 2024/11/27
- preSum
- [0x3F's solution](https://leetcode.cn/problems/make-array-elements-equal-to-zero/solutions/2991515/on-qian-hou-zhui-fen-jie-jian-ji-xie-fa-an2kt/)
- Weekly/Biweekly Contest 424

## Solution

Language: **C++**

```C++
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum == 0) {
            return nums.size() * 2;
        }
        int cur = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            if (sum % 2 == 0 && cur == sum / 2 && nums[i] == 0) {
                res += 2;
            } else if (sum % 2 && (cur == sum / 2 || cur == sum / 2 + 1) && nums[i] == 0) {
                res += 1;
            }

        }
        return res;
    }
};
```
