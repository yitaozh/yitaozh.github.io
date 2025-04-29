---
title: 1813. Sentence Similarity III
categories: Leetcode
date: 2025-04-05 21:54:39
tags:
    - Array
    - Two Pointers
    - String
---

[1813. Sentence Similarity III](https://leetcode.com/problems/sentence-similarity-iii/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given two strings `sentence1` and `sentence2`, each representing a **sentence**  composed of words. A sentence is a list of **words**  that are separated by a **single**  space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences `s1` and `s2` are considered **similar**  if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. **Note**  that the inserted sentence must be separated from existing words by spaces.

For example,

- `s1 = "Hello Jane"` and `s2 = "Hello my name is Jane"` can be made equal by inserting `"my name is"` between `"Hello"` and `"Jane"` in s1.
- `s1 = "Frog cool"` and `s2 = "Frogs are cool"` are **not**  similar, since although there is a sentence `"s are"` inserted into `s1`, it is not separated from `"Frog"` by a space.

Given two sentences `sentence1` and `sentence2`, return **true**  if `sentence1` and `sentence2` are **similar** . Otherwise, return **false** .

**Example 1:**

```bash
Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

Output: true
```

Explanation:

`sentence2` can be turned to `sentence1` by inserting "name is" between "My" and "Haley".

**Example 2:**

```bash
Input: sentence1 = "of", sentence2 = "A lot of words"

Output: false
```

Explanation:

No single sentence can be inserted inside one of the sentences to make it equal to the other.

**Example 3:**

```bash
Input: sentence1 = "Eating right now", sentence2 = "Eating"

Output: true
```

Explanation:

`sentence2` can be turned to `sentence1` by inserting "right now" at the end of the sentence.

**Constraints:**

- `1 <= sentence1.length, sentence2.length <= 100`
- `sentence1` and `sentence2` consist of lowercase and uppercase English letters and spaces.
- The words in `sentence1` and `sentence2` are separated by a single space.

## Hints/Notes

- 2025/04/03 Q2
- preSum
- [Leetcode solution](https://leetcode.com/problems/sentence-similarity-iii/editorial/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Solution

Language: **C++**

Cleaner solution:

```C++
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        istringstream iss1(sentence1), iss2(sentence2);
        vector<string> words1, words2;
        string word;
        while (iss1 >> word) words1.push_back(word);
        while (iss2 >> word) words2.push_back(word);
        // let's do the suffix
        int start = 0, end1 = words1.size() - 1, end2 = words2.size() - 1;
        if (end1 > end2) return areSentencesSimilar(sentence2, sentence1);
        while (start <= end1 && words1[start] == words2[start]) {
            start++;
        }
        while (end1 >= 0 && words1[end1] == words2[end2]) {
            end1--; end2--;
        }
        return start > end1;
    }
};
```

```C++
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int m = sentence1.size(), n = sentence2.size();
        if (m == n) {
            return sentence1 == sentence2;
        }
        if (m > n) {
            return areSentencesSimilar(sentence2, sentence1);
        }

        auto words1 = getWords(sentence1);
        auto words2 = getWords(sentence2);
        // let's do the suffix
        m = words1.size(), n = words2.size();
        vector<int> suffix(m + 1, 0);
        int r1 = words1.size() - 1, r2 = words2.size() - 1;
        while (r1 >= 0) {
            if (words1[r1] == words2[r2]) {
                suffix[r1] = suffix[r1 + 1] + 1;
                r1--; r2--;
            } else {
                break;
            }
        }
        while (r1 >= 0) {
            suffix[r1] = suffix[r1 + 1];
            r1--;
        }

        int preSum = 0, l1 = 0, l2 = 0;
        if (suffix[0] == m) {
            return true;
        }
        while (l1 < m && l2 < n) {
            if (words1[l1] == words2[l2]) {
                preSum++;
                l1++;
                l2++;
                if (suffix[l1] + preSum == m) {
                   return true;
                }
            } else {
                break;
            }
        }
        return false;
    }

    vector<string> getWords(string& sentence) {
        istringstream iss(sentence);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }
};
```
