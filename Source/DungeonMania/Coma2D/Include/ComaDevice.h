/*
* The MIT License (MIT)
* 
* Copyright (c) 2015 Heonyang Ju
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* 
* 
* MIT ���̼��� (MIT)
* 
* ���۱�(C) 2015 �����
* 
* �� ������ ����, �Ʒ��� ������ ������ �� ���� ���� ����Ʈ��� �ٷ�� ����
* ����Ʈ������ ���纻�� ���õ� ����("����Ʈ����")�� ȹ���ϴ� ������� ������
* ������ ��� �ȴ�. ���� ������ ���, ����, ����, ����, ����, ����, ���� ���̼���
* �׸���/�Ǵ� ����Ʈ������ ���纻�� �Ǹſ� ���޵� ����Ʈ��� ���� �������
* �׷��� �� �� �ֵ��� �㰡�ϴ� ���ѿ� ���� ������ ���� �Ѵ�.
* 
* ���� ���۱� ǥ�ÿ� �� �㰡 ǥ�ô� ��� ����Ʈ������ ���纻 �Ǵ� ����� �Ϻκп�
* ���ԵǾ�� �Ѵ�.
* 
* �� ����Ʈ����� Ư���� ������ ħ�� ������ ���� �����, ���ռ��� ��������
* ���ѵǴ� ���� �ƴ� ����� �Ǵ� �������� ��� ������ �������� "�ִ� �״��"
* ���� �ȴ�. ��� ��쿡�� ������ �Ǵ� ���۱��ڴ� ����Ʈ������ ���� �Ȱ� ��
* �Ǵ� ����Ʈ������ ��� �Ǵ� �ŷ��κ��� �߻��ϴ� ���, �ҹ� ���� �Ǵ� ��Ÿ ���࿡
* ����, ��� �Ҽ�, ���� �Ǵ� �ٸ� å���� ���ؼ��� å���� ����.
* 
* ������ MIT���̼��� ������ �������̸�, ��� �ؼ��� ������ �����Ѵ�.
*/

/*
* filename	ComaDevice.h
* fileinfo	�����ӿ�ũ ���� �̱��� Ŭ���� ��� ����
* author	����� (Heonyang Ju)
*/

#pragma once
#include "ComaWindow.h"
#include "ComaRenderer.h"
#include "comaUtil.h"
#include "WindowEvent.h"
#include "RendererEvent.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "PhysicsManager.h"

COMA_NS_BEGIN

class ComaDevice
{
private:
	ComaDevice(){};
	ComaDevice(const ComaDevice& other);
	~ComaDevice()
	{
		if(resourceManager) delete resourceManager;
		if(sceneManager) delete sceneManager;
		if(physicsManager) delete physicsManager;
		//inputManager�� window���� �������Ƿ� ������ �ʿ䰡 ����.
		
	};
	static ComaDevice* device;
public:
	static ComaDevice* GetDevice()
	{
		if (device == 0) device = new ComaDevice();
		return device;
	}
	void Release(){ 
		if (initialized)
		{
			if (window)
			{
				window->removeEventListener(WindowEvent::DESTROY,			this);
				window->removeEventListener(WindowEvent::MINIMIZED,			this);
				window->removeEventListener(WindowEvent::RESTORED,			this);
				window->removeEventListener(WindowEvent::RESIZE,			this);
				window->removeEventListener(WindowEvent::ENTER_RESIZEMOVE,	this);
				window->removeEventListener(WindowEvent::EXIT_RESIZEMOVE,	this);
				window->removeEventListener(WindowEvent::UPDATE,			this);
			}
			if (renderer)
			{
				renderer->removeEventListener(RendererEvent::UPDATE, this);
				renderer->removeEventListener(RendererEvent::RENDER, this);
			}
		}
		delete device;
	}
	void ReleaseAll()
	{
		if (window) delete window;
		if (renderer) delete renderer;
		delete device;
	}
	
public:
	//Device Setter
	bool setWindow(ComaWindow* window);
	bool setRenderer(ComaRenderer* renderer);
	bool setWindowRenderer(ComaWindow* window, ComaRenderer* renderer);

	//Device Getter
	ComaWindow* getWindow(){ return window; }
	ComaRenderer* getRenderer(){ return renderer; }

	//Device Control
	bool initDevice();
	bool initDevice(HINSTANCE hInstance);
	bool run();

	//Device Status Getter
	bool isRunning(){ return running; }
	bool isInitialized(){ return initialized; }

	//ManagerGetter
	ResourceManager* getResourceManager(){ return resourceManager; }
	SceneManager* getSceneManager(){ return sceneManager; }
	InputManager* getInputManager(){ return inputManager; }
	PhysicsManager* getPhysicsManager(){ return physicsManager; }

private:
	//Events
	void windowDestroyListener(Event* event);
	void windowMinimizeListener(Event* event);
	void windowRestoreListener(Event* event);
	void windowResizeListener(Event* event);
	void windowEnterResizeMoveListener(Event* event);
	void windowExitResizeMoveListener(Event* event);
	void windowUpdateListener(Event* event);
	void rendererUpdateListener(Event* event);
	void rendererRenderListener(Event* event);

private:
	bool initWindow();
	bool initWindow(HINSTANCE hInstance);
	bool initRenderer();
	bool initManagers();
	bool initOthers();
private:
	//Device Essencials
	ComaWindow* window;
	ComaRenderer* renderer;

	//Device Status
	bool running;
	bool initialized;

	//Managers
	ResourceManager* resourceManager;
	SceneManager* sceneManager;
	InputManager* inputManager;
	PhysicsManager* physicsManager;
};

COMA_END