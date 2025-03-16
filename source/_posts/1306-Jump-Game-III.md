---
title: 1306. Jump Game III
categories: Leetcode
date: 2025-03-15 22:56:39
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
---

[1306. Jump Game III](https://leetcode.com/problems/jump-game-iii/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

Given an array of non-negative integers `arr`, you are initially positioned at `start`index of the array. When you are at index `i`, you can jumpto `i + arr[i]` or `i - arr[i]`, check if you can reach**any**  index with value 0.

Notice that you can not jump outside of the array at any time.

**Example 1:**

```bash
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation:
All possible ways to reach at index 3 with value 0 are:
index 5 -> index 4 -> index 1 -> index 3
index 5 -> index 6 -> index 4 -> index 1 -> index 3
```

**Example 2:**

```bash
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true
**Explanation:
** One possible way to reach at index 3 with value 0 is:
index 0 -> index 4 -> index 1 -> index 3
```

**Example 3:**

```bash
Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
```

**Constraints:**

- `1 <= arr.length <= 5 * 10^4`
- `0 <= arr[i] <arr.length`
- `0 <= start < arr.length`

## Hints/Notes

- 2025/02/06 Q3
- dfs
- [Leetcode solution](https://leetcode.com/problems/jump-game-iii/editorial/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        int n = arr.size();
        vector<bool> visited(n, false);
        visited[start] = true;
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            if (arr[pos] == 0) {
                return true;
            }
            vector<int> possiblePos = {pos + arr[pos], pos - arr[pos]};
            for (int new_pos : possiblePos) {
                if (new_pos >= 0 && new_pos < n && !visited[new_pos]) {
                    q.push(new_pos);
                    visited[new_pos] = true;
                }
            }
        }
        return false;
    }
};
```
