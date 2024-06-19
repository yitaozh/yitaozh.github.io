---
title: 1237D. Balanced Playlist
categories: Leetcode
date: 2024-06-19 00:50:55
tags:
    - binary search
    - data structures
    - implementation
---

[D. Balanced Playlist](https://codeforces.com/problemset/problem/1237/D)

## Description

输入 n(2≤n≤1e5) 和长为 n 的数组 a(1≤a[i]≤1e9)。

0x3F 的播放列表中有 n 首歌，列表中的第 i 首歌的好听度为 a[i]。
这 n 首歌按照【列表循环】模式播放。播放完第 n 首歌，就会播放第 1 首歌。
如果 0x3F 听到一首歌，发现它的好听度 * 2 小于之前听到的最好听的歌，那么 0x3F 就会立刻停止播放。

输出 n 个数，其中第 i 个数等于，从播放列表中的第 i 首歌开始听，到停止播放时，完整播放的歌曲数目（停止播放时的那首歌不算）。
对于同一首歌，如果它被完整播放 x 次，就会统计 x 次。见示例 2。
如果可以无限循环，输出 -1。

## Hints/Notes

- monotonic stack

## Solution

Language: **C++**

```C++
#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

#include <fstream>

using namespace std;

istream &in = cin;
ostream &out = cout;

void solve(vector<int>& nums) {
    int size = nums.size();
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < size; i++) {
            nums.push_back(nums[i]);
        }
    }
    int left = 0, right = 0;
    deque<int> q;
    // we need to always keep the largest value, from left to right
    // we should use monotonic stack, but since we need to deque from
    // front, so deque serve our need better
    while (left < size) {
        while ((q.empty() || 2 * nums[right] >= q.front()) && right < nums.size()) {
            while (!q.empty() && nums[right] > q.back()) {
                q.pop_back();
            }
            q.push_back(nums[right]);
            right++;
        }
        int res = (right == nums.size()) ? -1 : right - left;
        out << res << " ";
        if (q.front() == nums[left]) {
            q.pop_front();
        }
        left++;
    }
    out << endl;
}

int main() {
    int n;
    in >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        in >> num;
        nums.push_back(num);
    }
    solve(nums);
    return 0;
}
```
