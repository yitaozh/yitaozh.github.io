---
title: 839. Similar String Groups
categories: Leetcode
date: 2025-04-20 17:48:24
tags:
    - Array
    - Hash Table
    - String
    - Depth-First Search
    - Breadth-First Search
    - Union Find
---

[839. Similar String Groups](https://leetcode.com/problems/similar-string-groups/description/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Description

Two strings, `X` and `Y`, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string `X`.

For example, `"tars"`and `"rats"`are similar (swapping at positions `0` and `2`), and `"rats"` and `"arts"` are similar, but `"star"` is not similar to `"tars"`, `"rats"`, or `"arts"`.

Together, these form two connected groups by similarity: `{"tars", "rats", "arts"}` and `{"star"}`. Notice that `"tars"` and `"arts"` are in the same group even though they are not similar. Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list `strs` of strings where every string in `strs` is an anagram of every other string in `strs`. How many groups are there?

**Example 1:**

```bash
Input: strs = ["tars","rats","arts","star"]
Output: 2
```

**Example 2:**

```bash
Input: strs = ["omv","ovm"]
Output: 1
```

**Constraints:**

- `1 <= strs.length <= 300`
- `1 <= strs[i].length <= 300`
- `strs[i]` consists of lowercase letters only.
- All words in `strs` have the same length and are anagrams of each other.

## Hints/Notes

- 2025/04/21 Q1
- union find
- [Leetcode solution](https://leetcode.com/problems/similar-string-groups/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> roots;

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        roots.resize(n);
        iota(roots.begin(), roots.end(), 0);
        for (int i = 0; i < strs.size(); i++) {
            for (int j = i + 1; j < strs.size(); j++) {
                int len = strs[i].size(), diff = 0;
                for (int k = 0; k < len; k++) {
                    if (strs[i][k] != strs[j][k]) {
                        diff++;
                    }
                }
                if (diff == 2 || strs[i] == strs[j]) {
                    int root1 = findRoot(i), root2 = findRoot(j);
                    roots[root1] = root2;
                }
            }
        }
        set<int> differentRoots;
        for (int i = 0; i < n; i++) {
            differentRoots.insert(findRoot(i));
        }
        return differentRoots.size();
    }

    int findRoot(int root) {
        if (roots[root] != root) {
            roots[root] = findRoot(roots[root]);
        }
        return roots[root];
    }
};
```
