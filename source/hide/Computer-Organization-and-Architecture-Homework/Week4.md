---
title: 计组 Week 4
date: 2016-09-27 22:16:00
---

# Computer Organization & Architecture Week 4
Copyright &copy; zccz14, follow CC-BY-NC License.

1 Problem 4.1 ~ 4.3

4.1 A set-associative cache consists of 64 lines, or slots, divided into four-line sets. Main memory contains 4K blocks of 128 words each. Show the format of main memory addresses.

total: $\log_2{(4K \times 128)} = 19$

word: $\log_2{128} = 7$

set: $\log_2{\frac{64}{4}} = 4$

tag: $19 - 7 - 4 = 8$

$$
\overbrace{
    \overbrace{00000000}^{\text{tag: } 8} 
    \overbrace{0000}^{\text{set: } 4}
    \overbrace{0000000}^{\text{word: } 7}
}^{\text{total: } 19}
$$

4.2 A two-way set-associative cache has lines of 16 bytes and a total size of 8 kbytes. The 64-Mbyte main memory is byte addressable. Show the format of main memory addresses.

total: $\log_2{64M} = 26$

block size(line size): $16$

word: $\log_2{16} = 4$

set: $\log_2{\frac{8K}{16 \times 2}} = 8$

tag: $26 - 4 - 8 = 14$

$$
\overbrace{
    \overbrace{00000000000000}^{\text{tag: } 14}
    \overbrace{00000000}^{\text{set: } 8}
    \overbrace{0000}^{\text{word: } 4}
}^{\text{total: } 26}
$$

4.3 For the hexadecimal main memory addresses 111111, 666666, BBBBBB, show the following information, in hexadecimal format:

a. Tag, Line, and Word values for a direct-mapped cache, using the format of Figure 4.10

111111: 

Tag: 11, Line: 444, Word: 1

666666: 

Tag: 66, Line: 1999, Word: 2

BBBBBB: 

Tag: BB, Line: 2EEE, Word: 3

b. Tag and Word values for an associative cache, using the format of Figure 4.12

111111:

Tag: 44444, Word: 1

666666:

Tag: 199999, Word: 2

BBBBBB:

Tag: 2EEEEE, Word: 3

c. Tag, Set, and Word values for a two-way set-associative cache, using the format of Figure 4.15

111111:

Tag: 22, Set: 444, Word: 1

666666:

Tag: CC, Set: 1999, Word: 2

BBBBBB:

Tag: 177, Set: EEE, Word: 3

2 For the address sequence: `1 2 3 4 1 2 3 4 1 2 3 4`, draw and compute the hit ratio of 3-line cache using FIFO & LRU; which methods can be used to improve the hit ratio?

**Assume that it used associative cache**

FIFO Procedure:

```
    [ ?, ?, ?] // init
=>  [ 1, ?, ?] // access 1
=>  [ 1, 2, ?] // access 2
=>  [ 1, 2, 3] // access 3
=>  [ 4, 2, 3] // access 4
=>  [ 4, 1, 3] // access 1
=>  [ 4, 1, 2] // access 2
=>  [ 3, 1, 2] // access 3
=>  [ 3, 4, 2] // access 4
=>  [ 3, 4, 1] // access 1
=>  [ 2, 4, 1] // access 2
=>  [ 2, 3, 1] // access 3
=>  [ 2, 3, 4] // access 4
```

FIFO Hits: 0

LRU Procedure:

**Just same with FIFO Procedure in this case**

LRU Hits: 0

Random or Optimistic Algorithm can be used to improve the hit ratio.

Using directly-mapped cache can also improve the hit ratio in this case.

3 Consider a machine with Cache-main memory system structure. Its main memory has 8 blocks (0-7), and its Cache has 4 lines(0-3) and adapts an organization of 2-way set associative with LRU replacement algorithm, require:

3-1 show the structure of main memory address

set: $\log_2{\frac{4}{2}} = 1$

tag: $\log_2{\frac{8}{2}} = 2$

**Assume** that 1 block has $2^x$ addresses. 

word: $x$

total: $x + 3$

3-2 show the corresponding relationship of main memory block number and Cache line number

let block number = $B$, line number = $L$

$$
\lfloor \frac{L}{2} \rfloor = B \mod 2
$$

In Genenal,

$$
\begin{equation}
  \lfloor \frac{L}{\text{the number of lines in a set}} \rfloor = B \mod \text{the number of sets} \\
  \text{the number of lines in a set} \times \text{the number of sets} = \text{total cache lines} \\
\end{equation}
$$


3-3 Supposed initial cache status is empty, for the address sequence: `1, 2, 4, 1, 3, 7, 0, 1, 2, 5, 4, 6, 4, 7, 2`, list the assigned addresses of cache lines after each visit.

```
    [ ?, ?, ?, ? ] // init
=>  [ ?, ?, 1, ? ] // access 1, line 2
=>  [ 2, ?, 1, ? ] // access 2, line 0
=>  [ 2, 4, 1, ? ] // access 4, line 1
=>  [ 2, 4, 1, ? ] // access 1, (Hit)
=>  [ 2, 4, 1, 3 ] // access 3, line 3
=>  [ 2, 4, 7, 3 ] // access 7, line 2
=>  [ 0, 4, 7, 3 ] // access 0, line 0
=>  [ 0, 4, 7, 1 ] // access 1, line 3
=>  [ 0, 2, 7, 1 ] // access 2, line 1
=>  [ 0, 2, 5, 1 ] // access 5, line 2
=>  [ 4, 2, 5, 1 ] // access 4, line 0
=>  [ 4, 6, 5, 1 ] // access 6, line 1
=>  [ 4, 6, 5, 1 ] // access 4, (Hit)
=>  [ 4, 6, 5, 7 ] // access 7, line 3
=>  [ 4, 2, 5, 7 ] // access 2, line 1
```

3-4 Given the hit ratio of cache after above steps.

Hit ratio: $\frac{2}{15} = 13.33 \% $
