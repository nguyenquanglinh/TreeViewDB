// ThemPb.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTreeView.h"
#include "ThemPb.h"
#include "afxdialogex.h"


// ThemPb dialog

IMPLEMENT_DYNAMIC(ThemPb, CDialogEx)

ThemPb::ThemPb(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGThemNhanVien, pParent)
{

}

ThemPb::~ThemPb()
{
}

void ThemPb::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ma, maPb);
	DDX_Control(pDX, IDC_EDIT_ten, tenPB);
}


BEGIN_MESSAGE_MAP(ThemPb, CDialogEx)
	ON_BN_CLICKED(IDOK, &ThemPb::OnBnClickedOk)
END_MESSAGE_MAP()


// ThemPb message handlers
bool ThemPb::GetMaPB() {
	try
	{
		CString ma;
		maPb.GetWindowTextW(ma);
		pb.SetMaPB(_ttoi(ma));
		return true;
	}
	catch (int x)
	{
		MessageBox(_T("Mã phòng ban không hợp lệ"), _T("Thông báo"), MB_OK);
		return false;
	}
}

void ThemPb::OnBnClickedOk()
{
	if (GetMaPB() == true) {
		CString  ten;
		tenPB.GetWindowTextW(ten);
		pb.SetTenPb(ten);
		CDialogEx::OnOK();
	}

}
