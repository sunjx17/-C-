
#ifdef KEYDLL_EXPORTS
#define KEYDLL_API extern "C" __declspec(dllexport)
#else
#define KEYDLL_API __declspec(dllimport)
#endif
#pragma once
//#include<iostream>
//#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <Winuser.h>
#include <string>
#include <sstream>
#include <process.h>
#include <time.h>
#include <fstream>
#include <iomanip>
using namespace std;
const int KeyBoardValue = 0x80000000;
string GetKeyName(int);
bool JudgeShift();


KEYDLL_API int __stdcall Path_Def;
KEYDLL_API int __stdcall Path_D;
KEYDLL_API int __stdcall Path_E;
KEYDLL_API int __stdcall Path_a;
int __stdcall StartKeySave(int interval,int n);
int __stdcall EndKeySave();
// 此类是从 Keydll.dll 导出的
//class KEYDLL_API CKeydll {
//public:
//	CKeydll(void);
//	// TODO: 在此添加您的方法。
//};
/*

extern KEYDLL_API int nKeydll;

KEYDLL_API int fnKeydll(void);*/
