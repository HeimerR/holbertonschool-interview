#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print("correct answer: 6")
    print("my answer: ", rain(walls))
    walls = [5, 1, 0, 2, 0, 3, 0, 4]
    print("correct answer: 18")
    print("my answer: ", rain(walls))
    walls = [7, 5, 3, 6, 8, 4, 1, 5]
    print("correct answer: 12")
    print("my answer: ", rain(walls))
    walls = [0, 0, 0, 2, 2, 2, 0, 0]
    print("correct answer: 0")
    print("my answer: ", rain(walls))
    walls = [100, 1, 100, 2, 0, 3, 0, 4]
    print("correct answer: 110")
    print("my answer: ", rain(walls))
    walls = [0, 1, 2, 3, 4, 5, 6, 7, 8]
    print("correct answer: 0")
    print("my answer: ", rain(walls))
    walls = [8, 7, 6, 5, 4, 3, 2, 1, 0]
    print("correct answer: 0")
    print("my answer: ", rain(walls))
    walls = [4, 1, 0, 2, 4, 3, 0, 4]
    print("correct answer: 14")
    print("my answer: ", rain(walls))
    walls = [0, 4, 9, 4, 4, 2, 4, 0]
    print("correct answer: 2")
    print("my answer: ", rain(walls))
