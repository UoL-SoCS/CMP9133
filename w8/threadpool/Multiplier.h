#include <iostream>

#define LENGTH 100

using namespace std;

class Multiplier {
	double A[LENGTH][LENGTH];
	double B[LENGTH][LENGTH];
	double C[LENGTH][LENGTH];

public:
	Multiplier() { }

	void run() {
		initialiseMatrices();
		multiplyMatrices();
		//displayMatrices();
	}

	void initialiseMatrices() {
		int counter = 0;
		for (int i = 0; i<LENGTH; i++) {
			for (int j = 0; j<LENGTH; j++) {
				counter++;
				A[i][j] = counter;
				B[i][j] = (LENGTH*LENGTH) + counter;
			}
		}
	}

	void multiplyMatrices() {
		for (int k = 0; k<LENGTH; k++) {
			for (int i = 0; i<LENGTH; i++) {
				double sum = 0;
				for (int j = 0; j<LENGTH; j++) {
					double prod = 0;
					for (int x = 0; x < 1000; x++) {
						prod = A[k][j] * B[j][i];
					}
					sum += prod;
				}
				C[k][i] = sum;
			}
		}
	}

	void displayMatrices() {
		displayMatrix(A);
		cout << "+" << endl;
		displayMatrix(B);
		cout << "=" << endl;
		displayMatrix(C);
	}

	void displayMatrix(double matrix[LENGTH][LENGTH]) {
		for (int i = 0; i<LENGTH; i++) {
			for (int j = 0; j<LENGTH; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};