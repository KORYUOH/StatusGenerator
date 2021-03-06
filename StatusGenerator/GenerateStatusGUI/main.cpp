#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <locale.h>
#include <locale> 
#include <iostream>
#include <codecvt> 
#include <cstdio> 
#include <locale> 
#include "const.h"
#include "../StatusGenerator/StatusGenerator.h"
#include "../GenerateStatusConsole/Generator/PlayerGenerator.h"
#include "../charset/CharEnc.h"

#include "resource.h"

using namespace std;

#define MAXSIZE 2048

PlayerGenerator Player1;
PlayerGenerator Player2;

enum class State
{
	BEGIN,
	READ,
	BATTLE,
	WAIT,
	FIN
};

State NowState;


LRESULT CALLBACK WndProc( HWND hwnd , UINT msg , WPARAM wp , LPARAM lp );

BOOL CALLBACK DlgProc( HWND hwnd , UINT Msg , WPARAM wp , LPARAM lp );

int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow )
{

	NowState = State::BEGIN;

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
					switch( NowState )
					{
						case State::FIN:
							SetWindowText( GetDlgItem( hwnd , IDC_BUTTON1 ) , "Battle" );
						case State::BEGIN:
							{
								char str1[ MAXSIZE ] = "";
								GetWindowText(GetDlgItem(hwnd,IDC_PLAYER1) , str1, MAXSIZE);
								Player1.NameEntry( str1 );
								char str2[ MAXSIZE ] = "";
								GetWindowText(GetDlgItem(hwnd,IDC_PLAYER2) , str2, MAXSIZE);
								Player2.NameEntry( str2 );
							}
							NowState = State::BATTLE;
							break;
						case State::WAIT:
							NowState = State::BATTLE;
							break;
						default:
							break;
					}
					break;
			}

	}
			
	switch ( NowState )
	{
		case State::BATTLE:
			if( !Player1.IsAlive() ||  !Player2.IsAlive() )
			{
				SetWindowText( GetDlgItem( hwnd , IDC_BUTTON1 ) , "Restart" );
				NowState = State::FIN;
				break;
			}
			{
				std::string str ="";
				if( Player1.IsWait() )
					Player1.Wait();
				else
				{
					str += Player1.Attack( Player2 );
					NowState = State::WAIT;
				}
				if( Player2.IsWait() )
					Player2.Wait();
				else
				{
					str += Player2.Attack( Player1 );
					NowState = State::WAIT;
				}
				{
					SetWindowText( GetDlgItem(hwnd,IDC_LOG) , str.c_str() );
				}
			}
			break;
		default:
			break;
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
