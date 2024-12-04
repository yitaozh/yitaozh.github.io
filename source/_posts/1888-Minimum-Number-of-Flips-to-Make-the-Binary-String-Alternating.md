---
title: 1888. Minimum Number of Flips to Make the Binary String Alternating
categories: Leetcode
date: 2024-10-25 21:34:32
tags:
    - String
    - Dynamic Programming
    - Greedy
    - Sliding Window
---

[1888. Minimum Number of Flips to Make the Binary String Alternating](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/)

## Description

You are given a binary string `s`. You are allowed to perform two types of operations on the string in any sequence:

- **Type-1: Remove**  the character at the start of the string `s` and **append**  it to the end of the string.
- **Type-2: Pick**  any character in `s` and **flip**  its value, i.e., if its value is `'0'` it becomes `'1'` and vice-versa.

Return the **minimum**  number of **type-2**  operations you need to perform such that `s` becomes **alternating** .

The string is called **alternating**  if no two adjacent characters are equal.

- For example, the strings `"010"` and `"1010"` are alternating, while the string `"0100"` is not.

**Example 1:**

```bash
Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
```

**Example 2:**

```bash
Input: s = "010"
Output: 0
Explanation: The string is already alternating.
```

**Example 3:**

```bash
Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`.

## Hints/Notes

- sliding window
- [0x3F's solution](https://leetcode.cn/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/solutions/815298/cong-qian-wang-hou-pi-pei-cong-hou-wang-uiq6a/)(didn't understand)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), right = 0, res = INT_MAX, prev = -1, cur = 0;
        while (right < 2 * n - 1) {
            int num = s[right % n] - '0';
            if (num == prev) {
                cur++;
                num ^= 1;
            }
            prev = num;
            if (right >= n - 1) {
                res = min(res, cur);
                int cur_head = s[right - n + 1];
                int next_head = s[right - n + 2];
                // if cur_head != next_head, then no need to change cur
                if (cur_head == next_head) {
                    cur = n - 1 - cur;
                    // I forget this step the first time
                    prev ^= 1;
                }
            }
            right++;
        }
        return res;
    }
};
```
