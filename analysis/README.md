# Analysis of Algorithms

Whether we are designing an algorithm or applying one that is widely accepted,
it is important to understand how the algorithm will perform. There are a number
of ways we can look at an algorithm’s performance, but usually the aspect of most
interest is how fast the algorithm will run. In some cases, if an algorithm uses
significant storage, we may be interested in its space requirement as well.
Whatever the case, determining how an algorithm performs requires a formal and
deterministic method.

- **Worst-case analysis:** The metric by which most algorithms are compared.
Other cases we might consider are the average case and best case. However,
worst-case analysis usually offers several advantages.

- **O-notation:** The most common notation used to formally express an
algorithm’s performance. O-notation is used to express the upper bound of a
function within a constant factor.

- **Computational complexity:** The growth rate of the resources (usually time)
an algorithm requires with respect to the size of the data it processes.
O-notation is a formal expression of an algorithm’s complexity.

## O-Notation

O-notation is the most common notation used to express an algorithm’s
performance in a formal manner. 

Normally we express an algorithm’s performance as a function of the size of the
data it processes. That is, for some data of size n, we describe its performance
with some function f (n). However, while in many cases we can determine f
exactly, usually it is not necessary to be this precise. Primarily we are interested
only in the growth rate of f, which describes how quickly the algorithm’s
performance will degrade as the size of the data it processes becomes
arbitrarily large.

**Simple rules:**

1. Constant terms are expressed as O(1). When analyzing the running time of an
algorithm, apply this rule when you have a task that you know will execute in
a certain amount of time regardless of the size of the data it processes. 

$$O(c) = O(1)$$

2. Multiplicative constants are omitted. When analyzing the running time of an
algorithm, apply this rule when you have a number of tasks that all execute
in the same amount of time. 

$$ O(cT) = cO(T) = O(T) $$

3. Addition is performed by taking the maximum. When analyzing the running
time of an algorithm, apply this rule when one task is executed after another.

$$ O(T_1) + O(T_2) = O(T_1 + T_2) = max((O(T_1),\, O(T_2))) $$

4. Multiplication is not changed but often is rewritten more compactly. When
analyzing the running time of an algorithm, apply this rule when one task
causes another to be executed some number of times for each iteration of
itself.

$$ O(T_1)O(T_2) = O(T_1 T_2) $$

## Computational Complexity

When speaking of the performance of an algorithm, usually the aspect of interest
is its complexity, which is the growth rate of the resources (usually time) it
requires with respect to the size of the data it processes.

| **Complexity** | **Example** |
| ---           | --- |
| O(1)          | Fetching the first element from a set of data |
| O($lg\,n$)    | Splitting a set of data in half, then splitting the halves in half, etc. |
| O(n)          | Traversing a set of data |
| O($n\,lg\,n$) | Splitting a set of data in half repeatedly and traversing each half |
| O($n^2$)      | Traversing a set of data once for each member of another set of equal size |
| O($2^n$)      | Generating all possible subsets of a set of data |
| O($n!$)       | Generating all possible permutations of a set of data |