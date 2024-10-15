class Employee:
    def __init__(self,name,num,basemoney):
        self.name = name
        self.num = num
        self.money = basemoney

    def pay(self):
        return self.base_salary
    
    def show(self):
        print(f"编号: {self.num}, 姓名: {self.name}, 月薪: {self.pay():.2f}")
    
class Manager(Employee):
    def __init__(self,name,num,basemoney,addmoney):
        super().__init__(name,num,basemoney)
        self.addmoney = addmoney
    
    def pay(self):
        return self.addmoney +2 *self.money
    
    def show(self):
        print(f"【主管】编号: {self.num}, 姓名: {self.name}, 月薪: {self.pay():.2f}")
        
class Salesman(Employee):
    def __init__(self,name,num,basemoney,addmoney):
        super().__init__(name,num,basemoney)
        self.addmoney = addmoney
    
    def pay(self):
        return 0.6 *self.addmoney +self.money
    
    def show(self):
        print(f"【销售员】编号: {self.num}, 姓名: {self.name}, 月薪: {self.pay():.2f}")


m1 = Manager('ayy',1,1000,1000)
m1.show()
a1 =Salesman('Yyx',2,1000,1000)
a1.show()