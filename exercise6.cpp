#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

int main(){

    //First you have to introduce the matrix A, its dimension n and the vector g down here. We will write down a random matrix A and vector g as an example, but feel free of changing them

    int n = 10;

    mat A = mat(n, n).randn();

    rowvec g = rowvec(n).randu();


    //Then we will perform columns operations for obtaining a triangular matrix and solve the equation system


    int m = n-1;

    for(int i = 0; i < m; i++){

        //We define the values that we're gonna use for making the operations with the rows

        rowvec fil1 = A.row(i);
        rowvec fil2 = A.row(i+1);
        double g1 = g(i);
        double g2 = g(i+1);
        double a2 = A(i+1,i);
        double a1 = A(i,i);

        //Now we do the operations

        fil2 -= a2/a1*fil1;
        g(i+1) = g2-a2/a1*g1;


        //Then we insert the new row that we've obtained in the matrix, removing the old one first

        A.shed_row(i+1);
        A.insert_rows(i+1, fil2);

    }


    //Now we will get the values for the vector we were looking for, that we will call v. First, we will create a zero vector an later we will fill it with the results we get

    vec v = vec(n,fill::zeros);

    //Then we get the last element of the vector, which is the only one that's obtained in a different way

    v(n-1) = g(n-1)/A(n-1,n-1);


    //Now we get the rest of them using a for

    for(int i = 0; i < m; i++){

        int j = i+2;

        v(n-j) = ( g(n-j) - A(n-j, n-j+1)*v(n-j+1) ) / A(n-j, n-j);

    }

    v.print("v.");

    return 0;

}
