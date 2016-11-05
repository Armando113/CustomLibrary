#include <iostream>
#include <stdlib.h>
#include "Vector4D.h"

int main()
{

	printf("Size of Vector4D: %i\n", sizeof(Vector4D));

	void *addr = _aligned_malloc(sizeof(Vector4D), 16);
	
	Vector4D *pVecty;
	Vector4D *pVecty2;

	if (addr != 0)
	{
		pVecty = new(addr)Vector4D(2.5f, 1.0f, -3.0f);
		//Shut up warnings
		pVecty;

		printf("Vecty = (%f, %f, %f) \n", pVecty->x, pVecty->y, pVecty->z);
	}

	//Get the second address
	addr = _aligned_malloc(sizeof(Vector4D), 16);
	
	if (addr != 0)
	{
		pVecty2 = new(addr)Vector4D(1.0f, 13.0f, 0.0f);
	}
	
	return 0;
}