#!/usr/bin/env python

from cipher import *

class RSA(Cipher):
    """A Class to encrypt or decrpyt a RSA """
    p = 0
    q = 0
    n = 0
    message = 0

    def init(self):
        """ Initialize data structures """
        print 'enter the message to encrypt/decrypt :',
        self.message = int(raw_input())
        print 'enter p & q :',
        self.p, self.q = (int(x) for x in raw_input().split())
        self.n = self.p * self.q
        print 'enter encryption exponent :',
        self.e = int(raw_input())
        if self.validate() == 0:
            sys.exit()
        print 'encrypt - 1 | decrypt - 2 :',
        choice = int(raw_input())
        return choice

    def validate(self):
        """ Check if e, (p-1)*(q-1) are relatively prime """
        prod = (self.p - 1) * (self.q - 1)
        g, x, y = self.egcd(self.e, prod)
        if not g == 1:
            print '(%d, %d) are not relatively prime!' % (self.e, prod)
            return 0
        return 1

    def encrypt(self):
        """ encrypts the plain text """
        return self.modexponent(self.message, self.e, self.n)

    def decrypt(self):
        """ decrypts the cipher text """
        prod = (self.p - 1) * (self.q - 1)
        g, x, y = self.egcd(self.e, prod)
        d = x % prod
        return self.modexponent(self.message, d, self.n)
