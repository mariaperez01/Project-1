#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

int main(){

    //First you have to introduce the number n that is the dimension of the solution v that we want to obtain. We will write down an example here, but feel free of changing it

    int n = 10;


    //After that, we introduce a new integer to simplify our writing later

    int m = n-1;


    //Now you have to introduce the vectors a, b and c. Again, we will write down a random example, but you can for sure introduce some specific vectors

    vec a = vec(m).randu();
    vec b = vec(n).randu();
    vec c = vec(m).randu();


    //We repeat the creation process of a, b and c for g

    rowvec g = rowvec(n).randu();



    //After introducing all of our data, we will operations with the elements of the matrix for obtaining a triangular matrix and solve the equation system

    for(int i = 0; i < m; i++){

        //Now we do the operations

        b(i+1) -= a(i)/b(i) * c(i) ;
        g(i+1) -= a(i)/b(i) * g(i);


    }


    //Finally, we will get the values for the vector we were looking for, that we will call v. First, we will create a zero vector that will be later filled with the results we get

    vec v = vec(n,fill::zeros);

    //Now we get the last element of the vector, which is the only one that's obtained in a different way

    v(m) = g(m)/b(m);


    //Then we get the rest of them using a for

    for(int i = 0; i < m; i++){

        int j = i+1;

        v(m-j) = ( g(m-j) - c(m-j)*v(n-j) ) / b(m-j);

    }

    v.print("v.");

    return 0;

}
