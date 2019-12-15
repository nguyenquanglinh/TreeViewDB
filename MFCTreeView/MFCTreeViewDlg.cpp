
// MFCTreeViewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTreeView.h"
#include "MFCTreeViewDlg.h"
#include "afxdialogex.h"
#include"SuaPB.h"
#include"SuaNhanVien.h"



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
	DDX_Control(pDX, IDC_LISTValue, myListView);
}

BEGIN_MESSAGE_MAP(CMFCTreeViewDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BTNConnect, &CMFCTreeViewDlg::OnBnClickedBtnconnect)
	ON_NOTIFY(NM_CLICK, IDC_CAR_TREE, &CMFCTreeViewDlg::OnNMClickCarTree)
	ON_NOTIFY(NM_RCLICK, IDC_CAR_TREE, &CMFCTreeViewDlg::OnNMRClickCarTree)
	ON_NOTIFY(HDN_ITEMDBLCLICK, 0, &CMFCTreeViewDlg::OnHdnItemdblclickListvalue)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LISTValue, &CMFCTreeViewDlg::OnLvnItemchangedListvalue)
	ON_BN_CLICKED(IDC_BUTTONThem, &CMFCTreeViewDlg::OnBnClickedButtonthem)
	ON_BN_CLICKED(IDC_btnSua, &CMFCTreeViewDlg::OnBnClickedbtnsua)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CMFCTreeViewDlg::OnHdnItemclickListvalue)
	ON_NOTIFY(NM_CLICK, IDC_LISTValue, &CMFCTreeViewDlg::OnNMClickListvalue)
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

void CMFCTreeViewDlg::AddTablePhongBan(vector<PhongBan>dsPb) {
	ClearTable();
	myListView.InsertColumn(0, _T("Mã phòng ban"), LVCFMT_LEFT, 90);
	myListView.InsertColumn(1, _T("Tên Phòng ban"), LVCFMT_RIGHT, 90);
	myListView.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	//myListView.SetExtendedStyle(LVS_EX_GRIDLINES);
	CString a;
	for each (PhongBan pb in dsPb)
	{
		a.Format(_T("%d"), pb.GetMaPB());
		int nIndex = myListView.InsertItem(0, a);
		myListView.SetItemText(nIndex, 1, pb.GetTenPB());
	}
}

int CMFCTreeViewDlg::GetCheDo() {
	int count = GetCount();
	if (count == 2) return 1;
	return 2;
}

int CMFCTreeViewDlg::GetCount() {
	HWND hWndHdr = (HWND)::SendMessage(myListView, LVM_GETHEADER, 0, 0);
	return (int)::SendMessage(hWndHdr, HDM_GETITEMCOUNT, 0, 0L);
}

void CMFCTreeViewDlg::ClearTable() {
	myListView.DeleteAllItems();
	int count = GetCount();
	while (count != 0)
	{
		myListView.DeleteColumn(0);
		count--;
		if (count == 0) {

			count = GetCount();
		}
	}
}

void CMFCTreeViewDlg::AddTableNV(vector<NhanVien>dsNv) {
	ClearTable();
	myListView.InsertColumn(0, _T("Mã nhân viên"), LVCFMT_LEFT, 90);
	myListView.InsertColumn(1, _T("Tên nhân viên"), LVCFMT_CENTER, 90);
	myListView.InsertColumn(2, _T("Mã Phòng ban"), LVCFMT_RIGHT, 90);
	myListView.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	/*myListView.SetExtendedStyle(LVS_EX_GRIDLINES);*/
	//myListView.SetExtendedStyle(myListViewGetExtendedStyle() | LVS_EX_FULLROWSELECT);
	CString a;
	for each (NhanVien nv in dsNv)
	{
		a.Format(_T("%d"), nv.GetMaNV());
		int nIndex = myListView.InsertItem(0, a);
		myListView.SetItemText(nIndex, 1, nv.GetTenNV());
		a.Format(_T("%d"), nv.GetMaPb());
		myListView.SetItemText(nIndex, 2, a);
	}

}

