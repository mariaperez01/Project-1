#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>


using namespace arma;
using namespace std;


int main() {

    //First you have to introduce the matrix A, its dimension n and the vector g down here. We will write down a random matrix A and vector g as an example, but feel free of changing them

    int n = 10000;

    int m = n-1;

    mat A = mat(n, n, fill::zeros);

    rowvec a = rowvec(m, fill::zeros);
    rowvec b = rowvec(n, fill::zeros);
    rowvec c = rowvec(m, fill::zeros);

    a.fill(-1);
    b.fill(2);
    c.fill(-1);

    a.brief_print("a.");
    b.brief_print("b.");
    c.brief_print("c.");


    A.diag(-1) = a;
    A.diag(0) = b;
    A.diag(1) = c;

    A.brief_print("A:");

    rowvec x = linspace<rowvec>(0, 1, n);
    rowvec f = 100. * exp(-10. * x);

    double h = 1 / (1.0*n);
    rowvec g = f*pow(h,2);
    g.brief_print("g:");

    //Then we will perform columns operations for obtaining a triangular matrix and solve the equation system


    for (int i = 0; i < m; i++) {

        //We define the values that we're gonna use for making the operations with the rows

        rowvec row1 = A.row(i);
        rowvec row2 = A.row(i + 1);
        double g1 = g(i);
        double g2 = g(i + 1);
        double bi = A(i, i);
        double ai = A(i + 1, i);
        

        //Now we do the operations

        row2 -= ai / bi * row1;
        g(i + 1) = g2 - ai / bi * g1;


        //Then we insert the new row that we've obtained in the matrix, removing the old one first

        A.shed_row(i + 1);
        A.insert_rows(i + 1, row2);

    }

    //Now we will get the values for the vector we were looking for, that we will call v. First, we will create a zero vector an later we will fill it with the results we get

    vec v = vec(n, fill::zeros);

    //Then we get the last element of the vector, which is the only one that's obtained in a different way

    v(m - 1) = g(m -  1) / A(m - 1 , m - 1);

    //Now we get the rest of them using a for

    for (int i = 0; i < m-1; i++) {

        int j = i + 1;

        v(m - j) = (g(m - j) - A(m - j, n - j ) * v(n - j )) / A(m - j, m - j);

    }

    v.brief_print("v.");
    vec xi = x.t();

    ofstream ofile; 
    ofile.open("vx10000solution.txt"); 
    ofile << "x     v" << endl; 
    ofile << scientific; 
    for (int i = 0; i < n; i++){
        
        ofile << xi(i) << "      " << v(i) << endl;
    }
    ofile.close();

    return 0;

}