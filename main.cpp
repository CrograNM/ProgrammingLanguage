//--------------------------------------------------------------------
// 10. 27 월요일 - 중간시험  
//--------------------------------------------------------------------
// fstream
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "save.h"
using namespace std;

// [문제] 파일 "main.cpp" 에 모두 몇 개의 단어가 있는지 출력하라
// (단어) 공백으로 분리된 문자집합을 말한다.
// 이제 실시간에 단어 개수를 셌다. 
// 단어를 오름차순으로 정렬하라. (사전식 - lexicographical order)
// 정렬된 단어를 출력하라.

int 사전식정렬(const void*, const void*);

const string FILE_NAME = "main.cpp";

//--------
int main()
//--------
{
	save(FILE_NAME);

	unsigned cnt {};
	{
		ifstream in { FILE_NAME };
		if (not in) {
			cout << "파일 열기 실패" << endl;
			return 1;
		}
		string str;
		while (in >> str) {
			++cnt;
		}
	}

	cout << "단어 개수: " << cnt << endl;
	cout << "키를 누르면 정렬합니다";
	char key;
	cin >> key;

	string* words = new string[cnt];

	ifstream in { FILE_NAME };
	if (not in) {
		cout << "파일 열기 실패" << endl;
		return 1;
	}
	for (int i = 0; i < cnt; ++i) {
		in >> words[i];
	}

	// 사전식 정렬
	qsort(words,cnt,sizeof(string),사전식정렬);

	// 정렬된 단어 출력
	for (int i = 0; i < cnt; ++i) {
		cout << words[i] << endl;
	}
	
	// "main()" 단어 개수 출력
	unsigned mainCnt {};
	for (int i = 0; i < cnt; ++i) {
		if ("main()" == words[i])
		{
			cout << words[i] << endl;
			++mainCnt;
		}
	}
	cout << "main() 개수 : " << mainCnt << endl;

	delete[] words;

	// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
	// AA BB CC DD EE FF GG HH II JJ KK LL MM NN OO PP QQ RR SS TT UU VV WW XX YY ZZ
	// AAA BBB CCC DDD EEE FFF GGG HHH III
	// AAB ACC ABB ADD EEE FFF GGG HHH III BBC BCC
}

int 사전식정렬(const void* a, const void* b)
{
	string s1 = *(string*)a; // 형변환 (void* -> string*) 후	역참조로 string 객체 얻기
	string s2 = *(string*)b; 
	
	if (s1 < s2) 
		return -1;
	if (s1 > s2) 
		return 1;
	return 0;
}