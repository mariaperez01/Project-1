# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

def u(x: float):
    return 1-(1-np.exp(-10))*x-np.exp(-10*x)

maximo = []
'''
# Make plots
   
# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))
'''
# We will create some strings for some steps in the loops with a different n

textnames = ['vx10solution.txt' , 'vx100solution.txt' , 'vx1000solution.txt' , 
             
             'vx10000solution.txt' , 'vx100000solution.txt']

nseq = ['10' , '100', '1000' , '10000' , '100000']

for i in range(0,5):
    xl = []

    vl = []

    with open(textnames[i] , "r") as infile:
        infile.readline()
        lines= infile.readlines()
        for line in lines:
            vals = line.split()
            xl.append(float(vals[0]))
            vl.append(float(vals[1]))
    
    x = np.array(xl)
    
    v = np.array(vl)
    
    # Compute numpy arrays with the absolute error, relative error and log10(relative error)
    abs_err = np.absolute(v - u(x))
    rel_err = np.absolute(abs_err / (u(x)+2.2250738585072014e-308))
    log10_abs_err = np.log10(abs_err)
    log10_rel_err = np.log10(rel_err)
    maximo.append(max(rel_err))
    #plt.plot(np.log10(nseq[i]), maximo[i], marker="x", label="n=" + nseq[i])
'''
plt.title("Maximum relative error", fontsize=10)
plt.ylabel(r'$max(\epsilon_i)$')
plt.xlabel("log10(n)")
plt.grid(True) #Grids get painted
plt.savefig("Problem_8-c_plot.pdf")
'''
print(maximo)