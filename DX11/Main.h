#pragma once
#include<Windows.h> // Windows 헤더파일
#include<stdlib.h> // C Runtime 헤더파일
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
	HRESULT initialize(HINSTANCE hinstance); // 윈도우 클래스를 등록하고 draw 리소스를 호출함.
	void RunMessageLoop();

private:
	HRESULT CreatDeviceIndependentResources(); // initialize 기기 독립성 resource
	HRESULT CreateDeviceResources(); // initialize 기기 의존성 resources
	void DiscardDeviceResources(); // 기기 독립성 리소스를 Release
	HRESULT OnRender(); // 콘텐츠를 그림
	void OnResize(UINT width, UINT height); // resize the render target
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); // the windows procedure

	static DemoApp* StaticObject;
	HWND m_hwnd;
	ID2D1Factory* m_pDirect2dFactory;
	ID2D1HwndRenderTarget* m_pRenderTarget;
	ID2D1SolidColorBrush* m_pLightSlateGrayBrush;
	ID2D1SolidColorBrush* m_pCornflowerBlueBrush;
};		