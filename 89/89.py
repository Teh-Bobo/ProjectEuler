import time
START = time.time()
nums = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
romans = {1000:"M",500:"D",100:"C",50:"L",10:"X",5:"V",1:"I"}
def romanToNumeral(roman):
    ret = [nums[c] for c in roman]
    for i in range(len(ret)-1): #handle subtraction like "IV"
        if ret[i] < ret[i+1]:
            ret[i+1] -= ret[i]
            ret[i] = 0
    return sum(ret)
def numeralsToRoman(numeral):
    ret = ""
    for base in sorted(romans.keys(),reverse=True):
        howmany = numeral//base
        ret += (romans[base]*howmany)
        numeral -= base*howmany
    ret = ret.replace("DCCCC","CM")\
        .replace("CCCC","CD")\
        .replace("LXXXX","XC")\
        .replace("XXXX","XL")\
        .replace("VIIII","IX")\
        .replace("IIII","IV")
    return ret
with open("p089_roman.txt") as file:
    print(sum(filter(None,map(lambda x: len(x)-len(numeralsToRoman(romanToNumeral(x))),[line.strip() for line in file]))))
print(time.time()-START)
