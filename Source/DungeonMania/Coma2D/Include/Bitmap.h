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
* filename	Bitmap.cpp
* fileinfo	��Ʈ�� ���ҽ� Ŭ���� ���� ����
* author	����� (Heonyang Ju)
*/

#pragma once
#include "Resource.h"
#include "ComaRenderer.h"
#include "RendererEvent.h"
#include <wincodec.h>
COMA_NS_BEGIN

class Bitmap :
	public Resource
{
private:
	Bitmap(ComaRenderer* renderer, IWICBitmapDecoder* decoder, bool load = false) :renderer(renderer), decoder(decoder), reload(false)
	{
		if (load)
			loadResource();
		renderer->setEventListener(RendererEvent::LOAD_RESOURCE_REQ,	BIND(Bitmap::loadReqListener), this);
		renderer->setEventListener(RendererEvent::UNLOAD_RESOURCES_REQ, BIND(Bitmap::unloadReqListener), this);
	}

//======================== Static Mathods ====================

public:
	virtual ~Bitmap();
	static Bitmap* createBitmap(TCHAR* filename);
	static Bitmap* createBitmap(IStream* stream);
	static Bitmap* createBitmap(ComaRenderer* renderer, TCHAR* filename);
	static Bitmap* createBitmap(ComaRenderer* renderer, IStream* stream);

	static Bitmap* createBitmapAndLoad(TCHAR* filename);
	static Bitmap* createBitmapAndLoad(IStream* stream);
	static Bitmap* createBitmapAndLoad(ComaRenderer* renderer, TCHAR* filename);
	static Bitmap* createBitmapAndLoad(ComaRenderer* renderer, IStream* stream);

	static void setRenderer(ComaRenderer* renderer);
private:
	static IWICBitmapDecoder* createBitmapDecoderFromFile(TCHAR* filename);
	static IWICBitmapDecoder* createBitmapDecoderFromStream(IStream* stream);
	static ID2D1Bitmap* createID2D1BitmapFromDecoder(ID2D1HwndRenderTarget* renderTarget, IWICBitmapDecoder* decoder);
	static IWICImagingFactory* factory;
	static ComaRenderer* mainRenderer;
//============================================================

public:
	ID2D1Bitmap* getResource(){ return bitmap; }
	bool isLoaded();
	bool loadResource();
	bool unloadResource();

private:
	ComaRenderer* renderer;
	ID2D1Bitmap* bitmap;
	IWICBitmapDecoder* decoder;
	bool reload;
	
	void loadReqListener(Event* event);
	void unloadReqListener(Event* event);
};

COMA_END