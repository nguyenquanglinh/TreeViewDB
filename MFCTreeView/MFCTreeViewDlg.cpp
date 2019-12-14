
// MFCTreeViewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTreeView.h"
#include "MFCTreeViewDlg.h"
#include "afxdialogex.h"
#include"ADOConnection.h"
#include "NhanVien.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCTreeViewDlg dialog

CMFCTreeViewDlg::CMFCTreeViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCTREEVIEW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTreeViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CAR_TREE, m_CarTree);
	DDX_Control(pDX, IDC_BTNConnect, btnConnect);
}

BEGIN_MESSAGE_MAP(CMFCTreeViewDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BTNConnect, &CMFCTreeViewDlg::OnBnClickedBtnconnect)
END_MESSAGE_MAP()


// CMFCTreeViewDlg message handlers

BOOL CMFCTreeViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here



	//return TRUE; // return TRUE unless you set the focus to a control
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCTreeViewDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCTreeViewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCTreeViewDlg::AddNode(vector<PhongBan> pb) {
	HTREEITEM hItem, hCar;
	hItem = m_CarTree.InsertItem(_T("BKav"), TVI_ROOT);
	for each (PhongBan pb in pb)
	{
		hCar = hItem = m_CarTree.InsertItem(pb.toString());
		for each (NhanVien nv in dbFile.GetDsNhanVienFromPhongBan(pb))
		{
			m_CarTree.InsertItem(nv.toString(), hCar);
		}
	}
	/*hItem = m_CarTree.InsertItem(_T("BKav"), TVI_ROOT);
	hCar = m_CarTree.InsertItem(_T("Economy"), hItem);
	m_CarTree.InsertItem(_T("BH-733"), hCar);
	m_CarTree.InsertItem(_T("SD-397"), hCar);
	m_CarTree.InsertItem(_T("JU-538"), hCar);
	m_CarTree.InsertItem(_T("DI-285"), hCar);
	m_CarTree.InsertItem(_T("AK-830"), hCar);
	hCar = m_CarTree.InsertItem(_T("Compact"), hItem);
	m_CarTree.InsertItem(_T("HG-490"), hCar);
	m_CarTree.InsertItem(_T("PE-473"), hCar);
	hCar = m_CarTree.InsertItem(_T("Standard"), hItem);
	m_CarTree.InsertItem(_T("SO-398"), hCar);
	m_CarTree.InsertItem(_T("DF-438"), hCar);
	m_CarTree.InsertItem(_T("IS-833"), hCar);
	hCar = m_CarTree.InsertItem(_T("Full Size"), hItem);
	m_CarTree.InsertItem(_T("PD-304"), hCar);
	hCar = m_CarTree.InsertItem(_T("Mini Van"), hItem);
	m_CarTree.InsertItem(_T("ID-497"), hCar);
	m_CarTree.InsertItem(_T("RU-304"), hCar);
	m_CarTree.InsertItem(_T("DK-905"), hCar);
	hCar = m_CarTree.InsertItem(_T("SUV"), hItem);
	m_CarTree.InsertItem(_T("FE-948"), hCar);
	m_CarTree.InsertItem(_T("AD-940"), hCar);
	hCar = m_CarTree.InsertItem(_T("Truck"), hItem);
	m_CarTree.InsertItem(_T("HD-394"), hCar);*/
}



void CMFCTreeViewDlg::OnBnClickedBtnconnect()
{
	// TODO: Add your control notification handler code here

	//connect


	/*CString x = aa == true ? _T("dung") : _T("sai");
	MessageBox(x, _T("thong bao connet"), MB_OK);*/
	if (dbFile.Connect()) {
		AddNode(dbFile.GetDsPhongBan());
		MessageBox(_T("Mo ket noi thanh cong"), _T("thong bao connet"), MB_OK);

	}
	//pb

	//aa = a.InsertIntoPhongBan(PhongBan(1, _T("pb")));
	//x = aa == true ? _T("dung") : _T("sai");
	//MessageBox(x, _T("thong bao them"), MB_OK);
	//aa = a.UpdatePhongBan(PhongBan(1, _T("pb")), PhongBan(2, _T("pb")));
	//x = aa == true ? _T("dung") : _T("sai");
	//MessageBox(x, _T("thong bao update"), MB_OK);
	//aa = a.DeletePhongBan(PhongBan(2, _T("pb")));
	//x = aa == true ? _T("dung") : _T("sai");
	//MessageBox(x, _T("thong bao xoa"), MB_OK);

	////nhan vien
	//aa = a.InsertIntoNhanVien(NhanVien(1, _T("nguyen van a")));
	//x = aa == true ? _T("dung") : _T("sai");
	//MessageBox(x, _T("thong bao them"), MB_OK);
	//aa = a.UpdateNhanvVien(NhanVien(1, _T("nguyen van a")), NhanVien(2, _T("nguyen van a")));
	//x = aa == true ? _T("dung") : _T("sai");
	//MessageBox(x, _T("thong bao update"), MB_OK);
	//aa = a.DeleteNhanVien(NhanVien(2, _T("nguyen van b")));
	//x = aa == true ? _T("dung") : _T("sai");
	//MessageBox(x, _T("thong bao xoa"), MB_OK);
}
