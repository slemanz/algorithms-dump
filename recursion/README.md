# Recursion

Recursion is a powerful principle that allows something to be defined in terms
of smaller instances of itself.

In computing, recursion is supported via recursive functions. A recursive
function is a function that calls itself. Each successive call works on a more
refined set of inputs, bringing us closer and closer to the solution of a
problem. 


## Basic recursion

A powerful principle that allows a problem to be defined
in terms of smaller and smaller instances of itself. In computing, we solve
problems defined recursively by using recursive functions, which are functions
that call themselves.

There are two basic phases of a recursive process: **winding** and
**unwinding**. In the winding phase, each recursive call perpetuates the
recursion by making an additional recursive call itself. The winding phase
terminates when one of the calls reaches a terminating condition. A terminating
condition defines the state at which a recursive function should return instead
of making another recursive call. For example, in computing the factorial of n,
the terminating conditions are n = 1 and n = 0, for which the function simply
returns 1. Every recursive function must have at least one terminating
condition; otherwise, the winding phase never terminates. Once the winding phase
is complete, the process enters the unwinding phase, in which previous instances
of the function are revisited in reverse order. This phase continues until the
original call returns, at which point the recursive process is complete

Example:

```C
#include "fact.h"

int fact(int n)
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (n == 1)
        return 1;
    else
        return n*fact(n - 1);
}
```
