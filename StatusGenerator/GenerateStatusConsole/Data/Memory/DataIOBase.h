#ifndef _DATAIOBASE_H__
#define _DATAIOBASE_H__
#pragma once

#include "../../const.h"
#include "../IDataIO.h"

class DataIOBase : public IDataIO
{
	DECLARE_INHERIT_CLASS( IDataIO )
	public:
		/** 
		 * @brief		コンストラクタ
		 */
		DataIOBase();
		
		/** 
		 * @brief		コンストラクタ
		 * @param		aFolder : フォルダパス
		 * @param		aFileName : ファイル名
		 */
		DataIOBase( const std::string& aFolder , const std::string& aFileName );

		/** 
		 * @brief		デストラクタ
		 */
		virtual ~DataIOBase(){};

		/** 
		 * @brief		ファイルを開く
		 */
		virtual void Open()override;

};
#endif
