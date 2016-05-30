#include "StatusGenerator.h"
#include	<random>
#include	<algorithm>
using namespace std;

//================================================================================
// コンストラクタ
IStatusGenerator::IStatusGenerator():
	mEngine(nullptr)
{
}


//================================================================================
// 生成シードの生成
void IStatusGenerator::SetSeed( const std::string& seed )
{

	if( HasEngine() )
	{
		FreeEngine();
	}

	unsigned int s = 0;

	std::for_each( seed.begin() , seed.end() , [&]( char c ){ s += c; } );

	mEngine = new mt19937( s );
	
}

//================================================================================
// 値取得
int IStatusGenerator::Roll( const struct GenerateLimit& limit )
{
	if( !HasEngine() )
	{
		RandomInit();
	}
	std::uniform_int_distribution<int> mDistribution(limit.MinLimit , limit.MaxLimit);

	return mDistribution( *mEngine );
}

//================================================================================
// エンジンを持っているか
bool IStatusGenerator::HasEngine()const
{
	return nullptr != mEngine;
}

//================================================================================
// エンジンをランダム初期化
void IStatusGenerator::RandomInit()
{
	if( HasEngine() )
	{
		FreeEngine();
	}

	mEngine = new mt19937( std::random_device()() );

}

//================================================================================
// エンジンを開放
void IStatusGenerator::FreeEngine()
{
	mEngine = nullptr;
}










