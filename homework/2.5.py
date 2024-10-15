import random


result_tuple = tuple(x for x in (random.randint(1, 5) for _ in range(3)) if x % 2 != 0)

print(result_tuple)
