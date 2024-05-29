---
title: 1343C. Alternating Subsequence
categories: Leetcode
date: 2024-05-29 00:00:03
tags:
---

TODO Remove the # before the problem number

## Hints/Notes

-

## Solution

Language: **C++**

```C++
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

void solve(vector<int>& nums) {
    int pos_size = 0, pos_res = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) {
            continue;
        }
        int positive = nums[i];
        size++;
        int j = i + 1;
        for (; j < nums.size(); j++) {
            if (nums[j] < 0) {
                break;
            }
            if (nums[j] > positive) {
                positive = nums[j];
            }
        }
        int negative = INT_MAX;
        for (; j < nums.size(); j++) {
            if (nums[j] > 0) {
                break;
            }
            if (nums[j] < negative) {
                negative = num[j];
            }
        }
        if (negative != INT_MAX) size++;

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        int size;
        cin >> size;
        vector<int> nums;
        for (int i = 0; i < size(); i++) {
            int num;
            cin >> num;
            nums.push_back(num);
        }
        solve(nums);
    }
    return 0;
}
```
