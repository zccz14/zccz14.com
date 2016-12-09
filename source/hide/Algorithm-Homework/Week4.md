---
title: Algorithm-Homework-4
---

# 算法设计与分析作业 #4

## 算法实现题

### 3-14 最少费用购物问题

商店中每种商品都有标价。例如，一朵花的价格是2元，一个花瓶的价格是5元。为了吸引顾客，商店提供了一组优惠商品价。优惠商品是把一种或多种商品分成一组，并降价销售。例如，3朵花的价格不是6元而是5元。2个花瓶加1朵花的优惠价是10元。试设计一个算法，计算出某一顾客所购商品应付的最少费用。

对于给定欲购商品的价格与数量，以及优惠商品价，编程计算所购商品应付的最少费用。

#### 数据输入

由文件 `input.txt` 提供欲购商品数据。文件的第1行中有1个整数 $ B (0 \le B \le 5) $，表示所购商品种类数。在接下来的 $ B $ 行中，每行有3个数 $C$， $K$ 和 $P$。$C$ 表示商品的编码（每种商品有唯一编码），$1 \le C \le 999$；$K$ 表示购买该种商品总数，$1 \le K \le 5$； $P$ 是该种商品的正常单价（每件商品的价格），$1 \le P \le 999$。请注意，一次最多可购买 $5 \times 5 = 25$ 件商品。

由文件 `offer.txt` 提供优惠商品价格数据。文件的第1行中有一个整数 $S (0 \le S \le 99)$，表示共有 $S$ 种优惠商品组合。接下来的 $S$ 行，每行的第1个数描述优惠商品组合中商品的种类数 $j$。接着是 $j$ 个数字对 $(C, K)$，其中$C$ 是商品编码，$1 \le C \le 999$；K 表示该种商品在此组合中的数量，$1 \le K \le 5$。每行最后一个数字 $P (1 \le P \le 9999)$ 表示此商品组合的优惠价。

#### 结果输出

程序运行结束时，将计算出的所购商品应付的最少费用输出到文件 `output.txt` 中。

#### 输入文件示例

`input.txt`

```
2
7 3 2
8 2 5
```

`offer.txt`

```
2
1 7 3 5
2 7 1 8 2 10
```

#### 输出文件示例

`output.txt`

```
14
```

#### 题解

**最小费用 = 标准费用 - 优惠费用**

总的来说，如果顾客什么优惠都不用，标准费用 $P_S = \sum_{i = 1}^{B}{K_i P_i}$。

这个部分与决策无关，根据给定订单可以计算，是个定值。

要使总费用最小，要使获得的优惠金额最大。

对于每一种优惠组合，可以优惠的金额也可以直接处理成一个定值。

如果将每一种优惠组合的优惠金额看作这个组合的**价值(value)**，将所需的各种物品的数量看作这个组合的**代价(cost)**，那么这就变成了一个**多维费用完全背包问题**。

同一个优惠可以多次使用，所以这是一个完全背包而不是一个0/1背包。

费用的维度是 $B$，这不超过5，要使得每种物品都不超过订单给定的数量，这就是背包的容量，或者说费用。

每个物品都最多有$0, 1, 2, 3, 4, 5$ 这 6 个数量（状态），最多有 5 维，因此表示费用的状态最多有 $ 6^5 = 7776 $ 个，完全可以**状态压缩 (Status Compressing)**一番，这样就避免了**长参数列表**。

> **状态压缩**
> 将较多的状态量压缩成一个状态。
> 如(3, 2, 1) 可以压缩成 $3 + 2 \times 6 + 1 \times 6^2 =  51 $
> 如 59 可以解压成 (5, 3, 1)
> 压缩过程与解压缩过程是互逆的，并且都是无损的。

压缩剩余物品数量的状态为$s$，定义$s$合法(valid)当且仅当s在解压函数定义域内，并且其解压缩后的状态向量$A$ 满足：

$$
\forall A_i \in A, 0 \le A_i \le K_i
$$

(其中 $K_i$ 为题设订单中物品 $i$ 的数量)

> **状态的线性性**
> 有未压缩状态向量 $a, b, a+b$, 以及其压缩后的状态 $S_a, S_b, S_{a+b}$，满足以下性质：
> $$S_{a+b} = S_a + S_b$$
> 例如(3, 2, 1) 压缩为 51，(2, 1, 0) 压缩为 8，则 (3, 2, 1) + (2, 1, 0) = (5, 3, 1) 可以压缩为 51 + 8 = 59。
> 这个性质使得题设中每个优惠组合(本质上就是一个状态向量)直接对应了一个压缩状态定值。
> 具有这个性质的原因是向量是线性空间的向量，压缩采用的空间基底在向量元素的定义域下线性无关。

设优惠组合$i$压缩后的状态增量为$\Delta_i$，净优惠金额为$N_i$：

$$
F(s + \Delta_i) = \max\{F(s) + N_i, F(s + \Delta_i)\}
$$

压缩/解压缩的时间复杂度为 $O(B)$，空间复杂度为 $O(1)$

递推的时间复杂度为 $O((S + B)(K + 1)^B)$，空间复杂度为 $O(S (K + 1)^B)$

{% include_code "多维费用完全背包：递推 + 状态压缩" Algorithm-Homework-Reference/3-14-1.cpp lang:cpp %}

实际上，这个递推问题的空间复杂度能使用**滚动数组**的技巧进行优化，优化到 $O((K + 1)^B)$。

原理是，在计算第 $i$ 个物品时，并不需要考虑前 $i - 1$ 个物品的决策（在物品这个维度可在线处理）。这也是背包问题比较经典的优化方式。

需要修改`Solve`函数内层循环的执行顺序，并且可以化简一个式子，这多棒！

```cpp
void Solve(int B, int S) {
  int maxST = compress(K);
  for (int i = 0; i < S; i++) {
    int delta = compress(Number[i]);
    for (int j = maxST; j >= delta; j--) {
      if (check(j) && check(j - delta)) {
        MaxProfit[j] = std::max(MaxProfit[j], MaxProfit[j - delta] + Profit[i]));
      }
    }
  }
}

```

然后将这个函数整合到主函数中在线处理(online processing)第i个物品。

将二维数组全部降为一维数组。

{% include_code "多维费用完全背包：递推 + 状态压缩 + 滚动数组 + 在线处理" Algorithm-Homework-Reference/3-14-2.cpp lang:cpp %}

回到上一层，我们看看不用递推式可以怎么解决这个问题：

直接在状态空间里搜索即可，为了加快速度再加上一个记忆化，有了之前的状态压缩，这里就很简单了。

$$
F(s) = \begin{cases}
  \max_{i \in S} \{F(s - \Delta_i) + N_i\} & s - \Delta_i \text{is valid} \\
  0 & \text{otherwise}
\end{cases}
$$

{% include_code "多维费用完全背包：记忆化搜索 + 状态压缩" Algorithm-Homework-Reference/3-14-3.cpp lang:cpp %}