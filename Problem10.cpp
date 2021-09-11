#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>


using namespace arma;
using namespace std;


//Our goal is to perform experiments and store the results in a text document so is easier to make the table/plot that we are looking for

int main() {

	//We will perform each program for n between 10 and 10⁶, so we will get for each program 6 different times. Due to that, we will first create two zero-vectors of lenght 6 for storing the data we'll obtain later

	vec ga = vec(6, fill::zeros);
	vec sa = vec(6, fill::zeros);


	//Let's start with the general algorithm we did in 6. We will create a loop for that will perform the experiment for each n and that will store the time it takes in the ga vector

	for (int j = 1; j <= 6; j++) {

		//First, we start measuring time

		clock_t t1 = clock();


		int n = pow(10, j);

		vec a = vec(n).randu();
		vec b = vec(n).randu();
		vec c = vec(n).randu();


		//We are going to fill vectors a b and c with the necessary values to get the same A matrix used in problem 9

		a.fill(-1);
		b.fill(2);
		c.fill(-1);

		rowvec g = rowvec(n).randu();

		for (int i = 1; i < n - 1; i++) {

			b(i) = b(i) - a(i) / b(i - 1) * c(i - 1);
			g(i) = g(i) - a(i) / b(i - 1) * g(i - 1);
		}


		vec v = vec(n, fill::zeros);

		v(n - 1) = g(n - 1) / b(n - 1);


		for (int i = n - 2; i >= 0; i--) {

			v(i) = (g(i) - c(i) * v(i + 1)) / b(i);

		}


		//Now we stop measuring time

		clock_t t2 = clock();


		//Finally we calculate the elapsed time and we store it in the correspondent position of the ga vector

		double duration_seconds = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

		ga(j - 1) = duration_seconds;

	}

	ga.print("ga.");

	//After timing the general algorithm, let's repite the same strategy with the special algorithm we did in 9.

	for (int j = 1; j <= 6; j++) {

		//We start measuring time

		clock_t t1 = clock();


		int n = pow(10, j);

		vec b = vec(n, fill::zeros);

		vec g = vec(n).randu();


		for (int i = 0; i < n - 1; i++) {

			b(i) = (i + 2) / (i + 1);
			g(i + 1) = g(i + 1) + ((i + 1) / (i + 2)) * g(i);
		}

		b(n - 1) = (n + 1) / (n);


		vec v = vec(n, fill::zeros);

		v(n - 1) = g(n - 1) / b(n - 1);


		for (int i = n - 2; i >= 0; i--) {

			v(i) = (g(i) + v(i + 1)) / b(i);

		}


		//We stop measuring time

		clock_t t2 = clock();


		//We calculate the elapsed time and we store it in the correspondent position of the sa vector

		double duration_seconds = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

		sa(j - 1) = duration_seconds;

	}

	sa.print("sa.");



	//Finally we create a text file with both vectors ga and sa

	ofstream ofile;
	ofile.open("timing.txt");
	ofile << "ga     sa" << endl;
	ofile << scientific;
	for (int i = 0; i < 6; i++) {

		ofile << ga(i) << "      " << sa(i) << endl;
	}
	ofile.close();

}
