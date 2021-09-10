#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

int main() {

    //The number n is the dimension of the solution v we want to obtain
     
    int n = 10; //As an example


    //After this, we introduce a new integer to simplify the code

    int m = n - 1;

    //Now we define vectors b and c a fill b with zeros and c with ones

    vec b = vec(n, fill::zeros);
    vec c = vec(m).fill(-1.);

    //We generate vector g and fill it with random numbers 

    vec g = vec(n).randu();

    //The following loop allows to fill the vectors defined before with the numbers that are needed

    for (int i = 0; i < m; i++) {

        //We create the elements of the vectors c and b by performing some operations 

        b(i) = (i + 2) / (i + 1);
        g(i + 1) = g(i + 1) + ((i + 1) / (i + 2)) * g(i);
    }

    //The last element of the vector b needs to be created apart because the loop stops at m-1

    b(m) = (m + 2) / (m + 1);

    //We print in screen vectors c and b
    b.print("b");
    c.print("b");


    //Finally, we will get the values for the vector we were looking for, that we will call v. First, we will create a zero vector that will be later filled with the results we get

    vec v = vec(n, fill::zeros);

    //Now we get the last element of the vector, which is the only one that's obtained in a different way

    v(m) = g(m) / b(m);


    //Then we get the rest of them using a loop for

    for (int i = 0; i < m; i++) {

        int j = i + 1;

        v(m - j) = (g(m - j) - (-1.) * v(n - j)) / b(m - j);

    }

    //We print in screen vector v

    v.print("v.");

    return 0;

}
