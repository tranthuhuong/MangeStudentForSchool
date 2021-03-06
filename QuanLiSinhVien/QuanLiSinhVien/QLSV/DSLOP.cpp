﻿#include "DSLOP.h"

DSLOP::DSLOP()
{
	SL = 0;
}

void DSLOP::nhapDSLOP()
{
	gotoxy(71, 2);
	setGreenText();
	cout << "NHAP DANH SACH LOP";
	for (int i = 0; i < 100; ++i)
	{
		char MLOP[15];
		char TENL[38];
		int NH;
		char c_NH[5];
		MLOP[0] = '\0';
		TENL[0] = '\0';
		c_NH[0] = '\0';
		setNormallText();

		//Xoa thong tin lop vua nhap
		for (int i = 0; i < 70; ++i)
		{
			SetColor(0);
			gotoxy(MINX_BLOP + i, MINY_BLOP + 4);
			cout << " ";
		}

		setNormallText();
		veKhungNhapTTLop();
	NHAPTTLOP:
		//Nếu MLOP rỗng thì trả về 0 nếu lớp hợp lệ, -1 nếu chuỗi rỗng
	int check1 = NhapChuoiVaChuSo(MLOP, 15, MINX_BLOP + 2, MINY_BLOP + 4);
		if (check1 == 0)
		{
			//Kiểm tra lớp có tồn tại không, nếu không tồn tại trả về -1
			if (searchLOP(MLOP) == -1)
			{
			NHAPTENLOP:
				//Nhập tên lớp, không cho phép rỗng
				int check2 = NhapChuoi(TENL, 38, xCot1 + 2, MINY_BLOP + 4);
				if (check2 == ESC)
				{
					char title[10] = "THONG BAO";
					char message[30] = "Ban co muon thoat?";
					char td[2][10] = { "    Co", "    Khong" };
					gotoxy(MINX_ALERTTB, MINY_ALERTNL);
					int check2 = veKhungThongBao(title, message, td);
					if (check2 == 0)
					{
						return;
					}
					else if (check2 == 1)
					{
						xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
						goto NHAPTENLOP;
					}
				}
				//Get năm hiện tại
				int namHienTai = getNamHienTai();
				do
				{
					//Nhập năm học
				NHAPNAMHOC:
					int check3 = NhapSo(c_NH, 4, xCot2 + 3, MINY_BLOP + 4);
					if (check3 == ESC)
					{
						char title[10] = "THONG BAO";
						char message[30] = "Ban co muon thoat?";
						char td[2][10] = { "    Co", "    Khong" };
						gotoxy(MINX_ALERTTB, MINY_ALERTNL);
						int check2 = veKhungThongBao(title, message, td);
						if (check2 == 0)
						{
							return;
						}
						else if (check2 == 1)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
							goto NHAPNAMHOC;
						}
					}
					NH = atoi(c_NH);
					/*
						năm học phải <= năm hiện tại
						Nếu năm học lớn hơn năm hiện tại hiện bảng thông báo cho người dùng
						cho họ chọn sửa lại hoặc thoát khỏi chức năng
					*/

					if (NH > namHienTai)
					{
						char title[10] = "THONG BAO";
						char message[30] = "Nam hoc khong hop le!";
						char td[2][10] = { "Chinh sua", "    Thoat" };
						gotoxy(MINX_ALERTTB, MINY_ALERTNL);
						int check2 = veKhungThongBao(title, message, td);
						//Nguoi dung chon chinh sua noi dung bi trung
						if (check2 == 0)
						{
							//Xóa bảng thông báo vừa in ra
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
						}
						else if (check2 == -1)
						{
							return;
						}
					}
				} while (NH > namHienTai);

				DANHSACHLOP[SL].nhapLOP(MLOP, TENL, NH);
				SL++;
			}
			else
			{
				char title[10] = "THONG BAO";
				char message[30] = "Ma lop ban nhap bi trung?";
				char td[2][10] = { "Chinh sua", "    Thoat" };
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int check2 = veKhungThongBao(title, message, td);
				//Nguoi dung chon chinh sua noi dung bi trung
				if (check2 == 0)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					//Quay lại cho người dung chỉnh sửa thông tin bị trùng
					goto NHAPTTLOP;
				}
				else if (check2 == 1)
				{
					break;
				}
			}
		}
		else if (check1 == ESC || check1 == -1)
		{
			char title[10] = "THONG BAO";
			char message[30] = "Ban co muon thoat?";
			char td[2][10] = { "    Co", "    Khong" };
			gotoxy(MINX_ALERTTB, MINY_ALERTNL);
			int check2 = veKhungThongBao(title, message, td);
			if (check2 == 0)
			{
				return;
			}
			else if (check2 == 1)
			{
				xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
				goto NHAPTTLOP;
			}

		}
	}
}

