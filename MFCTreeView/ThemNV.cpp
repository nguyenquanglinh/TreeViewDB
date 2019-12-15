// ThemNV.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTreeView.h"
#include "ThemNV.h"
#include "afxdialogex.h"


// ThemNV dialog

IMPLEMENT_DYNAMIC(ThemNV, CDialogEx)


ThemNV::ThemNV(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGThemNhanVien, pParent)
{

}

ThemNV::~ThemNV()
{
}

void ThemNV::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_manv, maNV);
	DDX_Control(pDX, IDC_EDIT_ten, tenNV);
	DDX_Control(pDX, IDC_EDIT_mapb, maPB);
}


BEGIN_MESSAGE_MAP(ThemNV, CDialogEx)
	ON_BN_CLICKED(IDOK, &ThemNV::OnBnClickedOk)
END_MESSAGE_MAP()


// ThemNV message handlers
bool ThemNV::GetMaNV() {
	try
	{
		CString manv;
		maNV.GetWindowTextW(manv);
		nv.SetMaNV(_ttoi(manv));
		return true;
	}
	catch (int x)
	{
		MessageBox(_T("Mã không hợp lệ "), _T("Thông báo"), MB_OK);
		return false;
	}

}

bool ThemNV::GetMaPB() {
	try
	{
		CString mapb;
		maPB.GetWindowTextW(mapb);
		nv.SetMaPB(_ttoi(mapb));
		return true;
	}
	catch (int x)
	{
		MessageBox(_T("Mã không hợp lệ "), _T("Thông báo"), MB_OK);
		return false;
	}
}

void ThemNV::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	if (GetMaNV()==true && GetMaPB()==true) {
		CString ten;
		tenNV.GetWindowTextW(ten);
		nv.SetTenNV(ten);
		CDialogEx::OnOK();
	}
	
}
