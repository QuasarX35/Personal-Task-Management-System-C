import math
import time 

def reverse(num):
    final_num = 0
    
    if num > 0:
        while num != 0:
            pow_10 = math.floor(math.log10(num))
            final_num += (num % 10) * (10 ** pow_10)
            if final_num > 2 ** 31:
                return "error"
            num //= 10
        return final_num
    
    if num < 0:
        num *= -1
        while num != 0:
            pow_10 = math.floor(math.log10(num))
            final_num += (num % 10) * (10 ** pow_10)
            if final_num < -2 ** 31:
                return "error"
            num //= 10
        return final_num * -1
    
    else:
        return num

def reverse2(x):
    rev = 0
    max, min = 2 ** 31 - 1, -2 ** 31
    while x != 0:
        pop = x % 10
        # Deal with Python Modulo
        if x < 0 and pop > 0:
            pop -= 10
        if rev > max // 10 or rev < min // 10 + 1: return 0
        x = (x - pop) // 10
        rev = rev * 10 + pop
    return rev

num = -123456789098
# print(reverse(num))
# print(reverse2(num))

# final_num = 0
# pow_10 = math.floor(math.log10(num))
# final_num += (num % 10) * (10 ** pow_10)
# num //= 10

# print(final_num)

print(reverse2(num))