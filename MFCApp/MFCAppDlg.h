
// MFCAppDlg.h: 头文件
//

#pragma once
#include "MyClass.h"
// CMFCAppDlg 对话框
#include "SerialPort.h"
#include "SerialPortInfo.h"
using namespace itas109;

class CMFCAppDlg : public CDialogEx
{
// 构造
public:
	CMFCAppDlg(CWnd* pParent = nullptr);	// 标准构造函数
	MyClass pFrame;//duilib
	CSerialPort m_SerialPort;//串口
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
