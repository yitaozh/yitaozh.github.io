---
title: 30. Substring with Concatenation of All Words
categories: Leetcode
date: 2024-10-28 20:48:00
tags:
    - Hash Table
    - String
    - Sliding Window
---

[30. Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/)

## Description

You are given a string `s` and an array of strings `words`. All the strings of `words` are of **the same length** .

A **concatenated string**  is a string that exactly contains all the strings of any permutation of `words` concatenated.

- For example, if `words = ["ab","cd","ef"]`, then `"abcdef"`, `"abefcd"`, `"cdabef"`, `"cdefab"`, `"efabcd"`, and `"efcdab"` are all concatenated strings. `"acdbef"` is not a concatenated string because it is not the concatenation of any permutation of `words`.

Return an array of the starting indices of all the concatenated substrings in `s`. You can return the answer in **any order** .

**Example 1:**

```bash
Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]
```

Explanation:

The substring starting at 0 is `"barfoo"`. It is the concatenation of `["bar","foo"]` which is a permutation of `words`.<br>
The substring starting at 9 is `"foobar"`. It is the concatenation of `["foo","bar"]` which is a permutation of `words`.

**Example 2:**

```bash
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []
```

Explanation:

There is no concatenated substring.

**Example 3:**

```bash
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]
```

Explanation:

The substring starting at 6 is `"foobarthe"`. It is the concatenation of `["foo","bar","the"]`.<br>
The substring starting at 9 is `"barthefoo"`. It is the concatenation of `["bar","the","foo"]`.<br>
The substring starting at 12 is `"thefoobar"`. It is the concatenation of `["the","foo","bar"]`.

**Constraints:**

- `1 <= s.length <= 10^4`
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 30`
- `s` and `words[i]` consist of lowercase English letters.

## Hints/Notes

- string hash
- sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    struct HashObj {
        const int MOD = 1'070'777'777;
        vector<__int128> P, H;
        template<typename Container> HashObj(Container &s, const int BASE) {
            int n = s.size();
            P.resize(n + 1); H.resize(n + 1);
            P[0] = 1; H[0] = 0;
            for (int i = 1; i <= n; i++) {
                P[i] = P[i - 1] * BASE % MOD;
            }
            // hash(s) = s[0] * base^(n-1) + s[1] * base^(n-2) + ... + s[n-2] * base + s[n-1]
            for (int i = 1; i <= n; i++) {
                H[i] = (H[i - 1] * BASE + s[i - 1]) % MOD;
            }
        }

        // the hash between [l, r]
        long long query(int l, int r) {
            if (l > r) return 0;
            return ((H[r + 1] - H[l] * P[r - l + 1]) % MOD + MOD) % MOD;
        }
    };

    vector<int> findSubstring(string s, vector<string>& words) {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        const int BASE = uniform_int_distribution<>(8e8, 9e8)(rng);
        int k = words.size();
        unordered_map<long long, int> m;
        for (int i = 0; i < k; i++) {
            string word = words[i];
            HashObj obj(word, BASE);
            m[obj.H[word.size()]]++;
        }
        int word_size = words[0].size(), total = m.size();
        HashObj sObj(s, BASE);
        vector<int> res;
        // the start index can be from 0, to word_size
        for (int i = 0; i < word_size; i++) {
            int right = 0, valid = 0;
            unordered_map<long long, int> cur;
            while (i + (right + 1) * word_size <= s.size()) {
                int l = i + right * word_size, r = i + (right + 1) * word_size - 1;
                long long h = sObj.query(l, r);
                if (m.contains(h)) {
                    cur[h]++;
                    if (cur[h] == m[h]) {
                        valid++;
                    }
                }
                if (right >= k - 1) {
                    l = i + (right - k + 1) * word_size;
                    r = i + (right - k + 2) * word_size - 1;
                    if (valid == m.size()) {
                        res.push_back(l);
                    }
                    h = sObj.query(l, r);
                    if (m.contains(h)) {
                        if (cur[h] == m[h]) {
                            valid--;
                        }
                        cur[h]--;
                    }
                }
                right++;
            }
        }
        return res;
    }
};
```
