#!/usr/bin/python

# Refer below for complete reference
# http://www.koders.com/python/fid7009D5725D29328D5F14BFD3C139B0337461D937.aspx?s=matrix#L5

def submatrix(m, row, col):
    nrows = len(m) - 1
    ncols = len(m[0]) - 1
    result = [ [None] * ncols for i in range(nrows) ]

    r = 0
    for i in range(nrows + 1):
        if i != row:
            c = 0
            for j in range(ncols + 1):
                if j != col:
                    result[r][c] = m[i][j]
                    c += 1
            r += 1
    return result

def cofactor(m, row, col):
    if (len(m) == 1):
        return m[0][0]
    else:
        sign = 1
        if (row + col) % 2 != 0:
            sign = -1
        return sign * det(submatrix(m, row, col))

def det(m):
    nrows = len(m)
    ncols = len(m[0])
    if (nrows == ncols):
        if (nrows == 1):
            result = m[0][0]
        elif (nrows == 2):
            result = m[0][0]*m[1][1] - m[0][1]*m[1][0]
        elif (nrows == 3):
            result = m[0][0]*(m[1][1]*m[2][2] - m[1][2]*m[2][1]) - m[0][1]*(m[1][0]*m[2][2] - m[1][2]*m[2][0]) + m[0][2]*(m[1][0]*m[2][1] - m[1][1]*m[2][0])
        else:
            result = 0
            for i in range(ncols):
                result += m[0][i] * cofactor(m, 0, i)
        return result

def transpose(m):
    nrows = len(m)
    ncols = len(m[0])
    result = [ [None] * nrows for i in range(ncols) ]
    for i in range(ncols):
        for j in range(nrows):
            result[i][j] = m[j][i]
    return result

# Defined as the transpose of the cofactor matrix
def adjoint(m):
    nrows = len(m)
    ncols = len(m[0])
    result = [ [None] * ncols for i in range(nrows) ]
    for i in range(nrows):
        for j in range(ncols):
            result[i][j] = cofactor(m, i, j)
    return transpose(result)

# Sum of the diagonal entries
def trace(m):
    nrows = len(m)
    result = 0
    for i in range(nrows):
        result += m[i][i]
    return result

# Defined as: (1 / det(M)) * adj(M)
def inverse(m):
    nrows = len(m)
    ncols = len(m[0])
    result = [ [0] * ncols for i in range(nrows) ]

    determinant = det(m)
    if determinant == 0:
        return result

    adj = adjoint(m)
    for i in range(nrows):
        for j in range(ncols):
            result[i][j] = (1.0 / determinant) * adj[i][j]
    return result

# Return a new matrix based on the original one but expanded to the
# given dimensions.  It can either be expanded to a zero matrix or an
# identity matrix (the default).
def matrix_expand(m, nrows, ncols, identity):
    nrows_old = len(m)
    ncols_old = len(m[0])

    res = [[0] * ncols for i in range(nrows)]
    if identity:
        for i in range(nrows):
            for j in range(ncols):
                if i == j: res[i][j] = 1

    for i in range(nrows_old):
        for j in range(ncols_old):
            res[i][j] = m[i][j]

    return res

def is_array(a):
    return (type(a) == tuple) or (type(a) == list)

def scalar_matrix(s, m):
    nrows = len(m)
    ncols = len(m[0])

    res = [[None] * ncols for i in range(nrows)]

    for i in range(nrows):
        for j in range(ncols):
            res[i][j] = s * m[i][j]
    return res

def matmult(m1, m2):
    ncols1 = len(m1)
    nrows1 = 1
    if is_array(m1[0]):
        nrows1 = len(m1)
        ncols1 = len(m1[0])
    else:
        # promote this vector to a matrix (row vector)
        colvec = [[None] * len(m1)]
        for i in range(len(m1)):
            colvec[0][i] = m1[i]
        m1 = colvec

    ncols2 = 1
    nrows2 = len(m2)
    if is_array(m2[0]):
        nrows2 = len(m2)
        ncols2 = len(m2[0])
    else:
        # promote this vector to a matrix (column vector)
        colvec = [[None] for i in range(len(m2))]
        for i in range(len(m2)):
            colvec[i][0] = m2[i]
        m2 = colvec

    # Perform matrix expansion if necessary
    if ncols1 < nrows2:
        m1 = matrix_expand(m1, nrows1, nrows2, True)
        ncols1 = nrows2
    elif ncols1 > nrows2:
        m2 = matrix_expand(m2, ncols1, ncols2, True)
        nrows2 = ncols1

    res = [[None] * ncols2 for i in range(nrows1)]

    for row1 in range(nrows1):
        sum = 0
        for col2 in range(ncols2):
            sum = 0
            for col1 in range(ncols1):
                sum += m1[row1][col1]*m2[col1][col2]
            res[row1][col2] = sum

    if nrows1 == 1:
        return res[0] # return a row vector
    elif ncols2 == 1:
        r = [None for i in range(nrows1)]
        for i in range(nrows1):
            r[i] = res[i][0]
        return r # return a column vector
    else:
        return res
