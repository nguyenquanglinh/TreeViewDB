create database [Bkav]
go
USE [Bkav]
GO
/****** Object:  Table [dbo].[NhanVien]    Script Date: 12/16/2019 12:38:21 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[NhanVien](
	[MaNV] [int] NOT NULL,
	[TenNV] [nvarchar](50) NULL,
	[MaPb] [int] NULL,
 CONSTRAINT [PK_NhanVien] PRIMARY KEY CLUSTERED 
(
	[MaNV] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[PhongBan]    Script Date: 12/16/2019 12:38:21 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PhongBan](
	[MaPb] [int] NOT NULL,
	[TenPB] [nvarchar](50) NULL,
 CONSTRAINT [PK_PhongBan] PRIMARY KEY CLUSTERED 
(
	[MaPb] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
INSERT [dbo].[NhanVien] ([MaNV], [TenNV], [MaPb]) VALUES (1, N'1', 1)
INSERT [dbo].[NhanVien] ([MaNV], [TenNV], [MaPb]) VALUES (2, N'2', 1)
INSERT [dbo].[NhanVien] ([MaNV], [TenNV], [MaPb]) VALUES (3, N'3', 2)
INSERT [dbo].[NhanVien] ([MaNV], [TenNV], [MaPb]) VALUES (4, N'4', 2)
INSERT [dbo].[NhanVien] ([MaNV], [TenNV], [MaPb]) VALUES (5, N'5', 3)
INSERT [dbo].[NhanVien] ([MaNV], [TenNV], [MaPb]) VALUES (6, N'6', 3)
INSERT [dbo].[NhanVien] ([MaNV], [TenNV], [MaPb]) VALUES (7, N'7', 4)
INSERT [dbo].[NhanVien] ([MaNV], [TenNV], [MaPb]) VALUES (8, N'8', 4)
INSERT [dbo].[NhanVien] ([MaNV], [TenNV], [MaPb]) VALUES (11, N'11', 5)
INSERT [dbo].[PhongBan] ([MaPb], [TenPB]) VALUES (1, N'pb1')
INSERT [dbo].[PhongBan] ([MaPb], [TenPB]) VALUES (2, N'pb2')
INSERT [dbo].[PhongBan] ([MaPb], [TenPB]) VALUES (3, N'pb3')
INSERT [dbo].[PhongBan] ([MaPb], [TenPB]) VALUES (4, N'pb4')
INSERT [dbo].[PhongBan] ([MaPb], [TenPB]) VALUES (5, N'kinh doanh')
ALTER TABLE [dbo].[NhanVien]  WITH CHECK ADD  CONSTRAINT [FK_NhanVien_PhongBan] FOREIGN KEY([MaPb])
REFERENCES [dbo].[PhongBan] ([MaPb])
ON DELETE SET NULL
GO
ALTER TABLE [dbo].[NhanVien] CHECK CONSTRAINT [FK_NhanVien_PhongBan]
GO
