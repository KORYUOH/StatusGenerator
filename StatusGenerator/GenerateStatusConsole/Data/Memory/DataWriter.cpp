#include	"DataWriter.h"
#include	<fstream>

DataWriter::DataWriter():Super()
{
}

DataWriter::DataWriter( const std::string& aFolder , const std::string& aFileName ):
	Super( aFolder , aFileName )
{
}

void DataWriter::ReadWrite( void* data , std::size_t size )
{
}







