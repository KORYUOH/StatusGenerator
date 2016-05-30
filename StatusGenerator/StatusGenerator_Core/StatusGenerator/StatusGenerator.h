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
		virtual ~IStatusGenerator(){};

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
	
		///エンジン
		std::mt19937* mEngine;
};



#endif
