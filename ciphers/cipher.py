#!/usr/bin/env python

import sys

class Cipher:
    mod = 26

    def init(self):
        pass

    def encrypt(self):
        pass

    def decrypt(self):
        pass

    def modexponent(self, base, exp, m):
        result = 1
        while exp > 0:
            if exp & 1 == 1:
                result = (result * base) % m
            base = (base * base) % m
            exp >>= 1
        return result % m

    def egcd(self, a, b):
        if a == 0:
            return b, 0, 1
        d, x1, y1 = self.egcd(b % a, a)
        x = y1 - (b / a) * x1
        y = x1
        return d, x, y

    def inversemod(self, a):
        g, x, y = self.egcd(a, self.mod)
        return x

    def case(self, ch):
        return (ch.isupper() and 'A') or 'a' # checks whether key char is upper/lower

