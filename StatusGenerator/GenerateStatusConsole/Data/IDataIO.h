#ifndef _IDATAIO_H_
#define <{1:_IDATAIO_H_}>
#pragma once
#include <string><`0`>

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
		void Open();

		/** 
		 * @brief		ファイルを開いているか
		 * @return		開いていればtrue
		 */
		bool IsOpen()const;
		
		/** 
		 * @brief		ファイルを閉じる
		 */
		void Close();

	protected:

		std::string FolderPath;
		std::string FileName;

};

#endif<`0`>
