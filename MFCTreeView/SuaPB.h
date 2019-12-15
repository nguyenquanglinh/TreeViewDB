#pragma once
#include"PhongBan.h"
#include "afxwin.h"

// SuaPB dialog

class SuaPB : public CDialogEx
{
	DECLARE_DYNAMIC(SuaPB)

public:
	SuaPB(CWnd* pParent = NULL);   // standard constructor
	virtual ~SuaPB();
	void SetText(PhongBan pb);
	PhongBan pb;
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGSuaPhongBan };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit maPb;
	CEdit tenPb;
	afx_msg
		bool GetMaPB();
	void OnBnClickedOk();
};
