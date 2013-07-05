//Copyright+LGPL

//-----------------------------------------------------------------------------------------------------------------------------------------------
// Copyright 2000-2013 Makoto Mori, Nobuyuki Oba
//-----------------------------------------------------------------------------------------------------------------------------------------------
// This file is part of MMVARI.

// MMVARI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

// MMVARI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public License along with MMTTY.  If not, see 
// <http://www.gnu.org/licenses/>.
//-----------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------
#ifndef LogConvH
#define LogConvH
#include "LogFile.h"

extern	const	char	*MONT1[];
extern	const	char	*MONT2[];
extern  const   char	*_BandText[];
//*************************************************************
// ���O�ϊ��̊�{�N���X
//
class CLogConv
{
protected:
	int		m_Type;    		// 0-TEXT, 1-LOG200, 2-HAMLOG, 3-DBASE
	int		m_Mode;			// 0-Read, 1-Write
	FILE	*m_fp;

	AnsiString	m_FileName;		// �ϊ����̃t�@�C����
public:
	__fastcall CLogConv();
	virtual __fastcall ~CLogConv();
	virtual int __fastcall IsOpen(void){return m_fp != NULL ? 1 : 0;};
	virtual int __fastcall Open(LPCSTR pName)=0;
	virtual int __fastcall Create(LPCSTR pName)=0;
	virtual int __fastcall Close(void)=0;
	virtual int __fastcall Read(SDMMLOG *sp)=0;
	virtual int __fastcall Write(SDMMLOG *sp)=0;
};

#define	TEXTCONVMAX		64
typedef struct {
	int	w;
	AnsiString	Key;
}TCONV;

//*************************************************************
// �e�L�X�g�t�@�C���A�N�Z�X�̃N���X
//
class CLogText : public CLogConv
{
public:
	int		m_Double;
	int		m_Delm;
	TCONV	m_rConv[TEXTCONVMAX];
	TCONV	m_tConv[TEXTCONVMAX];
	int		m_UTC;
	int		m_err;
protected:
	char	m_bf[2048];			// �t�@�C���o�b�t�@

private:
	int __fastcall Text2MMLOG(SDMMLOG *sp, LPSTR p, int &err);
	void __fastcall MMLOG2Text(LPSTR t, SDMMLOG *sp);

public:
	__fastcall CLogText();
	virtual int __fastcall Open(LPCSTR pName);
	virtual int __fastcall Create(LPCSTR pName);
	virtual int __fastcall Close(void);
	virtual int __fastcall Read(SDMMLOG *sp);
	virtual int __fastcall Write(SDMMLOG *sp);

};

void __fastcall MMLOG2Text(LPSTR t, SDMMLOG *sp, AnsiString &Key);
int __fastcall Text2MMLOG(SDMMLOG *sp, LPCSTR s, AnsiString &Key);
extern const LPCSTR ConvTbl[];
extern CLogText	LogText;

//*************************************************************
// �k�n�f�Q�O�O�t�@�C���A�N�Z�X�̃N���X
//
#define	LOG200WIDTH		200
class CLog200 : public CLogConv
{
public:
	int		m_Index;
	int		m_err;
protected:
	char	m_bf[200];			// �t�@�C���o�b�t�@
private:
public:
	__fastcall CLog200();
	virtual int __fastcall Open(LPCSTR pName);
	virtual int __fastcall Create(LPCSTR pName);
	virtual int __fastcall Close(void);
	virtual int __fastcall Read(SDMMLOG *sp);
	virtual int __fastcall Write(SDMMLOG *sp);
};

//*************************************************************
// �g�`�l�k�n�f�t�@�C���A�N�Z�X�̃N���X
//
#pragma option -a-	// �p�b�N�̎w��
typedef struct {
	char	Memo;		// 03h=��̨���ޖ���  83h=��̨���ޗL��iHAMLOG�ł� 1Ah�j
	char	YY, MM, DD;	// �ŏI�X�V�N����
	long	Max;		// ں��ތ���
	WORD	HeadLen;	// ͯ�ނ̒����iHAMLOG.DBS�� 449�j
	WORD	DataLen;	// ں��ނ̒����iHAMLOG.DBS�� 58�j
	char	dummy[20];	// 00h
}DBSHD;

typedef struct {
	char	Memo;		// 03h=��̨���ޖ���  83h=��̨���ޗL��iHAMLOG�ł� 1Ah�j
	char	YY, MM, DD;	// �ŏI�X�V�N����
	long	Max;		// ں��ތ���
	char	dm1;
	char	m1;			// 01h
	char	dm2;
	char	dummy[21];	// 00h
	char	dummy2[255-32];	// 00h
	char	term;		// 1ah
}DBRHD;

