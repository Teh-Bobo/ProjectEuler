import sys
sys.path.insert(0, "..\\..\\eulerlib-py")
import FactorTable
import time
import functools
import multiprocessing

def numoff(a,b):
    sa = str(a)
    sb = str(b)
    if len(sa) != len(sb):
        raise ValueError
    ret = 0
    mask = [True] * len(sa)
    diff = ''
    for i in range(len(sa)):
        if sa[i] != sb[i]:
            ret+=1
            mask[i] = False
            if diff == '':
                diff = sb[i]
            else:
                if diff != sb[i]:
                    return None
    return ret,tuple(mask),b
MAX = 10
##THREADS = 4
f = FactorTable.FactorTable(1000000)
##print("finished creating tables",time.time()-start)
while True:
    start = time.time()
    MAX *= 10
    MIN = MAX//10
    SWAPDIGITS = len(str(MAX))-1
    primes = f.PrimesInRange(MIN,MAX+1)

    allmasks = [[]] * len(primes)
    for i,p in enumerate(primes):
        ans = list(filter(lambda x: x != None and x[0] < SWAPDIGITS and x[0] > 0,\
                                                            map(lambda x: numoff(p,x),primes[i:])))
        if len(ans) > 5:
            mask = {}
            for t in ans:
                if t[1] in mask:
                    mask[t[1]].append(t[2])
                else:
                    mask.update({t[1]:[p,t[2]]})      
            allmasks[i] = mask[max(mask,key=mask.get)]
    print(list(functools.reduce(lambda x,y: x if len(x)>=len(y) else y,allmasks)))
    print(time.time()-start)    

##print(list(filter(lambda x: len(x) > 6,[list(filter(lambda x: numoff(x,p) < 2,primes[i:])) for i,p in enumerate(primes)])))


