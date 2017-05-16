#include "Header.h"


LPCSTR szWindowClass = "KISS-IDE";
LPCSTR Title = "KISS-IDE";
HINSTANCE hInst;

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow) {
	WNDCLASSEX wcex = mkwcex(WndProc, hInstance, szWindowClass);

	if (!RegisterClassEx(&wcex)) {
		errpop("Call to RegisterClassEx failed!\nThis shouldn't *ever* happen.\nIf you get this error again, search for 'C++ RegisterClassEx failed'", 1);
	}

	hInst = hInstance; // Store instance handle in our global variable  

	HWND hWnd = mkwin(szWindowClass, Title, hInstance);

	if (!hWnd){
		errpop("Call to CreateWindow failed!\nThis shouldn't *ever* happen.\n If you get this error again, search for 'C++ CreateWindow failed'", 1);
	}

	// <TF2 soilder voice> Dear god, we're going to actually show the window!
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);


	///// Main message loop:  
	return msgloop();
}