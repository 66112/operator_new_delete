//#ifdef _DEBUG
//#define new (operator new(__FILE__, __FUNCDNAME__, __LINE__))
//#define delete(p) (operator delete(p, __FILE__, __FUNCDNAME__, __LINE__)) 
//#endif

#include <iostream>
using namespace std;

void* operator new(size_t size, const char* strFileName, const char* strFuncName, size_t lineNo)
{ 
	void* p = ::operator new(size);   
	cout << strFileName << "--" << lineNo << "-- " << strFuncName << " new:" << size << "  " << p << endl;  
	return p; 
}

void operator delete(void* p, const char* strFileName, const char* strFuncName, size_t lineNo)
{ 
	cout << strFileName << "--" << strFuncName << "--" << lineNo  <<"--"<< p << endl;  
	::operator delete(p);
}


class Create
{
public:
	static Create* chuangjian()   //ֻ�ܵ��ú�����������
	{
		return new Create;
	}
private:
	//~Create() {}
	//Create() {}          //��Ĭ��
	//Create(const Create&);   //������
};
int main()
{
	/*Create* p1=Create::chuangjian();
	Create* p2=new Create[5];
	delete p2;*/
	//void* p= operator new(4, __FILE__, __FUNCDNAME__, __LINE__); //�ļ�·�������øú��������֣��к�
	//operator delete (p, __FILE__, __FUNCDNAME__, __LINE__);   
	int* p = new int[10]{0};
	for (int i = 0; i < 10; i++){
		cout << p[i] << endl;
	}
	delete p;
	return 0;
}