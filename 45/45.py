import time

start = time.time()
MAX = 500000
##tris = frozenset([(n*(n+1))//2 for n in range(1,MAX)]) #Not needed since every Hex number is a triangle number
pents = frozenset([(n*(3*n-1))//2 for n in range(1,MAX)])
hexs = frozenset([(n*(2*n-1)) for n in range(1,MAX)])
print(pents.intersection(hexs))
print(list(filter(lambda x: x in pents, hexs)))
print(time.time()-start)
