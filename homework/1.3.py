
import math
import random

#设计函数用来计算斐波那契数列中小于参数 n 的所有值


def man1(num)->list:
    curr =1
    last =0
    list = []  
    while curr<num:
        list.append(curr)
        tmp = curr
        curr = curr+last
        last = curr
    return list

#利用列表实现筛选法求素数
def man2(num):
    m = math.ceil(math.sqrt(num)+1)
    for i in range(2, m):
        if num%i == 0 and i<num:
            return False
            break
        else:
            return True

def manman2():
    n = input("请输入一个大于2的自然数:")
    n = int(n)
    list2 =[]
    list2=list(filter(man2, [i for i in range(2, n+1)]))
    print(list2)

def manman1():
    n = input("请输入一个大于2的自然数:")
    n = int(n)
    list2 =[i for i in range(2, n+1) if man2(i)]
    print(list2)


#：判断回文
def man3(str2):
    n = len(str2)
    right = n-1
    left = 0
    while left<n/2:
        if(str2[left]!=str2[right]):
            return False
        left+=1
        right-=1
    return True


#随机产生包含 n 个整数的列表，返回一个元组，其中第一个元素为所有参数的平均值，其他元素为所有参数中大于平均值的整数。

def man4(num):
    numbers = [random.randint(1, 100) for _ in range(num)]
    print(numbers)
    avg = sum(numbers) / num
    greater_than_avg = [num1 for num1 in numbers if num1 > avg]
    return (avg, *greater_than_avg)

#一年 365 天， 每周工作 5 天，休息 2 天，休息日水平下降0.01，工作日要努力到什么程度一年后的水平才与每天努力 1%所取得的效果（即37.78 倍）一样呢？
def man5():
    log_x = (math.log(37.78) - 105  * math.log(0.99 )) / 260 
    x = math.exp(log_x)
    return x

print(man5())


