# 系统类实现
def system_set_operations(setA, setB):
    # 交集
    intersection = setA.intersection(setB)
    # 并集
    union = setA.union(setB)
    # 差集
    difference = setA.difference(setB)

    return intersection, union, difference

# 示例
setA = {1, 2, 3, 4}
setB = {3, 4, 5, 6}

intersection, union, difference = system_set_operations(setA, setB)
print("交集:", intersection)
print("并集:", union)
print("差集 (setA - setB):", difference)

# 自定义集合类
class CustomSet:
    def __init__(self, elements):
        self.elements = elements

    def intersection(self, other):
        result = [item for item in self.elements if item in other.elements]
        return CustomSet(result)

    def union(self, other):
        result = self.elements[:]  # 复制自身元素
        for item in other.elements:
            if item not in result:
                result.append(item)
        return CustomSet(result)

    def difference(self, other):
        result = [item for item in self.elements if item not in other.elements]
        return CustomSet(result)

    def __repr__(self):
        return f"{self.elements}"

# 示例
setA = CustomSet([1, 2, 3, 4])
setB = CustomSet([3, 4, 5, 6])

intersection = setA.intersection(setB)
union = setA.union(setB)
difference = setA.difference(setB)

print("交集:", intersection)
print("并集:", union)
print("差集 (setA - setB):", difference)