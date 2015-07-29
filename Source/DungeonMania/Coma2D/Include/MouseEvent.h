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
* filename	MouseEvent.h
* fileinfo	���콺 �̺�Ʈ ��� ����
* author	����� (Heonyang Ju)
*/

#pragma once
#include "Event.h"

COMA_NS_BEGIN

class MouseEvent :
	public Event
{
public:
	MouseEvent(std::string type, bool buttonDown=false,bool altKey=false, bool ctrlKey=false, bool shiftKey=false, int delta=0, float stageX=0, float stageY=0, float localX=0, float localY=0);
	virtual ~MouseEvent();

public:
	static const std::string MIDDLE_CLICK;
	static const std::string MIDDLE_MOUSE_DOWN;
	static const std::string MIDDLE_MOUSE_UP;

	static const std::string CLICK;
	static const std::string MOUSE_DOWN;
	static const std::string MOUSE_UP;
	static const std::string MOUSE_MOVE;
	static const std::string MOUSE_OUT;
	static const std::string MOUSE_OVER;
	static const std::string MOUSE_WHEEL;

	static const std::string RIGHT_CLICK;
	static const std::string RIGHT_MOUSE_DOWN;
	static const std::string RIGHT_MOUSE_UP;
	
public:
	bool	getButtonDown()	{ return buttonDown; }
	bool	getAltKey()		{ return altKey; }
	bool	getCtrlKey()	{ return ctrlKey; }
	bool	getShiftKey()	{ return shiftKey; }

	int		getDelta()		{ return delta; }
	
	float	getStageX()		{ return stageX; }
	float	getStageY()		{ return stageY; }
	float	getLocalX()		{ return localX; }
	float	getLocalY()		{ return localY; }

private:
	bool buttonDown;
	bool altKey;
	bool ctrlKey;
	bool shiftKey;

	int delta;

	float stageX;
	float stageY;

	float localX;
	float localY;
};

COMA_END