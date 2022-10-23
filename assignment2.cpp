#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
//Your code goes here.

class Matrix
{
private:
	int n;
	int m;
	int** ary;

public:

	//1. Constructor(s)
	//Provide one or more constructors that take two integers n and m and create an n by m random matrix.
	//All n amd m values are limited to 3. No need to use dynamic memory allocation; just use a 3 by 3 array.

	Matrix(int n, int m) {
		this->n = n;
		this->m = m;
		this->ary = new int* [n];

		for (int i = 0; i < n; ++i)
			ary[i] = new int[m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				ary[i][j] = rand() % 4;
			}
		}

	}
	/* 
	~Matrix() {

		//delete this->ary;
		for (int i = 0; i < n; i++) {
			delete[] ary[i];
		}
		delete[] this->ary;


	}
	*/
	

	//2. transpose
	//This function returns its own transpose matrix.
	Matrix transpose() {

		// if input 2, 3
		// we should change 3, 2

		Matrix M(this->m,this->n);  // 3, 2
		for (int i = 0; i < m; i++)  // (m = 0 n = 1) 
		{
			M.ary[i][0] = ary[0][i];
			for (int j = 1; j < n; j++) {
				M.ary[i][j-1] = ary[j][i];
			}
			
		}
		cout << endl;
		return M;
	}


	//3. show
	//This function displays the matrix in the form of an n by m matrix.


	void show() {
		for (int i = 0; i < this->n; i++)
		{
			for (int j = 0; j < this->m; j++)
			{
				std::cout << ary[i][j] << " ";
			}
			std::cout << '\n';
		}
	}
	//4. +
	//Operator overloading for matrix addition.
	friend Matrix operator + (const Matrix &M, const Matrix &M2) {
		Matrix tmp(max( M.n,M2.n), max(M.m, M2.m));
		for (int i = 0; i < M.n; i++)
		{
			for (int j = 0; j < M.m; j++)
			{
				tmp.ary[i][j] = M.ary[i][j] + M2.ary[i][j];
			}
		}
		return tmp;
	}
	//5. *
	//Operator overloading for matrix multiplication.

	friend Matrix operator * (const Matrix& M, const Matrix& M2) {
		Matrix tmp(max(M.n, M2.n), max(M.m, M2.m));
		for (int i = 0; i < M.n; i++)
		{
			for (int j = 0; j < M.m; j++)
			{
				tmp.ary[i][j] = M.ary[i][j] * M2.ary[i][j]; 
				if (tmp.ary[i][j] < 0) tmp.ary[i][j] = 0;  //if outOfRange ary input 0; this statement's sometime occur outOfRange 
			}
		}
		return tmp;
	}

	//6. ==
	//Operator overloading to check if two given matrices are equal.
	friend bool operator == (const Matrix & M , const Matrix & M2) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (M.ary[i][j] != M2.ary[i][j]) return false;
			}
		}
		return true;
	}
};


//DO NOT TOUCH THE MAIN FUNCTION.
int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	Matrix A(2, 3), B(2, 3), C(2, 3), AT(3, 2), BT(3, 2), D(3, 2), E(2, 2), F(2, 2);
	AT = A.transpose();
	BT = B.transpose();
	cout << "A" << endl;
	A.show();
	cout << "=========" << endl;
	cout << "B" << endl;
	B.show();
	cout << "=========" << endl;
	cout << endl << "A " << (A == B ? "==" : "!=") << " B" << endl << endl << endl;

	C = A + B;
	cout << "C = A + B" << endl;
	C.show();
	cout << "=========" << endl;
	D = AT + BT;
	cout << "D = AT + BT" << endl;
	D.show();
	cout << endl << "C " << (C == D.transpose() ? "==" : "!=") << " Transpose of D" << endl << endl << endl;

	E = A * BT;
	cout << "E = A * BT" << endl;
	E.show();
	cout << "=========" << endl;
	F = B * AT;
	cout << "F = B * AT" << endl;
	F.show();
	cout << endl << "E " << (E == F.transpose() ? "==" : "!=") << " Transpose of F" << endl << endl << endl;

	return 0;
}