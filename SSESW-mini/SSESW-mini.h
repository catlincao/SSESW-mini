
// SSESW-mini.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSSESWminiApp: 
// �йش����ʵ�֣������ SSESW-mini.cpp
//

class CSSESWminiApp : public CWinApp
{
public:
	CSSESWminiApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSSESWminiApp theApp;