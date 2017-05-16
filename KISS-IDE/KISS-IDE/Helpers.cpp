#include "Header.h"

WNDCLASSEX mkwcex(WNDPROC WndProc, HINSTANCE hInstance, LPCSTR szWindowClass) {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	return wcex;
}

HWND mkwin(LPCSTR szWindowClass, LPCSTR Title, HINSTANCE hInstance) {
	return CreateWindow(
		szWindowClass, // window name
		Title, // Title bar text
		WS_OVERLAPPEDWINDOW, //?
		CW_USEDEFAULT, CW_USEDEFAULT, //?
		500, 100, // size
		NULL,
		NULL,
		hInstance,
		NULL);
}

void errpop(const char * text, int rc) {
	MessageBox(NULL,text,"KISS-IDE // Error",NULL);
	exit(rc);
}

void warnpop(const char * text) {
	MessageBox(NULL, text, "KISS-IDE // Warning", NULL);
}

void noticepop(const char * text) {
	MessageBox(NULL, text, "KISS-IDE // Notice", NULL);
}