void CMFCTreeViewDlg::AddNode(vector<PhongBan> dsPb) {
	for each (PhongBan pb in dsPb)
	{
		hCar = m_CarTree.InsertItem(pb.toString(), hItem);
		for each (NhanVien nv in dbFile.GetDsNhanVienFromPhongBan(pb))
		{
			m_CarTree.InsertItem(nv.toString(), hCar);
		}
	}

	AddTablePhongBan(dsPb);
}

void CMFCTreeViewDlg::OnBnClickedBtnconnect()
{
	CString a;
	btnConnect.GetWindowTextW(a);
	if (a == _T("Connect"))
	{
		if (dbFile.Connect()) {
			hItem = m_CarTree.InsertItem(_T("BKav"), TVI_ROOT);
			MessageBox(_T("Mo ket noi thanh cong"), _T("thong bao connet"), MB_OK);
			btnConnect.SetWindowTextW(_T("disconnect"));
		}
	}
	else
	{
		CDialogEx::OnOK();
	}
}

void  CMFCTreeViewDlg::Update() {
	m_CarTree.DeleteItem(hItem);
	hItem = m_CarTree.InsertItem(_T("BKav"), TVI_ROOT);
	AddNode(dbFile.GetDsPhongBan());
}

void CMFCTreeViewDlg::OnNMClickCarTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	HTREEITEM nodSelected = m_CarTree.GetSelectedItem();
	CString strSelected = m_CarTree.GetItemText(nodSelected);
	HTREEITEM nodParentLeague = m_CarTree.GetParentItem(nodSelected);
	CString strParentLeague = m_CarTree.GetItemText(nodParentLeague);
	if (strSelected == _T(""))
	{
		Update();
	}

	else
	{
		if (strSelected == _T("BKav"))AddTablePhongBan(dbFile.GetDsPhongBan());
		int x = strSelected.Find(_T("PB"));
		if (x == 0)
		{
			CString tenLop = strSelected.Tokenize(_T(" "), x);
			CString mapb = strSelected.Tokenize(_T(" "), x);
			int ma = _ttoi(mapb);
			CString dauNgang = strSelected.Tokenize(_T(" "), x);
			CString tenPB = strSelected.Tokenize(_T(" "), x);
			AddTableNV(dbFile.GetDsNhanVienFromPhongBan(PhongBan(ma, tenPB)));
		}
	}
}

void CMFCTreeViewDlg::OnNMRClickCarTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	CTreeCtrl & tc = m_CarTree;
	MessageBox(_T("Click"), _T("Thong bao"), MB_OK);
	//*Get the cursor position for this message *
	DWORD dwPos = GetMessagePos();
	//*Convert the co - ords into a CPoint structure *
	CPoint pt(GET_X_LPARAM(dwPos), GET_Y_LPARAM(dwPos));
	CPoint spt;
	spt = pt;
	//*convert to screen co - ords for the hittesting to work *
	tc.ScreenToClient(&spt);
	UINT test;
	HTREEITEM hti = tc.HitTest(spt, &test);
	if (hti != NULL)
	{
		//*Is the click atcually *on* the item ? *
		if (test & TVHT_ONITEM)
		{
			MessageBox(_T("HTREEITEM click"), _T("thong bao"), MB_OK);
		}
	}

	*pResult = 0;
}



