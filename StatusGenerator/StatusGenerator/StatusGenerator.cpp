#include "StatusGenerator.h"
#include	<random>
#include	<algorithm>
using namespace std;

//================================================================================
// コンストラクタ
IStatusGenerator::IStatusGenerator():
	mSeed(0),
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
	
	mSeed = s;

	mEngine = new mt19937( mSeed );
	
}

//================================================================================
// 生成シードの生成
void IStatusGenerator::SetSeed( unsigned int seed )
{
	if( HasEngine() )
	{
		FreeEngine();
	}

	mSeed = seed;
	mEngine = new mt19937( mSeed );
}

//================================================================================
// 生成シードの取得
unsigned int IStatusGenerator::GetSeed()const
{
	return mSeed;
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
// ダイスを振る
int IStatusGenerator::Dice( int quantity , int surface , int add )
{
	int result = 0;

	for( int i = 0 ; i < quantity ; ++i )
	{
		result += Roll( { 1 , surface} );
	}

	result += add;

	return result;
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

	mSeed = std::random_device()();

	mEngine = new mt19937( mSeed );

}

//================================================================================
// エンジンを開放
void IStatusGenerator::FreeEngine()
{
	if( !HasEngine() )
		return;
	delete mEngine;
	mEngine = nullptr;
}










