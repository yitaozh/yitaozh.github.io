---
title: 650D. Zip-line
categories: Leetcode
date: 2024-06-14 17:36:37
tags:
    - binary search
    - data structures
    - dp
    - hashing
---

[D. Zip-line](https://codeforces.com/problemset/problem/650/D)

## Description

输入 n(1≤n≤4e5) m(1≤m≤4e5) 和长为 n 的数组 a(1≤a[i]≤1e9)，数组下标从 1 开始。
然后输入 m 个询问，每个询问输入两个数 i(1≤i≤n) 和 b(1≤b≤1e9)。

对于每个询问，输出把 a[i] 替换成 b 后，a 的最长严格递增子序列（LIS）的长度。
注意每个询问之间彼此独立，比如第一个询问把 a[1] 替换成 6，那么对于第二个询问，a[1] 还是原来的值。

## Hints/Notes

- LIS

## Solution

Language: **C++**

```C++
void solve(vector<int>& heights, map<int, vector<pair<int, int>>> queries, int m) {
    vector<int> pre;
    vector<int> LIS;
    vector<int> res(m, 0);
    // do a pre and post order LIS search, in each case,
    // add the order of the queried index to res array
    for (int i = 0; i < heights.size(); i++) {
        if (queries.contains(i)) {
            for (auto indexHeightPair : queries[i]) {
                int idx = indexHeightPair.first;
                int h = indexHeightPair.second;
                int index = find(LIS, h);
                res[idx] += index + 1;
            }
        }
        int height = heights[i];
        int index = find(LIS, height);
        if (index == LIS.size()) {
            LIS.push_back(height);
        } else {
            LIS[index] = height;
        }
        pre.push_back(index + 1);
    }
    int longest = LIS.size();
    for (int& height : heights) {
        height = -height;
    }
    vector<int> post(heights.size(), 0);
    LIS.clear();
    for (int i = heights.size() - 1; i >= 0; i--) {
        if (queries.contains(i)) {
            for (auto indexHeightPair : queries[i]) {
                int idx = indexHeightPair.first;
                int h = -indexHeightPair.second;
                int index = find(LIS, h);
                res[idx] += index;
            }
        }
        int height = heights[i];
        int index = find(LIS, height);
        if (index == LIS.size()) {
            LIS.push_back(height);
        } else {
            LIS[index] = height;
        }
        post[i] = index + 1;
    }
    map<int, vector<int>> numOfPre;
    unordered_set<int> indexOfLongest;
    for (int i = 0; i < heights.size(); i++) {
        // if i is in the longest LIS array
        if (pre[i] + post[i] - 1 == longest) {
            numOfPre[pre[i]].push_back(i);
            indexOfLongest.insert(i);
        }
    }
    for (int i = 0; i < heights.size(); i++) {
        if (!queries.contains(i)) {
            continue;
        }
        for (auto indexHeightPair : queries[i]) {
            int idx = indexHeightPair.first;
            if (!indexOfLongest.contains(i)) {
                res[idx] = max(res[idx], longest);
            } else {
                // if the height[i] is in all LIS
                if (numOfPre[pre[i]].size() > 1) {
                    res[idx] = max(res[idx], longest);
                } else {
                    res[idx] = max(res[idx], longest - 1);
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        out << res[i] << endl;
    }
}

int main() {
    int n, m;
    in >> n >> m;
    vector<int> heights;
    map<int, vector<pair<int, int>>> queries;
    for (int i = 1; i <= n; i++) {
        int height;
        in >> height;
        heights.push_back(height);
    }
    for (int i = 0; i < m; i++) {
        int index, height;
        in >> index >> height;
        index--;
        queries[index].push_back({i, height});
    }
    solve(heights, queries, m);
    return 0;
}
```
