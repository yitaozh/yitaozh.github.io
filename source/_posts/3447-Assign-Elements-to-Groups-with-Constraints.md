---
title: 3447. Assign Elements to Groups with Constraints
categories: Leetcode
date: 2025-03-10 01:58:04
tags:
    - Array
    - Hash Table
---

[3447. Assign Elements to Groups with Constraints](https://leetcode.com/problems/assign-elements-to-groups-with-constraints/description/)

## Description

You are given an integer array `groups`, where `groups[i]` represents the size of the `i^th` group. You are also given an integer array `elements`.

Your task is to assign **one**  element to each group based on the following rules:

- An element at index `j` can be assigned to a group `i` if `groups[i]` is **divisible**  by `elements[j]`.
- If there are multiple elements that can be assigned, assign the element with the **smallest index**  `j`.
- If no element satisfies the condition for a group, assign -1 to that group.

Return an integer array `assigned`, where `assigned[i]` is the index of the element chosen for group `i`, or -1 if no suitable element exists.

**Note** : An element may be assigned to more than one group.

**Example 1:**

```bash
Input: groups = [8,4,3,2,4], elements = [4,2]

Output: [0,0,-1,1,0]
```

Explanation:

- `elements[0] = 4` is assigned to groups 0, 1, and 4.
- `elements[1] = 2` is assigned to group 3.
- Group 2 cannot be assigned any element.

**Example 2:**

```bash
Input: groups = [2,3,5,7], elements = [5,3,3]

Output: [-1,1,0,-1]
```

Explanation:

- `elements[1] = 3` is assigned to group 1.
- `elements[0] = 5` is assigned to group 2.
- Groups 0 and 3 cannot be assigned any element.

**Example 3:**

```bash
Input: groups = [10,21,30,41], elements = [2,1]

Output: [0,1,0,1]
```

Explanation:

`elements[0] = 2` is assigned to the groups with even values, and `elements[1] = 1` is assigned to the groups with odd values.

**Constraints:**

- `1 <= groups.length <= 10^5`
- `1 <= elements.length <= 10^5`
- `1 <= groups[i] <= 10^5`
- `1 <= elements[i] <= 10^5`

## Hints/Notes

- 2025/02/24 Q1
- Harmonic series
- [0x3F's solution](https://leetcode.cn/problems/assign-elements-to-groups-with-constraints/solutions/3068620/diao-he-ji-shu-mei-ju-yu-chu-li-mei-ge-s-8r67/)(checked)
- Weekly Contest 436

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = elements.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            if (!m.contains(elements[i])) {
                m[elements[i]] = i;
            }
        }
        int max_number = ranges::max(groups);
        vector<int> allNumbers(max_number + 1, INT_MAX);
        for (auto& [k, v] : m) {
            int cur = k;
            while (cur <= max_number) {
                if (allNumbers[cur] > v) {
                    allNumbers[cur] = v;
                }
                cur += k;
            }
        }
        vector<int> res;
        for (auto group : groups) {
            if (allNumbers[group] == INT_MAX) {
                res.push_back(-1);
            } else {
                res.push_back(allNumbers[group]);
            }
        }
        return res;
    }
};
```
