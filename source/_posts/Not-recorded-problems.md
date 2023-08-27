---
title: Not recorded problems
date: 2023-02-07 14:13:10
categories: Leetcode
tags:
---

## The problems not recorded

None

## The problems not noted

```bash
find . -name "[0-9]*" |  xargs grep -L "Hints"
```

## The problems not tagged

```bash
find . -name "[0-9]*" | xargs grep -A 1 "tags" | grep -e "---"
```
