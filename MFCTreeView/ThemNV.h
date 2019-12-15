#pragma once
#include"NhanVien.h"
#include "afxwin.h"
// ThemNV dialog

class ThemNV : public CDialogEx
{
	DECLARE_DYNAMIC(ThemNV)

public:
	ThemNV(CWnd* pParent = NULL);   // standard constructor
	virtual ~ThemNV();
	NhanVien nv;
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
	bool GetMaNV();
	bool GetMaPB();
	void OnBnClickedOk();
	CEdit maNV;
	CEdit tenNV;
	CEdit maPB;
};
