//
//  PhysicsCalculator.c
//  PhysicsCollision
//
//  Created by Otávio Netto Zani on 29/10/15.
//  Copyright © 2015 Otávio Netto Zani. All rights reserved.
//

#include "PhysicsCalculator.h"


char coarseCollision(PhysicsObject*a, PhysicsObject*b){
	Point aCenter = worldPosition(a->minimumCirclePosition, *a);
	Point bCenter = worldPosition(b->minimumCirclePosition, *b);
	float centerDistance = pointsDistance(aCenter, bCenter);
	float radiusSum = a->minimumCircleRadius + b->minimumCircleRadius;
	return centerDistance<radiusSum;
}

CollisionPair collideObjects(PhysicsObject* a, PhysicsObject* b){
	CollisionPair pair;
	
	if(!coarseCollision(a, b)){
		pair.a = NULL;
		pair.b = NULL;
		pair.depth = 0;
		pair.normal = pointMake(0, 0);
		return pair;
	}
	
	//if a coarse collision happened, we will search for a refined one in each of A's edges.
	//in this step we try to find every point where B has hitted A
	
	
	return pair;
}