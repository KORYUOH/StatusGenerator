#ifndef _IDATAIO_H_
#define _IDATAIO_H_
#pragma once
#include <string>
#include <fstream>

class IDataIO
{
	public:
		/** 
		 * @brief		コンストラクタ
		 */
		IDataIO();
		/** 
		 * @brief		コンストラクタ
		 * @param		aPath : ファイルパス
		 */
		IDataIO( const std::string& aPath );
		/** 
		 * @brief		コンストラクタ
		 * @param		aFolder : フォルダパス
		 * @param		aFileName : ファイル名
		 */
		IDataIO( const std::string& aFolder , const std::string& aFileName );
		
		/** 
		 * @brief		デストラクタ
		 */
		virtual ~IDataIO();

		/** 
		 * @brief		ファイルを開く
		 */
		virtual void Open();

		/** 
		 * @brief		ファイルを開いているか
		 * @return		開いていればtrue
		 */
		virtual bool IsOpen()const;

		/**
		 * @brief		データの読み書き
		 * @param	ptr : データポインタ
		 * @param	size : データサイズ
		 */
		virtual void ReadWrite(void* ptr , std::size_t size );
		
		/** 
		 * @brief		ファイルを閉じる
		 */
		virtual void Close();

	protected:

		std::string FolderPath;
		std::string FileName;
		std::fstream mStream;

};

#endif
