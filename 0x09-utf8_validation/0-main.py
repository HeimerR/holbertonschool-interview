#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data1 = [65]
print("1-expected true")
print(validUTF8(data1))

data2 = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print("2-expected true")
print(validUTF8(data2))

data3 = [229, 65, 127, 256]
print("3-expected false")
print(validUTF8(data3))

data4 = [241, 129, 129, 129]
print("4-expected true")
print(validUTF8(data4))

data5 = [225, 129, 129, 30]
print("5-expected true")
print(validUTF8(data5))

data6 = [193, 129, 64, 28]
print("6-expected true")
print(validUTF8(data6))

data7 = [241, 129, 129, 192]
print("7-expected false")
print(validUTF8(data7))

data8 = data1 + data2 + data4 +data5 +data6
print("8-expected true")
print(validUTF8(data8))