void DSLOP::inLOPTheoHang(LOP lop, int y, int stt)
{
	char MAL[15];
	char TENL[50];
	lop.getMALOP(MAL);
	lop.getTENLOP(TENL);

	gotoxy(MINX_XLOP + 3, y);
	cout << stt;
	gotoxy(X_XLOP_COT1 + 2, y);
	cout << MAL;
	gotoxy(X_XLOP_COT2 + 3, y);
	cout << TENL;
	gotoxy(X_XLOP_COT3 + 2, y);
	cout << lop.getNH();
}

void DSLOP::xuatDSLOPNK()
{
	int TSTrang;
	int trangHT = 1;
	char c_NH[5];  // Luu nam hoc
	c_NH[0] = '\0';
	int NH;

	gotoxy(72, 2);
	setGreenText();
	cout << "IN DANH SACH LOP";
	normal();
	char title[] = "THONG BAO";
	char message[] = "Nhap nam hoc de in danh sach";
	//Lấy năm hiện tại
	int namHT = getNamHienTai();
	bool flat = false;
	do {
		gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
		veTextField(c_NH, title, message);
		gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
		for (int i = 0; i < widthAlert - 4; ++i)
		{
			cout << " ";
		}
		NH = atoi(c_NH);

		if (NH > namHT)
		{
			gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
			SetColor(red_hightlight);
			cout << " Nam hoc khong hop le!";
			continue;
		}

		flat = false;
		for (int i = 0; i < SL; ++i)
		{
			if (NH == DANHSACHLOP[i].getNH())
			{
				flat = true;
				break;
			}
		}

		if (flat == false)
		{
			gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
			SetColor(red_hightlight);
			cout << " Khong tim duoc lop!";
		}
	} while (NH > namHT || flat == false);
	Sleep(100);

	//Xóa TextField
	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);

	gotoxy(73, 3);
	cout << "NAM HOC: " << c_NH;
	veKhungXuatLopTheoNK();

	//Thuc hien chuc nang
	//Luu tong so LOP thoa dieu kien
	int stt = 0;
	//Mảng chiSo dùng để lưu chỉ số các phan tu trong mang DANHSACHLOP có năm nhap hoc = nam do do nguoi dung nhap
	int chiSo[100];
	for (int i = 0; i < SL; ++i)
	{
		if (NH == DANHSACHLOP[i].NAMHOC)
		{
			chiSo[stt++] = i;
			if (stt <= 10)
			{
				inLOPTheoHang(DANHSACHLOP[i], Y_FIST_LOP + stt - 1, stt);
			}
		}
	}



	//tinh tong so trang va in ra mang hinh
	if (stt % 10 == 0)
	{
		TSTrang = stt / 10;
	}
	else
	{
		TSTrang = stt / 10 + 1;
	}

	//Chỉ số trong mang chiSo của phần tử đầu tiên trang đang hiển thị
	int firstItem;

	//In trang hien tai / Tong so trang
	gotoxy(X_XLOP_COT3 - 10, MINY_XLOP - 1);
	cout << "Trang: " << trangHT << " / " << TSTrang;

	//Cho biết nếu bấm F2 sẽ vào cột nào để chỉnh sửa (nếu nhấn F5 sẽ giảm 1, F6 sẽ tăng 1)
	int viTriChinhSua = 1;

	int kiTu;
	do {
		kiTu = 0;
		char temp = _getch();
		if (temp == -32 || temp == 0)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}
		switch (kiTu)
		{
		case PageUp:
		{
			if (trangHT > 1)
			{
				xoaNoiDungVe(MINX_XLOP - 1, MINY_XLOP - 1, widthBANG_XLOP, heightBANG_XLOP);
				trangHT--;
				gotoxy(X_XLOP_COT3 - 10, MINY_XLOP - 1);
				cout << "Trang: " << trangHT << " / " << TSTrang;
				veKhungXuatLopTheoNK();
				firstItem = (trangHT - 1) * 10;
				for (int i = 0; i < 10; ++i)
				{
					int k = chiSo[firstItem++];
					inLOPTheoHang(DANHSACHLOP[k], Y_FIST_LOP + i, firstItem);
				}
			}
			break;
		}
		case PageDown:
		{
			if (trangHT < TSTrang)
			{
				xoaNoiDungVe(MINX_XLOP - 1, MINY_XLOP - 1, widthBANG_XLOP + 1, heightBANG_XLOP + 1);
				trangHT++;
				gotoxy(X_XLOP_COT3 - 10, MINY_XLOP - 1);
				cout << "Trang: " << trangHT << " / " << TSTrang;
				veKhungXuatLopTheoNK();
				firstItem = (trangHT - 1) * 10;
				for (int i = 0; i < 10; ++i)
				{
					if (firstItem < stt)
					{
						int k = chiSo[firstItem++];
						inLOPTheoHang(DANHSACHLOP[k], Y_FIST_LOP + i, firstItem);
					}
				}
			}
			break;
		}
		case Enter:
		{
			firstItem = (trangHT - 1) * 10;
			int k = chiSo[firstItem];
			gotoxy(MINX_XLOP + 1, Y_FIST_LOP);
			SetBGColor(green_Dark);
			for (int i = 0; i < widthBANG_XLOP - 2; ++i)
			{
				cout << " ";
			}

			inLOPTheoHang(DANHSACHLOP[k], Y_FIST_LOP, firstItem + 1);

			//Dua con tro ve cuoi MALOP tai vi tri dang chon
			gotoxy(X_XLOP_COT1 + strlen(DANHSACHLOP[k].MALOP) + 2, Y_FIST_LOP);

			int kiTu;
			int viTri = firstItem;
			do
			{
				k = chiSo[viTri];

				char ML[15];
				char TENL[38];
				char namhoc[5];

				ML[0] = '\0';
				TENL[0] = '\0';
				namhoc[0] = '\0';

				DANHSACHLOP[k].getMALOP(ML);
				DANHSACHLOP[k].getTENLOP(TENL);
				itoa(DANHSACHLOP[k].NAMHOC, namhoc, 10);

				kiTu = 0;
				fflush(stdin);
				char temp = _getch();
				if (temp == -32 || temp == 0)
				{
					temp = _getch();
					kiTu = temp + 1000;
				}
				else
				{
					kiTu = temp;
				}
				switch (kiTu)
				{
				case PageDown:
				{
					if (viTri < (firstItem + 9) && viTri < stt - 1)
					{
						k = chiSo[viTri];
						viTriChinhSua = 1;
						//sua noi dung tại dòng cũ
						int y = wherey();
						gotoxy(MINX_XLOP + 1, y);
						SetBGColor(black);
						for (int i = 0; i < widthBANG_XLOP - 2; ++i)
						{
							cout << " ";
						}
						veKhungXuatLopTheoNK();
						inLOPTheoHang(DANHSACHLOP[k], y, viTri + 1);

						//Hight light dòng mới
						//k lúc này sẽ chứa chỉ số dòng mới
						k = chiSo[++viTri];
						
						SetBGColor(green_Dark);
						gotoxy(MINX_XLOP + 1, wherey() + 1);
						for (int i = 0; i < widthBANG_XLOP - 2; ++i)
						{
							cout << " ";
						}
						inLOPTheoHang(DANHSACHLOP[k], wherey(), viTri + 1);
						gotoxy(X_XLOP_COT1 + strlen(DANHSACHLOP[k].MALOP) + 2, Y_FIST_LOP + viTri);
						break;
					}
					else if (trangHT < TSTrang)
					{
	
						viTriChinhSua = 1;
						xoaNoiDungVe(MINX_XLOP - 1, MINY_XLOP - 1, widthBANG_XLOP + 1, heightBANG_XLOP + 1);
						trangHT++;
						gotoxy(X_XLOP_COT3 - 10, MINY_XLOP - 1);
						cout << "Trang: " << trangHT << " / " << TSTrang;
						veKhungXuatLopTheoNK();
						firstItem = (trangHT - 1) * 10;
						viTri = firstItem;
						for (int i = 0; i < 10; ++i)
						{
							if (viTri < stt)
							{
								k = chiSo[viTri++];
								inLOPTheoHang(DANHSACHLOP[k], Y_FIST_LOP + i, viTri);
							}
						}

						//hightLight dong dau tien trang moi
						viTri = firstItem;
						if (viTri < (firstItem + 9) && viTri < stt - 1)
						{
							int y = Y_FIST_LOP;
							k = chiSo[viTri];
							gotoxy(MINX_XLOP + 1, y);
							SetBGColor(green_Dark);
							for (int i = 0; i < widthBANG_XLOP - 2; ++i)
							{
								cout << " ";
							}
							inLOPTheoHang(DANHSACHLOP[k], y, viTri + 1);
							gotoxy(X_XLOP_COT1 + strlen(DANHSACHLOP[k].MALOP) + 2, Y_FIST_LOP + viTri);
						}
					}
					break;
				}
				case PageUp:
				{
					if (viTri > 0 && viTri > firstItem)
					{
						viTriChinhSua = 1;
						//sua noi dung tại dòng cũ
						int y = wherey();
						k = chiSo[viTri];
						gotoxy(MINX_XLOP + 1, y);
						SetBGColor(black);
						for (int i = 0; i < widthBANG_XLOP - 2; ++i)
						{
							cout << " ";
						}
						veKhungXuatLopTheoNK();
						inLOPTheoHang(DANHSACHLOP[k], y, viTri + 1);

						//Hight light dòng mới
						k = chiSo[--viTri];
						SetBGColor(green_Dark);
						gotoxy(MINX_XLOP + 1, wherey() - 1);
						for (int i = 0; i < widthBANG_XLOP - 2; ++i)
						{
							cout << " ";
						}
						inLOPTheoHang(DANHSACHLOP[k], wherey(), viTri + 1);
						gotoxy(X_XLOP_COT1 + strlen(DANHSACHLOP[k].MALOP) + 2, Y_FIST_LOP + viTri);
					}
					else if (trangHT > 0 && viTri > 0)
					{
						viTriChinhSua = 1;
						xoaNoiDungVe(MINX_XLOP - 1, MINY_XLOP - 1, widthBANG_XLOP + 1, heightBANG_XLOP + 1);
						trangHT--;
						gotoxy(X_XLOP_COT3 - 10, MINY_XLOP - 1);
						cout << "Trang: " << trangHT << " / " << TSTrang;
						veKhungXuatLopTheoNK();
						firstItem = (trangHT - 1) * 10;
						viTri = firstItem;
						for (int i = 0; i < 10; ++i)
						{
							if (viTri < stt)
							{
								k = chiSo[viTri++];
								inLOPTheoHang(DANHSACHLOP[k], Y_FIST_LOP + i, viTri);
							}
						}
						viTri = firstItem + 9;
						if (viTri > 0)
						{
							int y = Y_FIST_LOP + 9;
							k = chiSo[viTri];
							gotoxy(MINX_XLOP + 1, y);
							SetBGColor(green_Dark);
							for (int i = 0; i < widthBANG_XLOP - 2; ++i)
							{
								cout << " ";
							}

							inLOPTheoHang(DANHSACHLOP[k], y, viTri + 1);
							gotoxy(X_XLOP_COT1 + strlen(DANHSACHLOP[k].MALOP) + 2, Y_FIST_LOP + viTri);
						}
					}
					break;
				}
				case F2:
				{
					if (viTriChinhSua == 1)
					{
						do
						{
							SetBGColor(green_Dark);
							int kiTu = NhapChuoiVaChuSo(ML, 15, X_XLOP_COT1 + 2, Y_FIST_LOP + viTri);
							//Chuỗi mã lớp trả về bị rỗng
							if (kiTu == -1)
							{

								char title[] = "THONG BAO";
								char message[] = "Ma lop khong duoc rong!";
								char td[2][10] = { "Chinh sua", "    Huy" };
								normal();
								gotoxy(MINX_ALERTTB, MINY_ALERTTB);
								int select = veKhungThongBao(title, message, td);
								if (select == 0)
								{
									//Cho biet chuoi dang rong
									ML[0] = '\0';
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									continue;
								}
								else if (select == 1)
								{
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									int y = Y_FIST_LOP + viTri;
									k = chiSo[viTri];
									SetBGColor(green_Dark);
									gotoxy(MINX_XLOP + 1, y);
									for (int i = 0; i < widthBANG_XLOP - 2; ++i)
									{
										cout << " ";
									}
									inLOPTheoHang(DANHSACHLOP[k], y, viTri + 1);
									break;
								}


							}
							else if (searchLOP(ML) == -1 && kiTu == 0)
							{
								DANHSACHLOP[k].setMLOP(ML);
								break;
							}
							else if (strcmp(ML, DANHSACHLOP[k].MALOP) == 0)
							{
								break;
							}
							//Mã lớp bị trùng
							else if (searchLOP(ML) != -1 && kiTu == 0)
							{
								char title[] = "THONG BAO";
								char message[] = "Ma lop bi trung!";
								char td[2][10] = { "Chinh sua", "Huy" };
								normal();
								gotoxy(MINX_ALERTTB, MINY_ALERTTB);
								int select = veKhungThongBao(title, message, td);
								if (select == 0)
								{
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									continue;
								}
								else if (select == 1)
								{
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									int y = Y_FIST_LOP + viTri;
									k = chiSo[viTri];
									SetBGColor(green_Dark);
									gotoxy(MINX_XLOP + 1, y);
									for (int i = 0; i < widthBANG_XLOP - 2; ++i)
									{
										cout << " ";
									}
									inLOPTheoHang(DANHSACHLOP[k], y, viTri + 1);
									break;
								}
							}
						} while (true);
					}
					else if (viTriChinhSua == 2)
					{
						SetBGColor(green_Dark);
						int kiTu = NhapChuoi(TENL, 39, X_XLOP_COT2 + 3, Y_FIST_LOP + viTri);
						DANHSACHLOP[k].setTENL(TENL);
					}
					else if (viTriChinhSua == 3)
					{
						int NHOC;
						do
						{
							NhapSo(namhoc, 5, X_XLOP_COT3 + 2, Y_FIST_LOP + viTri);
							NHOC = atoi(namhoc);
							if (NHOC > namHT)
							{
								char title[] = "THONG BAO";
								char message[] = " Nam hoc khong hop le!";
								char td[2][10] = { "Chinh sua", "   Huy" };
								normal();
								gotoxy(MINX_ALERTTB, MINY_ALERTTB);
								int select = veKhungThongBao(title, message, td);
								if (select == 0)
								{
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									continue;
								}
								else if (select == 1)
								{
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									int y = Y_FIST_LOP + viTri;
									k = chiSo[viTri];
									SetBGColor(green_Dark);
									gotoxy(MINX_XLOP + 1, y);
									for (int i = 0; i < widthBANG_XLOP - 2; ++i)
									{
										cout << " ";
									}
									inLOPTheoHang(DANHSACHLOP[k], y, viTri + 1);
									break;
								}
							}
						} while (NHOC >= namHT);
						DANHSACHLOP[k].setNH(NHOC);
					}
					break;
				}
				case Left:
				{
					if (viTriChinhSua >= 2)
					{
						viTriChinhSua--;
						if (viTriChinhSua == 1)
						{
							gotoxy(X_XLOP_COT1 + strlen(ML) + 2, Y_FIST_LOP + viTri);
						}
						else if (viTriChinhSua == 2)
						{
							gotoxy(X_XLOP_COT2 + strlen(TENL) + 3, Y_FIST_LOP + viTri);
						}
					}
					break;
				}
				case Right:
				{
					if (viTriChinhSua <= 2)
					{
						viTriChinhSua++;
						if (viTriChinhSua == 3)
						{
							gotoxy(X_XLOP_COT3 + strlen(namhoc) + 2, Y_FIST_LOP + viTri);
						}
						else if (viTriChinhSua == 2)
						{
							gotoxy(X_XLOP_COT2+ strlen(TENL) + 3, Y_FIST_LOP + viTri);
						}
					}
					break;
				}
				case ESC:
				{
					return;
				}
				}
			} while (true);
			normal();
			break;
		}
		case ESC:
		{
			return;
		}
		}
	} while (true);
}

