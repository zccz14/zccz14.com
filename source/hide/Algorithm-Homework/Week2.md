title: Algorithm-Homework-2
date: 2016-09-13 21:01:10
categories:
- 算法设计与分析
- 作业
tags:
- 二分搜索
---

# 算法设计与分析作业 #2

Copyright © zccz14(陈铮), All Right Reserved.

## 算法分析题

2-2 下面的7个算法与本章中的二分搜索算法 BinarySearch 略有不同。请判断这7个算法的正确性。如果算法不正确，请说明产生错误的原因。如果算法正确，请给出算法的正确性证明。

### (1)

```cpp
template <class Type> 
int BinarySearch1(Type a[], const Type &x, int n) {
  int left = 0; int right = n - 1;
  while (left <= right) {
    int middle = (left + right) / 2;
    if (x == a[middle]) return middle;
    if (x > a[middle]) left = middle;
    else right = middle;
  }
  return -1;
}
```

**错误**。可能陷入死循环。

```
search 1 in {0} => Dead Loop
```



### (2)

```cpp
template <class Type> 
int BinarySearch2(Type a[], const Type &x, int n) {
  int left = 0; int right = n - 1;
  while (left < right - 1) {
    int middle = (left + right) / 2;
    if (x > a[middle]) left = middle;
    else right = middle;
  }
  if(x == a[left]) return left;
  else return -1;
}
```



**错误**。搜索范围不正确导致答案错误。

```
search 2 in {1, 2} => -1 (Wrong Answer)
```



### (3)

```cpp
template <class Type>
int BinarySearch3(Type a[], const Type &x, int n) {
  int left = 0; int right = n - 1;
  while (left + 1 != right) {
    int middle = (left + right) / 2;
    if (x >= a[middle]) left = middle;
    else right = middle;
  }
  if (x == a[left]) return left;
  else return -1;
}
```

**错误**。可能陷入死循环。

```
search 1 in {1} => Dead Loop
```



### (4)

```cpp
template <class Type>
int BinarySearch4(Type a[], const Type &x, int n) {
  if (n > 0 && x >= a[0]) {
    int left = 0; int right = n - 1;
    while (left < right) {
        int middle = (left + right) / 2;
        if (x < a[middle]) right = middle - 1;
        else left = middle;
    }
    if (x == a[left]) return left;
  }
  return -1;
}
```

**错误**。可能陷入死循环。

```
search 1 in {1, 2} => Dead Loop
```



### (5)

```cpp
template <class Type>
int BinarySearch5(Type a[], const Type &x, int n) {
  if (n > 0 && x >= a[0]) {
    int left = 0; int right = n - 1;
    while (left < right) {
        int middle = (left + right + 1) / 2;
        if (x < a[middle]) right = middle - 1;
        else left = middle;
    }
    if (x == a[left]) return left;
  }
  return -1;
}
```

**正确**。

证明：

**停机性**

循环结束条件：$left \ge right$

当 $left \lt right$ 时，有
$$
\begin{align}
middle & = \lfloor \frac{left + right + 1}{2} \rfloor \\
& \in [\lfloor \frac{left + (left + 1) + 1}{2} \rfloor, \lfloor \frac{(right - 1) + right + 1}{2} \rfloor] \\
& = [left + 1, right] \tag{1}
\end{align}
$$
下一个循环中 
$$
[left', right' ] =
\begin{cases}
[left, middle - 1] & x < a_{middle}\\
[middle, right] & \text{otherwise}\\
\end{cases} \tag{2}
$$


> $\sharp A$ 		基数：集合A的元素个数。

当 $x \lt a_{middle}$ 时：
$$
\begin{align}
\sharp [left', right'] & = \sharp [left, middle - 1] \\
& \le \sharp [left, right - 1] & (1) \\
& \lt \sharp [left, right]
\end{align}
$$
当 $x \ge a_{middle}$ 时：
$$
\begin{align}
\sharp [left', right'] & = \sharp [middle, right] \\
& \le \sharp [left + 1, right]  & (1)\\
& \lt \sharp [left, right] 
\end{align}
$$
无论哪种情况，新区间长度**严格小于**旧区间，当区间长度小于等于 1 时循环终止，因此循环是有穷的，此算法会于有限步骤后停机。

**正确性**

该算法正确当且仅当：

1. $x \in a$ 时，返回非负索引 $pos$ 使得$a_{pos} = x$
2. $x \not \in a$ 时，返回 $-1$

变量 `left` 始终是非负的，由（1）（2）得在整个程序中始终有：

$$
left \le right
$$

即当程序停机时一定有 $left = right$ 成立。



若 $x \in a = \{a_k| 0\le k \le n - 1\}$ 

当 $x \lt a_{middle}$ 时：
$$
a' = \{a_k | left \le k \le middle - 1\}
$$
由于$a$ 有序，因此$x \in a'$

当 $x \ge a_{middle}$ 时：
$$
a' = \{a_k | middle \le k \le right\}
$$
同理$x \in a'$

所以如果$x \in a$, $x$ 始终在 $a_{left} ,\cdots, a_{right}$ 区间内。

所以当循环结束时，如果$x = a_{left}$ ，返回 $left$ 即所求的索引 $pos$ 。

除此之外的任何情况均表明 $x \not \in a$ ，返回 $-1$ 。



证毕。

### (6)

```cpp
template <class Type>
int BinarySearch6(Type a[], const Type &x, int n) {
  if (n > 0 && x >= a[0]) {
    int left = 0; int right = n - 1;
    while (left < right) {
        int middle = (left + right + 1) / 2;
        if (x < a[middle]) right = middle - 1;
        else left = middle + 1;
    }
    if (x == a[left]) return left;
  }
  return -1;
}
```

**错误**。区间边界的迭代过于激进导致答案错误。

```
search 2 in {1, 2} => -1 (Wrong Answer)
```



### (7)

```cpp
template <class Type>
int BinarySearch7(Type a[], const Type &x, int n) {
  if (n > 0 && x >= a[0]) {
    int left = 0; int right = n - 1;
    while (left < right) {
        int middle = (left + right + 1) / 2;
        if (x < a[middle]) right = middle;
        else left = middle;
    }
    if (x == a[left]) return left;
  }
  return -1;
}
```

**错误**。可能陷入死循环。

```
search 1 in {1, 2} => Dead Loop
```



