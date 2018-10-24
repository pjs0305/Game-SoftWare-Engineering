#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>

#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include <Mmsystem.h>

#define DOWN	0x01
#define UP		0x02
#define LEFT	0x04
#define RIGHT	0x08

// 속도 : m/s [ 거리의 변화량 ]
// 가속도 : m/s^2 [ 속도의 변화량 ]
// 힘 : N
// 질량 : kg