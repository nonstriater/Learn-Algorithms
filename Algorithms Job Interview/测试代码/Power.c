#include "stdio.h"

double Power(double base, int exponent)
{
	if (exponent == 0) return 1;
	if (exponent == 1) return base;
  	double result = Power(base, exponent >> 1);
  	result *= result;

  	if (exponent & 1) result = result*base;

  	return result;
 }

 int main(int argc, char const *argv[])
 {
 	printf("%f\n", Power(2,4));
 	printf("%f\n", Power(2.1,4));
 	printf("%f\n", Power(0,4));
 	printf("%f\n", Power(2,0));
 	printf("%f\n", Power(2,-3)); //负数就挂了
 	return 0;
 }