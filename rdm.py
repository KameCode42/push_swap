import random

min_entier = -2**31
max_entier = 2**31 - 1

nombres_aleatoires = set()
while len(nombres_aleatoires) < 500:
    nombres_aleatoires.add(random.randint(min_entier, max_entier))

nombres_aleatoires = list(nombres_aleatoires)
random.shuffle(nombres_aleatoires)
print(*nombres_aleatoires)