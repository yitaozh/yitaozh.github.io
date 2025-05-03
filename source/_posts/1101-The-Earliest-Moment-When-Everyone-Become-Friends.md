---
title: 1101. The Earliest Moment When Everyone Become Friends
categories: Leetcode
date: 2025-05-03 01:52:36
tags:
    - Array
    - Union Find
    - Sorting
---

[1101. The Earliest Moment When Everyone Become Friends](https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/description/?envType=company&envId=google&favoriteSlug=google-three-months)

## Description

There are n people in a social group labeled from <code>0</code> to <code>n - 1</code>. You are given an array <code>logs</code> where <code>logs[i] = [timestamp<sub>i</sub>, x<sub>i</sub>, y<sub>i</sub>]</code> indicates that <code>x<sub>i</sub></code> and <code>y<sub>i</sub></code> will be friends at the time <code>timestamp<sub>i</sub></code>.

Friendship is **symmetric** . That means if <code>a</code> is friends with <code>b</code>, then <code>b</code> is friends with <code>a</code>. Also, person <code>a</code> is acquainted with a person <code>b</code> if <code>a</code> is friends with <code>b</code>, or <code>a</code> is a friend of someone acquainted with <code>b</code>.

Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return <code>-1</code>.

**Example 1:**

```bash
Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
Output: 20190301
Explanation:
The first event occurs at timestamp = 20190101, and after 0 and 1 become friends, we have the following friendship groups [0,1], [2], [3], [4], [5].
The second event occurs at timestamp = 20190104, and after 3 and 4 become friends, we have the following friendship groups [0,1], [2], [3,4], [5].
The third event occurs at timestamp = 20190107, and after 2 and 3 become friends, we have the following friendship groups [0,1], [2,3,4], [5].
The fourth event occurs at timestamp = 20190211, and after 1 and 5 become friends, we have the following friendship groups [0,1,5], [2,3,4].
The fifth event occurs at timestamp = 20190224, and as 2 and 4 are already friends, nothing happens.
The sixth event occurs at timestamp = 20190301, and after 0 and 3 become friends, we all become friends.
```

**Example 2:**

```bash
Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
Output: 3
Explanation: At timestamp = 3, all the persons (i.e., 0, 1, 2, and 3) become friends.
```

**Constraints:**

- <code>2 <= n <= 100</code>
- <code>1 <= logs.length <= 10^4</code>
- <code>logs[i].length == 3</code>
- <code>0 <= timestamp<sub>i</sub> <= 10^9</code>
- <code>0 <= x<sub>i</sub>, y<sub>i</sub> <= n - 1</code>
- <code>x<sub>i</sub> != y<sub>i</sub></code>
- All the values <code>timestamp<sub>i</sub></code> are **unique** .
- All the pairs <code>(x<sub>i</sub>, y<sub>i</sub>)</code> occur at most one time in the input.

## Hints/Notes

- 2025/04/28 Q2
- union finid
- [Leetcode solution](https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        ranges::sort(logs);
        int num_component = n;
        vector<int> roots(n);
        iota(roots.begin(), roots.end(), 0);
        for (auto& log : logs) {
            int x = log[1], y = log[2];
            int rootX = findRoot(x, roots), rootY = findRoot(y, roots);
            if (rootX != rootY) {
                roots[rootX] = rootY;
                if (--num_component == 1) {
                    return log[0];
                }
            }
        }
        return -1;
    }

    int findRoot(int root, vector<int> roots) {
        if (roots[root] != root) {
            roots[root] = findRoot(roots[root], roots);
        }
        return roots[root];
    }
};
```
