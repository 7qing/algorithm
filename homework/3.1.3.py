class Vehicle:
    def __init__(self,MaxSpeed,weight):
        self.__max_speed = MaxSpeed  
        self.__weight = weight   
        
    def get_max_speed(self):
        return self.__max_speed
    
    def set_max_speed(self, speed):
        self.__max_speed = speed
        
    def get_weight(self):
        return self.__weights
    

class Bicycle(Vehicle):
    def __init__(self,MaxSpeed,weight,height):
        super().__init__(MaxSpeed,weight)
        self.__height = height

    def set_max_speed(self, speed):
        super().set_max_speed(speed)
    def get_max_speed(self):
        return super().get_max_speed()
    @property
    def height(self):
        return self.__height
    
    @height.setter
    def height(self, value):

        self.__height = value
    
    @height.deleter
    def height(self):
        del self.__height


bike =Bicycle(100,10,2)
print (bike.get_max_speed())
bike.set_max_speed(120)
print (bike.get_max_speed())