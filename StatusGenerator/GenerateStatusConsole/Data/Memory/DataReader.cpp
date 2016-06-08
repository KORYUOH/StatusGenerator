#include	"DataReader.h"
#include	<fstream>
using namespace std;

//================================================================================
// コンストラクタ
DataReader::DataReader():
	Super()
{
	SetIOFlag( ios::in );
}

//================================================================================
// コンストラクタ
DataReader::DataReader( const string& aFolder , const string& aFileName ):
	Super( aFolder , aFileName )
{
	SetIOFlag( ios::in );
}

//================================================================================
// 開く
void DataReader::Open()
{
	if( HasStream() )
	{
		Close();
	}

	mStream = new fstream;
	mStream->open( FolderPath + FileName  , mIOFlag);
}

//================================================================================
// 読み書き
void DataReader::ReadWrite( void* data , std::size_t size )
{
	if( !HasStream() )
	{
		return;
	}

	mStream->read( (char*)data  , size );
}

//================================================================================
// 閉じる
void DataReader::Close()
{
	if( !HasStream() )
	{
		return;
	}

	mStream->close();

	delete mStream;
	mStream = nullptr;
}

//================================================================================
// 移動させる
void DataReader::Seek( size_t size , bool reverse )
{
	if( !HasStream() )
	{
		return;
	}

	mStream->seekp( size / sizeof( char ) , reverse ? ios::end : ios::beg );
}

//================================================================================
// 開いているか
bool DataReader::IsOpen()const
{
	if( !HasStream() )
	{
		return false;
	}
	
	return mStream->is_open();
}






