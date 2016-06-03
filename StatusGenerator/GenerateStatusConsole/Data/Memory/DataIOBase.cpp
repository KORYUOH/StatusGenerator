#include "DataIOBase.h"
#include "../../const.h"
#include <string>
#include <fstream>
using namespace std;

//================================================================================
// コンストラクタ
DataIOBase::DataIOBase():Super()
{
}

//================================================================================
// コンストラクタ
DataIOBase::DataIOBase( const string& aFolder , const string& aFileName ):Super( aFolder , aFileName )
{
}

//================================================================================
// ファイルを開く
void DataIOBase::Open()
{
}









