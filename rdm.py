import random

min_entier = -2**31
max_entier = 2**31 - 1

nombres_aleatoires = random.sample(range(min_entier, max_entier + 1), 500)
print(*nombres_aleatoires)