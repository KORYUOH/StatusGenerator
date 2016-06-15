#include "Dialog.h"
#include <windows.h>

void ICallPlugin::SetHandle( HWND hwnd )
{
	mHwnd = hwnd;
}

void ICallPlugInBase::DestroyCall ( WORD Hiword , WORD LoWord )
{
	PostQuitMessage( 0 );
}

void ICallPlugInBase::CommandCall( WORD Hiword , WORD LoWord )
{
}

Dialog* Dialog::mThis = nullptr;

Dialog::Dialog( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow ):
	mPlugIn( nullptr ),
	mInstance( hInstance ),
	mPrevInstance( hPrevInstance ),
	mCmdShow( nCmdShow )
{
}

int Dialog::Run(int DialogID)
{
	MakeDialog(DialogID);
	ShowWindow( mHwnd , mCmdShow );
	UpdateWindow( mHwnd );

	while( GetMessage( &mMsg , NULL , 0 , 0 )  )
	{
		TranslateMessage( &mMsg );
		DispatchMessage( &mMsg );
	}

	return mMsg.wParam;
}

void Dialog::MakeDialog(int DialogID)
{
	//mHwnd = CreateDialog( mInstance , MAKEINTRESOURCE( DialogID ) , 0 , ((DLGPROC)this->WndProc) );
	mThis = this;
	mHwnd = CreateDialog( mInstance , MAKEINTRESOURCE( DialogID ) , 0 , (DLGPROC)WndProc) ;
}

DLGPROC __stdcall Dialog::WndProc( HWND hwnd , UINT msg , WPARAM wp , LPARAM lp )
{
	if( mThis )
	{
		return mThis->Proc( hwnd , msg , wp , lp );
	}
	return 0;
}

DLGPROC __stdcall Dialog::Proc( HWND hwnd , UINT msg , WPARAM wp , LPARAM lp )
{
	if( mPlugIn )
	{
		mPlugIn->SetHandle( hwnd );
	}
	switch( msg )
	{
		case WM_DESTROY:
			if( mPlugIn )
			{
				mPlugIn->DestroyCall( HIWORD( wp ) , LOWORD( wp ) );
			}
			return 0;
		case WM_COMMAND:
			if( mPlugIn )
			{
				mPlugIn->CommandCall( HIWORD( wp ) , LOWORD( wp ) );
			}
	}
	return (DLGPROC)DefWindowProc(hwnd , msg , wp , lp);
}

HWND Dialog::GetHandleItem( int Index )
{
	return GetDlgItem( mHwnd , Index );
}


