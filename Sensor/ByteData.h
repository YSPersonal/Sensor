#pragma once
class ByteData
{
	const unsigned char* _data;
	const int _length;
	bool checkRange(int index, int size);
public:
	ByteData(const unsigned char* data, int length);
	
	
	unsigned char byteAt(int index);
	char charAt(int index);
	unsigned int uint32At(int index);
	int int32At(int index);
	unsigned short uint16At(int index);
	short int16At(int index);

	ByteData();
	~ByteData();
};

