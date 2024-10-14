#定义节点数据结构
class Node:
    def __init__(self, name, is_max, value=None):
        self.name = name      # 节点名称
        self.is_max = is_max  # 是否为 Max 节点
        self.value = value    # 叶子节点的值，如果有的话
        self.children = []    # 子节点列表
        self.alpha = float('-inf')  # 初始 Alpha 值
        self.beta = float('inf')    # 初始 Beta 值

    def add_child(self, child):
        self.children.append(child)

#Alpha - Beta 剪枝算法
def alpha_beta(node, alpha, beta):
    print(f"访问点: {node.name}, 初始 Alpha: {alpha}, Beta: {beta}")

#如果是叶子节点，返回其值
    if node.value is not None:
        print(f"叶子节点: {node.name} 值: {node.value}, Alpha: {alpha}, Beta: {beta}")
        return node.value

#Max 节点逻辑
    if node.is_max:
        value = float('-inf')
        for child in node.children:
            value = max(value, alpha_beta(child, alpha, beta))
            alpha = max(alpha, value)
            print(f"Max节点: {node.name}, 更新Alpha: {alpha}, Beta: {beta}")
#Beta 剪枝
            if alpha >= beta:
                print(f"Beta 剪枝 节点: {node.name}, Alpha: {alpha}, Beta: {beta}")
                break
        return value
#Min 节点逻辑
    else:
        value = float('inf')
        for child in node.children:
            value = min(value, alpha_beta(child, alpha, beta))
            beta = min(beta, value)
            print(f"Min 节点: {node.name}, Alpha: {alpha}, 更新 Beta: {beta}")
#Alpha 剪枝
            if beta <= alpha:
                print(f"Alpha 剪枝 Node {node.name}, Alpha: {alpha}, Beta: {beta}")
                break
        return value

#创建博弈树结构
#根节点 N00(Max 节点)
N00 = Node("N00", is_max=True)

#第二层节点
N10 = Node("N10", is_max=False)

N11 = Node("N11", is_max=False)

#第三层节点
N20 = Node("N20", is_max=True)
N21 = Node("N21", is_max=True)
N22 = Node("N22", is_max=True)
N23 = Node("N23", is_max=True)

#第四层叶子节点
N30 = Node("N30", is_max=False)
N31 = Node("N31", is_max=False)
N32 = Node("N32", is_max=False)
N33 = Node("N33", is_max=False)
N34 = Node("N34", is_max=False)
N35 = Node("N35", is_max=False)
N36 = Node("N36", is_max=False)
N37 = Node("N37", is_max=False)

N40 = Node("N40", is_max=True, value=60)
N41 = Node("N41", is_max=True, value=63)
N42 = Node("N42", is_max=True, value=15)
N43 = Node("N43", is_max=True, value=58)
N44 = Node("N44", is_max=True, value=81)
N45 = Node("N45", is_max=True, value=74)
N46 = Node("N46", is_max=True, value=88)
N47 = Node("N47", is_max=True, value=15)
N48 = Node("N48", is_max=True, value=20)
N49 = Node("N49", is_max=True, value=92)
N4a = Node("N4a", is_max=True, value=9)
N4b = Node("N4b", is_max=True, value=62)
N4c = Node("N4c", is_max=True, value=82)
N4d = Node("N4d", is_max=True, value=92)
N4e = Node("N4e", is_max=True, value=54)
N4f = Node("N4f", is_max=True, value=17)

#添加节点到树结构中
N00.add_child(N10)
N00.add_child(N11)

N10.add_child(N20)
N10.add_child(N21)

N11.add_child(N22)
N11.add_child(N23)

N20.add_child(N30)
N20.add_child(N31)

N21.add_child(N32)
N21.add_child(N33)

N22.add_child(N34)
N22.add_child(N35)

N23.add_child(N36)
N23.add_child(N37)

N30.add_child(N40)
N30.add_child(N41)

N31.add_child(N42)
N31.add_child(N43)

N32.add_child(N44)
N32.add_child(N45)

N33.add_child(N46)
N33.add_child(N47)

N34.add_child(N48)
N34.add_child(N49)

N35.add_child(N4a)
N35.add_child(N4b)

N36.add_child(N4c)
N36.add_child(N4d)

N37.add_child(N4e)
N37.add_child(N4f)

#执行 Alpha - Beta 剪枝并打印 Alpha 和 Beta
final_value = alpha_beta(N00, float('-inf'), float('inf'))
print(f"结果: {final_value}")
