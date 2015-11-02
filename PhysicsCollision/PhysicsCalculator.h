//
//  PhysicsCalculator.h
//  PhysicsCollision
//
//  Created by Otávio Netto Zani on 29/10/15.
//  Copyright © 2015 Otávio Netto Zani. All rights reserved.
//

#ifndef PhysicsCalculator_h
#define PhysicsCalculator_h

#include <stdio.h>

#endif /* PhysicsCalculator_h */

#include "PhysicsObject.h"
typedef struct CP{
	float depth;
	Vector normal;
	Point location;
}CollisionPair;


//returns a collision pair between objects A and B, this method calculates both coarse and refined collision
void collideObjects(PhysicsObject* a, PhysicsObject* b);