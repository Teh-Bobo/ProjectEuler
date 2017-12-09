import sys
sys.path.insert(0, "C:\\Users\\bobo\\Documents\\Code\\eulerlib-py")
import FactorTable
import time

MAX = 1000000

f = FactorTable.FactorTable(MAX)
print("Done making table")
start = time.time()
for i in range(100000,MAX):
    if len(f.PrimeFactors(i)) == 4\
       and len(f.PrimeFactors(i-1)) == 4\
       and len(f.PrimeFactors(i-2)) == 4\
       and len(f.PrimeFactors(i-3)) == 4:
        print(i-3,i-2,i-1,i)
        print(time.time()-start)
        break
