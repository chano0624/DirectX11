#pragma once
#include<Windows.h> // Windows �������
#include<stdlib.h> // C Runtime �������
#include<malloc.h>
#include<memory.h>
#include<wchar.h>
#include<math.h>
#include<d2d1.h>
#include<d2d1helper.h>
#include<dwrite.h>
#include<wincodec.h>

template<class Interface> inline void SafeRelease(Interface** ppinterffaceToRelease)
{
	if (*ppinterffaceToRelease != NULL)
	{
		(*ppinterffaceToRelease)->Release();

		(*ppinterffaceToRelease) = NULL;
	}
}

class DemoApp
{
public:
	DemoApp();
	~DemoApp();
	HRESULT initialize(HINSTANCE hinstance); // ������ Ŭ������ ����ϰ� draw ���ҽ��� ȣ����.
	void RunMessageLoop();

private:
	HRESULT CreatDeviceIndependentResources(); // initialize ��� ������ resource
	HRESULT CreateDeviceResources(); // initialize ��� ������ resources
	void DiscardDeviceResources(); // ��� ������ ���ҽ��� Release
	HRESULT OnRender(); // �������� �׸�
	void OnResize(UINT width, UINT height); // resize the render target
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); // the windows procedure

	static DemoApp* StaticObject;
	HWND m_hwnd;
	ID2D1Factory* m_pDirect2dFactory;
	ID2D1HwndRenderTarget* m_pRenderTarget;
	ID2D1SolidColorBrush* m_pLightSlateGrayBrush;
	ID2D1SolidColorBrush* m_pCornflowerBlueBrush;
};		