typedef struct {
	char	Name[11];
	BYTE	Type;
	BYTE	dm1[4];
	BYTE	Len;
	BYTE	dm2[15];
}DBSLOT;

typedef struct {
	char	del[1];		/*	�폜�}�[�N	*/
	char	calls[7];	/*	��ٻ��		*/
	char	potbl[3];	/*	�ړ��ر		*/
	char	code[6]; 	/*	JCC����		*/
	char	glid[6];	/*	��د��۹���	*/
	char	freq[4]; 	/*	���g��		*/
	char	mode[3]; 	/*	Ӱ��		*/
	char	name[12]; 	/*	����		*/
	char	qsl [1]; 	/*	QSL via		*/
	char	send[1]; 	/*	QSL SEND	*/
	char	rcv[1]; 	/*	QSL RCV    	*/
	char	date[3]; 	/*	���t		*/
	char	time[2]; 	/*	����		*/
	char	hiss[2]; 	/*	HIS RST		*/
	char	myrs[2]; 	/*	MY  RST		*/
	long	ofs;		/*	HAMLOG.DBR �̾�ı��ڽ	*/
}SDHAMLOG;

typedef struct {		/* DBR�̃t�B�[���h�ʒu�f�[�^	*/
	BYTE	LenQTH;
	BYTE	LenREM1;
	BYTE	LenREM2;
}FHDDBR;
#pragma option -a.	// �p�b�N�����̎w��

class CHamLog : public CLogConv
{
public:
	int		m_Index;
	int		m_err;
protected:
	DBSHD		m_hd;			// DBS�w�b�_
	SDHAMLOG	m_RecBuf;		// ���R�[�h�o�b�t�@

	AnsiString	m_DBRName;		// DBR�t�@�C���̖��O
	FILE		*m_dbrfp;		// DBR�t�@�C���̃t�@�C���|�C���^
	DBRHD		m_dbrhd;		// DBR�w�b�_
private:
	int __fastcall Seek(DWORD Index);
	BOOL __fastcall MakeHD(void);

public:
	__fastcall CHamLog();
	virtual int __fastcall Open(LPCSTR pName);
	virtual int __fastcall Create(LPCSTR pName);
	virtual int __fastcall Close(void);
	virtual int __fastcall Read(SDMMLOG *sp);
	virtual int __fastcall Write(SDMMLOG *sp);
};

void __fastcall HAMLOGtoMMLOG(SDMMLOG *sp, SDHAMLOG *hp, FILE *dbrfp);
int __fastcall MMLOGtoHAMLOG(SDHAMLOG *hp, SDMMLOG *sp, FILE *dbrfp);
void __fastcall AddMMLOGKey(AnsiString &REM1, AnsiString &REM2, LPCSTR s, LPCSTR pKey);
void __fastcall SetMMLOGKey(SDMMLOG *sp, LPSTR bf);
void __fastcall SpaceCopy(LPSTR t, LPCSTR s, int n);

//*************************************************************
// ADIF�A�N�Z�X�̃N���X
//
class CLogADIF : public CLogConv
{
public:
protected:
	char	m_bf[1024];			// �t�@�C���o�b�t�@
	LPSTR	m_p;
	int		m_conv;
private:
	void __fastcall MMLOG2ADIF(LPSTR t, SDMMLOG *sp);
	void __fastcall SetData(SDMMLOG *sp, LPCSTR pKey, LPSTR pData);
	void __fastcall AdjustData(SDMMLOG *sp);
	void OutF(int &col, FILE *fp, LPCSTR fmt, ...);

public:
	__fastcall CLogADIF();
	virtual int __fastcall Open(LPCSTR pName);
	virtual int __fastcall Create(LPCSTR pName);
	virtual int __fastcall Close(void);
	virtual int __fastcall Read(SDMMLOG *sp);
	virtual int __fastcall Write(SDMMLOG *sp);

};

//*************************************************************
// Cabrillo �A�N�Z�X�̃N���X
//
class CLogCabrillo : public CLogConv
{
public:
protected:
	char	m_bf[1024];			// �t�@�C���o�b�t�@
	LPSTR	m_p;
	AnsiString	m_SNR;
private:
	void __fastcall MMLOG2Cabrillo(LPSTR t, SDMMLOG *sp);
	void __fastcall AdjustData(SDMMLOG *sp);

public:
	__fastcall CLogCabrillo();
	virtual int __fastcall Open(LPCSTR pName);
	virtual int __fastcall Create(LPCSTR pName);
	virtual int __fastcall Close(void);
	virtual int __fastcall Read(SDMMLOG *sp);
	virtual int __fastcall Write(SDMMLOG *sp);
};

#endif
