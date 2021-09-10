#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

int main(){

    //First you have to introduce the number n that is the dimension of the solution v that we want to obtain. We will write down an example here, but feel free of changing it

    int n = 10;


    //Now you have to introduce the vectors a, b and c. Again, we will write down a random example, but you can for sure introduce some specific vectors

    vec a = vec(n).randu();
    vec b = vec(n).randu();
    vec c = vec(n).randu();


    //We repeat the creation process of a, b and c for g

    rowvec g = rowvec(n).randu();



    //After introducing all of our data, we will operations with the elements of the matrix for obtaining a triangular matrix and solve the equation system

    for(int i = 1; i < n-1; i++){

        //Now we do the operations

        b(i) = b(i) -  a(i)/b(i-1) * c(i-1);
        g(i) = g(i) -  a(i)/b(i-1) * g(i-1);


    }


    //Finally, we will get the values for the vector we were looking for, that we will call v. First, we will create a zero vector that will be later filled with the results we get

    vec v = vec(n,fill::zeros);

    //Now we get the last element of the vector, which is the only one that's obtained in a different way

    v(n-1) = g(n-1)/b(n-1);


    //Then we get the rest of them using a for

    for(int i = n-2; i >=  0; i--){

        v(i) = ( g(i) - c(i)*v(i+1) ) / b(i);

    }


    //Once we have obtained all the values, we print the vector v

    v.print("v.");

    return 0;

}