void CMFCTreeViewDlg::OnLvnItemchangedListvalue(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CMFCTreeViewDlg::OnBnClickedButtonthem()
{
	// TODO: Add your control notification handler code here
	if (GetCheDo() == 1) {//có 2 cột=>bảng pb
		SuaPB pb;
		pb.DoModal();
		if (pb.pb.GetMaPB() != NULL)
		{
			//dbFile.InsertIntoPhongBan(pb.pb);
			Update();
		}

		/*dbFile.InsertIntoPhongBan(PhongBan());*/
	}
	else
	{//them ơ bang nhan vien;
		ThemNV nv;
		nv.DoModal();
		if (nv.nv.GetMaNV() != NULL)
		{
			dbFile.InsertIntoNhanVien(nv.nv);
			Update();
		}
	}
}

void CMFCTreeViewDlg::OnBnClickedbtnsua()
{
	// TODO: Add your control notification handler code here
	if (GetCheDo() == 1) {//có 2 cột=>bảng pb
		SuaPB pb;
		pb.DoModal();
		if (pb.pb.GetMaPB() != NULL)
		{
			dbFile.InsertIntoPhongBan(pb.pb);
			Update();
		}

		/*dbFile.InsertIntoPhongBan(PhongBan());*/
	}
	else
	{//them ơ bang nhan vien;
		SuaNhanVien nv;
		nv.DoModal();
		if (nv.nv.GetMaNV() != NULL)
		{
			dbFile.InsertIntoNhanVien(nv.nv);
			Update();
		}
	}
}


void CMFCTreeViewDlg::OnHdnItemclickListvalue(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	HTREEITEM nodSelected = m_CarTree.GetSelectedItem();
	CString strSelected = m_CarTree.GetItemText(nodSelected);
	HTREEITEM nodParentLeague = m_CarTree.GetParentItem(nodSelected);
	CString strParentLeague = m_CarTree.GetItemText(nodParentLeague);

	POSITION pos = myListView.GetFirstSelectedItemPosition();
	int nItem = 0;
	if (pos == NULL)
		TRACE0("No items were selected!\n");
	else
	{
		while (pos)
		{
			int nItem = myListView.GetNextSelectedItem(pos);
			TRACE1("Item %d was selected!\n", nItem);
			// you could do your own processing on nItem here
		}
	}
	/*CString strSelected = myListView.GetItem()*/
	TCHAR szBuffer[1024];
	DWORD cchBuf(1024);
	LVITEM lvi;
	lvi.iItem = nItem;
	lvi.iSubItem = 0;
	lvi.mask = LVIF_TEXT;
	lvi.pszText = szBuffer;
	lvi.cchTextMax = cchBuf;
	myListView.GetItem(&lvi);
	*pResult = 0;
}

void CMFCTreeViewDlg::OnHdnItemdblclickListvalue(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: Add your control notification handler code here
	CMenu submenu;
	submenu.CreatePopupMenu();
	submenu.AppendMenuW(MF_STRING, IDD_MFCTREEVIEW_DIALOG, _T("xin chao"));

	/*submenu.AppendMenuW(MF_STRING, myListView, L"&Copy");
	submenu.AppendMenuW(MF_SEPARATOR);
	submenu.AppendMenuW(MF_STRING, myListView, L"&Delete");
	submenu.AppendMenuW(MF_POPUP, reinterpret_cast<UINT_PTR>(submenu.m_hMenu), L"");*/

	submenu.Detach();
	*pResult = 0;
}

void CMFCTreeViewDlg::OnNMClickListvalue(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	POSITION pos = myListView.GetFirstSelectedItemPosition();
	int selected = -1;
	if (pos != NULL)
	{
		while (pos)
		{
			int nItem = myListView.GetNextSelectedItem(pos);
			selected = nItem + 1;
		}
	}
	DWORD_PTR  xxx = myListView.GetItemData(selected);
	TCHAR szBuffer[1024];
	DWORD cchBuf(1024);
	LVITEM lvi;
	lvi.iItem = selected;
	lvi.iSubItem = 0;
	lvi.mask = LVIF_TEXT;
	lvi.pszText = szBuffer;
	lvi.cchTextMax = cchBuf;
	myListView.GetItem(&lvi);
	//returns -1 if not selected;
	/*int nItem = m_CarTree.GetNextSelectedItem(pos);
	selected = nItem + 1;*/
	*pResult = 0;
}
