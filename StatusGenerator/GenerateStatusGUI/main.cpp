#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#include "resource.h"

LRESULT CALLBACK WndProc( HWND hwnd , UINT msg , WPARAM wp , LPARAM lp );

BOOL CALLBACK DlgProc( HWND hwnd , UINT Msg , WPARAM wp , LPARAM lp );

int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow )
{

	HWND hwnd ;
	HACCEL haccel;
	MSG msg;
	WNDCLASS winc;
	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = 0;
	winc.cbWndExtra = DLGWINDOWEXTRA;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon( NULL , IDI_APPLICATION );
	winc.hCursor = LoadCursor( NULL , IDC_ARROW );
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT("STATUS");

	if( !RegisterClass( &winc ) ) return -1;

	//hwnd = CreateWindow(
	//		TEXT(""),TEXT(""),
	//		WS_OVERLAPPEDWINDOW |WS_VISIBLE,
	//		CW_USEDEFAULT , CW_USEDEFAULT,
	//		CW_USEDEFAULT , CW_USEDEFAULT,
	//		NULL , NULL,
	//		hInstance , NULL );
	hwnd = CreateDialog( hInstance , MAKEINTRESOURCE( IDD_DIALOG1 ) , 0 , (DLGPROC)WndProc );

	if( hwnd == NULL ) return -1;

	ShowWindow( hwnd , nCmdShow );
	UpdateWindow( hwnd );

	while( GetMessage( &msg , NULL , 0 , 0 )  )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc( HWND hwnd , UINT msg , WPARAM wp , LPARAM lp )
{
	switch( msg )
	{
		case WM_DESTROY:
			PostQuitMessage( 0 );
			return 0;
		case WM_COMMAND:
			switch( LOWORD( wp ) )
			{
				case IDC_BUTTON1:
					int a = 0;
					break;
			}


	}
	
	return DefWindowProc(hwnd , msg , wp , lp);
}


BOOL CALLBACK DlgProc( HWND hwnd , UINT msg , WPARAM wp , LPARAM lp )
{
	switch( msg )
	{
		default:
			break;
	}
	
	return FALSE;
}
