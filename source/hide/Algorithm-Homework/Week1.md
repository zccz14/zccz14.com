title: Algorithm-Homework-1
date: 2016-09-07 23:19:00
categories:
- 算法设计与分析
- 作业
tags:
- 计算理论
---

# 算法设计与分析作业 #1

Copyright © zccz14(陈铮), All Right Reserved.

## 算法分析题

1-5 硬件厂商 XYZ 公司宣称他们最新研制的微处理器运行速度为其竞争对手 ABC 公司同类产品的100倍。对于计算复杂性分别为 $n, n^2, n^3$ 和 $n!$ 的各算法，若用 ABC 公司的计算机在1小时内能解输入规模为 $n$ 的问题。那么用 XYZ 公司的计算机在1小时内分别能解输入规模为多大的问题？

解：

$$
100T_{ABC} (n) \ge T_{XYZ}(n)
$$

| 复杂度   | ABC 公司能解决的问题规模 | XYZ 公司能解决的问题规模                       |
| ----- | -------------- | ------------------------------------ |
| $n$   | $n$            | $100n$                               |
| $n^2$ | $n$            | $10n$                                |
| $n^3$ | $n$            | $\lfloor 100^{\frac{1}{3}}n \rfloor$ |
| $n!$  | $n$            | $n$                                  |

实际上对于阶乘来说，答案并不简单等同于$n$。

设 XYZ 公司能解决的问题规模为 $k$：
$$
100(n!) \ge k!
$$
总是取满足上述不等式最大的 $k$。

对于$n \ge 100$ 的情况，$(n + 1)! \gt 100(n!) \ge k!  \Rightarrow k=n$

当$100(n!) \ge (n+1)! \Rightarrow n \le 99$ 时，$k$ 可取 $n + 1$；

当$100(n!) \ge (n+2)! \Rightarrow n \le 8$ 时，$k$ 可取 $n + 2$；

当$100(n!) \ge (n+3)! \Rightarrow n \le 2$ 时，$k$ 可取 $n + 3$；

当$100(n!) \ge (n+4)! \Rightarrow n \not \in N^+$ ，说明 $k$ 不可取 $n + 4$；

由于总是取满足上述不等式最大的 $k$，问题的答案变得很简单：

XYZ 公司能解决的问题规模为$f(n)$：
$$
\begin{align}
f(n) &= n + [n \le 2] + [n \le 8] + [n \le 99] \\
&=
  \begin{cases}
  n + 3, & n \le 2 \\
  n + 2, & 2 \lt n \le 8 \\
  n + 1, & 8 \lt n \le 99 \\
  n, & \text{otherwise}
  \end{cases}
\end{align}
$$
顺便给出生成函数$F$：
$$
F(z) = \frac{3 - 2z - z^2 + z^3 - z^9 + z^{10} - z^{100} + z^{101}}{(z -1)^2}
$$
1-7 证明 $n! = o(n^n)$ 。

证明：

由斯特灵公式 (Stirling Formula) 得
$$
\begin{align}
\lim_{n \to +\infty} {
	\frac{n!}{n^n}
} 
& = \lim_{n \to +\infty} {
	\frac{\sqrt{2 \pi n} (\frac{n}{e})^n}{n^n}
} \\
& = \lim_{n \to +\infty} {
	\frac{\sqrt{2 \pi n} }{e^n}
} = 0
\end{align}
$$
所以
$$
n!=o(n^n)
$$
证毕。

1-9 证明：如果一个算法在平均情况下的计算时间复杂性为 $\theta (f(n))$ ，则该算法在最坏情况下所需的计算时间为 $\Omega(f(n))$ 。

证明：

由 $\theta$ 的定义：
$$
T_{avg}(n) = \Omega(f(n))
$$
显然有：
$$
T_{avg}(n) \le T_{max}(n)
$$
所以：
$$
\Omega(f(n)) \le T_{max}(n)
$$
因此$T_{max}(n)$ 具有渐进复杂度下界 $\Omega(f(n))$

证毕。