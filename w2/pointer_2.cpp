#include <iostream>

void main()
{
const int x = 10;
const int *y = &x;

int z = 5;
y = &z;
*y  = 10;


}