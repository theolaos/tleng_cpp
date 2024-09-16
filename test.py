from time import time

from build.tleng3 import add, subtract

t1 = time()
print("add(1,2) == 3")
print(add(1,2) == 3)


print("subtract(1,2) == -1")
print(subtract(1,2) == -1)
t2 = time()

print(f"Tests finished in: {t2 - t1} seconds!")