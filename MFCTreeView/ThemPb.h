#pragma once
#include"PhongBan.h"
#include "afxwin.h"

// ThemPb dialog

class ThemPb : public CDialogEx
{
	DECLARE_DYNAMIC(ThemPb)

public:
	ThemPb(CWnd* pParent = NULL);   // standard constructor
	virtual ~ThemPb();
	PhongBan pb;
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		bool GetMaPB();
	void OnBnClickedOk();
	CEdit maPb;
	CEdit tenPB;
};
