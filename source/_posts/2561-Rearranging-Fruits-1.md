---
title: 2561. Rearranging Fruits
categories: Leetcode
date: 2025-05-02 22:42:54
tags:
    - Array
    - Hash Table
    - String
    - Depth-First Search
    - Breadth-First Search
    - Graph
    - Topological Sort
---

[3481. Apply Substitutions](https://leetcode.com/problems/apply-substitutions/description/?envType=company&envId=google&favoriteSlug=google-three-months)

## Description

You are given a <code>replacements</code> mapping and a <code>text</code> string that may contain **placeholders**  formatted as <code>%var%</code>, where each <code>var</code> corresponds to a key in the <code>replacements</code> mapping. Each replacement value may itself contain **one or more**  such **placeholders** . Each **placeholder**  is replaced by the value associated with its corresponding replacement key.

Return the fully substituted <code>text</code> string which **does not**  contain any **placeholders** .

**Example 1:**

```bash
Input: replacements = [["A","abc"],["B","def"]], text = "%A%_%B%"

Output: "abc_def"
```

Explanation:

* The mapping associates <code>"A"</code> with <code>"abc"</code> and <code>"B"</code> with <code>"def"</code>.
* Replace <code>%A%</code> with <code>"abc"</code> and <code>%B%</code> with <code>"def"</code> in the text.
* The final text becomes <code>"abc_def"</code>.

**Example 2:**

```bash
Input: replacements = [["A","bce"],["B","ace"],["C","abc%B%"]], text = "%A%_%B%_%C%"

Output: "bce_ace_abcace"
```

Explanation:

* The mapping associates <code>"A"</code> with <code>"bce"</code>, <code>"B"</code> with <code>"ace"</code>, and <code>"C"</code> with <code>"abc%B%"</code>.
* Replace <code>%A%</code> with <code>"bce"</code> and <code>%B%</code> with <code>"ace"</code> in the text.
* Then, for <code>%C%</code>, substitute <code>%B%</code> in <code>"abc%B%"</code> with <code>"ace"</code> to obtain <code>"abcace"</code>.
* The final text becomes <code>"bce_ace_abcace"</code>.

**Constraints:**

* <code>1 <= replacements.length <= 10</code>
* Each element of <code>replacements</code> is a two-element list <code>[key, value]</code>, where:
  * <code>key</code> is a single uppercase English letter.
  * <code>value</code> is a non-empty string of at most 8 characters that may contain zero or more placeholders formatted as <code>%<key>%</code>.
* All replacement keys are unique.
* The <code>text</code> string is formed by concatenating all key placeholders (formatted as <code>%<key>%</code>) randomly from the replacements mapping, separated by underscores.
* <code>text.length == 4 * replacements.length - 1</code>
* Every placeholder in the <code>text</code> or in any replacement value corresponds to a key in the <code>replacements</code> mapping.
* There are no cyclic dependencies between replacement keys.

## Hints/Notes

* 2025/04/26 Q2
* dfs
* No solution fromm 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<string, string> mapping;
        for (auto& replacement : replacements) {
            string key = replacement[0], val = replacement[1];
            mapping[key] = val;
        }
        for (auto [key, val] : mapping) {
            if (val.find('%') != string::npos) {
                string res = replace(val, mapping);
                mapping[key] = res;
            }
        }
        string res = replace(text, mapping);
        return res;
    }

    string replace(string text, unordered_map<string, string>& mapping) {
        int n = text.size();
        string res;
        for (int i = 0; i < n; i++) {
            if (text[i] != '%') {
                res.push_back(text[i]);
            } else {
                int start = ++i;
                while (text[i] != '%') {
                    i++;
                }
                string key = text.substr(start, i - start);
                string next_val = mapping[key];
                while (next_val.find('%') != string::npos) {
                    string next_res = replace(next_val, mapping);
                    mapping[next_val] = next_res;
                    next_val = mapping[next_val];
                }
                res += next_val;
            }
        }
        return res;
    }
};
```
