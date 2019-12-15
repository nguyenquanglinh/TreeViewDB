
// MFCTreeViewDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "ADOConnection.h"
#include "NhanVien.h"
#include"stdlib.h"
#include"ThemPb.h"
#include"ThemNV.h"


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
	HTREEITEM hItem, hCar;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void AddTablePhongBan(vector<PhongBan> nv);
	int GetCheDo();
	int GetCount();
	void ClearTable();
	void AddTableNV(vector<NhanVien> dsNv);
	void AddNode(vector<PhongBan> pb);
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_CarTree;
	CButton btnConnect;
	afx_msg void OnBnClickedBtnconnect();
	void Update();
	afx_msg void OnNMClickCarTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickCarTree(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl myListView;
	afx_msg void OnHdnItemdblclickListvalue(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedListvalue(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonthem();
	afx_msg void OnBnClickedbtnsua();
	afx_msg void OnHdnItemclickListvalue(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickListvalue(NMHDR *pNMHDR, LRESULT *pResult);
};
