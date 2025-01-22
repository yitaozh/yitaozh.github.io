---
title: 3315. Construct the Minimum Bitwise Array II
categories: Leetcode
date: 2024-10-19 16:34:48
tags:
    - Array
    - Bit Manipulation
---

[3315. Construct the Minimum Bitwise Array II](https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/)

## Description

You are given an array `nums` consisting of `n` prime integers.

You need to construct an array `ans` of length `n`, such that, for each index `i`, the bitwise `OR` of `ans[i]` and `ans[i] + 1` is equal to `nums[i]`, i.e. `ans[i] OR (ans[i] + 1) == nums[i]`.

Additionally, you must **minimize**  each value of `ans[i]` in the resulting array.

If it is not possible to find such a value for `ans[i]` that satisfies the **condition** , then set `ans[i] = -1`.

**Example 1:**

```bash
Input: nums = [2,3,5,7]

Output: [-1,1,4,3]
```

Explanation:

- For `i = 0`, as there is no value for `ans[0]` that satisfies `ans[0] OR (ans[0] + 1) = 2`, so `ans[0] = -1`.
- For `i = 1`, the smallest `ans[1]` that satisfies `ans[1] OR (ans[1] + 1) = 3` is `1`, because `1 OR (1 + 1) = 3`.
- For `i = 2`, the smallest `ans[2]` that satisfies `ans[2] OR (ans[2] + 1) = 5` is `4`, because `4 OR (4 + 1) = 5`.
- For `i = 3`, the smallest `ans[3]` that satisfies `ans[3] OR (ans[3] + 1) = 7` is `3`, because `3 OR (3 + 1) = 7`.

**Example 2:**

```bash
Input: nums = [11,13,31]

Output: [9,12,15]
```

Explanation:

- For `i = 0`, the smallest `ans[0]` that satisfies `ans[0] OR (ans[0] + 1) = 11` is `9`, because `9 OR (9 + 1) = 11`.
- For `i = 1`, the smallest `ans[1]` that satisfies `ans[1] OR (ans[1] + 1) = 13` is `12`, because `12 OR (12 + 1) = 13`.
- For `i = 2`, the smallest `ans[2]` that satisfies `ans[2] OR (ans[2] + 1) = 31` is `15`, because `15 OR (15 + 1) = 31`.

**Constraints:**

- `1 <= nums.length <= 100`
- `2 <= nums[i] <= 10^9`
- `nums[i]` is a prime number.

## Hints/Notes

- 2024/09/24
- find the rightmost 0's index, make the 1 at its right to 0
- bit manipulation, lowbit(rightmost 1) of t = t & -t
- so the right most 0 of t is (~t) & (-(~t))
- [0x3F's solution](https://leetcode.cn/problems/construct-the-minimum-bitwise-array-ii/solutions/2948584/o1-ji-suan-mei-ge-shu-pythonjavacgo-by-e-6l9l/)(checked)
- Biweekly Contest 141

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            if ((num & 1) == 0) {
                res.push_back(-1);
            } else {
                int tmp = ~num;
                tmp &= -tmp;
                // now tmp is lowbit of (~num)
                // i.e. the rightmost 0's bit set for num
                // shift the value right one bit, and xor make the
                // right bit to 0(previously 1)
                res.push_back(num ^ (tmp >> 1));
            }
        }
        return res;
    }
};
```
