---
title: 3307. Find the K-th Character in String Game II
categories: Leetcode
date: 2024-10-15 16:56:08
tags:
    - Math
    - Bit Manipulation
    - Recursion
---

[3307. Find the K-th Character in String Game II](https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/)

## Description

Alice and Bob are playing a game. Initially, Alice has a string `word = "a"`.

You are given a **positive**  integer `k`. You are also given an integer array `operations`, where `operations[i]` represents the **type**  of the `i^th` operation.

Now Bob will ask Alice to perform **all**  operations in sequence:

- If `operations[i] == 0`, **append**  a copy of `word` to itself.
- If `operations[i] == 1`, generate a new string by **changing**  each character in `word` to its **next**  character in the English alphabet, and **append**  it to the original `word`. For example, performing the operation on `"c"` generates `"cd"` and performing the operation on `"zb"` generates `"zbac"`.

Return the value of the `k^th` character in `word` after performing all the operations.

**Note**  that the character `'z'` can be changed to `'a'` in the second type of operation.

**Example 1:**

```bash
Input: k = 5, operations = [0,0,0]

Output: "a"
```

Explanation:

Initially, `word == "a"`. Alice performs the three operations as follows:

- Appends `"a"` to `"a"`, `word` becomes `"aa"`.
- Appends `"aa"` to `"aa"`, `word` becomes `"aaaa"`.
- Appends `"aaaa"` to `"aaaa"`, `word` becomes `"aaaaaaaa"`.

**Example 2:**

```bash
Input: k = 10, operations = [0,1,0,1]

Output: "b"
```

Explanation:

Initially, `word == "a"`. Alice performs the four operations as follows:

- Appends `"a"` to `"a"`, `word` becomes `"aa"`.
- Appends `"bb"` to `"aa"`, `word` becomes `"aabb"`.
- Appends `"aabb"` to `"aabb"`, `word` becomes `"aabbaabb"`.
- Appends `"bbccbbcc"` to `"aabbaabb"`, `word` becomes `"aabbaabbbbccbbcc"`.

**Constraints:**

- `1 <= k <= 10^14`
- `1 <= operations.length <= 100`
- `operations[i]` is either 0 or 1.
- The input is generated such that `word` has **at least**  `k` characters after all operations.

## Hints/Notes

- bit manipulation
- Weekly Contest 417

## Solution

Language: **C++**

```C++
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        // after n operations, there are 2^n digits, which means
        // k is in the range [1, 2^n], and k - 1 is in the range
        // [0, 2^n - 1], i.e. k - 1 would have at most n digits
        k--;
        int count = 0;
        // 64 - __builtin_clz(k) is the number of bits of k,
        // if k < 2^m, we don't need to care about operations [2^m, n)
        // if k == 0, we still need one iteration, while __builtin_clz() doesn't accept 0
        n = k ? min(64 - __builtin_clz(k), n) : 1;
        while (n > 0) {
            // check the nth digit of k
            int digit = (long long)(k >> (n - 1)) & 1;
            // if digit is 0, then it's in the first half, else second half
            //  1. if it's in the first half, then operation[n - 1] wouldn't matter
            //  2. if it's in the second half, then we need to record one
            if (digit && operations[n - 1]) {
                count++;
            }
            n--;
        }
        return (count % 26) + 'a';
    }
};
```
