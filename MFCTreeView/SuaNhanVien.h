#pragma once
#include"NhanVien.h"
#include "afxwin.h"

// SuaNhanVien dialog

class SuaNhanVien : public CDialogEx
{
	DECLARE_DYNAMIC(SuaNhanVien)

public:
	SuaNhanVien(CWnd* pParent = NULL);   // standard constructor
	virtual ~SuaNhanVien();
	void SetText(NhanVien nv);
	NhanVien nv;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGSuaNhanVien };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	bool GetMaNV();

	bool GetMaPB();

	DECLARE_MESSAGE_MAP()
public:
	CEdit maNV;
	CEdit tenNV;
	CEdit maPB;
	afx_msg void OnBnClickedOk();
};
