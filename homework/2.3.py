import random
import string

# 生成随机字符串
def random_string(max_len):
    length = random.randint(1, max_len)  # 随机生成 1 到 max_len 长度的字符串
    return ''.join(random.choice(string.ascii_letters + string.digits) for _ in range(length))

# 生成含有 n 个嵌套列表的结构
def generate_nested_list(n, m):
    nested_list = []
    for _ in range(n):
        # 每个子列表包含 1 到 n 个随机字符串
        num_of_strings = random.randint(1, n)
        sublist = [random_string(m) for _ in range(num_of_strings)]
        nested_list.append(sublist)
    return nested_list

# 按照字符串长度降序排序
def sort_nested_list(nested_list):
    for sublist in nested_list:
        sublist.sort(key=len, reverse=True)  # 对每个子列表按照长度降序排序
    return nested_list


n = int(input("请输入列表个数 n: "))
m = int(input("请输入字符串最大长度 m: "))
        
 # 生成嵌套列表
nested_list = generate_nested_list(n, m)
        
print("\n生成的嵌套列表:")
for sublist in nested_list:
    print(sublist)
        
sorted_nested_list = sort_nested_list(nested_list)
        
print("\n排序后的嵌套列表:")
for sublist in sorted_nested_list:
    print(sublist)
