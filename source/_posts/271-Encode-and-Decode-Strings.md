---
title: 271. Encode and Decode Strings
categories: Leetcode
date: 2025-01-07 17:06:58
tags:
    - Array
    - String
    - Design
---

[271. Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Design an algorithm to encode <b>a list of strings</b> to <b>a string</b>. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

```bash
string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
```

Machine 2 (receiver) has the function:

```bash
vector<string> decode(string s) {
  //... your code
  return strs;
}
```

So Machine 1 does:

```bash
string encoded_string = encode(strs);
```

and Machine 2 does:

```bash
vector<string> strs2 = decode(encoded_string);
```

`strs2` in Machine 2 should be the same as `strs` in Machine 1.

Implement the `encode` and `decode` methods.

You are not allowed tosolve the problem using any serialize methods (such as `eval`).

**Example 1:**

```bash
Input: dummy_input = ["Hello","World"]
Output: ["Hello","World"]
Explanation:
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---> Machine 2

Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
```

**Example 2:**

```bash
Input: dummy_input = [""]
Output: [""]
```

**Constraints:**

- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` contains any possible characters out of `256` valid ASCII characters.

**Follow up:** Could you write a generalized algorithm to work on any possible set of characters?

## Hints/Notes

- 2025/01/04
- string
- premium

## Solution

Language: **C++**

```C++
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto& str : strs) {
            int n = str.size();
            res += to_string(n);
            res.push_back(' ');
            res += str;
            res.push_back(' ');
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        for (int i = 0; i < s.size(); ) {
            int start = i;
            while (s[i] != ' ') {
                i++;
            }
            int size = stoi(s.substr(start, i - start));
            i++;
            res.push_back(s.substr(i, size));
            i += size + 1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
```
