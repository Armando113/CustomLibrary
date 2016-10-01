#include <iostream>
#include <stdlib.h>
#include "Vector3D.h"

int main()
{

	printf("Size of Vector3D: %i\n", sizeof(Vector3D));
	
	Vector3D *vecty1 = new Vector3D();
	Vector3D *vecty2 = new Vector3D(1.0f, 1.0f, 1.0f);

	printf("Dot of (0,0,0) & (1,1,1): %f\n", Vector3D::Dot(*vecty1, *vecty2));

	delete(vecty1);
	delete(vecty2);

	vecty1 = new Vector3D(1.0f, 0.0f, 0.0f);//Right
	vecty2 = new Vector3D(0.0f, 0.0f, 1.0f);//Forward

	Vector3D *upVect = &Vector3D::CrossProduct(*vecty2, *vecty1);

	//Get the Up vector
	printf("The CP of (0,0,1) and (1,0,0): (%f,%f,%f)\n", upVect->x, upVect->y, upVect->z);

	delete(upVect);

	
	
	return 0;
}