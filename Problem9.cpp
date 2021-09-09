#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

int main() {

    //First you have to introduce the number n that is the dimension of the solution v that we want to obtain. We will write down an example here, but feel free of changing it

    int n = 10;


    //After that introduce a new integer to simplify our writing later

    int m = n - 1;


    vec c = vec(m).fill(1.);
    vec b = vec(n).fill(1.);

    vec g = vec(n).randu();


    for (int i = 0; i < m; i++) {
        c(i) = -(i * 1.0 + 1.0) * c(i);
        b(i) = (i * 1.0 + 2.0) * b(i);
        g(i + 1) = (i * 1.0 + 1.0) * g(i * 1.0 + 1.0) + g(i);
    }

    b(m) = (m * 1.0 + 2.0) * b(m);


    c.print("c");
    b.print("b");


    //Finally, we will get the values for the vector we were looking for, that we will call v. First, we will create a zero vector that will be later filled with the results we get

    vec v = vec(n, fill::zeros);

    //Now we get the last element of the vector, which is the only one that's obtained in a different way

    v(m) = g(m) / b(m);


    //Then we get the rest of them using a for

    for (int i = 0; i < m; i++) {

        int j = i + 1;

        v(m - j) = (g(m - j) - c(m - j) * v(n - j)) / b(m - j);

    }

    v.print("v.");

    return 0;

}