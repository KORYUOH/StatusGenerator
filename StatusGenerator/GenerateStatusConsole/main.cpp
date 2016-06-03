#include	<iostream>
#include	"const.h"
#include	"../StatusGenerator/StatusGenerator.h"
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
	return 0;
}