void DSLOP::chinhSuaTTLOP()
{
	int x;
	char TENL[38];
	char c_NH[5];
	int NAMHOC;
	char MLOP[15];
	MLOP[0] = '\0';
	gotoxy(72, 2);
	setGreenText();
	cout << "SUA THONG TIN LOP";
	normal();
	char title[] = "THONG BAO";
	char message[] = "  Nhap ma lop can chinh sua";
	do
	{
		gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
		int kiTu = veTextFieldNhapKituSo(MLOP, title, message);
		if (kiTu == ESC)
		{
			return;
		}
		gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
		for (int i = 0; i < widthAlert - 4; ++i)
		{
			cout << " ";
		}
		x = searchLOP(MLOP);
		if (x == -1)
		{
			gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
			SetColor(red_hightlight);
			cout << "  Ma lop khong hop le!";
			continue;
		}
		else
		{
			break;
		}
	} while (true);

	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);

	DANHSACHLOP[x].getTENLOP(TENL);
	NAMHOC = DANHSACHLOP[x].getNH();
	itoa(NAMHOC, c_NH, 10);

	veKhungNhapTTLop();
	
	gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
	cout << MLOP;
	gotoxy(xCot1 + 2, MINY_BLOP + 4);
	cout << TENL;
	gotoxy(xCot2 + 3, MINY_BLOP + 4);
	cout << NAMHOC;

	int viTri = 1;
	gotoxy(MINX_BLOP + strlen(MLOP) + 2, MINY_BLOP + 4);

	int kiTu;
	do
	{
		DANHSACHLOP[x].getMALOP(MLOP);
		DANHSACHLOP[x].getTENLOP(TENL);
		NAMHOC = DANHSACHLOP[x].getNH();
		itoa(NAMHOC, c_NH, 10);

		kiTu = 0;
		fflush(stdin);
		char temp = _getch();
		if (temp == 0 || temp == -32)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}

		if (kiTu == ESC)
		{
			return;
		}
		else if (kiTu == Right)
		{
			if (viTri == 1)
			{
				viTri++;
				gotoxy(xCot1 + strlen(TENL) + 2, MINY_BLOP + 4);
			}
			else if (viTri == 2)
			{
				viTri++;
				gotoxy(xCot2 + 7, MINY_BLOP + 4);
			}
		}
		else if (kiTu == Left)
		{
			if (viTri == 3)
			{
				viTri--;
				gotoxy(xCot1 + strlen(TENL) + 2, MINY_BLOP + 4);
			}
			else if (viTri == 2)
			{
				viTri--;
				gotoxy(MINX_BLOP + strlen(MLOP) + 2, MINY_BLOP + 4);
			}
		}
		else if (kiTu == F2)
		{
			if (viTri == 1)
			{
				do
				{
					int check = NhapChuoiVaChuSo(MLOP, 15, MINX_BLOP + 2, MINY_BLOP + 4);
					if (check == -1)
					{

						char title[] = "THONG BAO";
						char message[] = "Ma lop khong duoc rong!";
						char td[2][10] = { "Chinh sua", "    Huy" };
						normal();
						gotoxy(MINX_ALERTTB, MINY_ALERTTB);
						int select = veKhungThongBao(title, message, td);
						if (select == 0)
						{
							//Cho biet chuoi dang rong
							MLOP[0] = '\0';
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							continue;
						}
						else if (select == 1)
						{
							veKhungNhapTTLop();

							gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
							cout << MLOP;
							gotoxy(xCot1 + 2, MINY_BLOP + 4);
							cout << TENL;
							gotoxy(xCot2 + 3, MINY_BLOP + 4);
							cout << NAMHOC;
							break;
						}
					}
					else if (check == ESC)
					{
						xoaNoiDungVe(MINX_BLOP - 1, MINY_BLOP - 1, 70, 7);
						veKhungNhapTTLop();

						DANHSACHLOP[x].getMALOP(MLOP);
						gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
						cout << MLOP;
						gotoxy(xCot1 + 2, MINY_BLOP + 4);
						cout << TENL;
						gotoxy(xCot2 + 3, MINY_BLOP + 4);
						cout << NAMHOC;

						gotoxy(MINX_BLOP + strlen(MLOP) + 2, MINY_BLOP + 4);

						break;
					}
					else if (searchLOP(MLOP) == -1 && check == 0)
					{
						DANHSACHLOP[x].setMLOP(MLOP);
						break;
					}
					else if (strcmp(MLOP, DANHSACHLOP[x].MALOP) == 0)
					{
						break;
					}
					//Mã lớp bị trùng
					else if (searchLOP(MLOP) != -1 && check == 0)
					{
						char title[] = "THONG BAO";
						char message[] = "Ma lop bi trung!";
						char td[2][10] = { "Chinh sua", "Huy" };
						normal();
						gotoxy(MINX_ALERTTB, MINY_ALERTTB);
						int select = veKhungThongBao(title, message, td);
						if (select == 0)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							continue;
						}
						else if (select == 1)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							
							xoaNoiDungVe(MINX_BLOP - 1, MINY_BLOP - 1, 70, 7);
							veKhungNhapTTLop();

							DANHSACHLOP[x].getMALOP(MLOP);

							gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
							cout << MLOP;
							gotoxy(xCot1 + 2, MINY_BLOP + 4);
							cout << TENL;
							gotoxy(xCot2 + 3, MINY_BLOP + 4);
							cout << NAMHOC;

							gotoxy(MINX_BLOP + strlen(MLOP) + 2, MINY_BLOP + 4);
						}
					}
				} while (true);
				
			}
			else if (viTri == 2)
			{
				do
				{
					int check = NhapChuoi(TENL, 38, xCot1 + 2, MINY_BLOP + 4);
					if (check == ESC)
					{
						TENL[0] = '\0';
						continue;
					}
					else
					{
						DANHSACHLOP[x].setTENL(TENL);
						break;
					}
				} while (true);
			}
			else if (viTri == 3)
			{
				do
				{
					int check = NhapSo(c_NH, 5, xCot2 + 3, MINY_BLOP + 4);
					NAMHOC = atoi(c_NH);
					int namHT = getNamHienTai();

					if (strlen(c_NH) < 4)
					{
						
						continue;
					}
					else if (NAMHOC > namHT)
					{
						char title[10] = "THONG BAO";
						char message[30] = "Nam hoc khong hop le!";
						char td[2][10] = { "Chinh sua", "    Huy" };
						gotoxy(MINX_ALERTTB, MINY_ALERTNL);
						int check2 = veKhungThongBao(title, message, td);
						//Nguoi dung chon chinh sua noi dung bi trung
						if (check2 == 0)
						{
							//Xóa bảng thông báo vừa in ra
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
							continue;
						}
						else if (check2 == 1)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
							
							xoaNoiDungVe(MINX_BLOP - 1, MINY_BLOP - 1, 70, 7);
							veKhungNhapTTLop();

							NAMHOC = DANHSACHLOP[x].getNH();
							gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
							cout << MLOP;
							gotoxy(xCot1 + 2, MINY_BLOP + 4);
							cout << TENL;
							gotoxy(xCot2 + 3, MINY_BLOP + 4);
							cout << NAMHOC;

							gotoxy(xCot2 + 7, MINY_BLOP + 4);

							break;
						}
					}
					else
					{
						break;
					}
				} while (true);
			}
		}
	} while (true);


}

