//
//  main.c
//  PhysicsCollision
//
//  Created by Otávio Netto Zani on 26/10/15.
//  Copyright © 2015 Otávio Netto Zani. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "PhysicsCalculator.h"

int main(int argc, const char * argv[]) {
	
	//Object A
	PhysicsObject* a = (PhysicsObject*)calloc(1, sizeof(PhysicsObject));
	
	a->type = OBJECT_TYPE_POLYGON;
	
	addPointToObject(a, pointMake(0, 0));
	addPointToObject(a, pointMake(2, -2));
	addPointToObject(a, pointMake(4, 0));
	addPointToObject(a, pointMake(2, 2));
	
	a->rotationCenter = pointMake(0, 2);
	
	a->rotation = 0;
	a->position = pointMake(0, 0);
	
	calculateMinimumCircle(a);
	
	separateTriangles(a);
	
	//Object B
	PhysicsObject* b = (PhysicsObject*)calloc(1, sizeof(PhysicsObject));
	
	b->type = OBJECT_TYPE_POLYGON;
	
	addPointToObject(b, pointMake(0, -1));
	addPointToObject(b, pointMake(2, -4));
	addPointToObject(b, pointMake(4, -1));
	
	b->rotationCenter = pointMake(2, -2);
	
	b->rotation = PI;
	b->position = pointMake(0, 0);
	
	calculateMinimumCircle(b);
	
	separateTriangles(b);
	
	//collisions
	
	collideObjects(b, a);
	
    return 0;
}
