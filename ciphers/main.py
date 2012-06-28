#!/usr/bin/env python

from caesar import *
from affine import *
from vigenere import *
from hill import *
from rsa import *

def main():
    vg = VigenereCipher()
    vg.key = "ankitgupta"
    for line in open('/home/anks/.creds','r').readlines():
        vg.message = line
        print vg.decrypt(),

    return 0

if __name__ == '__main__':
    main()


