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
* filename	EventDispatcher.h
* fileinfo	�̺�Ʈ �й� �� ó�� Ŭ���� ��� ����
* author	����� (Heonyang Ju)
*/


/*===================================================================================
EventDispatcher.h
EventDispatcherŬ������ �̺�Ʈ�� �����ϰ� ���, ����, �߻��� ����ϴ� �⺻ Ŭ�����̴�.
��κ��� Coma2D Ŭ������ EventDispatcher�� ��ӹ�����, �̺�Ʈ�� �����ϱ� ���ؼ� �� Ŭ
������ ��ӹ޾ƾ� �Ѵ�.

void setEventListener(string, EventFunction)
�̺�Ʈ �����ʸ� ����Ʈ�� �߰��ϴ� ������ �Ѵ�. ��Ͻÿ��� void(Event*)������ �Լ���
bind�ϰ�, �̺�Ʈ�� �������� Ÿ��(string)�� �����ؾ� �Ѵ�.
�Ϲ������� type�� �ش� Ÿ���� �����ϴ� EventŬ�������� static const std::string��
���·� �����ȴ�.

void removeEventListener(string, EventFunction)
�̺�Ʈ �����ʸ� ����Ʈ���� �����ϴ� ������ �Ѵ�.

bool hasEventListener(string);
�ش� �̺�Ʈ Ÿ���� �����ʿ� ������ ��� true�� ��ȯ�Ѵ�.

void dispatchEvent(Event*)
�̺�Ʈ�� �߻���Ų��. �ش� �̺�Ʈ�� ������ Ÿ���� ���� �����ʸ� ��� �����Ų��. �Լ���
����� Event��ü�� ���ڷ� �����Ѵ�.
====================================================================================*/

#pragma once
#include <functional>
#include <vector>
#include <string>
#include "Event.h"
#define BIND(T) std::bind(&T, this, std::placeholders::_1)

COMA_NS_BEGIN

typedef std::function<void(Event*)> EventFunction;

struct Listener	//�̺�Ʈ �����ʸ� �����ϴ� ����ü
{
	std::string type;		//�̺�Ʈ Ÿ��
	EventFunction function;	//���� �Լ�
	void* target;			//�̺�Ʈ�� ������ Ŭ����
};


class EventDispatcher
{
public:
	EventDispatcher();
	virtual ~EventDispatcher();
	
	void setEventListener(std::string type, EventFunction function, void* target = nullptr);			//�̺�Ʈ ������ ��ü�� ����Ѵ�.
	void removeEventListener(std::string type, void* target);		//�̺�Ʈ ������ ��ü�� �����Ѵ�.
	bool hasEventListener(std::string type);								//�ش� Ÿ���� �����ʰ� ������ ��� true��ȯ
	void dispatchEvent(Event* event);										//�̺�Ʈ�� �߻���Ų�� (��ϵ� �ش� ������ ����)
private:
	std::vector<Listener> listenerList;	//�̺�Ʈ �����ʰ� ����� ����Ʈ
};

COMA_END