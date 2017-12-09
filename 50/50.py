import sys
sys.path.insert(0, "C:\\Users\\bobo\\Documents\\Code\\eulerlib-py")
import FactorTable
import time

start = time.time()
MAX = 100000
f = FactorTable.FactorTable(MAX+1)
primes = f.PrimesInRange(2,MAX+1)
print(len(primes))
print("finished creating tables",time.time()-start)

anslen = 0
anssum = 0
#This works, but the bigger the MAX the more memory it takes
##sss = [[primes[i:i+length] for i in range(len(primes)//2)] for length in range(1,len(primes)//2)]
##ans = list(filter(None,list(map(lambda ss: list(filter(lambda x: len(x) > anslen and sum(x)<MAX and f.IsPrime(sum(x)),ss)),sss))))[-1][0]

for length in range(1,len(primes)//2):
    #Trade-off between the above, memory intesive way, and the below CPU intensive way
    ss = [primes[i:i+length] for i in range(len(primes)//2)]
    sumss = map(sum,ss)
    a = list(filter(lambda x: len(x) > anslen and sum(x)<MAX and f.IsPrime(sum(x)),ss))
    if len(a) is not 0:
        anslen = length
        anssum = sum(a[0])
##    for i in range(2,MAX-length-2):
##        s = primes[i:i+length]
##        sums = sum(s)
##        if sums >= MAX: break
##        if f.IsPrime(sums) and len(s) > anslen:
##            print(s,sums)
##            break
##print(ans)
print(anslen,anssum)
print(time.time()-start)
