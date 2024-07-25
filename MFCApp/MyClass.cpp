#include "pch.h"
#include "MyClass.h"
#include <functional>
MyClass::MyClass()
{
	
}

LRESULT MyClass::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	bHandled = FALSE;
	return 0;
}

void MyClass::Test123()
{
	int a = 1;
	GetSkinFile();
}

CDuiString MyClass::GetSkinFile()
{
	return _T("MainSkin.xml");
}

CDuiString MyClass::GetSkinFolder()
{
	return  _T("Skins\\");
}

LPCTSTR MyClass::GetWindowClassName(void) const
{
	return LPCTSTR("UIMainFrame");
}

void MyClass::InitWindow()
{
	pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("mylist")));
	CListBodyUI* pp = pList->GetCListBodyUI();
	pp->CallScrollBarBottom = std::bind(&MyClass::Test123, this);

	for (size_t i = 0; i < 10; i++)
	{
		if (builder.GetMarkup()->IsValid())
		{
			pEle = static_cast<CContainerUI*>(builder.Create(this, &m_PaintManager));
		}
		else
		{
			pEle = static_cast<CContainerUI*>(builder.Create(_T("list_empty_bk.xml"), (UINT)0, NULL, &m_PaintManager));
		}
		StrCount.Format(_T("%d"), count++);
		pList->Add(pEle);
		CButtonUI* pDelChartDataBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("DelChartData")));
		pDelChartDataBtn->OnNotify += MakeDelegate(this, &MyClass::OnBtnClickOfEnter);

		pDelInstt = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("ins")));
		pDelInstt->OnNotify += MakeDelegate(this, &MyClass::OnBtnClickins);

		CLabelUI* pLab1 = static_cast<CLabelUI*>(pEle->FindSubControl(_T("1993")));
		pLab1->SetText(StrCount);

		pLab4 = static_cast<CButtonUI*>(pEle->FindSubControl(_T("MyEDIT")));
		pLab4->OnNotify += MakeDelegate(this, &MyClass::OnBtnEdit);

		pLab5 = static_cast<CButtonUI*>(pEle->FindSubControl(_T("MyDelete")));
		pLab5->OnNotify += MakeDelegate(this, &MyClass::OnBtnDelete);
	}

}


void MyClass::Notify(TNotifyUI & msg)
{
	int a = 1;
}

bool MyClass::OnBtnClickOfEnter(void* param)
{
	TNotifyUI * msg = (TNotifyUI*)param;
	if(msg->pSender->GetName() ==_T("DelChartData") && msg->sType == _T("click"))
		PostQuitMessage(0);
	return 1;
}

bool MyClass::OnBtnClickins(void* param)
{
	TNotifyUI * msg = (TNotifyUI*)param;
	if (msg->pSender->GetName() == _T("ins") && msg->sType == _T("click"))
	{
		pEle = static_cast<CContainerUI*>(builder.Create(this, &m_PaintManager));
		pList->Add(pEle);
		StrCount.Format(_T("%d"), count++);

		CLabelUI* pLab1 = static_cast<CLabelUI*>(pEle->FindSubControl(_T("1993")));
		pLab1->SetText(StrCount);

		pLab4 = static_cast<CButtonUI*>(pEle->FindSubControl(_T("MyEDIT")));
		pLab4->OnNotify += MakeDelegate(this, &MyClass::OnBtnEdit);

		pLab5 = static_cast<CButtonUI*>(pEle->FindSubControl(_T("MyDelete")));
		pLab5->OnNotify += MakeDelegate(this, &MyClass::OnBtnDelete);
	}

	return TRUE;
}

bool MyClass::OnBtnDelete(void* param)
{
	TNotifyUI * msg = (TNotifyUI*)param;
	if (msg->sType == _T("click"))
	{
		// 获取事件发送者控件的父控件 ,这里为什么获取 2 次父类，因为xml里面删除按钮被嵌套了 2 层，第一层父类是 HorizontalLayout ，第二层顶层父类是 ListContainerElement，
		//ListContainerElement 才是我们要找到的最顶层父类，是需要删除的
		CControlUI* pParent = msg->pSender->GetParent();
		pParent = pParent->GetParent();
		CListContainerElementUI* pListSub = (CListContainerElementUI*)pParent;

		if(pListSub)
			pList->Remove(pListSub);
	}

	return TRUE;
}

bool MyClass::OnBtnEdit(void * param)
{
	TNotifyUI * msg = (TNotifyUI*)param;
	if (msg->sType == _T("click"))
	{
		CControlUI* pParent = msg->pSender->GetParent();
		pParent = pParent->GetParent();
		CListContainerElementUI* pListSub = (CListContainerElementUI*)pParent;

		CLabelUI* pLis1t = static_cast<CLabelUI*>(pListSub->FindSubControl(_T("1994")));
		
		pLis1t->SetText(_T("123"));
	}

	return TRUE;
}