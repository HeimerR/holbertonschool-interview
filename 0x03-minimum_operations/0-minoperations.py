#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    """ calculates the fewest number of operations needed to result
    in exactly n H
    example:
        n = 9
        H => Copy All => Paste => HH => Paste =>HHH => Copy All
        => Paste => HHHHHH => Paste => HHHHHHHHH
        Number of operations: 6
    """
    if n < 2:
        return 0
    factors = []
    i = 2
    while i <= n:
        if n % i == 0:
            factors.append(i)
            n = n / i
        else:
            i += 1
    return sum(factors)
