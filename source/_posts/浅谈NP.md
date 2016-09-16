---
title: 浅谈NP
date: 2016-09-12 13:02:24
tags:
- 计算理论
---

"NP" 是指一种时间复杂度 "非确定性多项式" (Non-deterministic Polynomial) 时间复杂度。

这里的 Non-deterministic 并非是指 "不能确定是不是能在多项式时间内求解"，而是特指 "非确定性状态机"。

"NP" 问题是能在非确定性状态机下以多项式时间求解的。

{% asset_img NP.png "P NP NPC NP-hard 问题关系图" %}

> 由于是浅谈，正文将不包含任何关于 "图灵机" 的说法。
> 默认读者没有任何 "状态机" 的知识。

<!--more-->

# 定义

先给出本文谈及的四类时间复杂度问题的(通俗)定义：

## P (Polynomial)
> 可在多项式时间内求解的问题。

例如求一个序列的升序(排序)问题，最简单的方法是可以在 $O(n^2)$ 的复杂度内解决。

$n^2$ 是一个多项式，因此排序问题是一个 P 问题。

## NP (Non-deterministic Polynomial)
> 可在多项式时间内验证的问题。

能在多项式时间内求解(P)意味着一定能在多项式时间内验证(NP)，因此$P \subseteq NP$

另外一个有趣的性质是，**假设**你有无穷多个计算机，那么你可以**并发地验证**所有可能的答案，在验证每一个答案都需要多项式时间，总的来说还是多项式时间复杂度。

**量子计算机**致力于如何造出近乎无限的计算机来并发解决NP问题。

## NPC (NP Complete)
> 任意NP问题都可在多项式时间内规约成的NP问题。

首先它的定义说明 **一个NPC问题一定是一个NP问题**，$NPC \subseteq NP$。

规约即等价转化，按照定义我们可以得到一个有趣的性质：

**如果**我们能找到一个NPC问题(假设这个NPC问题为$X$)的多项式时间解法：

$$
\require{AMScd}
\begin{CD}
    \forall NP @>\text{Polynomial Time}>> X @>\text{Polynomial Time}>> P\\
\end{CD}
$$

那么所有的NP问题都能在多项式时间内解决，即$NP = P$。

> 但现在 NP 与 P 是否相等仍没有人能证明。

可满足性(SAT)问题是最早发现的一个NPC问题，是这样描述的：

**给定一个N元命题，是否存在一个指派使得命题为真？**

例如三元命题 $(a \land b \lor c) \lor (a \land \lnot b)$ 是存在指派$(a, b, c) = (true, true, true)$ 使得命题为真的。

## NP-Hard
> 任意NP问题都可在多项式时间内规约成的问题。

首先 NP-Hard 的定义说明 **一个NPC问题一定是一个NP-Hard问题** ，$NPC \subseteq NP-Hard$。 

由于 NP-Hard 问题不一定是一个NP问题，即便证明了 $NP = P$，对于降低NP-Hard的复杂性依然没有什么卵用。

所以我们说 "NP-Hard 至少与 NPC 一样难"。

***

最后回顾一下上面的图，感受一下。