//--------------------------------------------------------------------
// 10. 27 ������ - �߰�����  
//--------------------------------------------------------------------
// fstream
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "save.h"
using namespace std;

// [����] ���� "main.cpp" �� ��� �� ���� �ܾ �ִ��� ����϶�
// (�ܾ�) �������� �и��� ���������� ���Ѵ�.
// ���� �ǽð��� �ܾ� ������ �ô�. 
// �ܾ ������������ �����϶�. (������ - lexicographical order)
// ���ĵ� �ܾ ����϶�.

int ����������(const void*, const void*);

//--------
int main()
//--------
{
	save("main.cpp");

	unsigned cnt {};
	{
		ifstream in { "main.cpp" };
		if (not in) {
			cout << "���� ���� ����" << endl;
			return 1;
		}
		string str;
		while (in >> str) {
			++cnt;
		}
	}

	string* words = new string[cnt];

	ifstream in { "main.cpp" };
	if (not in) {
		cout << "���� ���� ����" << endl;
		return 1;
	}
	for (int i = 0; i < cnt; ++i) {
		in >> words[i];
	}

	// ������ ����
	qsort(words,cnt,sizeof(string),����������);

	for (int i = 0; i < cnt; ++i) {
		cout << words[i] << endl;
	}

	delete[] words;

	// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
	// AA BB CC DD EE FF GG HH II JJ KK LL MM NN OO PP QQ RR SS TT UU VV WW XX YY ZZ
	// AAA BBB CCC DDD EEE FFF GGG HHH III
	// AAB ACC ABB ADD EEE FFF GGG HHH III BBC BCC
}

int ����������(const void* a, const void* b)
{
	string s1 = *(string*)a; // ����ȯ (void* -> string*) ��	�������� string ��ü ���
	string s2 = *(string*)b; 
	
	if (s1 < s2) 
		return -1;
	if (s1 > s2) 
		return 1;
	return 0;
}