void DSLOP::xoaLOP()
{
	int x;
	char TENL[38];
	char c_NH[5];
	int NAMHOC;
	char MLOP[15];

	gotoxy(77, 2);
	setGreenText();
	cout << "XOA LOP";
	normal();
	do
	{
		MLOP[0] = '\0';
		char title[] = "THONG BAO";
		char message[] = "     Nhap ma lop can xoa  ";
		do
		{
			gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
			int kiTu = veTextFieldNhapKituSo(MLOP, title, message);
			if (kiTu == ESC)
			{
				return;
			}
			gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
			for (int i = 0; i < widthAlert - 4; ++i)
			{
				cout << " ";
			}
			x = searchLOP(MLOP);
			if (x == -1)
			{
				gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
				SetColor(red_hightlight);
				cout << "  Ma lop khong hop le!";
				continue;
			}
			else
			{
				break;
			}
		} while (true);

		xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);

		DANHSACHLOP[x].getTENLOP(TENL);
		NAMHOC = DANHSACHLOP[x].getNH();
		itoa(NAMHOC, c_NH, 10);

		veKhungNhapTTLop();

		gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
		cout << MLOP;
		gotoxy(xCot1 + 2, MINY_BLOP + 4);
		cout << TENL;
		gotoxy(xCot2 + 3, MINY_BLOP + 4);
		cout << NAMHOC;

		char message1[] = "Ban co chac chan xoa lop?";
		char td[2][10] = { "  Co", "   Khong" };
		gotoxy(MINX_ALERTTB, MINY_ALERTNL);
		int select = veKhungThongBao(title, message1, td);
		if (select == 0)
		{
			xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
			if (DANHSACHLOP[x].First != NULL)
			{
				char title[] = "THONG BAO";
				char message[] = "    Lop khong the xoa!";
				char td[2][10] = { "Nhap lai", "  Thoat" };
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int select = veKhungThongBao(title, message, td);
				if (select == 0)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					xoaNoiDungVe(MINX_BLOP, MINY_BLOP, 70, 10);
				}
				else
				{
					return;
				}
			}
			else
			{
				xoaPhanTu(DANHSACHLOP, SL, x);
				char title[] = "THONG BAO";
				char message[] = "    Xoa thanh cong";
				char td[2][10] = { "Tiep tuc", "  Thoat" };
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int select = veKhungThongBao(title, message, td);
				if (select == 0)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					xoaNoiDungVe(MINX_BLOP, MINY_BLOP, 70, 10);
				}
				else
				{
					return;
				}
			}
		}
		else
		{
			return;
		}
		
	} while (true);
}

