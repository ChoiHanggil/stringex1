#include <iostream>

int StrLength(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

class String
{
private:
	char* mStr;

public:
	String()
	{
		mStr = nullptr;
	}
	String(const char* str)
	{
		int len = StrLength(str) + 1;
		mStr = new char[len];
		for (int i = 0; i < len; i++)
		{
			mStr[i] = str[i];
		}
	}
	String(const String& str)
	{
		int len = StrLength(str.mStr) + 1;
		mStr = new char[len];
		for (int i = 0; i < len; i++)
		{
			mStr[i] = str.mStr[i];
		}
	}
	~String()
	{
		delete[] mStr;
		mStr = nullptr;
	}
	char* Getter()
	{
		return mStr;
	}
	void Setter(char* str)
	{
		mStr = str;
	}
	char* operator +(const String& str)
	{
		int lLen = StrLength(mStr);
		int rLen = StrLength(str.mStr);
		char* sum = new char[lLen + rLen +1];
		for (int i = 0; i < lLen; i++)
		{
			sum[i] = mStr[i];
		}
		for (int i = lLen +1 ; i < lLen + rLen + 1; i++)
		{
			sum[i] = mStr[i];
		}

		return sum;
	}

	String& operator =(const String& str)
	{
		delete[] mStr;
		int len = StrLength(str.mStr) + 1;
		mStr = new char[len];
		for (int i = 0; i < len; i++)
		{
			mStr[i] = str.mStr[i];
		}
		return *this;
	}
	char& operator [] (int i)
	{
		return mStr[i];
	}
};

std::ostream& operator << (std::ostream& os, String str)
{
	os << str.Getter();
	return os;
}
String& operator +=(String& lstr, String rstr)
{
	delete[] lstr.Getter();

	int lLen = StrLength(lstr.Getter());
	int rLen = StrLength(rstr.Getter());
	lstr.Setter(new char[lLen + rLen +1]);

	for (int i = 0; i < lLen; i++)
	{
		lstr[i] = lstr[i];
	}
	for (int i = lLen + 1; i < lLen + rLen + 1; i++)
	{
		lstr[i] = lstr[i];
	}
	return lstr;
}



int main()
{
	String empty;
	std::cout << empty << std::endl;

	String s1("hello");
	std::cout << s1 << std::endl;

	String s2(s1);
	std::cout << s2 << std::endl;

	String s3 = s1 + s2;
	std::cout << s3 << std::endl;

	s3 += s3;
	std::cout << s3 << std::endl;

	std::cout << s3[0] << ", " << s3[1] << std::endl;
	s3[0] = 'H';
	std::cout << s3 << std::endl;

	empty = s3;
	std::cout << empty << std::endl;

	empty = empty;
	std::cout << empty << std::endl;
	std::cout << empty << std::endl;


}