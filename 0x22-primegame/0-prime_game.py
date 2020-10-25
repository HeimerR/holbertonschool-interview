#!/usr/bin/python3
""" Prime Game """


def isprime(n):
    """ n: number to check if it is prime"""
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def delete_numbers(n, nums):
    """ delete numbers - assign zero """
    for i in range(len(nums)):
        if nums[i] % n == 0:
            nums[i] = 0


def isWinner(x, nums):
    """ where x is the number of rounds and nums is an array of n
        Return: name of the player that won the most rounds
        Iriaf the winner cannot be determined, return None
        You can assume n and x will not be larger than 10000
    """
    nums.sort()
    winner = False
    for turn in range(2 * x):
        """
        # uncomment to monitor turns
        if turn % 2 != 0:
            print("Ben turn {}/{}".format(turn+1, 2*x))
        else:
            print("Maria turn {}/{}".format(turn+1, 2*x))
        """
        change = False
        for i, n in enumerate(nums):
            # print("n: ", n, "i: ", i)
            if n > 1 and isprime(n):
                delete_numbers(n, nums)
                change = True
                # print(nums)
                break
        if change is False:
            winner = True
            # print(nums)
            break
    if winner is False:
        return None
    if turn % 2 != 0:
        return "Maria"
    return "Ben"
