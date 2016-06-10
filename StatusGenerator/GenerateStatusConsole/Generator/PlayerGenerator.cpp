#include "PlayerGenerator.h"
#include <iostream>

using namespace std;

const int PlayerGenerator::Base = 15;
const int PlayerGenerator::MinBase = 5;
const int PlayerGenerator::TIME_BASE = 60;

PlayerGenerator::PlayerGenerator():
	Super(),
	mParam( { 0 , 0 , 0 , 0 } ),
	mNowHitPoint( 0 ),
	mAgilityCount( 0 )
{
}

void PlayerGenerator::NameEntry( const std::string& name )
{
	mName = name;
	SetSeed( name );
	Generate( mParam );
}

void PlayerGenerator::Generate( PlayerParam& param )
{
	param.HitPoint	= Roll( {50 , 150} );
	param.Attack	= Dice( 3 , 5 );
	param.Defence	= Dice( 3 , 5 );
	param.Agility	= Dice( 3 , 5 );
	mNowHitPoint = param.HitPoint;
	mAgilityCount = TIME_BASE;

	RandomInit();
	PrintStatus( true );
}

void PlayerGenerator::Attack( PlayerGenerator& Target )
{
	bool bIsCritical = false;
	int dmg = MinBase + Dice ( 1 , Base + ( mParam.Attack - Target.mParam.Defence ) - MinBase );

	if( Roll( {0 , 100} ) < mParam.Agility )
	{
		dmg = (int)(dmg * 1.2f);
		bIsCritical = true;
	}

	Target.mNowHitPoint -= dmg;

	if( Target.mNowHitPoint < 0 )
	{
		Target.mNowHitPoint = 0;
	}

	cout << mName << "のこうげき" << endl;
	if( bIsCritical )
		cout << "クリティカル！ ";
	cout << Target.mName << "に" << dmg << "ダメージを与えた"<<endl;

	PrintStatus();
	Target.PrintStatus();

}

void PlayerGenerator::Wait( )
{
	if( mAgilityCount < 0 )
	{
		mAgilityCount += TIME_BASE;
	}
	
	mAgilityCount -= mParam.Agility;

}

bool PlayerGenerator::IsWait()const
{
	return mAgilityCount >= 0;
}

bool PlayerGenerator::IsAlive()const
{
	return mNowHitPoint > 0;
}

void PlayerGenerator::PrintStatus(bool all)
{
	cout << "================================================================================"<<endl;
	cout << mName << endl;
	cout << "HP : " << mNowHitPoint << " / " << mParam.HitPoint << endl;
	cout << "[";
	const int max = 51;
	for( int i = 1; i < max ; ++i )
	{
		if( ((float)i/(float)max) <= ( (float)mNowHitPoint / (float)mParam.HitPoint ) )
			cout  << "*";
		else
			cout << " ";
	}
	cout << "]" << endl;
	if( !all )
		return;
	cout << "ATK : " << mParam.Attack << endl;
	cout << "DEF : " << mParam.Defence << endl;
	cout << "AGI : " << mParam.Agility << endl;
}








