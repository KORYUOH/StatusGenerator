#ifndef _DATAWRITER_H_
#define _DATAWRITER_H_
#include "DataIOBase.h"
#include "../../const.h"

class DataWriter : public DataIOBase
{
	DECLARE_INHERIT_CLASS( DataIOBase )
	public:

		/** 
		 * @brief		コンストラクタ
		 */
		DataWriter();
		
		/** 
		 * @brief		コンストラクタ
		 * @param		aFolder : フォルダパス
		 * @param		aFileName : ファイル名
		 */
		DataWriter(const std::string& aFolder , const std::string& aFileName );
		/** 
		 * @brief		デストラクタ
		 */
		virtual ~DataWriter(){};

		/** 
		 * @brief		開く
		 */
		virtual void Open()override;
		
		/** 
		 * @brief		読み書き
		 * @param		data : データ
		 * @param		size : データサイズ
		 */
		virtual void ReadWrite( void* data , std::size_t size )override;
		
		/** 
		 * @brief		閉じる
		 */
		virtual void Close()override;



		/** 
		 * @brief		データの先頭位置をシーク
		 * @param		size : 移動サイズ
		 * @param		reverse = false : 逆転フラグ
		 */
		virtual void Seek( std::size_t size , bool reverse = false );

		/** 
		 * @brief		ファイルを開いているか
		 * @return		開いていればtrue
		 */
		virtual bool IsOpen()const;


};
#endif
