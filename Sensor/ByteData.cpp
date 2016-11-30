#include "ByteData.h"
#include "socket.h"


bool ByteData::checkRange(int index, int size)
{
	if (index >= 0 && index + size < _length)
		return true;
	return false;
}

ByteData::ByteData(const unsigned char * data, int length) :
	_data(data), _length(length)
{
}

unsigned char ByteData::byteAt(int index)
{
	if (!checkRange(index, 1))
		return 0;
	return _data[index];
}

char ByteData::charAt(int index)
{
	if (!checkRange(index, 1))
		return 0;
	return _data[index];
}

unsigned int ByteData::uint32At(int index)
{
	if (!checkRange(index, 4))
		return 0;
	
	auto data = ntohl(*(unsigned long*)(_data+index));
	return *(unsigned int*)(&data);
}

int ByteData::int32At(int index)
{
	if (!checkRange(index, 4))
		return 0;

	auto data = ntohl(*(unsigned long*)(_data + index));
	return *(int*)(&data);
}

unsigned short ByteData::uint16At(int index)
{
	if (!checkRange(index, 2))
		return 0;

	auto data = ntohs(*(unsigned short*)(_data + index));
	return *(unsigned short*)(&data);
}

short ByteData::int16At(int index)
{
	if (!checkRange(index, 2))
		return 0;

	auto data = ntohs(*(unsigned short*)(_data + index));
	return *(short*)(&data);
}

ByteData::ByteData() :
	_data(0), _length(0)
{
}


ByteData::~ByteData()
{
}
