#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

int main() {

    //The number n is the dimension of the solution v we want to obtain

    int n = 10; //As an example


    //Now we define vector b and fill it with zeros

    vec b = vec(n, fill::zeros);

    //We generate vector g and fill it with random numbers

    vec g = vec(n).randu();

    //The following loop allows to fill the vectors defined before with the numbers that are needed

    for (int i = 0; i < n-1; i++) {

        //We create the elements of the vectors c and b by performing some operations

        b(i) = (i + 2) / (i + 1);
        g(i + 1) = g(i + 1) + ((i + 1) / (i + 2)) * g(i);
    }

    //The last element of the vector b needs to be created apart because the loop stops at m-1

    b(n-1) = (n+1) / (n);



    //Finally, we will get the values for the vector we were looking for, that we will call v. First, we will create a zero vector that will be later filled with the results we get

    vec v = vec(n, fill::zeros);

    //Now we get the last element of the vector, which is the only one that's obtained in a different way

    v(n-1) = g(n-1) / b(n-1);


    //Then we get the rest of them using a loop for

    for (int i = n-2; i >= 0 ; i--) {

        v(i) = (g(i) + v(i+1)) / b(i);

    }


    //We print in screen vector v

    v.print("v.");

    return 0;

}
