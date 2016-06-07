#include	"DataWriter.h"
#include	<fstream>
using namespace std;

//================================================================================
// コンストラクタ
DataWriter::DataWriter():Super()
{
}

//================================================================================
// コンストラクタ
DataWriter::DataWriter( const string& aFolder , const string& aFileName ):
	Super( aFolder , aFileName )
{
}

//================================================================================
// 開く
void DataWriter::Open()
{
	if( HasStream() )
	{
		Close();
	}

	mStream = new ofstream;

	ofstream* p = dynamic_cast< ofstream* > (mStream) ;
	if( nullptr == p )
	{
		return;
	}
	
	p->open( FolderPath + FileName );
}

//================================================================================
// 読み書き
void DataWriter::ReadWrite( void* data , std::size_t size )
{
	if( !HasStream() )
	{
		return;
	}

	ofstream* p = dynamic_cast< ofstream* > (mStream) ;
	if( nullptr == p )
	{
		return;
	}
	p->write( (char*)data  , size );
}

//================================================================================
// 閉じる
void DataWriter::Close()
{
	if( !HasStream() )
	{
		return;
	}

	ofstream* p = dynamic_cast< ofstream* > (mStream) ;
	if( nullptr == p )
	{
		return;
	}
	
	p->close();

	delete mStream;
	mStream = nullptr;
}

//================================================================================
// 移動させる
void DataWriter::Seek( size_t size , bool reverse )
{
	if( !HasStream() )
	{
		return;
	}

	ofstream* p = dynamic_cast< ofstream* > (mStream) ;
	if( nullptr == p )
	{
		return;
	}
	p->seekp( size / sizeof( char ) , reverse ? ios::end : ios::beg );
}

//================================================================================
// 開いているか
bool DataWriter::IsOpen()const
{
	return HasStream();
}






