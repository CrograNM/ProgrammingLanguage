#include <iostream>
#include <fstream>
#include <string> // (강의 파일 [cite: 786])
#include "save.h" // (강의 파일 [cite: 706])

// (강의 파일 [cite: 650])
using namespace std;

const string FILE_NAME = "월910.txt";

// (이전 문제에서 사용된 전역 변수 및 함수)
unsigned long long compare_call_count { 0 }; // (강의 파일 [cite: 396] 전역변수)

// (강의 파일  오름차순 비교함수)
int compareAscending(const void* a, const void* b)
{
    // (int*)로 형변환 후 역참조
    return (*(int*)a - *(int*)b);
}

// (이전 문제의 홀수/짝수 비교함수)
int compareOddsEvens(const void* a, const void* b)
{
    ++compare_call_count;
    int x = *(int*)a;
    int y = *(int*)b;
    int modX = x % 2;
    int modY = y % 2;
    // 홀수(1)가 짝수(0)보다 앞에 오도록 내림차순
    return modY - modX;
}


//--------
int main()
//--------
{
    // --- [파일 읽기 및 N 찾기] ---
    unsigned cnt {}; // (강의 파일 [cite: 788])
    {
        // (강의 파일 [cite: 787])
        ifstream in { FILE_NAME };
        if (not in) { // (강의 파일 [cite: 787])
            cout << "파일 열기 실패" << endl;
            return 1;
        }
        int temp_val;
        // (강의 파일 [cite: 788] 방식)
        while (in >> temp_val) {
            ++cnt;
        }
    } // (RAII, 강의 파일 [cite: 779])

    // N값 계산 (파일의 개수 cnt는 N-1 임)
    unsigned N = cnt + 1;
    cout << "(4-1) N값: " << N << endl;


    // --- [메모리에 저장] ---
    // (강의 파일 [cite: 647, 659])
    int* p = new int[cnt];

    ifstream in { FILE_NAME };
    if (not in) {
        cout << "파일 열기 실패" << endl;
        return 1;
    }
    // (강의 파일 [cite: 659-660] 방식)
    for (int i = 0; i < cnt; ++i) {
        in >> p[i]; // (동적 할당된 메모리에 값 저장)
    }

    // --- [현재 문제: 없는 정수 찾기 (Sorting Method)] ---

    // 1. 1부터 N까지 오름차순으로 정렬
    // (강의 파일 [cite: 637, 722] qsort 사용)
    qsort(p, cnt, sizeof(int), compareAscending);

    // 2. "값이 튀는 부분" 찾기
    long long missing_number = 0;

    // (Edge Case 1: 만약 1이 없다면, p[0]은 2가 됨)
    if (p[0] != 1) {
        missing_number = 1;
    } else {
        // (Edge Case 3: 1과 N 사이의 값이 없는 경우)
        // (강의 파일 [cite: 352] bool 플래그 사용)
        bool IsFound = false;
        for (int i = 0; i < cnt - 1; ++i) {
            // p[i+1]의 값이 p[i]의 다음 값(+1)이 아니라면
            if (p[i + 1] != (p[i] + 1)) {
                missing_number = p[i] + 1; // 튀는 값(빠진 값)
                IsFound = true; // (강의 파일 [cite: 352])
                break; // (강의 파일 [cite: 352])
            }
        }

        // (Edge Case 2: 1부터 N-1까지 다 있는데 N이 없는 경우)
        if (IsFound == false) { // (강의 파일 [cite: 353])
            missing_number = N;
        }
    }

    cout << "없는 정수: " << missing_number << endl;


    // --- [이전 문제: qsort로 홀수/짝수 정렬] ---

    // (강의 파일 [cite: 637])
    qsort(p, cnt, sizeof(int), compareOddsEvens);
    cout << "비교함수 호출 횟수: " << compare_call_count << endl;


    // --- [메모리 반환] ---

    // (강의 파일 [cite: 695, 704])
    delete[] p;

    save("main.cpp"); // (강의 파일 [cite: 706])
}