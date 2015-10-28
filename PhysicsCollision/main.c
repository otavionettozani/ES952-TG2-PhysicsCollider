//
//  main.c
//  PhysicsCollision
//
//  Created by Otávio Netto Zani on 26/10/15.
//  Copyright © 2015 Otávio Netto Zani. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "PhysicsObject.h"

#include "Math.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	
	PhysicsObject* a = (PhysicsObject*)calloc(1, sizeof(PhysicsObject));
	
	a->type = OBJECT_TYPE_POLYGON;
	
	addPointToObject(a, pointMake(1, 0));
	addPointToObject(a, pointMake(10, 0));
	addPointToObject(a, pointMake(5, 1));
	addPointToObject(a, pointMake(5, 4));
	
	a->rotationCenter = pointMake(1, 0);
	
	a->rotation = PI;
	//a->position = pointMake(1, 1);
	
	calculateMinimumCircle(a);
	
	printf("sizeof->%lu\n",sizeof(PhysicsObject));
	
	printf("%f (%f,%f)\n",a->minimumCircleRadius, a->minimumCirclePosition.x, a->minimumCirclePosition.y);
	
	Point b = worldPosition(pointMake(0, 0), *a);
	
	printf("(%f, %f)\n",b.x,b.y);
	
	
	separateTriangles(a);
	
	printf("triangles----\n");
	for (int k = 0; k<6; k++) {
		for (int j=0; j<3; j++) {
			printf("(%g,%g) ",a->format.polygonInfo.triangles[k][j].x,a->format.polygonInfo.triangles[k][j].y);
		}
		printf("\n");
	}
	printf("triangles end----\n");
	
    return 0;
}
