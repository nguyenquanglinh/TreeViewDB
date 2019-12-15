#include "ThemNhanVien.h"

BEGIN_MESSAGE_MAP(ThemNhanVien, CDialogEx)
	ON_BN_CLICKED(IDOK, &ThemNhanVien::OnBnClickedOk)
END_MESSAGE_MAP()


void ThemNhanVien::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
