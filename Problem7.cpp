#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>


using namespace arma;
using namespace std;


int main() {

    int n = 100;

    int m = n-1;

    vec a = vec(m, fill::zeros);
    vec b = vec(n, fill::zeros);
    vec c = vec(m, fill::zeros);

    a.fill(-1);
    b.fill(2);
    c.fill(-1);

    a.brief_print("a.");
    b.brief_print("b.");
    c.brief_print("c.");


    vec x = linspace<vec>(0, 1, n);
    vec f = 100. * exp(-10. * x);

    double h = 1 / (1.0*n);
    vec g = f*pow(h,2);
    g.brief_print("g:");


    for (int i = 0; i < m; i++) {
        
        b(i+1) -= a(i) / b(i) * c(i);
        g(i + 1) -= a(i) / b(i) * g(i);

    }

    //Now we will get the values for the vector we were looking for, that we will call v. First, we will create a zero vector an later we will fill it with the results we get

    vec v = vec(n, fill::zeros);

    //We won't change the first and last element to satisfy the boundary conditions

    //Then we get the next-to-last element of the vector, which is the only one that's obtained in a different way

    v(m - 1) = g(m - 1) / b(m - 1);

    //Now we get the rest of them using a for

    for (int i = 0; i < m-1; i++) {

        int j = i + 1;

        v(m - j) = (g(m - j) - c(m - j) * v(n - j )) / b(m - j);

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
