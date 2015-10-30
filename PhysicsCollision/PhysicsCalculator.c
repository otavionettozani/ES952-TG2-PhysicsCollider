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
	//in this step we try to find every point where B has hitted A and A has hitted B
	int Acurrent, Anext, Abefore, Bcurrent, Bnext;
	for (Acurrent=0; Acurrent<a->format.polygonInfo.count; Acurrent++) {
		/*Given 3 sequenced vertex, we create two vectors, one from the
		 first to the second vertex and other from the second to the
		 third vertex.*/
		Anext = Acurrent==a->format.polygonInfo.count-1?0:Acurrent+1;
		Abefore = Acurrent==0?a->format.polygonInfo.count-1:Acurrent-1;
		Point PA1 = worldPosition(a->format.polygonInfo.points[Abefore],*a);
		Point PA2 = worldPosition(a->format.polygonInfo.points[Acurrent],*a);
		Point PA3 = worldPosition(a->format.polygonInfo.points[Anext],*a);
		Vector A1 = pointMake(PA2.x-PA1.x, PA2.y-PA1.y);
		Vector A2 = pointMake(PA3.x-PA2.x, PA3.y-PA2.y);
		
		for (Bcurrent = 0; Bcurrent<b->format.polygonInfo.count; Bcurrent++) {
			/*for each edge of B, we will find if any of the edges are hitted by both
			 edges defined before, if thats the case, then A hitted B on that point
			 If both edges of A hitted more than one edge of B, we will keep the highest
			 depth*/
			Bnext = Bcurrent==b->format.polygonInfo.count-1?0:Bcurrent+1;
			Point PB1 = worldPosition(b->format.polygonInfo.points[Bcurrent], *b);
			Point PB2 = worldPosition(b->format.polygonInfo.points[Bnext], *b);
			Vector B = pointMake(PB2.x-PB1.x, PB2.y-PB1.y);
			Vector I1 = pointMake(PB1.x-PA1.x, PB1.y-PA1.y);
			Vector I2 = pointMake(PB1.x-PA2.x, PB1.y-PA2.y);
			
			float crossBI1 = B.x*I1.y-B.y*I1.x;
			float crossBI2 = B.x*I2.y-B.y*I2.x;
			float crossAI1 = A1.x*I1.y-A1.y*I1.x;
			float crossAI2 = A2.x*I2.y-A2.y*I2.x;
			float crossBA1 = B.x*A1.y-B.y*A1.x;
			float crossBA2 = B.x*A2.y-B.y*A2.x;
			
			float t1 = crossAI1/crossBA1;
			float w1 = crossBI1/crossBA1;
			float t2 = crossAI2/crossBA2;
			float w2 = crossBI2/crossBA2;
			
			
		}
	
	}
	
	return pair;
}