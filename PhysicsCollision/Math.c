//
//  Math.c
//  PhysicsCollision
//
//  Created by Otávio Netto Zani on 27/10/15.
//  Copyright © 2015 Otávio Netto Zani. All rights reserved.
//

#include "Math.h"
#define THRESHOLD 0.00001

float BS_sqrt(float value){
	float base = 0, top = value;
	float answer = value/2;
	
	while (answer*answer-value<-THRESHOLD || answer*answer-value>THRESHOLD) {
		if(answer*answer<value){
			base = answer;
		}else{
			top	= answer;
		}
		answer = (base+top)/2.;
	}
	
	return answer;
}

float TS9_sin(float angle){
	while(angle<-PI){
		angle+=2*PI;
	}
	while(angle>PI){
		angle-=2*PI;
	}
	
	float angle2 = angle*angle;
	float angle3 = angle2*angle;
	float angle5 = angle2*angle3;
	float angle7 = angle2*angle5;
	float angle9 = angle2*angle7;
	
	return angle - 0.166666*angle3 + 0.008333*angle5 - 0.000198*angle7 + 0.000002*angle9;
}

float TS8_cos(float angle){
	while(angle<-PI){
		angle+=2*PI;
	}
	while(angle>PI){
		angle-=2*PI;
	}
	
	float angle2 = angle*angle;
	float angle4 = angle2*angle2;
	float angle6 = angle4*angle2;
	float angle8 = angle4*angle4;
	
	return 1 - 0.5*angle2 + 0.041666*angle4 - 0.001388*angle6 + 0.000024*angle8;
}