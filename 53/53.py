import operator as op
import functools
import math
import time
def nCr(n, r):
    r = min(r, n-r)
    if r == 0: return 1
    numer = functools.reduce(op.mul, range(n, n-r, -1))
    denom = functools.reduce(op.mul, range(1, r+1))
    return numer//denom

start = time.time()
count = 0
for N in range(1,101):
    for R in range(1,N):
        if nCr(N,R) > 1000000:
            count += 1
print(count)
print(time.time() - start)
