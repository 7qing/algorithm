#编写程序，先生成包含 1000 个随机字符的字符串，然后统计每个字符出现的次数。要求：查找资料编写至少 2 种不同的求解方法。
import string
import random
from collections import Counter

str1 = ''.join(random.choice(string.ascii_lowercase) for _ in range(1000))




#1.
counter1 =Counter(str1)
for char, count in counter1.items():
    print(f"{char}: {count} 次")
    
#2.
dict = {}
for char in str1:
    if char in dict:
        dict[char]+=1
    else:
        dict[char]=1

for char, count in dict.items():
    print(f"{char}: {count} 次")