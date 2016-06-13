#include "PlayerGenerator.h"
#include <sstream>

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

string PlayerGenerator::Attack( PlayerGenerator& Target )
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

	stringstream sstr;

	sstr << mName << "のこうげき" << endl;
	if( bIsCritical )
		sstr << "クリティカル！ ";
	sstr << Target.mName << "に" << dmg << "ダメージを与えた"<<endl;

	PrintStatus();
	Target.PrintStatus();

	return sstr.str();

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

string PlayerGenerator::PrintStatus(bool all)
{
	stringstream sstr;
	sstr << "================================================================================"<<endl;
	sstr << mName << endl;
	sstr << "HP : " << mNowHitPoint << " / " << mParam.HitPoint << endl;
	sstr << "[";
	const int max = 51;
	for( int i = 1; i < max ; ++i )
	{
		if( ((float)i/(float)max) <= ( (float)mNowHitPoint / (float)mParam.HitPoint ) )
			sstr  << "*";
		else
			sstr << " ";
	}
	sstr << "]" << endl;
	if( !all )
		return sstr.str();
	sstr << "ATK : " << mParam.Attack << endl;
	sstr << "DEF : " << mParam.Defence << endl;
	sstr << "AGI : " << mParam.Agility << endl;

	return sstr.str();
}








