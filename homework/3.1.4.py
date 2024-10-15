class Myqueue:
    def __init__(self, size):
        """
        初始化队列，设置最大容量 size 和当前元素计数 curr。
        """
        self.size = size  # 队列的最大大小
        self.data = []    # 队列的数据存储
        self.curr = 0     # 当前队列中的元素数
    
    def empty(self) -> bool:
        return self.curr == 0
    
    def full(self) -> bool:
        return self.curr == self.size
    
    def top(self):
        if not self.empty():
            return self.data[0]  # 返回队列的第一个元素
        else:
            raise IndexError("队列为空，无法获取队首元素")  # 抛出异常
    
    def push(self, data):
        if not self.full():
            self.data.append(data)  # 添加元素到队列的末尾
            self.curr += 1          # 更新队列的元素计数
        else:
            raise OverflowError("队列已满，无法添加元素")  # 抛出异常
    
    def pop(self):
        if not self.empty():
            self.curr -= 1          # 更新队列的元素计数
            return self.data.pop(0)  # 移除并返回队列的第一个元素
        else:
            raise IndexError("队列为空，无法弹出元素")  # 抛出异常