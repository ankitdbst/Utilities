#!/usr/bin/env python

from cipher import *

class AffineCipher(Cipher):
    """A Class to encrypt or decrpyt a affine cipher"""
    a = 0
    b = 0
    message = ""

    def init(self):
        """ Initialize data structures """
        print 'enter the message to encrypt/decrypt :',
        self.message = raw_input()
        print 'enter a & b :',
        self.a, self.b = (int(x) for x in raw_input().split())
        if self.validate() == 0:
            sys.exit()
        print 'encrypt - 1 | decrypt - 2 :',
        choice = int(raw_input())
        return choice

    def validate(self):
        """ Check if a, mod are relatively prime """
        g, x, y = self.egcd(self.a, self.mod)
        if not g == 1:
            print '(%d, %d) are not relatively prime!' % (self.a, self.mod)
            return 0
        return 1

    def shifte(self, s, a, b):
        """ shifts by 'b' after multiplying by 'a' """
        if not s.isspace() and not s.isdigit():
            ch = self.case(s)
            s = chr(((a * (ord(s) - ord(ch)) + b + self.mod) % self.mod) + ord(ch))
        return s

    def shiftd(self, s, inva, b):
        """ shifts by 'b' after multiplying by 'a-1' """
        if not s.isspace() and not s.isdigit():
            ch = self.case(s)
            s = chr(((inva * (ord(s) - ord(ch) - b) + self.mod) % self.mod) + ord(ch))
        return s

    def encrypt(self):
        """ encrypts the plain text """
        return ''.join(self.shifte(i, self.a, self.b) for i in self.message)

    def decrypt(self):
        """ decrypts the cipher text """
        return ''.join(self.shiftd(i, self.inversemod(self.a), self.b) for i in self.message)
