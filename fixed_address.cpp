#include <iostream>


int main(){
	const double x = 12 ;
	double * ptr;

	std::cout << " sabitlerin degeri " << x << std::endl;

	ptr = (double *)&x;
	*ptr = 123;  

	std::cout << x;

	



}