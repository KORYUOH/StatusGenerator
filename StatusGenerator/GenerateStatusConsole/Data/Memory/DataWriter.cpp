﻿#include	"DataWriter.h"
#include	<fstream>
using namespace std;

//================================================================================
// コンストラクタ
DataWriter::DataWriter():
	Super()
{
	SetIOFlag( ios::out );
}

//================================================================================
// コンストラクタ
DataWriter::DataWriter( const string& aFolder , const string& aFileName ):
	Super( aFolder , aFileName )
{
	SetIOFlag( ios::out );
}

//================================================================================
// 開く
void DataWriter::Open()
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
void DataWriter::ReadWrite( void* data , std::size_t size )
{
	if( !HasStream() )
	{
		return;
	}

	mStream->write( (char*)data  , size );
}

//================================================================================
// 閉じる
void DataWriter::Close()
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
void DataWriter::Seek( size_t size , bool reverse )
{
	if( !HasStream() )
	{
		return;
	}

	mStream->seekp( size / sizeof( char ) , reverse ? ios::end : ios::beg );
}

//================================================================================
// 開いているか
bool DataWriter::IsOpen()const
{
	if( !HasStream() )
	{
		return false;
	}
	
	return mStream->is_open();
}






