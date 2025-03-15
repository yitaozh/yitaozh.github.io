---
title: 56. Merge Intervals
categories: Leetcode
date: 2024-12-22 01:25:58
tags:
    - Array
    - Sorting
---

[56. Merge Intervals](https://leetcode.com/problems/merge-intervals/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an array of `intervals`where `intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]`, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

**Example 1:**

```bash
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```

**Example 2:**

```bash
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

**Constraints:**

- `1 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= start<sub>i</sub> <= end<sub>i</sub> <= 10^4`

## Hints/Notes

- 2024/12/21
- sort
- [0x3F's solution](https://leetcode.cn/problems/merge-intervals/solutions/2798138/jian-dan-zuo-fa-yi-ji-wei-shi-yao-yao-zh-f2b3/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        ranges::sort(intervals);
        int n = intervals.size();
        for (int i = 0; i < n; ) {
            int start = intervals[i][0], end = intervals[i][1];
            i++;
            while (i < n && intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
                i++;
            }
            res.push_back({start, end});
        }
        return res;
    }
};
```

AutoX phone screen problem:

```C++
/*
A span is defined as [start, width]. Given two lists of spans <list1, list2>, write an algorithm to determine whether list1 fully covers list2 or not.
    1) list1=[[0.5, 0.3], [0.7, 0.6]], list2=[[0.5, 0.7]] -> true
    2) list1=[[0.7, 0.6], [0.5, 0.3]], list2=[[0.7, 0.65]] -> false
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

bool canFullyCover(vector<pair<double, double>> list1, vector<pair<double, double>> list2) {
    int size1 = list1.size(), size2 = list2.size();
    if (size2 == 0) {
        return true;
    }
    if (size1 == 0 && size2 != 0) {
        return false;
    }
    ranges::sort(list1); ranges::sort(list2);
    int idx1 = 0, idx2 = 0;
    stack<pair<double, double>> prevPair1, prevPair2;
    while ((idx1 < size1 || !prevPair1.empty()) && (idx2 < size2 || !prevPair2.empty())) {
        // high level ideas:
        // 1. we need to construct the pair1/pair2 if there's no prevPair1/prevPair2
        // 2. after the construction, we can compare the two intervals
        double start1, end1;
        if (!prevPair1.empty()) {
            start1 = prevPair1.top().first;
            end1 = prevPair1.top().second;
        } else {
            start1 = list1[idx1].first, end1 = start1 + list1[idx1].second;
            while (idx1 < size1 && list1[idx1].first <= end1) {
                double new_end = list1[idx1].first + list1[idx1].second;
                end1 = max(end1, new_end);
                idx1++;
            }
        }

        double start2, end2;
        if (!prevPair2.empty()) {
            start2 = prevPair2.top().first;
            end2= prevPair2.top().second;
        } else {
            start2 = list2[idx2].first, end2 = list2[idx2].first + list2[idx2].second;
            while (idx2 < size2 && list2[idx2].first <= end2) {
                double new_end = list2[idx2].first + list2[idx2].second;
                end2 = max(end2, new_end);
                idx2++;
            }
        }

        if (start2 < start1) {
            return false;
        } else {
            if (end1 < start2) {
                if (!prevPair1.empty()) prevPair1.pop();
                prevPair2.push({start2, end2});
                continue;
            } else {
                if (end2 > end1) {
                    return false;
                } else if (end2 == end1) {
                    if (!prevPair1.empty()) prevPair1.pop();
                    if (!prevPair2.empty()) prevPair2.pop();
                } else{
                    if (!prevPair2.empty()) prevPair2.pop();
                    prevPair1.push({start1, end1});
                    continue;
                }
            }
        }
    }
    if (idx2 == size2 && prevPair2.empty()) {
        return true;
    } else {
        return false;
    }
}

// To execute C++, please define "int main()"
int main() {
    vector<pair<double, double>> list1, list2;
    list1 = {{0.5, 0.3}, {0.7, 0.7}};
    list2 = {{0.5, 0.7}};
    cout << canFullyCover(list1, list2) << endl;
    list1 = {{0.5, 0.3}, {0.7, 0.6}};
    list2 = {{0.5, 0.9}};
    cout << canFullyCover(list1, list2) << endl;;
    list1 = {{0.5, 0.3}, {0.7, 0.6}};
    list2 = {};
    cout << canFullyCover(list1, list2) << endl;;
    return 0;
}
```
