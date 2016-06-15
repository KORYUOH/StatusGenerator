/**
 * @file	Dialog.h
 * @brief	ダイアログ
 * @author	KORYUOH
 */
#ifndef __DIALOG_H__
#define __DIALOG_H__
#pragma once

#include <windows.h>

#ifndef INHERIT_CLASS_DECLARE
#define INHERIT_CLASS_DECLARE( BASE ) typedef BASE Super;
#endif

class ICallPlugin
{
	public:
		void SetHandle( HWND hwnd );
		virtual void DestroyCall( WORD Hiword , WORD LoWord ) = 0;
		virtual void CommandCall( WORD Hiword , WORD LoWord ) = 0;
	protected:
		HWND mHwnd;
};

class ICallPlugInBase : public ICallPlugin
{
	INHERIT_CLASS_DECLARE( ICallPlugin )
	public:
		virtual void DestroyCall( WORD Hiword , WORD LoWord );
		virtual void CommandCall( WORD Hiword , WORD LoWord );
};

class Dialog
{
	public:
	Dialog( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow );
	
	virtual int Run(int DialogID);

	static DLGPROC __stdcall WndProc( HWND hwnd , UINT msg , WPARAM wp , LPARAM lp );
	DLGPROC __stdcall Proc( HWND hwnd , UINT msg , WPARAM wp , LPARAM lp );
	
	protected:

	void MakeDialog(int DialogID);

	HWND GetHandleItem( int Index );
	
	static Dialog* mThis;
	protected:
	ICallPlugin *mPlugIn;
	HINSTANCE mInstance;
	HINSTANCE mPrevInstance;
	HWND mHwnd ;
	//HACCEL haccel;
	MSG mMsg;
	int mCmdShow;
};
#endif
