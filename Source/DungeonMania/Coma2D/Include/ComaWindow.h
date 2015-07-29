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
* filename	ComaWindow.h
* fileinfo	������ ���� �� ���� Ŭ���� ��� ����
* author	����� (Heonyang Ju)
*/

#pragma once
#include "EventDispatcher.h"
#include "ComaRenderer.h"
#include "InputManager.h"
COMA_NS_BEGIN
struct WindowData
{
	HICON icon;
	HCURSOR cursor;
	HBRUSH backgroundColor;
	DWORD style;
	DWORD styleEx;
	TCHAR* title;
	int nCmdShow;
	POINT windowPosition;
	RECT windowSize;
	RECT maxWindowSize;
	RECT minWindowSize;
	RECT fullscreenSize;
};

class ComaWindow :
	public EventDispatcher
{
public:
	ComaWindow(HINSTANCE hInstance, int nCmdShow = SW_SHOW);
	virtual ~ComaWindow();

	//Window Initialize
	bool	createWindow();
	bool	run();

	LRESULT messageProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
public:
	HINSTANCE	getInstance() { return hInstance; }
	HWND		getWindow(){ return hWnd; }
	InputManager* getInputManager(){ return inputManager; }

	DWORD	getStyle();
	DWORD	getStyleEx();
	TCHAR*	getTitle();
	RECT	getWindowSize();
	RECT	getWindowRect();
	RECT	getScreenSize();
	POINT	getWindowPosition();

	//Window Setter
	bool setIcon(HICON icon);
	bool setCursor(HCURSOR cursor);
	bool setBackgroundColor(HBRUSH brush);
	bool setStyle(DWORD style);
	bool setStyleEx(DWORD styleEx);
	bool setTitle(TCHAR* title);
	bool setCmdShow(int nCmdShow);


	bool setWindowRect(RECT rect);
	bool setWindowRect(int left, int top, int right, int bottom);
	bool setWindowSize(RECT rect);
	bool setWindowSize(int width, int height);
	bool setWindowPosition(POINT point);
	bool setWindowPosition(int x, int y);
	bool setScreenSize(RECT rect);
	bool setScreenSize(int width, int height);


	bool setMaxScreenSize(RECT rect);
	bool setMaxScreenSize(int width, int height);
	bool setMaxWindowSize(RECT rect);
	bool setMaxWindowSize(int width, int height);
	bool setMinScreenSize(RECT rect);
	bool setMinScreenSize(int width, int height);
	bool setMinWindowSize(RECT rect);
	bool setMinWindowSize(int width, int height);

	bool addStyle(DWORD style);
	bool removeStyle(DWORD style);
	bool addStyleEx(DWORD styleEx);
	bool removeStyleEx(DWORD styleEx);
	
	//Window Status Getter
	bool isCreated(){ return created; }
	bool isRunning(){ return running; }
	bool isActivated(){ return activated; }
	bool isFullscreen(){ return fullscreen; }
	bool isMaximized(){ return maximized; }
	bool isMinimized(){ return minimized; }
	bool isResizing(){ return resizing; }
	bool isMoving(){ return moving; }

	//Window Status Changer
	bool setFullscreen(bool mode);
	bool setFullscreen(bool mode, int width, int height);
	bool setscreen();
	bool minimizeWindow();
	bool maximizeWindow();
	bool restoreWindow();

private:
	//Window Essencials
	HINSTANCE	hInstance;
	HWND		hWnd;
	WindowData windowData;

	//Manager
	InputManager* inputManager;
	
	//Window Status
	bool created;
	bool running;
	bool activated;
	bool fullscreen;
	bool maximized;
	bool minimized;
	bool resizing;
	bool moving;

};

COMA_END

