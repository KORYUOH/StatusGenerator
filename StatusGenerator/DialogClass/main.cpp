#include "DialogClass/Dialog.h"
#include "resource.h"

int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow )
{
	Dialog d( hInstance , hPrevInstance , lpCmdLine , nCmdShow );
	
	d.Run( IDD_DIALOG1 );
	return 0;
}