bool DSLOP::nhapDSSVLOP()
{
	char labelTb[20] = "NHAP SINH VIEN LOP";
	labelTable(labelTb);
	char title[] = "THONG BAO";
	char message[] = "Nhap Ma Lop de them sinh vien";
	char maLop[15];
	int i = -1;
	maLop[0] = '\0';
	do {
		gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
		switch (veTextFieldNhapKituSo(maLop, title, message))
		{
		case ESC:
			return false;
			break;
		case 0:
			if (searchLOP(maLop) == -1 && maLop[0] != '\0')
			{
				gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
				SetColor(red_hightlight);
				cout << "Khong ton tai " << maLop;
				Sleep(1000);
				xoaNoiDungVe(MINX_ALERTTB + 4, MINY_ALERTNL + 3, 20, 1);

			}
			break;
		default:
			break;
		}
		i = searchLOP(maLop);
	} while (i == -1);
	Sleep(100);
	//Xóa TextField
	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);

	DANHSACHLOP[i].createDSSV();

	return true;
}

bool DSLOP::xuatDSSVLOP()
{
	char labelTb[20] = "NHAP SINH VIEN LOP";
	labelTable(labelTb);
	char title[] = "THONG BAO";
	char message[] = "Nhap Ma Lop xem sinh vien";
	char maLop[15];
	int i = -1;
	maLop[0] = '\0';
	do {
		gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
		switch (veTextFieldNhapKituSo(maLop, title, message))
		{
		case ESC:
			return false;
			break;
		case 0:
			if (searchLOP(maLop) == -1 && maLop[0] != '\0')
			{
				gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
				SetColor(red_hightlight);
				cout << "Khong ton tai " << maLop;
				Sleep(1000);
				xoaNoiDungVe(MINX_ALERTTB + 4, MINY_ALERTNL + 3, 20, 1);

			}
			break;
		default:
			break;
		}
		i = searchLOP(maLop);
	} while (i == -1);
	Sleep(100);
	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);
	DANHSACHLOP[i].xuatDSSV();
	return false;
}

int DSLOP::searchLOP(char MLOP[])
{
	for (int i = 0; i < SL; ++i)
	{
		if (strcmp(MLOP, DANHSACHLOP[i].MALOP) == 0)
		{
			return i;
		}
	}
	return -1;
}

bool DSLOP::nhapDiemLOP(DSMH ds, char MLOP[], char MAMH[], int lanThi)
{
	return false;
}

bool DSLOP::inBangDiemTheoLanThi(DSMH ds, char MLOP[], char MAMH[], int lanThi)
{
	return false;
}

bool DSLOP::inDiemTrungBinh(char MLOP[])
{
	return false;
}

void DSLOP::inDiemTongKet(char MLOP[])
{
}

DSLOP::~DSLOP()
{
}
PTRNODESV DSLOP:: searchAllSV(char MSV[]){
	for (int i = 0; i < SL; ++i){
		if (DANHSACHLOP[i].searchSV(MSV) != NULL) return DANHSACHLOP[i].searchSV(MSV);

	}
	return NULL;
}