from __future__ import annotations

from time import time

from tleng3 import add, idivision, subtract

t1 = time()
print("add(1,2) == 3")
print(add(1,2) == 3)


print("subtract(1,2) == -1")
print(subtract(1,2) == -1)


print("idivision(6,2) == 3")
print(idivision(6,2) == 3)

print("idivision(6,0) == 0")
print(idivision(6,0) == 0)
t2 = time()

print(f"Tests finished in: {t2 - t1} seconds!")