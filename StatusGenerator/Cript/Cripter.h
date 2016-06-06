#ifndef	_CRIPTER_H_
#define	_CRIPTER_H_
#pragma once

#include	<string>
#include	<random>

class Cripter
{
	public:
		/** 
		 * @brief		コンストラクタ
		 */
		Cripter();
		/** 
		 * @brief		デストラクタ
		 */
		virtual ~Cripter();

		/** 
		 * @brief		変換パスの設定
		 * @param		pass : 変換パス
		 */
		void SetPass( const std::string& pass );

		/** 
		 * @brief		暗号化
		 * @param		data : データ
		 * @param		size : サイズ
		 */
		void Encrypt(void* data , std::size_t size, bool bInit = false);

		/** 
		 * @brief		初期化
		 */
		void Reset();

	protected:

		/** 
		 * @brief		エンジンがあるか
		 * @return		持っていればtrue
		 */
		bool HasEngine()const;

		/** 
		 * @brief		初期化されているか
		 * @return		されていればtrue
		 */
		bool IsInitialized()const;

		/** 
		 * @brief		エンジン初期化
		 */
		void InitEngine();

		/** 
		 * @brief		エンジン開放
		 */
		void FreeEngine();

		/** 
		 * @brief		出力を得る
		 * @return		結果
		 */
		int Generate();

	private:

		///初期化フラグ
		bool bIsInitialized;

		///パス
		std::string mPass;

		///エンジン
		std::mt19937* mEngine;
};
#endif
