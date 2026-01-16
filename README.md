# Algorithms Dump

**Algorithms** are well-defined procedures for solving problems.

**Data structures** are conceptual organizations of information. They go hand in
hand with algorithms because many algorithms rely on them for efficiency.

## General Approaches

1. **Randomized algorithms** rely on the statistical properties of random numbers. One
example of a randomized algorithm is quicksort 

2. **Divide-and-conquer algorithms** revolve around three steps: divide, conquer, and
combine. In the divide step, we divide the data into smaller, more manageable
pieces. In the conquer step, we process each division by performing some opera-
tion on it. In the combine step, we recombine the processed divisions. One exam-
ple of a divide-and-conquer algorithm is merge sort

3. **Dynamic-programming** solutions are similar to divide-and-conquer methods in that
both solve problems by breaking larger problems into subproblems whose results
are later recombined. However we solve each subproblem using recursion and combine
its result with the results of other subproblems.

4. **Greedy algorithms** make decisions that look best at the moment. In other words,
they make decisions that are locally optimal in the hope that they will lead to
globally optimal solutions. Unfortunately, decisions that look best at the moment
are not always the best in the long run. Therefore, greedy algorithms do not
always produce optimal results; however, in some cases they do. One example of
a greedy algorithm is Huffman coding, which is an algorithm for data compression 

5. **Approximation algorithms** are algorithms that do not compute optimal solutions;
instead, they compute solutions that are “good enough.” Often we use approximation
algorithms to solve problems that are computationally expensive but are too
significant to give up on altogether. The traveling-salesman problem  is one 
example of a problem usually solved using an approximation algorithm.

## Software Engineering

Good understanding of data structures and algorithms is an important part of
developing well-crafted software. Equally important is a dedication to applying
sound practices in software engineering in our implementations. 

- **Modularity:** One way to achieve modularity in software design is to focus
on the development of black boxes. In software, a black box is a module whose
internals are not intended to be seen by users of the module. Users interact
with the module only through a prescribed interface made public by its creator. 

- **Readability:** We can make programs more readable in a number of ways.
Writing meaningful comments, using aptly named identifiers, and creating code
that is self-documenting are a few examples. 

- **Simplicity:** Unfortunately, as a society we tend to regard “complex” and
“intelligent” as words that go together. In actuality, intelligent solutions are
often the simplest ones. Furthermore, it is the simplest solutions that are
often the hardest to find. 

- **Consistency:** One of the best things we can do in software development is
to establish coding conventions and stick to them. Of course, conventions must
also be easy to recognize.

---

## Topics

- **[Recursion](recursion/README.md)**
- Analysis of Algorithms