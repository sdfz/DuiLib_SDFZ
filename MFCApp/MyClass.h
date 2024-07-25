#pragma once

#include "UIlib.h"
#include "Utils/WinImplBase.h"
using namespace DuiLib;


class MyClass:public WindowImplBase
{
public:
	MyClass();
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
	virtual LPCTSTR GetWindowClassName(void) const;
	virtual void InitWindow();
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	void Test123();
protected:
	void Notify(TNotifyUI& msg);
	bool OnBtnClickOfEnter(void* param);
	bool OnBtnClickins(void* param);
	bool OnBtnDelete(void* param);
	bool OnBtnEdit(void* param);

	CButtonUI*	pDelInstt;
	CButtonUI*	listClick;
	//std::map<CString, CContainerUI*> pEle;
	CContainerUI* pEle;
	CButtonUI* pLab4;
	CButtonUI* pLab5;
	CListUI* pList;
	int count = 0;
	CDialogBuilder builder;
	CString StrCount;
};

