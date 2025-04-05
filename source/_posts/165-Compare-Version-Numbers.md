---
title: 165. Compare Version Numbers
categories: Leetcode
date: 2025-03-31 02:42:35
tags:
    - Two Pointers
    - String
---

[165. Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/description/?envType=company&envId=apple&favoriteSlug=apple-six-months)

## Description

Given two **version strings** , `version1` and `version2`, compare them. A version string consists of **revisions**  separated by dots `'.'`. The **value of the revision**  is its **integer conversion**  ignoring leading zeros.

To compare version strings, compare their revision values in **left-to-right order** . If one of the version strings has fewer revisions, treat the missing revision values as `0`.

Return the following:

- If `version1 < version2`, return -1.
- If `version1 > version2`, return 1.
- Otherwise, return 0.

**Example 1:**

```bash
Input: version1 = "1.2", version2 = "1.10"

Output: -1
```

Explanation:

version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

**Example 2:**

```bash
Input: version1 = "1.01", version2 = "1.001"

Output: 0
```

Explanation:

Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

**Example 3:**

```bash
Input: version1 = "1.0", version2 = "1.0.0.0"

Output: 0
```

Explanation:

version1 has less revisions, which means every missing revision are treated as "0".

**Constraints:**

- `1 <= version1.length, version2.length <= 500`
- `version1` and `version2`only contain digits and `'.'`.
- `version1` and `version2`**are valid version numbers** .
- All the given revisions in`version1` and `version2`can be stored in a **32-bit integer** .

## Hints/Notes

- 2025/03/31 Q1
- string
- [Leetcode solution](https://leetcode.com/problems/compare-version-numbers/editorial/?envType=company&envId=apple&favoriteSlug=apple-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;
        istringstream iss1(version1), iss2(version2);
        string token;
        while (getline(iss1, token, '.')) v1.push_back(token);
        while (getline(iss2, token, '.')) v2.push_back(token);
        for (int i = 0; i < max(v1.size(), v2.size()); i++) {
            int i1 = i < v1.size() ? stoi(v1[i]) : 0;
            int i2 = i < v2.size() ? stoi(v2[i]) : 0;
            if (i1 != i2) return i1 > i2 ? 1 : -1;
        }
        return 0;
    }
};
```
