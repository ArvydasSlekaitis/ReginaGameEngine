///////////////////////////////////////////////////////////
//  BasicMessageEnumaration.h
//  Created on:      11-08-2009
//  Last modified:   11-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_BASICMESSAGEENUMARATION_H
#define REGINA_BASICMESSAGEENUMARATION_H

enum BasicMessageID
{
msg_none=0,
msg_Collision_WithDynamicObject = 30000,			//DATA - CCollisionObject_Dynamic
msg_Collision_WithStaticObject = 30001,				//DATA - CCollisionObject_Static
msg_Collision_WithParticlePhisicsObject = 30002,	//DATA - CCollisionObject_ParticlePhisics
msg_Collision_With2DWall = 30003,					//DATA - CWall_2D
msg_Collision_WithFloor = 30004,					//DATA - NULL
msg_Collision_With2DDoor = 30005,					//DATA - CDoor_2D
msg_Collision_MoveObject = 30010,					//DATA - D3DXVECTOR3
msg_Open_Door = 30030,								//DATA - NULL
msg_Close_Door = 30031								//DATA - NULL
};

#endif
