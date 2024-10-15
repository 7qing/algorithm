max_overlap = lambda s1, s2: max([i for i in range(min(len(s1), len(s2)) + 1) if s1[-i:] == s2[:i]])
merge_strings = lambda s1, s2: s1 + s2[max_overlap(s1, s2):]


s1 = "1234"
s2 = "2347"
print(f"最大交叉部分长度: {max_overlap(s1, s2)}")
print(f"合并后的字符串: {merge_strings(s1, s2)}")
