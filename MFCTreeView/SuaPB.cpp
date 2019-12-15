// SuaPB.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTreeView.h"
#include "SuaPB.h"
#include "afxdialogex.h"


// SuaPB dialog

IMPLEMENT_DYNAMIC(SuaPB, CDialogEx)

SuaPB::SuaPB(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGSuaPhongBan, pParent)
{
	
}

SuaPB::~SuaPB()
{
}

void SuaPB::SetText(PhongBan pb)
{
	CString ma;
	ma.Format(_T("%d"), pb.GetMaPB());
	maPb.SetWindowTextW(ma);
	tenPb.SetWindowTextW(pb.GetTenPB());
	UpdateData(true);
}

void SuaPB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ma, maPb);
	DDX_Control(pDX, IDC_EDIT_ten, tenPb);
}

BEGIN_MESSAGE_MAP(SuaPB, CDialogEx)
	ON_BN_CLICKED(IDOK, &SuaPB::OnBnClickedOk)
END_MESSAGE_MAP()


// SuaPB message handlers

bool SuaPB::GetMaPB() {
	try
	{
		CString ma;
		maPb.GetWindowTextW(ma);
		pb.SetMaPB(_ttoi(ma));
		return true;
	}
	catch (const std::exception&)
	{
		MessageBox(_T("Mã phòng ban không hợp lệ"), _T("Thông báo"), MB_OK);
		return false;
	}
}

void SuaPB::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	if (GetMaPB() == true) {
		CString  ten;
		tenPb.GetWindowTextW(ten);
		pb.SetTenPb(ten);
		CDialogEx::OnOK();
	}
}
