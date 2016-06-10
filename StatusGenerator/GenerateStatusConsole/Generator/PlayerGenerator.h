#ifndef _PLAYERGENERATOR_H_
#define _PLAYERGENERATOR_H_
#pragma once

#include	"../const.h"
#include	"../../StatusGenerator/StatusGenerator.h"
#include	<string>

class PlayerGenerator : public IStatusGenerator
{
	DECLARE_INHERIT_CLASS( IStatusGenerator )
	public:

		static const int Base;
		static const int MinBase;
		static const int TIME_BASE;
		/** 
		 * @brief		コンストラクタ
		 */
		PlayerGenerator();

		void NameEntry( const std::string& name );

		void Attack( PlayerGenerator& Target );

		void Wait();

		bool IsWait()const;

		bool IsAlive()const;

		void PrintStatus(bool all = false);

	protected:

		/** 
		 * @brief		パラメーター生成
		 * @param		パラメーター
		 */
		void Generate( PlayerParam& param );

	protected:
		
		std::string mName;
		
		PlayerParam mParam;

		int mNowHitPoint;

		int mAgilityCount;

};


#endif

