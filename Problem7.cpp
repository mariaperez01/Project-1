#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>


using namespace arma;
using namespace std;


int main() {
    
    //First, you have to introduce n, the number of grid points in which you want to divide the interval [0,1]. Here, we have used n=100 as an example 
   
    int n = 100; // Number of inner points 

    //Now we introduce m to make the writing easier later
    
    
   //We introduce the vectors a, b and c that will always be the same 

    vec a = vec(n, fill::zeros);
    vec b = vec(n, fill::zeros);
    vec c = vec(n, fill::zeros);

    a.fill(-1);
    b.fill(2);
    c.fill(-1);

    //Now, we create the vector x, a vector of n points starting on 0 and ending on 1

    vec x = linspace<vec>(0, 1, n);
    
    //With it, we compute f
    
    vec f = 100. * exp(-10. * x);
    
    /After that, we calculate the stepsize h, and with that and f, we calculate the vector g
    
    double h = 1.0 / (n-1.0);
    double hh = h*h;
    vec g = f*hh;

    
    //We now do the forward calculations
    
    for (int i=1; i < n-1; i++){
        b(i) = b(i) - a(i)*c(i-1)/b(i-1);
        g(i) = g(i) - a(i)*g(i-1)/b(i-1);
    }

  //  for (int i = 0; i < m; i++)  
   //     b(i+1) -= a(i+1) / b(i) * c(i);
    //    g(i + 1) -= a(i+1) / b(i) * g(i);
    //}

    //And, finally, we will get the values for the vector we were looking for, that we will call v, using the backwards calculations 
    
    vec v = vec(n, fill::zeros);

    //We won't change the first and last element to satisfy the boundary conditions, so we get the next-to-last element of the vector, which is the only one that's obtained in a different way

    v(n-2) = g(n-2) / b(n-2);

    //Now we get the rest of them using a for(except for the first one, as we have already said)

 
       
    for (int i=n-3; i > 0; i--){
        v(i) = (g(i)-c(i)*v(i+1)) / b(i)
    } 
    
  

    v.brief_print("v.");
    
    //For section b we will create a .txt file that stores the x vector and the v solution obtained
    ofstream ofile; 
    ofile.open("vx100solution.txt"); 
    ofile << "x     v" << endl; 
    ofile << scientific; 
    for (int i = 0; i < n; i++){
        
        ofile << x(i) << "      " << v(i) << endl;
    }
    ofile.close();

    return 0;

}
