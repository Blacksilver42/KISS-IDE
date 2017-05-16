// head.h

#ifndef __KISS_HEAD_H__
#define __KISS_HEAD_H__
///////////////////////////////////////////////// EXTERNAL HEADERS

#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>  

///////////////////////////////////////////////// FUNCTION PROTOTYPES

// Main.cpp
int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
);


// Helpers.cpp
WNDCLASSEX mkwcex(WNDPROC WndProc, HINSTANCE hInstance, LPCSTR szWindowClass);
HWND mkwin(LPCSTR szWindowClass, LPCSTR Title, HINSTANCE hInstance);
void errpop(const char * text, int rc);
void warnpop(const char * text);
void noticepop(const char * text);

// Msgloop.cpp
int msgloop();

// WndProc.cpp
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


#else
#warning "head.h: Included multiple times!\nDon't worry, I've caught the error; it'll be fine."
#endif