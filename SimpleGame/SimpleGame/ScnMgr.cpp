#include "stdafx.h"
#include "ScnMgr.h"

ScnMgr::ScnMgr()
{
	m_Renderer = NULL;
	m_Object = NULL;

	// Initialize Renderer
	m_Renderer = new Renderer(500, 500);
	if (!m_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	//Load Test Texture
	m_TestTexture = m_Renderer->CreatePngTexture("./Test.png");

	m_Object = new Object();
}

ScnMgr::~ScnMgr()
{
	if (m_Renderer) { delete m_Renderer; m_Renderer = NULL; }
	if (m_Object) { delete m_Object; m_Object = NULL; }
}

void ScnMgr::RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	Vector p = m_Object->GetPosition();
	Size s = m_Object->GetSize();
	Color c = m_Object->GetColor();

	// Renderer Player
	m_Renderer->DrawTextureRectHeight(p.x * 100.f, p.y * 100.f, 0.0f,
		s.x * 100.f, s.y * 100.f, 
		c.r, c.g, c.b, c.a, 
		m_TestTexture, p.z * 100.0f);
}

void ScnMgr::MouseInput(int button, int state, int x, int y)
{
	//RenderScene();
}

void ScnMgr::KeyDownInput(unsigned char key, int x, int y)
{
	if (key == 'w') KeyState |= UP;
	if (key == 'a') KeyState |= LEFT;
	if (key == 's') KeyState |= DOWN;
	if (key == 'd') KeyState |= RIGHT;
}

void ScnMgr::KeyUpInput(unsigned char key, int x, int y)
{ 
	if (key == 'w') KeyState &= ~UP;
	if (key == 'a') KeyState &= ~LEFT;
	if (key == 's') KeyState &= ~DOWN;
	if (key == 'd') KeyState &= ~RIGHT;
}

void ScnMgr::SpecialKeyInput(int key, int x, int y)
{
	//RenderScene();
}

void ScnMgr::ApplyForce(float x, float y)
{
	m_Object->ApplyForce(x, y);
}

void ScnMgr::Update(float ElapsedTime)
{
	float fx = 0, fy = 0;
	if (KeyState & UP)		fy += 100;
	if (KeyState & DOWN)	fy -= 100;
	if (KeyState & LEFT)	fx -= 100;
	if (KeyState & RIGHT)	fx += 100;

	ApplyForce(fx, fy);


	m_Object->Update(ElapsedTime);
}