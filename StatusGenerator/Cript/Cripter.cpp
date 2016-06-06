#include "Cripter.h"
#include	<algorithm>

using namespace std;

//================================================================================
// コンストラクタ
Cripter::Cripter():
	bIsInitialized( false ),
	mPass(""),
	mEngine( nullptr )
{
}

//================================================================================
// デストラクタ
Cripter::~Cripter()
{
	FreeEngine();
}

//================================================================================
// パス設定
void Cripter::SetPass( const string& pass )
{
	mPass = pass;
}

//================================================================================
// 暗号化
void Cripter::Encrypt(void* data , size_t size , bool bInit )
{
	
	if( HasEngine() )
	{
		if( !IsInitialized() && bInit )
		{
			InitEngine();
		}
	}
	char* d = (char*)data;

	const int max = size / sizeof( char );

	for( int i = 0 ; i < max ; ++i )
	{
		d[i] = d[i] ^ Generate();
	}

}

//================================================================================
// 初期化
void Cripter::Reset()
{
	FreeEngine();
	mPass = "";
}

//================================================================================
// 所持判定
bool Cripter::HasEngine()const
{
	return nullptr != mEngine;
}

//================================================================================
// エンジン初期化
void Cripter::InitEngine()
{
	if( HasEngine() )
	{
		FreeEngine();
	}

	unsigned int seed = 0;

	for_each( mPass.begin() , mPass.end() , [&seed](const char c ){ seed += c;});

	mEngine = new mt19937( seed );
	
	bIsInitialized = true;

}

//================================================================================
// エンジン開放
void Cripter::FreeEngine()
{
	if( !HasEngine() )
	{
		return;
	}

	delete mEngine;
	mEngine = nullptr;
	bIsInitialized = false;
}

//================================================================================
// 生成
int Cripter::Generate()
{
	if( !HasEngine() )
	{
		InitEngine();
	}
	
	return (*mEngine)();
}

//================================================================================
// 初期化済みか？
bool Cripter::IsInitialized()const
{
	return bIsInitialized;
}








