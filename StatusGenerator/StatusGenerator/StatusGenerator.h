/**============================================================
 * @file	StatusGenerator.h
 * @brief	ステータス自動生成
 * @author	KORYUOH
 * @version	0.01
============================================================*/
#ifndef	_STATUS_GENERATOR_H_
#define	_STATUS_GENERATOR_H_
#pragma once

#include	<string>
#include	<random>

struct GenerateLimit
{
	int MinLimit;
	int MaxLimit;
};

class IStatusGenerator
{
	public:
		/**
		 * @brief	コンストラクタ
		 */
		IStatusGenerator();
		
		/**
		 * @brief	デストラクタ
		 */
		virtual ~IStatusGenerator(){FreeEngine();};

		/**
		 * @brief	生成
		 * @note	Use Override
		 */
		template< typename _Ty>
		void Generate(_Ty* Data){};

		/**
		 * @brief	生成シードの設定
		 * @param[in]	seed : データシード文字列
		 */
		void SetSeed( const std::string& seed );
		
	protected:

		/**
		 * @brief	値取得
		 * @param[in]	limit : 取得限界
		 */
		int Roll( const struct GenerateLimit& limit );

		/** 
		 * @brief		ダイスを振る xdy+s n個のy面ダイス
		 * @param		quntity : 個数
		 * @param		surface : 面
		 * @param		add = 0 : 加算値(省略可能)
		 * @return		結果
		 */
		int Dice( int quantity , int surface , int add = 0 );

		/**
		 * @brief	エンジンを持っているか？
		 * @return 持っていればtrue
		 */
		bool HasEngine()const;

		/**
		 * @brief	エンジンランダム初期化
		 */
		void RandomInit();

		/**
		 * @brief	エンジンを開放
		 */
		void FreeEngine();

	private:

		///シード値
		unsigned int mSeed;
	
		///エンジン
		std::mt19937* mEngine;
};



#endif
