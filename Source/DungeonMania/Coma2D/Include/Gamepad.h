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
* filename	Gamepad.h
* fileinfo	�����е� ��ü ��� ����
* author	����� (Heonyang Ju)
*/

#pragma once
#include "EventDispatcher.h"
#include <Xinput.h>

COMA_NS_BEGIN

const short GAMEPAD_THUMBSTICK_DEADZONE = (short)(0.20f * 0X7FFF);
const short GAMEPAD_TRIGGER_DEADZONE = 20;
const DWORD MAX_CONTROLLERS = 4;

const DWORD GAMEPAD_DPAD_UP = 0x0001;
const DWORD GAMEPAD_DPAD_DOWN = 0x0002;
const DWORD GAMEPAD_DPAD_LEFT = 0x0004;
const DWORD GAMEPAD_DPAD_RIGHT = 0x0008;
const DWORD GAMEPAD_START_BUTTON = 0x0010;
const DWORD GAMEPAD_BACK_BUTTON = 0x0020;
const DWORD GAMEPAD_LEFT_THUMB = 0x0040;
const DWORD GAMEPAD_RIGHT_THUMB = 0x0080;
const DWORD GAMEPAD_LEFT_SHOULDER = 0x0100;
const DWORD GAMEPAD_RIGHT_SHOULDER = 0x0200;
const DWORD GAMEPAD_A = 0x1000;
const DWORD GAMEPAD_B = 0x2000;
const DWORD GAMEPAD_X = 0x4000;
const DWORD GAMEPAD_Y = 0x8000;

class Gamepad :
	public EventDispatcher
{
public:
	Gamepad(UINT controllerIndex);
	virtual ~Gamepad();

public:
	void update(double deltaTime);
	void updateConntected();


	void vibrateLeft(float speed, float time);
	void vibrateRight(float speed, float time);
	void vibrateRawLeft(WORD speed, float time);
	void vibrateRawRight(WORD speed, float time);

	bool isConnected(){ return connected; }
	XINPUT_STATE getState(){ return state; }

	bool getDpadUp()		{ return ((state.Gamepad.wButtons&GAMEPAD_DPAD_UP) != 0); }
	bool getDpadDown()		{ return ((state.Gamepad.wButtons&GAMEPAD_DPAD_DOWN) != 0); }
	bool getDpadLeft()		{ return ((state.Gamepad.wButtons&GAMEPAD_DPAD_LEFT) != 0); }
	bool getDpadRight()		{ return ((state.Gamepad.wButtons&GAMEPAD_DPAD_RIGHT) != 0); }
	bool getStartButton()	{ return ((state.Gamepad.wButtons&GAMEPAD_START_BUTTON) != 0); }
	bool getBackButton()	{ return ((state.Gamepad.wButtons&GAMEPAD_BACK_BUTTON) != 0); }
	bool getLeftThumb()		{ return ((state.Gamepad.wButtons&GAMEPAD_LEFT_THUMB) != 0); }
	bool getRightThumb()	{ return ((state.Gamepad.wButtons&GAMEPAD_RIGHT_THUMB) != 0); }
	bool getLeftShoulder()	{ return ((state.Gamepad.wButtons&GAMEPAD_LEFT_SHOULDER) != 0); }
	bool getRightShoulder()	{ return ((state.Gamepad.wButtons&GAMEPAD_RIGHT_SHOULDER) != 0); }
	bool getA()				{ return ((state.Gamepad.wButtons&GAMEPAD_A) != 0); }
	bool getB()				{ return ((state.Gamepad.wButtons&GAMEPAD_B) != 0); }
	bool getX()				{ return ((state.Gamepad.wButtons&GAMEPAD_X) != 0); }
	bool getY()				{ return ((state.Gamepad.wButtons&GAMEPAD_Y) != 0); }

	BYTE	getRawLeftTrigger();
	BYTE	getRawRightTrigger();
	SHORT	getRawLeftThumbX();
	SHORT	getRawLeftThumbY();
	SHORT	getRawRightThumbX();
	SHORT	getRawRightThumbY();

	float	getLeftTrigger()		{ return getRawLeftTrigger() / 255.f; }
	float	getRightTrigger()		{ return getRawRightTrigger() / 255.f; }
	float	getLeftThumbX()			{ return getRawLeftThumbX() / 32767.f; }
	float	getLeftThumbY()			{ return getRawLeftThumbY() / 32767.f; }
	float	getRightThumbX()		{ return getRawRightThumbX() / 32767.f; }
	float	getRightThumbY()		{ return getRawRightThumbY() / 32767.f; }
	Point	getLeftThumbPosition()	{ return Point{ getLeftThumbX(), getLeftThumbY() }; }
	Point	getRightThumbPosition()	{ return Point{ getRightThumbX(), getRightThumbY() }; }

private:
	void vibrateController(double frameTime);
	void createEvent();

private:
	UINT				controllerIndex;

	XINPUT_STATE        state;
	XINPUT_VIBRATION    vibration;
	float               vibrateTimeLeft;
	float               vibrateTimeRight;
	bool                connected;
	float				vibrateReadyTime; // ������ �� ��, ���� �ð������� ���ð��� �ʿ��ϴ�.

	bool				buttonArray[14];
	DWORD*				indexData;

};

COMA_END