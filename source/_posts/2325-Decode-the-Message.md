---
title: 2325. Decode the Message
categories: Leetcode
date: 2025-05-11 17:43:39
tags:
    - Hash Table
    - String
---

[2325. Decode the Message](https://leetcode.com/problems/decode-the-message/description/?envType=company&envId=coinbase&favoriteSlug=coinbase-all)

## Description

You are given the strings <code>key</code> and <code>message</code>, which represent a cipher key and a secret message, respectively. The steps to decode <code>message</code> are as follows:

- Use the **first**  appearance of all 26 lowercase English letters in <code>key</code> as the **order**  of the substitution table.
- Align the substitution table with the regular English alphabet.
- Each letter in <code>message</code> is then **substituted**  using the table.
- Spaces <code>' '</code> are transformed to themselves.

- For example, given <code>key = "**hap** p**y**  **bo** y"</code> (actual key would have **at least one**  instance of each letter in the alphabet), we have the partial substitution table of (<code>'h' -> 'a'</code>, <code>'a' -> 'b'</code>, <code>'p' -> 'c'</code>, <code>'y' -> 'd'</code>, <code>'b' -> 'e'</code>, <code>'o' -> 'f'</code>).

Return the decoded message.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/05/08/ex1new4.jpg" style="width: 752px; height: 150px;">

```bash
Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
Output: "this is a secret"
Explanation: The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "**the**  **quick**  **brown**  **f** o**x**  **j** u**mps**  o**v** er the **lazy**  **d** o**g** ".
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/05/08/ex2new.jpg" style="width: 754px; height: 150px;">

```bash
Input: key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
Output: "the five boxing wizards jump quickly"
Explanation: The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "**eljuxhpwnyrdgtqkviszcfmabo** ".
```

**Constraints:**

- <code>26 <= key.length <= 2000</code>
- <code>key</code> consists of lowercase English letters and <code>' '</code>.
- <code>key</code> contains every letter in the English alphabet (<code>'a'</code> to <code>'z'</code>) **at least once** .
- <code>1 <= message.length <= 2000</code>
- <code>message</code> consists of lowercase English letters and <code>' '</code>.

## Hints/Notes

- 2025/05/05 Q1
- String
- No solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mapping;
        char cur_key = 'a';
        for (char& c : key) {
            if (isalpha(c) && !mapping.contains(c)) {
                mapping[c] = cur_key;
                cur_key++;
            }
            if (mapping.size() >= 26) {
                break;
            }
        }
        string res;
        for (char c : message) {
            if (isalpha(c)) {
                res.push_back(mapping[c]);
            } else {
                res.push_back(' ');
            }
        }
        return res;
    }
};
```
