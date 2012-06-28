#!/usr/bin/env python
#       anks
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.mlab import griddata
from mpl_toolkits.mplot3d import axes3d, Axes3D

def plotcurve(x, y, z):
    fig = plt.figure()
    ax = Axes3D(fig)

    xi = np.linspace(min(x), max(x))
    yi = np.linspace(min(y), max(y))

    X, Y = np.meshgrid(xi, yi)
    Z = griddata(x, y, z, xi, yi)

    surf = ax.plot_surface(X, Y, Z, rstride=5, cstride=5, cmap=cm.jet,
                           linewidth=1, antialiased=True)

    ax.set_zlim3d(np.min(Z), np.max(Z))
    fig.colorbar(surf)

    plt.show()    

def main():
	
	# dimension of the plot
    n, m = [int(i) for i in raw_input().split()]
	
    x = []
    y = []
    for i in xrange(0, n):
        for j in xrange(0, m):
            x.append(float(i))
            y.append(float(j))
    
    z = []
    for i in xrange(0, n):
        A = raw_input().split()
        for c in A:
            z.append(float(c));
    
    # plot 3d surface for the given set of points    
    plotcurve(x, y, z)
    
    return 0

if __name__ == '__main__':
	main()




