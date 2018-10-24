/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include "ScnMgr.h"

ScnMgr* SceneManager;

DWORD g_PrevTime = 0;
DWORD g_CurrTime = 0;
float ElapsedTime = 0.0f;

void RenderScene(void)
{
	g_CurrTime = timeGetTime();
	ElapsedTime = (float)(g_CurrTime - g_PrevTime) / 1000.0f;
	g_PrevTime = g_CurrTime;

	SceneManager->RenderScene();
	SceneManager->Update(ElapsedTime);

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	SceneManager->MouseInput(button, state, x, y);
}

void KeyDownInput(unsigned char key, int x, int y)
{
	SceneManager->KeyDownInput(key, x, y);
}

void KeyUpInput(unsigned char key, int x, int y)
{
	SceneManager->KeyUpInput(key, x, y);
}

void SpecialKeyInput(int key, int x, int y)
{
	SceneManager->SpecialKeyInput(key, x, y);
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyDownInput);  // Down »ý·«
	glutKeyboardUpFunc(KeyUpInput);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	SceneManager = new ScnMgr();

	g_PrevTime = ::timeGetTime();

	glutMainLoop();
	
	if(SceneManager) delete SceneManager;

    return 0;
}

