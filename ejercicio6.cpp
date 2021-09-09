#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

//We will introduce the matrix A transposing it so we can extract the columns easily
//Then we will perform columns operations for obtaining a triangular matrix and solve the equation system


int main(){

int n = 4;

mat A(n,n,fill::zeros);

A << 2 << -1 << 0 << 0 << endr
<< -1 << 2 << -1 <<0 << endr
<< 0 << -1 << 2 << -1 << endr
<< 0 << 0 << -1 << 2 << endr;

rowvec g(n,fill::zeros);

g << 3 << 2 << 1 << 0;

int m = n-1;

for(int i = 0; i < m; i++){

//We define the values that we're gonna use for making the operations with the rows

	rowvec fil1 = A.row(i);
	rowvec fil2 = A.row(i+1);
	int g1 = g(i);
	int g2 = g(i+1);
	int a2 = A(i+1,i);
	int a1 = A(i,i);


//Now we do the operation

	fil2 -= a2/a1 * fil1;
	g(i+1) = g2-a2/a1 * g1;


//Then we insert the new column that we've obtained in the matrix

	A.shed_row(i+1);
	A.insert_rows(i+1, fil2);

}

A.print("A:");
g.print("g:");

//Now we will get the values for the vector we were looking for, that we will call v

vec v = vec(n,fill::zeros);

//First we get the last element of the vector, which is the only one that's obtained in a different way

v(n-1) = g(n)/A(n,n);


//Now we get the rest of them using a for

for(int i = 0; i < m; i++){

int j = i+2;

v(n-j) = (  g(n-j) - A(n-j, n-j+1)*v(n-j+1) ) / A(n-j+1, n-j+1);

}

v.print("v.");

return 0;

}


