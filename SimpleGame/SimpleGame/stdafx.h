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

// �ӵ� : m/s [ �Ÿ��� ��ȭ�� ]
// ���ӵ� : m/s^2 [ �ӵ��� ��ȭ�� ]
// �� : N
// ���� : kg