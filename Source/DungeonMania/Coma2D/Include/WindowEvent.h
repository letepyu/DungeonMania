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
* filename	WindowEvent.h
* fileinfo	������ ���� Ŭ������ �̺�Ʈ ��� ����
* author	����� (Heonyang Ju)
*/

#pragma once
#include "Event.h"
#include "ComaWindow.h"

COMA_NS_BEGIN

class WindowEvent :
	public Event
{
public:
	WindowEvent(std::string type, ComaWindow* target, WPARAM wParam = NULL, LPARAM lParam = NULL);
	~WindowEvent();

public:
	static const std::string CREATED;
	static const std::string DESTROY;

	static const std::string ACTIVATED;
	static const std::string INACTIVATED;

	static const std::string MINIMIZED;
	static const std::string MAXIMIZED;
	static const std::string RESTORED;

	static const std::string RESIZE;
	static const std::string RESIZING;
	static const std::string MOVE;
	static const std::string MOVING;

	static const std::string ENTER_FULLSCREEN;
	static const std::string EXIT_FULLSCREEN;

	static const std::string ENTER_RESIZEMOVE;
	static const std::string EXIT_RESIZEMOVE;
	
	
	static const std::string UPDATE;

public:
	POINT getWindowPosition(){ return target->getWindowPosition(); }
	RECT getScreenSize(){ return target->getScreenSize(); }
	RECT getWindowSize(){ return target->getWindowSize(); }
	RECT getWindowRect(){ return target->getWindowRect(); }

	int getWindowX(){ return target->getWindowPosition().x; }
	int getWindowY(){ return target->getWindowPosition().y; }
	int getScreenWidth(){ return target->getScreenSize().right; }
	int getScreenHeight(){ return target->getScreenSize().bottom; }
	int getWindowWidth(){ return target->getWindowSize().right; }
	int getWindowHeight(){ return target->getWindowSize().bottom; }
	
	bool isCreated(){ return target->isCreated(); }
	bool isRunning(){ return target->isRunning(); }
	bool isActivated(){ return target->isActivated(); }
	bool isFullscreen(){ return target->isFullscreen(); }
	bool isMaximized(){ return target->isMaximized(); }
	bool isMinimized(){ return target->isMinimized(); }
	bool isResizing(){ return target->isResizing(); }
	bool isMoving(){ return target->isMoving(); }

	ComaWindow* getTarget(){ return target; }
	WPARAM getWParam(){ return wParam; }
	LPARAM getLParam(){ return lParam; }
private:
	ComaWindow* target;
	WPARAM wParam;
	LPARAM lParam;
};
COMA_END