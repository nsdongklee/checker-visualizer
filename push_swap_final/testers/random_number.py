import random

rand_num = list(range(100))
random.shuffle(rand_num)

_ = [print(n, end=' ') for n in rand_num]
