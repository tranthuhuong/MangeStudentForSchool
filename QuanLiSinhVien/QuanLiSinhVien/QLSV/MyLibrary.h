﻿#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <iomanip> 
#include <stdlib.h>
#include <ctime>
using namespace std;

// Tọa độ bảng nhập thông tin của lớp
const int MINX_BLOP = 46;
const int MAXX_BLOP = 115;
const int MINY_BLOP = 4;
const int MAXY_BLOP = 10;
const int xCot1 = 64; //Cột đứng thứ nhất trong bảng nhập thông tin lớp
const int xCot2 = 105;//Cột đứng thứ hai trong bảng nhập thông tin lớp

//Tọa độ  bảng xuất thông tin Lớp
const int MINY_ALERTTB = 20;
const int MINX_ALERTTB = 65;

//Tọa độ bảng thông báo Nhập thông tin lớp
const int MINY_ALERTNL = 12;


//Tọa độ bảng nhập thông tin sinh viên
const int MINX_BSV = 46;
const int MAXX_BSV = 115;
const int MINY_BSV = 4;
const int MAXY_BSV = 10;
const int svCot1 = 58; //Cột đứng thứ nhất trong bảng nhập thông tin sinh Vien
const int svCot2 = 85;//Cột đứng thứ hai trong bảng nhập thông tin sinh Viên
const int svCot3 = 97;//Cột đứng thứ hai trong bảng nhập thông tin sinh Viên
const int svCot4 = 102;//Cột đứng thứ hai trong bảng nhập thông tin sinh Viên

//Các phím chức năng
const int PageUp = 1072;
const int PageDown = 1080;
const int Left = 1075;
const int Right = 1077;
const int Enter = 13;
const int Space = 32;
const int BackSpace = 8;
const int Delete = 1083;
const int ESC = 27;
const int F2 = 1060;
const int F5 = 1063;
const int F6 = 1064;

//Dinh nghia mau
const int red_hightlight = 12;
const int black = 0;
const int green = 10;
const int blue = 1;
const int trang = 15;
const int green_Dark = 2;

const int widthAlert = 30;
const int heightAlert = 6;

const int heightTextField = 7;

//Tọa độ bảng xuất danh sách lớp
const int MINX_XLOP = 46;
const int MAXX_XLOP = 115;
const int MINY_XLOP = 5;
const int MAXY_XLOP = 18;
const int X_XLOP_COT1 = 52;
const int X_XLOP_COT2 = 65;
const int X_XLOP_COT3 = 107;
const int widthBANG_XLOP = 70;
const int heightBANG_XLOP = 14;
const int Y_FIST_LOP = MINY_XLOP + 3;

//Tọa độ bảng nhập môn học
const int MINX_BMH = 46;
const int MAXX_BMH = 115;
const int MINY_BMH = 4;
const int MAXY_BMH = 10;
const int X_BMH_COT1 = 56;
const int X_BMH_COT2 = 101;
const int X_BMH_COT3 = 108;
const int width_BMH = 70;
const int height_BMH = 6;

//Tọa độ bảng xuất danh sách sinh viên
const int MINX_XSV = 46;
const int MAXX_XSV = 115;
const int MINY_XSV = 5;
const int MAXY_XSV = 18;
const int X_XSV_COT1 = 50;
const int X_XSV_COT2 = 62;
const int X_XSV_COT3 = 84;
const int X_XSV_COT4 = 96;
const int X_XSV_COT5 = 102;

const int widthBANG_XSV = 70;
const int heightBANG_XSV = 14;
const int Y_FIST_SV = MINY_XSV + 3;

//Khởi tạo mặc định các tham số
const int SoChuSo = 4;

//Các hàm trong thư viện để vẽ
void gotoxy(short x, short y);
int wherex(void);
int wherey(void);
void SetColor(WORD color);
void SetBGColor(WORD color);

//Set Color cho Text
void setGreenText();   //Text xanh trên nền trắng
void setNormallText(); //Text den trên nền trắng

//Các hàm setColor khác
void normal();		//Chữ có màu trắng trên nền đen
void normalButton();//button nền đỏ thẫm chữ trắng
void highLight();   //Button nền đỏ sáng chữ trắng
void colorStroke(); //Set color text màu đỏ đậm

//Các hàm xử lí chuỗi
void xoaKiTu(char a[], int& n, int i);
void themKiTu(char a[], int& n,int& i, char c);

//Các hàm nhập chuỗi
int NhapChuoi(char a[], int MAX, int x, int y);
int NhapChuoiVaChuSo(char a[], int MAX, int x, int y);
int NhapSo(char a[], int MAX, int x, int y);
int NhapTen(char a[], int MAX, int x, int y);

//Các hàm vẽ đường line và các góc 
void veLineNamNgang(int x, int y, int width, int maMau);
void veLineThangDung(int x, int y, int height, int maMau);
void veGocTrenBenTrai(int x, int y, int maMau);
void veGocTrenBenPhai(int x, int y, int maMau);
void veGocDuoiBenTrai(int x, int y, int maMau);
void veGocDuoiBenPhai(int x, int y, int maMau);

//Ham ve button
/*
	x: Tọa độ x góc trên bên trái
	y: Tọa độ y góc trên bên trái
	width: chiều rộng button
	height: chiều cao button
*/
void paintNormalButton(int x, int y, char label[], int width, int height);
void highLightButton(int x, int y, char label[], int width, int height);
void paintColorButton(int x, int y, char label[], int width, int height, int color);

//Ham vẽ giao dien
void xoaNoiDungVe(int x, int y, int width, int height);
void veKhungNhapTTLop();
void veKhungXuatLopTheoNK();
/*	vẽ alert thông báo cho người dùng.
	title: Tên thông báo, message: nội dung thông báo, thực đơn: menu chọn
	hàm này sẽ trả về 0 nếu chọn vào menu 0 (có), 1 nếu chọn menu 1(không)
*/
int veKhungThongBao(char title[], char message[], char td[][10]);
void veTextField(char KQ[], char title[], char message[]);
int veTextFieldNhapKituSo(char KQ[], char title[], char message[]);
void veKhungNhapMH();
void labelTable(char label[]);
//hàm trả về năm hiện tại
int getNamHienTai();

template <class T>
void xoaPhanTu(T a[], int&n, int i)
{
	for (int j = i; j < n - 1; ++j)
	{
		a[j] = a[j + i];
	}
	--n;
}

//0 neu chuoi s1 > s2, tra ve -1 neu s1 < s2
int soSanhChuoi(char s1[], char s2[]);

void veKhungNhapTTSinhVien();
void veKhungXuatSVTheoLop();




