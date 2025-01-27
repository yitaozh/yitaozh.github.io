---
title: 721. Accounts Merge
categories: Leetcode
date: 2025-01-27 15:29:58
tags:
    - Array
    - Hash Table
    - String
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Sorting
---

[721. Accounts Merge](https://leetcode.com/problems/accounts-merge/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a list of `accounts` where each element `accounts[i]` is a list of strings, where the first element `accounts[i][0]` is a name, and the rest of the elements are **emails**  representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails **in sorted order** . The accounts themselves can be returned in **any order** .

**Example 1:**

```bash
Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
```

**Example 2:**

```bash
Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
```

**Constraints:**

- `1 <= accounts.length <= 1000`
- `2 <= accounts[i].length <= 10`
- `1 <= accounts[i][j].length <= 30`
- `accounts[i][0]` consists of English letters.
- `accounts[i][j] (for j > 0)` is a valid email.

## Hints/Notes

- 2025/01/27
- union find or dfs
- [0x3F's solution](https://leetcode.cn/problems/accounts-merge/solutions/2844186/ha-xi-biao-dfspythonjavacgojsrust-by-end-z9nh/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

Union find:

```C++
class Solution {
public:
    vector<int> roots;

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        roots.resize(n);
        iota(roots.begin(), roots.end(), 0);
        unordered_map<string, int> emailToIndex;
        vector<string> names;
        for (int i = 0; i < n; i++) {
            auto& account = accounts[i];
            string name = account[0];
            names.push_back(name);
            vector<int> indexes;
            for (int j = 1; j < account.size(); j++) {
                if (emailToIndex.contains(account[j])) {
                    indexes.push_back(emailToIndex[account[j]]);
                } else {
                    emailToIndex[account[j]] = i;
                }
            }
            if (!indexes.empty()) {
                int root = findRoot(indexes[0]);
                for (int j = 1; j < indexes.size(); j++) {
                    int rootJ = findRoot(indexes[j]);
                    roots[rootJ] = root;
                }
                roots[i] = root;
            }
        }
        unordered_map<int, set<string>> m;
        for (auto& [email, idx] : emailToIndex) {
            int root = findRoot(idx);
            m[root].insert(email);
        }
        vector<vector<string>> res;
        for (auto& [idx, v] : m) {
            vector<string> cur;
            cur.push_back(names[idx]);
            cur.insert(cur.end(), v.begin(), v.end());
            res.push_back(cur);
        }
        return res;
    }

    int findRoot(int root) {
        if (roots[root] != root) {
            roots[root] = findRoot(roots[root]);
        }
        return roots[root];
    }
};
```

dfs:

```C++
class Solution {
public:
    vector<bool> visited;
    unordered_map<string, vector<int>> m;
    unordered_set<string> email_set;

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        visited.resize(n, false);
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                m[accounts[i][j]].push_back(i);
            }
        }
        vector<vector<string>> res;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            email_set.clear();
            dfs(i, accounts);
            vector<string> cur = {accounts[i][0]};
            cur.insert(cur.end(), email_set.begin(), email_set.end());
            ranges::sort(cur.begin() + 1, cur.end());
            res.push_back(cur);
        }
        return res;
    }

    void dfs(int index, vector<vector<string>>& accounts) {
        visited[index] = true;
        unordered_set<int> s;
        for (int i = 1; i < accounts[index].size(); i++) {
            string& email = accounts[index][i];
            email_set.insert(email);
            for (int j : m[email]) {
                if (!visited[j]) {
                    dfs(j, accounts);
                }
            }
        }

    }
};
```
