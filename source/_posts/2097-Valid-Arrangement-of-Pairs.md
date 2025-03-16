---
title: 2097. Valid Arrangement of Pairs
categories: Leetcode
date: 2025-03-15 22:36:59
tags:
    - Depth-First Search
    - Graph
    - Eulerian Circuit
---

[2097. Valid Arrangement of Pairs](https://leetcode.com/problems/valid-arrangement-of-pairs/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given a **0-indexed**  2D integer array `pairs` where pairs[i] = [start<sub>i</sub>, end<sub>i</sub>]. An arrangement of `pairs` is **valid**  if for every index `i` where `1 <= i < pairs.length`, we have end<sub>i-1</sub> == start<sub>i</sub>.

Return **any**  valid arrangement of `pairs`.

**Note:**  The inputs will be generated such that there exists a valid arrangement of `pairs`.

**Example 1:**

```bash
Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
Output: [[11,9],[9,4],[4,5],[5,1]]
```

**Explanation:**

This is a valid arrangement since end<sub>i-1</sub> always equals start<sub>i</sub>.

end<sub>0</sub> = 9 == 9 = start<sub>1</sub>

end<sub>1</sub> = 4 == 4 = start<sub>2</sub>

end<sub>2</sub> = 5 == 5 = start<sub>3</sub>

**Example 2:**

```bash
Input: pairs = [[1,3],[3,2],[2,1]]
Output: [[1,3],[3,2],[2,1]]
```

Explanation:
This is a valid arrangement since end<sub>i-1</sub> always equals start<sub>i</sub>.

end<sub>0</sub> = 3 == 3 = start<sub>1</sub>

end<sub>1</sub> = 2 == 2 = start<sub>2</sub>

The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.

**Example 3:**

```bash
Input: pairs = [[1,2],[1,3],[2,1]]
Output: [[1,2],[2,1],[1,3]]
```

Explanation:

This is a valid arrangement since end<sub>i-1</sub> always equals start<sub>i</sub>.

end<sub>0</sub> = 2 == 2 = start<sub>1</sub>

end<sub>1</sub> = 1 == 1 = start<sub>2</sub>

**Constraints:**

- `1 <= pairs.length <= 10^5`
- `pairs[i].length == 2`
- `0 <= start<sub>i</sub>, end<sub>i</sub> <= 10^9`
- `start<sub>i</sub> != end<sub>i</sub>`
- No two pairs are exactly the same.
- There **exists**  a valid arrangement of `pairs`.

## Hints/Notes

- 2025/02/06 Q2
- Eulerian Path
- [Leetcode solution](https://leetcode.com/problems/valid-arrangement-of-pairs/editorial/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_map<int, deque<int>> matrix;
    unordered_map<int, int> inDegree, outDegree;
    vector<int> path;
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        for (int i = 0; i < n; i++) {
            int start = pairs[i][0], end = pairs[i][1];
            matrix[start].push_back(end);
            outDegree[start]++;
            inDegree[end]++;
        }
        int startPoint = -1;
        for (auto& [k, _] : outDegree) {
            if (inDegree[k] < outDegree[k]) {
                startPoint = k;
                break;
            }
        }
        if (startPoint == -1) {
            startPoint = pairs[0][0];
        }
        dfs(startPoint);
        ranges::reverse(path);
        vector<vector<int>> res;
        for (int i = 0; i < path.size() - 1; i++) {
            res.push_back({path[i], path[i + 1]});
        }

        return res;
    }

    void dfs(int node) {
        while (!matrix[node].empty()) {
            int nextNode = matrix[node].front();
            matrix[node].pop_front();
            dfs(nextNode);
        }
        path.push_back(node);
    }
};
```
