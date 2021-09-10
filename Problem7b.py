# -*- coding: utf-8 -*-
"""
Created on Wed Sep  8 20:55:12 2021

@author: JulianElToro
"""
import matplotlib.pyplot as plt
import numpy as np

# We will create some strings for some steps in the loops with a different n

textnames = ['vx10solution.txt' , 'vx100solution.txt' , 'vx1000solution.txt' , 
             
             'vx10000solution.txt' , 'vx100000solution.txt' , 'vx1000000solution.txt']

nseq = ['10' , '100', '1000' , '10000' , '100000' , '1000000']

Problem = ["Problem7bn10.pdf","Problem7bn100.pdf","Problem7bn1000.pdf",
           "Problem7bn10000.pdf","Problem7bn100000.pdf","Problem7bn1000000.pdf",]

# The loop

for i in range(0,6): 

    v = [] #Vector v is created

    x = [] #Vector x is  created 

    #The  code  opens  the  data  file and adds every xvalue to the x vector. and the same with the v values

    with  open(textnames[i] , "r") as  infile:
        infile.readline () #Skip  first  line.
        lines = infile.readlines ()
        for  line in  lines:
            vals = line.split() #Splits  the  data  file  into  two  columnes
            x.append(float(vals [0])) #Adds  every x value  to  vector x
            v.append(float(vals [1])) #Adds  every v value  to  vector v
            
       # Exact solution
        u = 1-(1-np.exp(-10))*np.array(x)-(np.exp(-10*np.array(x)))
        
    #Plot
    plt.figure()
    plt.xlim(0,1) # x-axis limit
    plt.plot(x , u , color='red' , label="u(x)") #Plot of the exact solution
    plt.plot(x , v , color = 'blue', label="v" ) #Plot of the v values
    plt.ylabel('u(x) | v') #
    plt.xlabel('x')
    plt.title('Exact solution u(x) vs solution v, n = ' +str(nseq[i]))
    plt.grid(True) #A grid is plotted
    plt.legend(loc="upper right") #Legend in the topright corner
    plt.savefig(Problem[i]) #We save the plot into a .pdf file
    plt.show


