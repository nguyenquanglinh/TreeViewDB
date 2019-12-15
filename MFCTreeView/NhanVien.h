#pragma once
class NhanVien
{
private:
	int maNV=NULL;
	CString tenNV=NULL;
	int maPb=NULL;
public:
	NhanVien();
	~NhanVien();
	NhanVien(int maNV,CString tenNV,int maPB);
	NhanVien(int maNV, CString tenNV);
	void SetTenNV(CString tenNV);
	void SetMaNV(int maNV);
	void SetMaPB(int maNV);
	CString GetTenNV();
	int GetMaNV();
	CString toString();
	int GetMaPb();
};

