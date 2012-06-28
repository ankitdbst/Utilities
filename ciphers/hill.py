#!/usr/bin/env python

from cipher import *
from matrix import *

class HillCipher(Cipher):
    """A Class to encrypt or decrpyt a Hill Cipher cipher"""
    key = ""
    message = ""
    msgmatrix = []
    keymatrix = []
    nrows = ncols = 0

    def init(self):
        """ Initialize data structures """
        print 'enter the message to encrypt/decrypt :',
        self.message = raw_input()
        self.nrows = self.ncols = len(self.message)
        print 'enter the key :',
        self.key = raw_input()
        self.fillmatrix()
        if self.validate() == 0:
            sys.exit()
        print 'encrypt - 1 | decrypt - 2 :',
        choice = int(raw_input())
        return choice

    def validate(self):
        """ Checks if det, mod are relatively prime """
        d = det(self.keymatrix)
        g, x, y = self.egcd(d, self.mod)
        if not g == 1:
            print '(det(%s) = %d, %d) are not relatively prime!' % (self.key, d, self.mod)
            return 0
        return 1

    def fillmatrix(self):
        """ fills the key and message matrix """
        self.msgmatrix = [(ord(i) - ord(self.case(i))) for i in self.message ]
        self.keymatrix = [ [None] * self.ncols for i in xrange(0, self.nrows) ]
        for i in xrange(0, self.nrows):
            for j in xrange(0, self.ncols):
                ch = self.case(self.key[i*self.ncols+j])
                self.keymatrix[i][j] = ord(self.key[i*self.ncols+j]) - ord(ch)

    def encrypt(self):
        """ encrypts the plain text """
        evector = matmult(self.keymatrix, self.msgmatrix)
        return ''.join(chr((evector[i] % self.mod) + ord(self.case(self.key[i]))) for i in xrange(0, len(evector)))

    def decrypt(self):
        """ decrypts the cipher text """
        adj = adjoint(self.keymatrix)
        invd = self.inversemod(det(self.keymatrix))
        invmatrix = scalar_matrix(invd, adj)
        dvector = matmult(invmatrix, self.msgmatrix)
        return ''.join(chr((dvector[i] % self.mod) + ord(self.case(self.key[i]))) for i in xrange(0, len(dvector)))

