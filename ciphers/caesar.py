#!/usr/bin/env python

from cipher import *

class CaesarCipher(Cipher):
    """A Class to encrypt or decrpyt a caesar cipher"""
    key = 0
    message = ""

    def init(self):
        """ Initialize data structures """
        print 'enter the message to encrypt/decrypt :',
        self.message = raw_input()
        print 'enter the key :',
        self.key = int(raw_input())
        print 'encrypt - 1 | decrypt - 2 :',
        choice = int(raw_input())
        return choice

    def shift(self, s, k):
        """ shifts the input char by 'k' """
        if not s.isspace() and not s.isdigit():
            ch = self.case(s)
            s = chr(((ord(s) - ord(ch) + k + self.mod) % self.mod) + ord(ch))
        return s

    def encrypt(self):
        """ encrypts the plain text """
        return ''.join(self.shift(i, self.key) for i in self.message)

    def decrypt(self):
        """ decrypts the cipher text """
        return ''.join(self.shift(i, -self.key) for i in self.message)
