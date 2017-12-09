import decimal
import math
import multiprocessing

MAX = 1000
PREC = 2200
THREADS = 4
decimal.getcontext().prec = PREC
decimal.getcontext().rounding = decimal.ROUND_FLOOR

def shortestRep(num):
    rep = ""
    for i in range(int(len(num)/2),0,-1):
        t = num[:i]
        if (t * math.ceil(len(num)/len(t)))[:len(num)] == num:
            rep = t
    return rep
win = ""
for d in range(3,MAX+1,2):
    res = str(decimal.Decimal(1)/decimal.Decimal(d))
    for start in range(2,int(len(res)/2)):
        sr = shortestRep(res[start:])
        if len(sr) > len(win):
            win = sr
            print(str(d) + "," + str(len(win)) + " - " + sr + " - " + res)
            break
    if len(win) >= int(PREC/2): break
