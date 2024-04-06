---
title: 187. Repeated DNA Sequences
categories: Leetcode
date: 2023-01-25 12:30:03
tags:
    - Hash Table
    - String
    - Bit Manipulation
    - Sliding Window
    - Rolling Hash
    - Hash Function
---

[187\. Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Hash Function](https://leetcode.com/tag/hash-function/)

The **DNA sequence** is composed of a series of nucleotides abbreviated as `'A'`, `'C'`, `'G'`, and `'T'`.

* For example, `"ACGAATTCCG"` is a **DNA sequence**.

When studying **DNA**, it is useful to identify repeated sequences within the DNA.

Given a string `s` that represents a **DNA sequence**, return all the **`10`-letter-long** sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in **any order**.

**Example 1:**

```text
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
```

**Example 2:**

```text
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
```

**Constraints:**

* 1 <= s.length <= 10<sup>5</sup>
* `s[i]` is either `'A'`, `'C'`, `'G'`, or `'T'`.

## Hints/Notes

* Rabin karb algorithm
* Make the string a int number(base number 4)
* Use a set to represent the results first, then transform it to vector to return

```C++
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        return vector<string>();
    }
}
```

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<int> nums;
        for (char c : s) {
            int num = 0;
            switch(c) {
                case 'A':
                    num = 0;
                    break;
                case 'C':
                    num = 1;
                    break;
                case 'G':
                    num = 2;
                    break;
                case 'T':
                    num = 3;
                    break;
            }
            nums.push_back(num);
        }
        int left = 0, right = 0, len = s.size(), sum = 0;
        set<int> exist;
        set<string> res;
        while (right < len) {
            int num = nums[right++];
            sum = sum * 4 + num;
            if (right - left == 10) {
                if (exist.count(sum)) {
                    res.insert(s.substr(left, right - left));
                } else {
                    exist.insert(sum);
                }
                sum -= nums[left++] * pow(4, 9);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
```
