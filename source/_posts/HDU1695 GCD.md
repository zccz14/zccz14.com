---
title: "HDU 1695 GCD"
date: 2016-09-11 17:27:00
categories:
- 解题报告
tags:
- 莫比乌斯反演
---

求 $[1, A]×[1, B]$ 中使得 $gcd(x, y) = K $的无序数对 $(x, y)$ 的个数。

<!--more-->

# 题目重现
Given 5 integers: $a, b, c, d, k$, you're to find $x \in [a, b], y \in [c, d]$ that $gcd(x, y) = k$. $gcd(x, y)$ means the greatest common divisor of $x$ and $y$.
Since the number of choices may be very large, you're only required to output the total number of different number pairs.
Please **notice** that, $(x=5, y=7)$ and $(x=7, y=5)$ are considered to be the same.

You can assume that $a = c = 1$ in all test cases.

## Input
The input consists of several test cases. The first line of the input is the number of the cases. There are no more than 3,000 cases.
Each case contains five integers: 
$a, b, c, d, k, 0 < a \le b \le 100,000, 0 < c \le d \le 100,000, 0 \le k \le 100,000$
,as described above.

 

## Output
For each test case, print the number of choices. Use the format in the example.
## Sample Input
```
2
1 3 1 5 1
1 11014 1 14409 9
```


## Sample Output
```
Case 1: 9
Case 2: 736427
```

# 题解

问题基于一个简单的结论：

$$
\sum_{1 \le x \le A, 1 \le y \le B} [K | gcd(x, y)] = \lfloor \frac{A}{K} \rfloor \lfloor \frac{B}{K} \rfloor
$$

设
$$
G_{AB}(K) = \sum_{1 \le x \le A, 1 \le y \le B} [K | gcd(x, y)] \\
F_{AB}(K) = \sum_{1 \le x \le A, 1 \le y \le B} [K = gcd(x, y)] \\
$$

可见有：
$$
G_{AB}(K) = \sum_{K | k} F_{AB}(k)
$$

由莫比乌斯反演原理有：
$$
F_{AB}(k) = \sum_{d \ge 1} {\mu(d) G_{AB}(d k)}
$$

所以：
$$
F_{AB}(K) = \sum_{1 \le x \le A, 1 \le y \le B} [K = gcd(x, y)] = \sum_{d \ge 1} \mu(d) \lfloor \frac{A}{d K} \rfloor \lfloor \frac{B}{d K} \rfloor
$$

此题中要求$(x, y), (y, x)$ 不重复计数

不妨设$A \le B$
$$
Ans(A, B, K) = F_{AB}(K) - \frac{F_{AA}(K)}{2}
$$

# 参考代码
+ [HDU 1695](https://gist.github.com/zccz14/e06bd8f6afa9c707c014f5674ef97a9b)