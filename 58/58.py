import sys
sys.path.insert(0, "..\\..\\eulerlib-py")
import FactorTable
#size of ring = len(side of ring)*4 - 4
#To travel d-r: size of ring + d-r
#d-r = iter, 1^2, 3^2, 5^2...
#d-l = d-r - sqrt(d-r) - 1
#u-l = d-l - sqrt(d-r) - 1
#u-r = u-l - sqrt(d-r) - 1

##nums = [1]
corners = [0,0,0,0]
i = 3
primes = 0
nonprimes = 1
f = FactorTable.FactorTable(50000000)
print("Table Done")
while True:
##    nums.append(i**2)
    corners[0] = i**2
##    nums.append(nums[-1]-i+1)
    corners[1] = corners[0]-i+1
##    nums.append(nums[-1]-i+1)
    corners[2] = corners[1]-i+1
##    nums.append(nums[-1]-i+1)
    corners[3] = corners[2]-i+1
    for p in corners:
        if f.IsPrime(p):
            primes+=1
        else:
            nonprimes+=1
    print(primes/(nonprimes+primes))
    if primes/(nonprimes+primes) < .1:
        print(i)
        break
    i += 2
