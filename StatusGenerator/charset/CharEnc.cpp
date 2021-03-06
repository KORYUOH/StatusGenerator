#include "CharEnc.h"
#include <locale>
#include <codecvt>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string CharEnc::ToString( const wstring& wstr )
{
	std::locale("");
	std::wstring_convert<std::codecvt_utf8<wchar_t> , wchar_t > cv;
	return cv.to_bytes( wstr );
}

wstring CharEnc::ToWString( const string& cstr )
{
	std::locale("");
	std::wstring_convert<std::codecvt_utf8<wchar_t> , wchar_t > cv;
	return cv.from_bytes( cstr );
}
