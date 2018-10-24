#pragma once

#include "Renderer.h"
#include "Object.h"

class ScnMgr
{
private:
	Renderer *m_Renderer;
	Object *m_Object;
	int KeyState;

	GLuint m_TestTexture = 0;

public:
	ScnMgr();
	virtual ~ScnMgr();

	void RenderScene(void);
	void Update(float ElapsedTime);

	void KeyUpInput(unsigned char key, int x, int y);
	void KeyDownInput(unsigned char key, int x, int y);
	void MouseInput(int button, int state, int x, int y);
	void SpecialKeyInput(int key, int x, int y);
	void ApplyForce(float x, float y);
};

