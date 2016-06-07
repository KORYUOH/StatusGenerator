﻿#include "IDataIO.h"
#include <iostream>

//================================================================================
// コンストラクタ
IDataIO::IDataIO():
	FolderPath(""),
	FileName(""),
	mStream( nullptr )
{
}

//================================================================================
// コンストラクタ
IDataIO::IDataIO(const std::string& aPath):
	FolderPath(""),
	FileName(""),
	mStream( nullptr )
{
}

//================================================================================
// コンストラクタ
IDataIO::IDataIO(const std::string& aFolder , const std::string& aFileName):
	FolderPath(aFolder),
	FileName(aFileName),
	mStream( nullptr )
{
}

//================================================================================
// デストラクタ
IDataIO::~IDataIO()
{
	Close();
}

//================================================================================
// ファイルを開く
void IDataIO::Open()
{
}

//================================================================================
// ファイルを開いているか
bool IDataIO::IsOpen()const
{
	return false;
}

//================================================================================
// ファイルを閉じる
void IDataIO::Close()
{
}

//================================================================================
// データの読み書き
void IDataIO::ReadWrite( void* ptr , size_t size )
{
}

//================================================================================
// データの先頭位置をシーク
void IDataIO::Seek( size_t size , bool reverse )
{
}




