#include <Windows.h>
#include <AWin32.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* pCmdLine, int nCmdShow)
{
	Window window1;
	window1.Title = L"Hi";
	window1.Background = Sliver;
	window1.Instance = hInstance;
	Show(window1,nCmdShow);
}