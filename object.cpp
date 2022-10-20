#include <iostream>

using namespace std;

class OOP {
private:
	int* m;
public:
	OOP() { this->m = 0; }
	OOP(OOP& A) {
		m = new int(0);
		*m = *(A.m);
	}
	void set(int v) { *m = v; }
	void display() { std::cout << this->m << std::endl; }
};

int main() {
	OOP a, b; // static memory 
	//dynamic memory : OOP *a = new OOP

	b.set(5);
	OOP c(b); // equal 
	//        OOP c;
	//        c = b;
	a.display();
	b.display();
	c.display();

}