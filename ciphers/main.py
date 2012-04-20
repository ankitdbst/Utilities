#!/usr/bin/env python

from caesar import *
from affine import *
from vigenere import *
from hill import *
from rsa import *

def main():
    rs = RSA()
    choice = rs.init()
    options = {
        1 : rs.encrypt,
        2 : rs.decrypt
    }
    print options[choice]()

    return 0

if __name__ == '__main__':
    main()


