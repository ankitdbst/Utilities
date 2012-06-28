import sys, copy

class Node():
    def __init__(self):
        self.brd = []
        self.turn = 1
        self.son = None
        self.next = None

class TicTacToe():    

    def __init__(self):
        self.brd = []
        # Initialize empty board
        self.brd = [['.' for j in xrange(0, 3)] for i in xrange(0, 3)]
        self.player = 'X'
        self.looklevel = 2 # look ahead level for the game tree

    def nextMove(self, brd):        
        """
            Calculates the best move for the player
            by setting up the game tree and evaluating
            each node of the tree
        """        
        # Discrepancy in the algorithm cause the 
        # other player to win too! ;) So checking that..
        if self.player == 'X':
            player = 'O'
        else:
            player = 'X'
        res = self.checkBoard(brd, player)
        if not res == 'unknown':
            # pretest
            code = 0
            return code, brd, res

        self.brd = brd
        ptree = self.buildTree()
        best, value = self.bestMatch(ptree)
        # Check for winner after best match returns
        # next board config
        res = self.checkBoard(best.brd, self.player)
        code = 1
        return code, best.brd, res

    def bestMatch(self, ptree):
        """
            Returns the child node with the highest 
            static evaluation
        """
        if ptree.son == None:
            # Leaf node
            return ptree, self.evaluate(ptree.brd, ptree.turn)
        else:
            # Non-leaf node
            p = ptree.son
            pbest, pvalue = self.bestMatch(p)
            pbest = p
            # This is because we can calculate
            # min(x, y) = -max(-x, -y)
            if ptree.turn == -1:
                pvalue = -pvalue
            p = p.next
            while not p == None:
                q, val = self.bestMatch(p)
                if ptree.turn == -1:
                    val = -val
                if val > pvalue:
                    pvalue = val
                    pbest = p
                p = p.next
            if ptree.turn == -1:
                pvalue = -pvalue

            return pbest, pvalue

    def buildTree(self):
        """
            Builds the game tree for the next move
        """
        ptree = Node()
        ptree.brd = self.brd
        ptree.turn = 1
        ptree = self.expandTree(ptree, 0)
        return ptree

    def expandTree(self, p, depth):
        """
            Expands the game tree to the required
            looklevel (ahead)
        """
        if depth < self.looklevel:
            q = self.generate(p)
            p.son = q
            while q != None:
                if p.turn == 1:
                    q.turn = -1
                else:
                    q.turn = 1
                q.son = None
                self.expandTree(q, depth+1)
                q = q.next

        return p

    def generate(self, p):
        """
            Generate all possible combinations 
            of the child node of the given node
            in the game tree
        """
        root = None        
        
        # Create new node
        temp = Node()
        temp.brd = p.brd

        # Decide turn of player
        if p.turn == 1:
            player = self.player
        else:
            if self.player == 'X':
                player = 'O'
            else:
                player = 'X'

        for i in xrange(0, 3):
            for j in xrange(0, 3):
                if p.brd[i][j] == '.':
                    temp.brd[i][j] = player
                    temp.next = None
                    # If no root node for LL
                    if root == None:
                        # Copy temp node to root
                        root = copy.deepcopy(temp)
                        p = root
                    else:
                        p.next = copy.deepcopy(temp)
                        p = p.next
                    # Reset the value
                    temp.brd[i][j] = '.'

        return root

    def evaluate(self, brd, turn):
        """
            Given a board config, this method 
            returns a static evaluation of the 
            chances of the player (whose turn it is)  
        """
        # Decide turn of player
        if turn == 1:
            player = self.player
        else:
            if self.player == 'X':
                player = 'O'
            else:
                player = 'X'

        # Compute score
        score = 0
        d1 = d2 = False

        for i in xrange(0, 3):
            for j in xrange(0, 3):
                if brd[i][j] == player:
                    if i == j: 
                        d1 = True
                    if i == 2-j:
                        d2 = True
                    score += self.getAxial(brd, player, i, j)

        score += self.getDiagonal(brd, player, d1, d2)

        return score

    def getDiagonal(self, brd, player, d1, d2):
        """
            Examine the diagonals for a perfect score
        """
        score = 0

        # Check main diagonal
        if d1:
            found = True
            for i in xrange(0, 3):
                if not brd[i][i] == player and not brd[i][i] == '.':
                    found = False
            if found == True:
                score += 1
        
        # Check other diagonal
        if d2:
            found = True
            for i in xrange(0, 3):
                if not brd[i][2-i] == player and not brd[i][2-i] == '.':
                    found = False
            if found == True:
                score += 1

        return score

    def getAxial(self, brd, player, i, j):        
        """
            Examine the Horizontal & Vertical axis
            for a perfect score
        """
        score = 0
        # Check Vertical line
        found = True
        for k in xrange(0, 3):
            if not brd[k][j] == player and not brd[k][j] == '.':
                fount = False
                break
        if found == True:
            score += 1 

        # Check Horizontal line
        found = True
        for k in xrange(0, 3):
            if not brd[i][k] == player and not brd[i][k] == '.':
                found = False
                break
        if found == True:
            score += 1

        return score        

    def checkBoard(self, brd, player):
        """
            This checks the board for the winner (or draw) after
            nextMove has been calculated
        """
        res = 'unknown'

        d1 = d2 = True
        for i in xrange(0, 3):
            if ((   brd[i][0] == player and 
                    brd[i][1] == player and
                    brd[i][2] == player ) 
                    or 
                (   brd[0][i] == player and
                    brd[1][i] == player and
                    brd[2][i] == player )):
                res = player
            if not brd[i][i] == player:
                d1 = False
            if not brd[i][2-i] == player:
                d2 = False
        if d1 == True or d2 == True:
            res = player

        for i in xrange(0, 3):
            for j in xrange(0, 3):
                # Game is not completed
                if brd[i][j] == '.':
                    return res
        
        return 'draw'

    def setPlayerTurn(self, player):        
        """ 
            Set player turn
        """
        self.player = player

    def getPlayerTurn(self):
        """
            Return current player
        """
        return self.player

    def prettyPrint(self, brd):
        """
            Prints the board in a user
            friendly fashion
        """
        for i in brd:
            for j in i:
                print j + ' ',
            print '\n'

    def printTree(self, p):
        """
            Prints the game tree upto 
            looklevel in a bottom up fashion
        """
        if not p == None:
            while not p == None:
                self.printTree(p.son)
                self.prettyPrint(p.brd)
                p = p.next
            
