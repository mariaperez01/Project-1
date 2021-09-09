#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

int main(){

    //First you have to introduce the number n that is the dimension of the solution v that we want to obtain. We will write down an example here, but feel free of changing it

    int n = 10;


    //After that introduce a new integer to simplify our writing later

    int m = n-1;


    //Now, we create a nxn matrix of zeros where we will introduce the diagonals a, b and c

    mat A = mat(n, n, fill::zeros);

    //Then you have to introduce the vectors a, b and c. Again, we will write down a random example, but you can for sure introduce some specific vectors

    rowvec a = rowvec(m).randu();
    rowvec b = rowvec(n).randu();
    rowvec c = rowvec(m).randu();

    //And we introduce them in the matrix

    A.diag(-1) = a;
    A.diag(0) = b;
    A.diag(1) = c;


    //We repeat the creation process of a, b and c for g

    rowvec g = rowvec(n).randu();



    //After introducing all of our data, we will perform rows  operations for obtaining a triangular matrix and solve the equation system

    for(int i = 0; i < m; i++){

        //First, we define the values that we're gonna use for making the operations with the rows

        rowvec row1 = A.row(i);
        rowvec row2 = A.row(i+1);
        double g1 = g(i);
        double g2 = g(i+1);
	double bi = A(i,i);
        double ai = A(i+1,i);

        //Now we do the operations

        row2 -= ai/bi*row1;
        g(i+1) = g2-ai/bi*g1;


        //Then we insert the new row that we've obtained in the matrix, removing the old one first

        A.shed_row(i+1);
        A.insert_rows(i+1, row2);

    }


    //Finally, we will get the values for the vector we were looking for, that we will call v. First, we will create a zero vector that will be later filled with the results we get

    vec v = vec(n,fill::zeros);

    //Now we get the last element of the vector, which is the only one that's obtained in a different way

    v(m) = g(m)/A(m,m);


    //Then we get the rest of them using a for

    for(int i = 0; i < m; i++){

        int j = i+1;

        v(m-j) = ( g(m-j) - A(m-j, n-j)*v(n-j) ) / A(m-j, m-j);

    }

    v.print("v.");

    return 0;

}
