---
title: 1point3acre experiences
date: 2024-12-02 20:31:04
tags: Personal
hidden: true
---

## Why write this doc?

Collect information on how to prepare for the following 3 categories

1. Coding
2. System design
3. Behavioral question

First, go through each blog, then collect the information

## Plan

Assume i start the application on 2025/01/20, plan each day's work. **It's a total of 40 days**

* Finish the review by 12/15/2024, then 4~6 problems per day
* Do 6.824, DDIA and Alex Xu in order, i think i should do 2 Alex Xu per day

## Coding

1. Finish the review by end of 12/15
1. Work on leetcode 150, 6 questions per day

## System design

1. DDIA first 9 chapters
2. 6.824 17 videos
3. Alex Xu's 16 + 13 chapters, check the reference
4. newgpu
5. [System design interval](https://www.youtube.com/c/SystemDesignInterview)

## Behavioral question

go through the [google doc](https://docs.google.com/document/d/112HBiMNvu6TYbDUOfVRe_MS4A-fKaWYrpMlmnsiMNiA/edit?tab=t.0) prior to submit applications

## Appendix

[24年夏跳槽经历 及经验分享](https://www.1point3acres.com/bbs/thread-1086637-1-1.html)

**主要介绍了SD的套路**

1. functional requirements
2. non functional requirements，这个很经典了，就是consistency, availability, fault tolerance, durability, scalability, latency, correctness和idempotency
3. capacity estimation
4. API design
5. high level design
6. database选择，先从functional requirement的角度说access pattern，然后相对应的来选择sql/no sql/time series
7. 最后讲cache，怎么populate，invalidate cache。怎么保证freshness等等。然后讨论怎么scale cache/redis cluster怎么搞。

准备：

1. DDIA
2. Alex Xu's books, but only high level design and reference
3. Know the classic db, nosql/sql/timeseris/kv, including small db like couchdb/cockroach/yugabyte, their architecture and optimal use case. kafka/spark/redis's architecture and use case. redis
4. 3 mock interview

[跳槽拿了7个senior offer，分享一下经验](https://www.1point3acres.com/bbs/thread-768263-1-1.html)

内推很重要

**介绍了时间线**

1. 1st month SD, last week submit applications and work on coding
2. 2nd month first 3 weeks phone screen. After that all in SD
3. 3rd month mid 2 weeks on site.
4. Results come in at late 3rd month

准备

Coding:

1. Only use 2 weeks.
2. Most frequent problems, write less than 100 but read more than 400.
3. 面经 >> 刷题。write all 面经

Behavioral:

1. Prepare one story for each 15 leadership principles
2. 因为重点不在故事背景，在于你在特定情况下你扮演了什么角色，采取了什么措施，得到了什么结果。每个故事最后一定不要忘记强调结果，如果没有结果你编也要编出一些正面的结果。
3. 关于面试要踩的“点”，一般都是常识性的点，比如“你能不能合理处理跟同事的矛盾”，“你是否关心你的产品的用户”，“你是否能在复杂的情况下做出技术决策”，“作为TL，你是否能帮助junior工程师成长”等等

System design：

1. DDIA
2. YouTube infoQ channel
3. YouTube Scott Shi channel
4. 4 mock interview

套路：

1. functional requirements 和 non-functional requirements 15分钟
2. topics: "API design", "capacity estimation", "high-level architecture design"，"database (schema, sql/nosql, sharding, replication)"和"other topics
3. Capacity estimation
4. High-level architecture design
5. Database (schema, sql/nosql, sharding, replication)
6. Other topics（cache/how to scale/push vs. pull/monitoring/rate limiting/failure handling/logging

Offer 谈判技巧

[L6和L5系统设计面试区别](https://www.1point3acres.com/bbs/thread-1054990-1-1.html)

1. 思维的高度、广度和深度
2. 少做假设，多和面试官确认
3. 第一性原理思考（First Principle Thinking）
4. 软件工程思维

反套路：

1. 在面试官给出问题之后，一定要反问面试官问题，把题目的要求弄清楚，这是固定套路。但是具体问什么问题，一定要灵活，要只问当前问题的核心问题，比如让你设计一个monitoring系统，availability就很重要，一定要问，但是对于其他题目，availability往往不是最重要的指标，就尽量不要一开始讨论（除非是面试官主动提出，或者在讨论完其他核心问题后你觉得可以讨论）。
2. 在确定题目的要求之后，到底是先做API Design，High-level Design，Database Design，Back-of-the-envelope Estimation，还是先做其他的，都没有固定套路，应该根据题目找出你认为当前最重要的话题。“找出当前最重要的话题”也是系统设计考察的重要能力，如果一个面试者总是没办法自己独立找到当前最重要的话题，那肯定是过不了L6的面试的。
3. 知道什么时候dive deep，知道什么时候一笔带过。很多面试者喜欢只对自己熟悉的领域dive deep，却对其他领域一笔带过。面试中要尽量对核心领域（对整个设计有重大影响）多讨论，对其他领域少讨论，当然，“能独立找出当前设计的核心领域”也是面试考察的重点。
4. 对系统的failure recovery和scalability很了解。这个是固定套路了。对于大多数题目，当你把该说的都说了以后，总是可以看看这两个话题有没有涵盖：每一个服务，有没有都做到能recover from failure，以及是否scalable。

[深度谈谈系统设计面试](https://www.1point3acres.com/bbs/thread-1061024-1-1.html)

Source: [System Design Guru](https://www.youtube.com/@newgpu-sys-design/videos)

[码农2024上半年跳槽总结](https://www.1point3acres.com/bbs/thread-1079232-1-1.html)

Coding:

* Mock more

SD:

* Alex Xu
* mock
* practice by oneself at home with timer
* 面试之前根据面经自己做一遍最好能想到哪些地方可能会有scalability或者reliability的问题然后想一想怎么解决对于数据库想一想如何做partition还有message queue不同的partition的tradeoff是什么

套路：很具体，值得打一遍

[彻底击碎行为问题(可能是对你最有帮助的BQ教程)](https://www.1point3acres.com/bbs/thread-895663-1-1.html)

The [google doc](https://docs.google.com/document/d/112HBiMNvu6TYbDUOfVRe_MS4A-fKaWYrpMlmnsiMNiA/edit?tab=t.0)

It's worth taking a look and write my own story

[2024老年工程师（6+YOE）上岸经验](https://www.1point3acres.com/bbs/thread-1061265-1-1.html)

Some general recommendations:

1. Keep interviewing
2. participate in design review and check blogs
3. find a mentor

How to apply

Don't use linkedin to apply.

Talk with hiring manager > talk with recruiter >> internal refer >> apply by oneself > linkedin

准备：

Coding

Grind75

SD

1. DDIA
2. Alex Xu
3. newgpu
4. mock。录像，复盘

Behavioral:

1. mock
2. learning
3. reverse interview, think about question

Project dive deep

1. mock with one friend

[L6和L5面试区别(BQ&系统设计)](https://www.1point3acres.com/bbs/thread-1055577-1-1.html)

Focused on BQ

Not only what i have done, also why i did that.

[分享一下六月的跳槽经历senior/staff级别](https://www.1point3acres.com/bbs/thread-911428-1-1.html)

准备：

Coding:

Meta tag problems

SD:

Alex xu
[System design interval](https://www.youtube.com/c/SystemDesignInterview)

Project deep dive:

The project you have worked on

[4YOE跳槽8个Onsite面试全部拿到Offer](https://www.1point3acres.com/bbs/thread-814766-1-1.html)

Timeline:

1st month: coding + apply
2nd month: one question per day + phone interview, system design
3rd month: on site

准备：

Coding:

Learn + 面经

SD:

1. [System design interval](https://www.youtube.com/c/SystemDesignInterview)
2. DDIA
3. Scott Shi

Some experiences

1. 心态很重要
2. 沟通很重要，要一直交流
3. 遇到面经直接写

Negotiate salary:

[Tips for negotiating your salary (from an ex-FAANG recruiter)](https://www.youtube.com/watch?v=u9BoG1n1948&t=1s)

[4yoe跳槽senior面试经验](https://www.1point3acres.com/bbs/thread-784035-1-1.html)

Offer negotiation:

Recommend levels.fyi, they can help you write the mail

[跳槽总结：科技公司Senior Engineer工资范围](https://www.1point3acres.com/bbs/thread-802273-1-1.html)

要拿大包，就得至少有一个愿意给大包的，最好是上来就给大包，比如snap, fb, amazon, netflix, stripe, bytedance。然后一个愿意compete的公司（非标准包公司），比如apple, roblox，两个就可以推上去。不建议拿一堆标准包空间不大的公司，只能干瞪眼。

[面试大厂的必考题 - 刷题的必经之路](https://www.1point3acres.com/bbs/thread-1100664-1-1.html)

Some most important questions
