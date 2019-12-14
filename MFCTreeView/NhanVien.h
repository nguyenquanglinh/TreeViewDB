#pragma once
class NhanVien
{
private:
	int maNV;
	CString tenNV;
	int maPb=NULL;
public:
	NhanVien();
	~NhanVien();
	NhanVien(int maNV,CString tenNV,int maPB);
	NhanVien(int maNV, CString tenNV);
	void SetTenNV(CString tenNV);
	void SetMaNV(int maNV);
	CString GetTenNV();
	int GetMaNV();
	CString toString();
};

