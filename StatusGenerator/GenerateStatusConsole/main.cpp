﻿#include	<iostream>
#include	<fstream>
#include	"const.h"
#include	"../StatusGenerator/StatusGenerator.h"
#include	"../Cript/Cripter.h"
#include	"Data/Memory/DataWriter.h"
#include	"Generator/PlayerGenerator.h"
using namespace std;


struct Params
{
	int hp;
	int atk;
	int def;
};

class Generator : public IStatusGenerator
{
	DECLARE_INHERIT_CLASS( IStatusGenerator )
	public:
	void Generate(struct Params* p)
	{
		p->hp	=	Roll( {50 , 150} );
		p->atk	=	Dice(3,5);
		p->def	=	Dice(3,5);
	}
};

int main(int argc, char* argv[])
{
	CHECKLEAK

		string player1;
		string player2;
		cout << "Player1 Name? : " ;
		cin >> player1;
		cout << "Player2 Name? : " ;
		cin >> player2;

		PlayerGenerator p1;
		PlayerGenerator p2;

		p1.NameEntry( player1 );
		p2.NameEntry( player2 );
		
		while( p1.IsAlive() && p2.IsAlive() )
		{
			if( p1.IsWait() )
				p1.Wait();
			else
			{
				cout << p1.Attack( p2 );
				//getchar();
			}
			if( p2.IsWait() )
				p2.Wait();
			else
			{
				cout << p2.Attack( p1 );
				//getchar();
			}
		}
	
/*
		std::cout << "Hello,World!" << std::endl;

	Generator g;

	string s ="";

	cout << "Name ? : ";
	cin >> s;

	g.SetSeed( s );

	Params p;

	g.Generate( &p );

	cout << "HP : " <<	p.hp	<< endl;
	cout << "ATK : " <<	p.atk	<< endl;
	cout << "DEF : " <<	p.def	<< endl;

	int size = sizeof( p ) / sizeof( char );
	cout << "size : " << size << endl;
	cout << " S Addr : 0x" << &p << endl;
	cout << " E Addr : 0x" << &p+sizeof(p) << endl;
	ofstream ofs;
	ofstream ofs2;
	ofs.open("data.dat" , ios::out | ios::binary );
	ofs2.open("data2.dat" , ios::out | ios::binary );
	for( int i = 0 ; i  < size ; ++i )
	{
		cout << (char)(&p+sizeof(char)*i) << endl;
		//ofs << (char)(&p+sizeof(char)*i);
		//cout << (char)(&p+sizeof(char)*i) << endl;
	}
	ofs.write( (char*) &p , sizeof(p) );
	ofs.close();

	{
		Params x = p;
		Cripter cript;
		cript.SetPass( "engine" );
		cript.Encrypt( &x , sizeof(x) );
		ofs2.write( (char*) &x, sizeof( x ) );
		ofs2.close();
	}

	Params t = {0,0,0};
	ifstream ifs;
	ifs.open("data.dat" , ios::in|ios::binary);
	if( !ifs.fail() )
	{
		cout << "T" << endl;
		cout << "HP : " <<	t.hp	<< endl;
		cout << "ATK : " <<	t.atk	<< endl;
		cout << "DEF : " <<	t.def	<< endl;
		int siz = sizeof( t ) / sizeof( char );
		//for( int i = 0; i < siz ; ++i )
		//{
			ifs.read( (char*) &t , sizeof(t) );
		//}
		cout << "T============" << endl;
		cout << "HP : " <<	t.hp	<< endl;
		cout << "ATK : " <<	t.atk	<< endl;
		cout << "DEF : " <<	t.def	<< endl;

	}
	ifs.close();
	
	Params r = {0,0,0};
	ifstream ifs2;
	ifs2.open("data2.dat" , ios::in|ios::binary);
	if( !ifs2.fail() )
	{
		Cripter cript;
		cript.SetPass( "engine" );
		cout << "R" << endl;
		cout << "HP : " <<	r.hp	<< endl;
		cout << "ATK : " <<	r.atk	<< endl;
		cout << "DEF : " <<	r.def	<< endl;
		int siz = sizeof( r ) / sizeof( char );
			ifs2.read( (char*) &r , sizeof(r) );
		cript.Encrypt( &r , sizeof(r) );
		cout << "R============" << endl;
		cout << "HP : " <<	r.hp	<< endl;
		cout << "ATK : " <<	r.atk	<< endl;
		cout << "DEF : " <<	r.def	<< endl;

	}
	ifs2.close();

	DataWriter writer( "./" , "test.dat" );
	writer.SetIOFlag( ios::out | ios::binary ); 
	writer.Open();
	cout << writer.IsOpen() << endl;
	writer.ReadWrite( &r , sizeof( r ) );
	writer.Close();

*/

	return 0;
}
