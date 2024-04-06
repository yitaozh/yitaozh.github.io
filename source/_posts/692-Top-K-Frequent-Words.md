---
title: 692. Top K Frequent Words
categories: Leetcode
date: 2023-11-06 23:12:02
tags:
    - Hash Table
    - String
    - Trie
    - Sorting
    - Heap (Priority Queue)
    - Bucket Sort
    - Counting
---

[692\. Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Trie](https://leetcode.com/tag/https://leetcode.com/tag/trie//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Bucket Sort](https://leetcode.com/tag/https://leetcode.com/tag/bucket-sort//), [Counting](https://leetcode.com/tag/https://leetcode.com/tag/counting//)

Given an array of strings `words` and an integer `k`, return _the_ `k` _most frequent strings_.

Return the answer **sorted** by **the frequency** from highest to lowest. Sort the words with the same frequency by their **lexicographical order**.

**Example 1:**

```bash
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
```

**Example 2:**

```bash
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
```

**Constraints:**

* `1 <= words.length <= 500`
* `1 <= words[i].length <= 10`
* `words[i]` consists of lowercase English letters.
* `k` is in the range `[1, The number of **unique** words[i]]`

**Follow-up:** Could you solve it in `O(n log(k))` time and `O(n)` extra space?

## Hints/Notes

* priority queue

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (string word : words) {
            m[word]++;
        }
        auto cmp = [](pair<int, string> lhs, pair<int, string> rhs) {
            if (lhs.first != rhs.first) {
                return lhs.first < rhs.first;
            }
            return lhs.second > rhs.second;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        for (auto it : m) {
            string word = it.first;
            int freq = it.second;
            pq.push({freq, word});
        }
        vector<string> res;
        while (k > 0 && !pq.empty()) {
            auto pair = pq.top();
            pq.pop();
            res.push_back(pair.second);
            k--;
        }
        return res;
    }
};
```
