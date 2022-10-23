#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
				HW 2 (7pts, Due: 10/23 23:59PM)
Provide a class Matrix to complete this code.
You have to implement the following methods:



Submit this file to the LMS.
*/


//Your code goes here.
using namespace std;

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

    Matrix(int n, int m){
        this.n = n;
        this.m = m;
        
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
    void destroy();
	void show();
	void set();
	void transpose();

};

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@ need fix
void Matrix::destroy() {
	for (int i = 0; i < n; ++i)
	    	ary[i] = new int[m];
	
	delete this->ary;
}

//3. show
//This function displays the matrix in the form of an n by m matrix.

void Matrix::show() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ary[i][j] << " ";
		}
		cout << '\n';
	}
}


//2. transpose
//This function returns its own transpose matrix.
void Matrix::transpose() {
	for (int i = 0; i < m; i++)
	{
		cout << ary[0][i] << " ";
		for (int j = 1; j < n; j++) {
			cout << ary[j][i] << " ";
		}
		cout << endl;
	}
}

//4. +
//Operator overloading for matrix addition.
Matrix Matrix::Operator+(Matrix M){
    Matrix tmp;
    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp.ary[i][j] = arr[i][j] + M.arr[i][j];
		}
	}
}
//5. *
//Operator overloading for matrix multiplication.

Matrix Matrix::Operator+(Matrix M){
    Matrix tmp;
    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp.ary[i][j] = arr[i][j] * M.arr[i][j];
		}
	}
}

//6. ==
//Operator overloading to check if two given matrices are equal.

Matrix Matrix::Operator+(Matrix M){
    Matrix tmp;
    bool flag = true;
    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(arr[i][j] != M.arr[i][j]) flag = false;
		}
	}
}



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
