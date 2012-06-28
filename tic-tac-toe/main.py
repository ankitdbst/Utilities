#!usr/bin/env python
import time, TicTacToe
from TicTacToe import TicTacToe

def main():

    t = TicTacToe()
    board = [['.' for i in xrange(0, 3)] for j in xrange(0, 3)]
    t.prettyPrint(board)

    print "You wanna take on first ? (y/n)",
    op = raw_input().lower()
    if op == 'y':
        player = 'X'
        bot = 'O'
        t.setPlayerTurn(bot)
    else:        
        player = 'O'
        bot = 'X'
        t.setPlayerTurn(bot)
        print "I'll start then.."
        time.sleep(0.5)
        code, board, res = t.nextMove(board)
        t.prettyPrint(board)            

    while True:
        i, j = getMove(board)
        board[i][j] = player
        print "Your move is.."
        t.prettyPrint(board)

        code, board, res = t.nextMove(board)
        if code == 1:
            print "Here is my move.."
            time.sleep(0.5)
            t.prettyPrint(board)

        if not res == 'unknown':
            if res == 'draw':
                print "It's a draw!"
            else:
                if res == player:
                    print "You won!"
                else:
                    print "I won!"
            break

    print "Thanks for playing. Good day!"
    return 0

# Get the position of input move
def getMove(board):
    print "Enter next position [eg. A1, B2] :",
    i, j = parseInput(raw_input().upper(), board)
    return i, j

# Basic input check
def parseInput(move, board):
    i = ord(move[0]) - ord('A')
    j = int(move[1]) - 1
    if not (i >= 0 and i < 3) or not (j >= 0 and j < 3):
        print "Move out of range."
        i, j = getMove(board)
    if not board[i][j] == '.':
        print "Move already exists."
        i, j = getMove(board)
    return i, j

if __name__ == '__main__':
    main()