#pragma once
#ifndef UNICODE 
#define UNICODE
#endif
#define Sliver 1
#define Black 2
#define SkyBlue 3
#define LightBlue 4
#define LightGray 5
#define White 6
#define Gray 7
#include <Windows.h>
__int64 bcg;
__int64 WINAPI WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
struct Window
{
	UINT cbSize = sizeof(Window);
	UINT style = 0;
	int cbClsExtra = 0;
	int cbWndExtra = 0;
	HINSTANCE Instance;
	HICON Icon = LoadIconW(0, IDI_APPLICATION);
	HCURSOR Cursor = LoadCursorW(0, IDC_ARROW);
	__int64 Background = 6;
	LPCWSTR MenuName = 0;
	LPCWSTR ClassName = L"WindowClass";
	HICON	IconSm = LoadIconW(0, IDI_APPLICATION);
	LPCWSTR Title = L"";
};
int WINAPI Show(Window wnd, int n)
{
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = wnd.Instance;
	wc.hIconSm = wnd.IconSm;
	wc.cbClsExtra = wnd.cbClsExtra;
	wc.cbWndExtra = wnd.cbWndExtra;
	wc.hbrBackground = (HBRUSH)wnd.Background;
	wc.hIcon = wnd.Icon;
	wc.hCursor = wnd.Cursor;
	wc.style = wnd.style;
	wc.lpszClassName = wnd.ClassName;
	wc.lpfnWndProc = WindowProc;
	wc.lpszMenuName = wnd.MenuName;
	bcg = wnd.Background;
	RegisterClassExW(&wc);
	HWND hwnd = CreateWindowEx(0, wnd.ClassName, wnd.Title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, wnd.Instance, 0);
	ShowWindow(hwnd, n);
	MSG msg;
	for (; GetMessageW(&msg, 0, 0, 0) > 0;)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	return 0;
}
__int64 WINAPI WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (uMsg == WM_PAINT) 
	{	
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		FillRect(hdc, &ps.rcPaint,(HBRUSH)bcg);
		EndPaint(hwnd, &ps);
	}
	else if(uMsg == WM_DESTROY) PostQuitMessage(0);
	return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}	