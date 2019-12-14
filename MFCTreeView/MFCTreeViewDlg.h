
// MFCTreeViewDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "ADOConnection.h"


// CMFCTreeViewDlg dialog
class CMFCTreeViewDlg : public CDialogEx
{
// Construction
public:
	CMFCTreeViewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTREEVIEW_DIALOG };
#endif
private:
	ADOConnection dbFile;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void AddNode(vector<PhongBan> pb);
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_CarTree;
	CButton btnConnect;
	afx_msg void OnBnClickedBtnconnect();
};
