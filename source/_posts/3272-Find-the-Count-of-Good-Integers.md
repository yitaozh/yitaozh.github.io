---
title: 3272. Find the Count of Good Integers
categories: Leetcode
date: 2024-10-06 16:22:51
tags:
    - Hash Table
    - Math
    - Combinatorics
    - Enumeration
---

[3272. Find the Count of Good Integers](https://leetcode.com/problems/find-the-count-of-good-integers/description/)

## Description

You are given two **positive**  integers `n` and `k`.

An integer `x` is called **k-palindromic**  if:

- `x` is a palindrome.
- `x` is divisible by `k`.

An integer is called **good**  if its digits can be rearranged to form a **k-palindromic**  integer. For example, for `k = 2`, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.

Return the count of **good**  integers containing `n` digits.

**Note**  that any integer must **not**  have leading zeros, **neither**  before **nor**  after rearrangement. For example, 1010 cannot be rearranged to form 101.

**Example 1:**

```bash
Input: n = 3, k = 5

Output: 27
```

Explanation:

Some of the good integers are:

- 551 because it can be rearranged to form 515.
- 525 because it is already k-palindromic.

**Example 2:**

```bash
Input: n = 1, k = 4

Output: 2
```

Explanation:

The two good integers are 4 and 8.

**Example 3:**

```bash
Input: n = 5, k = 6

Output: 2468
```

**Constraints:**

- `1 <= n <= 10`
- `1 <= k <= 9`

## Hints/Notes

- Combinatorics
- Biweekly Contest 138

## Solution

Language: **C++**

```C++
class Solution {
public:

    long long countGoodIntegers(int n, int k) {
        vector<int> fac = {1};
        for (int i = 1; i <= n; i++) {
            int prev = fac.back();
            fac.push_back(prev * i);
        }
        int start = (int)pow(10, (n - 1) / 2);
        unordered_set<long> visited;
        long long res = 0;
        for (int i = start; i < start * 10; i++) {
            vector<int> bits;
            int count[10] = {0}, val = i, curIdx = n - 1;
            while (val != 0) {
                int tmp = val % 10;
                bits.insert(bits.begin(), tmp);
                val /= 10;
            }
            vector<int> whole(bits);
            vector<int> rev(bits.rbegin() + n % 2, bits.rend());
            whole.insert(whole.end(), rev.begin(), rev.end());
            long wholeNum = getVal(whole);
            if (wholeNum % k) {
                continue;
            }
            // by the end of a valid iteration, we have calculated all the
            // combinator of digits in whole, so if a later number has the
            // same digit set, we can skip
            long minVal = reordered(whole);
            if (visited.contains(minVal)) {
                continue;
            }
            visited.insert(minVal);
            for (int j = 0; j < whole.size(); j++) {
                count[whole[j]]++;
            }
            // at this time, we are sure that this number is palindromic
            // now we want to know how many combinations we can get
            // the first digit cannot be 0, while the following bits can
            // be any number
            int num = (n - count[0]) * fac[n - 1];
            // for each digits(0 ~ 9), their own permutation should be divided
            for (int j = 0; j < 10; j++) {
                num /= fac[count[j]];
            }
            res += num;
        }
        return res;
    }

    long reordered(vector<int> bits) {
        sort(bits.begin(), bits.end());
        return getVal(bits);
    }

    long getVal(vector<int>& bits) {
        long sum = 0;
        for (int i = 0; i < bits.size(); i++) {
            sum *= 10;
            sum += bits[i];
        }
        return sum;
    }
};
```
