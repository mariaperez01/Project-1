# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

def u(x: float):
    return 1-(1-np.exp(-10))*x-np.exp(-10*x)
    
# Read data into numpy arrays

infilename = "vx10solution.txt"

n=10

xl = []

vl = []

with open(infilename , "r") as infile:
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
rel_err = np.absolute(abs_err / u(x))
log10_abs_err = np.log10(abs_err)
log10_rel_err = np.log10(rel_err)

# Make plots

# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))
plt.plot(x, log10_abs_err, color='red', label="n=10")
    
# Read new data into numpy arrays

infilename = "vx100solution.txt"

n=100

xl = []

vl = []

with open(infilename , "r") as infile:
    infile.readline()
    lines= infile.readlines()
    for line in lines:
        vals = line.split()
        xl.append(float(vals[0]))
        vl.append(float(vals[1]))
        
# h, d2u_approx, d2u_exact = np.loadtxt("output.txt", usecols=(0,1,2), unpack=True)

x = np.array(xl)

v = np.array(vl)

# Compute numpy arrays with the absolute error, relative error and log10(relative error)
abs_err = np.absolute(v - u(x))
rel_err = np.absolute(abs_err / u(x))
log10_abs_err = np.log10(abs_err)
log10_rel_err = np.log10(rel_err)

plt.plot(x, log10_abs_err, color='blue', label="n=100")

# Read new data into numpy arrays

infilename = "vx1000solution.txt"

n=1000

xl = []

vl = []

with open(infilename , "r") as infile:
    infile.readline()
    lines= infile.readlines()
    for line in lines:
        vals = line.split()
        xl.append(float(vals[0]))
        vl.append(float(vals[1]))
        
# h, d2u_approx, d2u_exact = np.loadtxt("output.txt", usecols=(0,1,2), unpack=True)

x = np.array(xl)

v = np.array(vl)

# Compute numpy arrays with the absolute error, relative error and log10(relative error)
abs_err = np.absolute(v - u(x))
rel_err = np.absolute(abs_err / u(x))
log10_abs_err = np.log10(abs_err)
log10_rel_err = np.log10(rel_err)

plt.plot(x, log10_abs_err, color='green', label="n=1000")

# Read new data into numpy arrays

infilename = "vx10000solution.txt"

n=10000

xl = []

vl = []

with open(infilename , "r") as infile:
    infile.readline()
    lines= infile.readlines()
    for line in lines:
        vals = line.split()
        xl.append(float(vals[0]))
        vl.append(float(vals[1]))
        
# h, d2u_approx, d2u_exact = np.loadtxt("output.txt", usecols=(0,1,2), unpack=True)

x = np.array(xl)

v = np.array(vl)

# Compute numpy arrays with the absolute error, relative error and log10(relative error)
abs_err = np.absolute(v - u(x))
rel_err = np.absolute(abs_err / u(x))
log10_abs_err = np.log10(abs_err)
log10_rel_err = np.log10(rel_err)

plt.plot(x, log10_abs_err, color='pink', label="n=10000")

# Read new data into numpy arrays

infilename = "vx100000solution.txt"

n=100000

xl = []

vl = []

with open(infilename , "r") as infile:
    infile.readline()
    lines= infile.readlines()
    for line in lines:
        vals = line.split()
        xl.append(float(vals[0]))
        vl.append(float(vals[1]))
        
# h, d2u_approx, d2u_exact = np.loadtxt("output.txt", usecols=(0,1,2), unpack=True)

x = np.array(xl)

v = np.array(vl)

# Compute numpy arrays with the absolute error, relative error and log10(relative error)
abs_err = np.absolute(v - u(x))
rel_err = np.absolute(abs_err / u(x))
log10_abs_err = np.log10(abs_err)
log10_rel_err = np.log10(rel_err)

plt.plot(x, log10_abs_err, color='purple', label="n=100000")

# Read new data into numpy arrays

infilename = "vx1000000solution.txt"

n=1000000

xl = []

vl = []

with open(infilename , "r") as infile:
    infile.readline()
    lines= infile.readlines()
    for line in lines:
        vals = line.split()
        xl.append(float(vals[0]))
        vl.append(float(vals[1]))
        
# h, d2u_approx, d2u_exact = np.loadtxt("output.txt", usecols=(0,1,2), unpack=True)

x = np.array(xl)

v = np.array(vl)

# Compute numpy arrays with the absolute error, relative error and log10(relative error)
abs_err = np.absolute(v - u(x))
rel_err = np.absolute(abs_err / u(x))
log10_abs_err = np.log10(abs_err)
log10_rel_err = np.log10(rel_err)

plt.plot(x, log10_abs_err, color='yellow', label="n=1000000")

plt.title("Log10 of absolute error", fontsize=10)
plt.ylabel(r'$log_{10}(\Delta_i)$')
plt.xlabel("x")
plt.grid(True) #Grids get painted
plt.savefig("Problem_8-a_plot.pdf")
