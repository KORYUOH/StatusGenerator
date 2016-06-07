#ifndef _DATAWRITER_H_
#define _DATAWRITER_H_
#include "DataIOBase.h"
#include "../../const.h"

class DataWriter : public DataIOBase
{
	DECLARE_INHERIT_CLASS( DataIOBase )
	public:

		DataWeiter();
		DataWeiter(const std::string& aFolder , const std::string& aFileName );
		virtual ~DataWeiter(){};

		virtual void ReadWrite( void* data , std::size_t size )override;


};
#endif
