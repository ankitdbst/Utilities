#!/usr/bin/env python
import math
from GeneralHashFunctions import *

class Bloom():

    BITLENGTH  = 30

    """
        Implements the famous bloom filters using the
        GeneralHashFunctions from here :
        http://www.partow.net/programming/hashfunctions/index.html
    """
    def __init__(self, n):
        self.n = n
        self.m = self.BITLENGTH
        # calculate the optimal value of # of hash functions
        self.k = int((self.m/self.n)*math.log(2))
        # unset bits of the array
        self.arr = []
        self.arr = self.arr + [0]*(self.m - len(self.arr))
        # populate list of available hash functions
        self.hash_func = ['RSHash', 'JSHash', 'PJWHash', 'ELFHash', 'BKDRHash',
                        'SDBMHash', 'DJBHash', 'DEKHash', 'BPHash', 'FNVHash',
                        'APHash']        

    def insert(self, s):
        for i in xrange(0, self.k):
            pos = globals()[self.hash_func[i]](s) % self.m
            self.arr[pos] = 1

    def query(self, s):
        for i in xrange(0, self.k):
            pos = globals()[self.hash_func[i]](s) % self.m
            if self.arr[pos] == 0:
                return False
        return True

    def falsePos(self):
        # calculate probability of false positives
        setbits = 0
        for i in self.arr:
            if i == 1:
                setbits += 1        
        return round(math.pow(setbits*1.0 / self.m, self.k) * 100)

def main():
    
    n = int(raw_input())

    # instantiate new bloom filter
    b = Bloom(n)

    for i in xrange(0, n):
        word = raw_input()
        # insert into bloom filter
        b.insert(word)

    print "Probabilty of false positives", b.falsePos()

    q = int(raw_input())
    for i in xrange(0, q):
        word = raw_input()
        # query the filter for presence  
        if b.query(word) == False:
            print "%s does not exist in the dictionary" % word
        else:
            print "%s may be in the dictionary" % word

if __name__=='__main__':
    main()