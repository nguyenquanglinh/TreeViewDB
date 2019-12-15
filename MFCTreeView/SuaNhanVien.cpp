// SuaNhanVien.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTreeView.h"
#include "SuaNhanVien.h"
#include "afxdialogex.h"


// SuaNhanVien dialog

IMPLEMENT_DYNAMIC(SuaNhanVien, CDialogEx)

SuaNhanVien::SuaNhanVien(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGSuaNhanVien, pParent)
{

}

SuaNhanVien::~SuaNhanVien()
{
}

void SuaNhanVien::SetText(NhanVien nv)
{
	CString a;
	a.Format(_T("%d"), nv.GetMaNV());
	maNV.SetWindowTextW(a);
	tenNV.SetWindowTextW(nv.GetTenNV());
	if (nv.GetMaPb() == NULL)
		maPB.SetWindowTextW(_T("NULL"));
	else
	{
		a.Format(_T("%d"), nv.GetMaPb());
		maPB.SetWindowTextW(a);
	}

}

void SuaNhanVien::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_manv, maNV);
	DDX_Control(pDX, IDC_EDIT_ten, tenNV);
	DDX_Control(pDX, IDC_EDIT_mapb, maPB);
}


BEGIN_MESSAGE_MAP(SuaNhanVien, CDialogEx)
	ON_BN_CLICKED(IDOK, &SuaNhanVien::OnBnClickedOk)
END_MESSAGE_MAP()


// SuaNhanVien message handlers
bool SuaNhanVien::GetMaNV() {
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

bool SuaNhanVien::GetMaPB() {
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

void SuaNhanVien::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	if (GetMaNV() == true && GetMaPB() == true) {
		CString ten;
		tenNV.GetWindowTextW(ten);
		nv.SetTenNV(ten);
		CDialogEx::OnOK();
	}
}
