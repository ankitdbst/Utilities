#!/usr/bin/env python

from cipher import *

class VigenereCipher(Cipher):
    """A Class to encrypt or decrpyt a affine cipher"""
    key = ""
    keynum = 6 # default
    message = ""

    def init(self):
        """ Initialize data structures """
        print 'enter the message to encrypt/decrypt :',
        self.message = raw_input()
        print 'enter the key :',
        self.key = raw_input()
        print 'encrypt - 1 | decrypt - 2 :',
        choice = int(raw_input())
        return choice

    def shift(self, s, index, sign):
        """ shifts the input char by 'k' """
        if s.isalpha():
            ch = self.case(s)
            k = ord(self.key[index % len(self.key)]) - ord(ch)
            s = chr(((ord(s) - ord(ch) + sign * k + self.mod) % self.mod) + ord(ch))
        elif s.isdigit():
            s = str((int(s) + sign*self.keynum) % 10);
        return s

    def encrypt(self):
        """ encrypts the plain text """
        return ''.join(self.shift(self.message[i], i, 1) for i in xrange(0, len(self.message)))

    def decrypt(self):
        """ decrypts the cipher text """
        return ''.join(self.shift(self.message[i], i, -1) for i in xrange(0, len(self.message)))
