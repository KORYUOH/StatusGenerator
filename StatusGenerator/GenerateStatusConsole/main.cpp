#include	<iostream>
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
	public:
	void Generate(struct Params* p)
	{
		p->hp	=	Roll({1,6});
		p->atk	=	Roll({1,6});
		p->def	=	Roll({1,6});
	}
};

int main(int argc, char* argv[])
{
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
