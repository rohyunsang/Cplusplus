#include <iostream>
#include <random> //rand()

using namespace std;

class Matrix
{
private:
	int n;
	int m;
	int** ary;

public:
	void create();
	void destroy();
	void display();
	void set();
	void transpose();
	int getMax();
	bool isSquare();
};

void Matrix::create() {

	cin >> this->n >> this->m;

	this->ary = new int* [n];

	for (int i = 0; i < n; ++i)
		ary[i] = new int[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			int tmp;
			cin >> tmp;
			ary[i][j] = tmp;
		}
	}
}

void Matrix::destroy() {
	delete this->ary;
}

void Matrix::display() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ary[i][j] << " ";
		}
		cout << '\n';
	}
}

void Matrix::set() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			ary[i][j] = rand() % 5;
		}
	}
}

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

int Matrix::getMax() {
	int max = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ary[i][j] > max) max = ary[i][j];
		}
	}
	return max;
}

bool Matrix::isSquare() {
	if (this->n == this->m) return true;
	else return false;
}

//DO NOT TOUCH THE MAIN FUNCTION.
int main() {

	for (int i = 0; i < 3; i++) {
		Matrix* A = new Matrix;
		cout << "====Matrix A[" << i << "]====" << endl << endl;
		A->create();
		A->set();  //rand()
		A->display();
		A->transpose();
		
		cout << "Maximum value: " << A->getMax() << endl;
		cout << "Matrix A[" << i << "] is " << (A->isSquare() ? "" : "not ") << "a square matrix." << endl;
		A->destroy();
		delete A;
		cout << endl << "==== Bye!!! ====" << endl << endl;
	}

	return 0;
}
