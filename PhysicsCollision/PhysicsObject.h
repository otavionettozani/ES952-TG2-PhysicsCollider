//
//  PhysicsObject.h
//  PhysicsCollision
//
//  Created by Otávio Netto Zani on 26/10/15.
//  Copyright © 2015 Otávio Netto Zani. All rights reserved.
//

#ifndef PhysicsObject_h
#define PhysicsObject_h

#include <stdio.h>

#endif /* PhysicsObject_h */

#define PHYSICS_OBJECT_MAXIMUM_POINTS 8

//defines the type of the object
typedef enum objectType{
	OBJECT_TYPE_CIRCLE = 0,
	OBJECT_TYPE_POLYGON = 1
}ObjectType;

//defines the format of a point
typedef struct PT{
	float x;
	float y;
}Point;

//defines the physics object itself
typedef struct PO{
	Point position;
	float rotation;
	Point rotationCenter;
	ObjectType type;
	union Format{
		float radius;
		struct PolygonInfo{
			int count;
			Point points[PHYSICS_OBJECT_MAXIMUM_POINTS];
			Point triangles[PHYSICS_OBJECT_MAXIMUM_POINTS-2][3]; //vertex of each triangle.
		} polygonInfo;
	}format;
	float minimumCircleRadius;
	Point minimumCirclePosition;
	
	
}PhysicsObject;

//--------------------------Building Objects--------------------------//

//constructor of point
Point pointMake(float x, float y);

//add the point to an object, returns 1 if succeed, 0 otherwise
char addPointToObject(PhysicsObject* object, Point point);

//-----------------Geometry Validation and Generics--------------------//

//verifies if object is a valid physicsObject
char isObjectValid(PhysicsObject* object);

//distance between 2 points
float pointsDistance(Point a, Point b);

//returns the position of point pt (originally in local reference) in a world reference
Point worldPosition(Point point, PhysicsObject object);

//--------------------------Pre-Physics Geometry Calculations--------------------------//

//calculates the minimum circle using the Emo Welzl method
void calculateMinimumCircle(PhysicsObject* object);

void separateTriangles(PhysicsObject* object);

