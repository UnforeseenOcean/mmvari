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
#ifndef LogFileH
#define LogFileH

#include "ComLib.h"
//---------------------------------------------------------------------------
#define	MMLOGID	"MMLOG DATA Ver1.00\032"

extern const char	*_band[];

typedef struct {	// Log�̓���I�v�V����
	char	m_TimeZone;				// �\���p�^�C���]�[��

	int		m_UpperName;			// �啶���ւ̕ϊ�
	int		m_UpperQTH;				// �啶���ւ̕ϊ�
	int		m_UpperREM;				// �啶���ւ̕ϊ�
	int		m_UpperQSL;				// �啶���ւ̕ϊ�

	int		m_DefMyRST;				// 0-OFF, 1-ON

	int		m_CopyFreq;				// 0-Band, 1-Freq
	int		m_CopyHis;				// 0-599, 1-599001, 2-599UTC
	int		m_CopyName;				// 0-OFF, 1-ON
	int		m_CopyQTH;				// 0-OFF, 1-ON
	int		m_CopyREM;				// 0-OFF, 1-ON
	int		m_CopyQSL;				// 0-OFF, 1-ON
	int		m_CopyREMB4;			// 0-OFF, 1-ON

	int		m_AutoSave;				// �����Z�[�u

	int		m_QSOMacroFlag;			// 0-OFF, 1-ON
	int		m_CheckBand;			// ����o���h�ł̏d�����`�F�b�N
	int		m_QSOMacro[5];			// 0-Run 1st, 1-Run 2nd, 2-Run Dupe, 3-S&P 1st, 4-S&P 2nd
	WORD	m_QSOMacroKey[5];
	AnsiString	m_QSOMacroStr[5];

	AnsiString	m_THRTTY;
	AnsiString	m_THSSTV;
	AnsiString	m_THGMSK;
	int     m_THTZ;
	int		m_ClipRSTADIF;
	int		m_DateType;

    int		m_Backup;				// �o�b�N�A�b�v�쐬

	BYTE	m_Hamlog5Len[17];
}LOGSET;

#define	MLCALL	16		/* ��ٻ�݂̒���		*/
#define	MLRST	20		/* RST�i���o�̒���	*/
#define	MLREM	56		/* �L���̒���		*/
#define	MLNAME	16		/* ���O�̒���		*/
#define	MLQTH	28		/* �p�s�g�̒���		*/
#define	MLQSL	54		/* �p�r�k�̒���		*/
#define	MLPOW	4		/* �d��				*/
#define	MLOPT	8		/* �I�v�V����		*/

#define MODEMAX	48

#define	YEAR(c)	(((c)<50)?(2000+(c)):(1900+(c)))

#pragma option -a-	// �p�b�N�̎w��
typedef struct {			/* �l�l�k�n�f�f�[�^�`��	*/
	BYTE	year;		/* �N		*/
	WORD	date;			/* ���t		*/
	WORD	btime;			/* �J�n����	*/
	WORD	etime;			/* �I������	*/
	char	call[MLCALL+1];	/* ��ٻ��	*/
	char	ur[MLRST+1];	/* T ��߰�	*/
	char	my[MLRST+1];	/* R ��߰�	*/
	BYTE	band;		/* �����	*/
	SHORT	fq;				/* ���g��	*/
	BYTE	mode;		/* Ӱ��		*/
	char	pow[MLPOW+1];	/* �d��		*/
	char	name[MLNAME+1];	/* ���O		*/
	char	qth[MLQTH+1];	/* QTH		*/
	char	qsl[MLQSL+1];	/* QSL		*/
	char	send;			/* QSL ���M	*/
	char	recv;			/* QSL ��M	*/
	char	cq;				/* cq/call	*/
	WORD	env;			/* ���Ǌ�	*/
	char	rem[MLREM+1];	/* �L��		*/
	char	opt1[MLOPT+1];	/* ��߼��	*/
	char	opt2[MLOPT+1];	/* ��߼��2	*/
}SDMMLOG;

#define	FHDOFF	256			/* �擪�̃w�b�_�̃I�t�Z�b�g		*/
#define	UMODEMAX	32
typedef struct {
	char	id[20];			/* �t�@�C���o�[�W����			*/
	char	dmy[4];			/* �_�~�[�̈�					*/
	USHORT	mlt;			/* �}���`���̃T�C�Y			*/
	char	td;				/* �����R�[�h					*/
	char	hash;			/* �n�b�V���f�[�^�i�[�t���O		*/
	long	size;			/* �f�[�^�T�C�Y					*/
	char	master;			/* �}�X�^�[�t�@�C���t���O		*/
	char	dm2[15];		/* �_�~�[�Q						*/
	char	mode[UMODEMAX][6];	/* ���[�U��`���[�h				*/
}FHD;
#pragma option -a.	// �p�b�N�����̎w��

class CIndex
{
private:
	int		m_IndexMax;		// �m�ے��̃C���f�b�N�X�̐�
	int		m_IndexCnt;		// ���݂̃C���f�b�N�X�̐�
	LPSTR	pIndex;			// �C���f�b�N�X�̈�̃|�C���^(16�o�C�g�C���f�b�N�X)
	BYTE	*pMult;			// �}���`���̃|�C���^
public:
	__fastcall CIndex();
	__fastcall ~CIndex();
	void __fastcall AllocIndex(int n);
	void __fastcall ClearIndex(void);
	void __fastcall WriteIndex(LPCSTR pCall, int n);
	void __fastcall ReadIndex(LPSTR pCall, int n);
	LPSTR __fastcall PointIndex(int n);
	void __fastcall AddBlock(LPCSTR p, int len);
	int __fastcall ReadIndex(int handle, FHD *hp);
	void __fastcall MakeIndex(int handle, FHD *hp);
	int __fastcall WriteIndex(int handle, FHD *hp);
};

#define	FINDMAX		32768
class CLogFind
{
public:
	int			m_FindCnt;
	int			m_FindCmp1Max;
	int			m_FindCmp2Max;
	int			m_FindStr1Max;
	int			m_FindStr2Max;

	int			*pFindTbl;
	AnsiString	m_FindStr;
public:
	__fastcall CLogFind();
	__fastcall ~CLogFind();
	inline int __fastcall GetCount(void){return m_FindCnt;};
	inline void __fastcall Clear(void){
		m_FindCnt = m_FindCmp1Max = m_FindCmp2Max = m_FindStr1Max = m_FindStr2Max = 0;
	};
	int __fastcall Add(int n);
	void __fastcall Ins(int n);

	inline void __fastcall Write(int n){
		pFindTbl[m_FindCnt] = n;
		m_FindCnt++;
	};
	inline void __fastcall SetText(LPCSTR p){
		if( p != m_FindStr.c_str() ){
			m_FindStr = p;
		}
	};
	inline LPCSTR __fastcall GetText(void){
		return m_FindStr.c_str();
	};
	inline void __fastcall ClearText(void){
		m_FindStr = "";
	};
};

class CLogFile
{
private:
	int		m_Open;			// �I�[�v���t���O
	int		m_EditFlag;		// �ҏW�t���O
	int		m_Handle;		// �t�@�C���n���h��
	CIndex	m_Index;		// ���݃I�[�v�����̃C���f�b�N�X
	FHD		m_fhd;			// ���݃I�[�v�����̃t�@�C���w�b�_
	AnsiString	m_Name;		// ���O�t�@�C���̖��O
	char	m_modebuf[8];
public:
	AnsiString	m_FileName;	// ���O�t�@�C���̖��O�i�t���p�X�j

	int		m_CurNo;
	int		m_CurChg;
	SDMMLOG	m_sd;
	SDMMLOG	m_bak;
	SDMMLOG	m_asd;

	CLogFind	m_Find;		// �J�����g�����f�[�^
	LOGSET		m_LogSet;
private:
	void __fastcall SetHisRST(SDMMLOG *sp);
	void __fastcall InitHeader(void);

public:
	__fastcall CLogFile();
	__fastcall ~CLogFile();

	void __fastcall DoBackup(void);

	int __fastcall Open(LPCSTR pName, BOOL fNew);
	int __fastcall Close(void);

	void __fastcall ReadIniFile(LPCSTR pKey, TMemIniFile *pIniFile);
	void __fastcall WriteIniFile(LPCSTR pKey, TMemIniFile *pIniFile);

	void __fastcall MakeIndex(void);

	inline int __fastcall IsEdit(void){return m_EditFlag;};
	void __fastcall MakePathName(LPCSTR pName);
	void __fastcall MakeName(LPCSTR pName);
	inline LPCSTR __fastcall GetName(void){return m_Name.c_str();};

	inline int __fastcall GetCount(void){return m_fhd.size;};
	inline int __fastcall IsOpen(void){return m_Open;};
	int __fastcall GetData(SDMMLOG *sp, int n);
	int __fastcall PutData(SDMMLOG *sp, int n);

	LPCSTR __fastcall GetDateString(SDMMLOG *sp, int sw);
	inline LPCSTR __fastcall GetDateString(SDMMLOG *sp){ return GetDateString(sp, m_LogSet.m_DateType); };
	LPCSTR __fastcall GetTimeString(WORD d);


	LPCSTR __fastcall GetModeString(BYTE m);
	void __fastcall SetMode(SDMMLOG *sp, LPCSTR s);

	LPCSTR __fastcall GetFreqString(BYTE b, short fq);
	void __fastcall SetFreq(SDMMLOG *sp, LPCSTR p);
	LPCSTR __fastcall GetOptStr(int n, SDMMLOG *sp);
	void __fastcall SetOptStr(int n, SDMMLOG *sp, LPCSTR pOpt);

	void __fastcall CopyAF(void);

	void __fastcall SortDate(int bb, int eb);
	int __fastcall FindSameBand(BOOL fMode);
	int __fastcall FindSameDate(void);

	void __fastcall FindStrSet(CLogFind *fp, LPCSTR pCall);
	int __fastcall FindCmpSet(CLogFind *fp, LPCSTR pCall);
	int __fastcall FindClipSet(CLogFind *fp, LPCSTR pCall);
	int __fastcall FindSet(CLogFind *fp, LPCSTR pCall);
	int __fastcall Find(LPCSTR pCall, int b, int dir);
	int __fastcall IsAlready(LPCSTR pCall);
	void __fastcall DeleteAll(void);
	void __fastcall DeleteLast(void);
	void __fastcall Delete(int top, int end);
	void __fastcall Insert(int n, SDMMLOG *sp);

	void __fastcall InitCur(void);
	void __fastcall SetLastPos(void);

	int __fastcall ReadAscii(SDMMLOG *sp, LPSTR p);

};

void __fastcall JSTtoUTC(int &Year, int &Mon, int &Day, int &Hour);
void __fastcall JSTtoUTC(SDMMLOG *sp);
void __fastcall UTCtoJST(int &Year, int &Mon, int &Day, int &Hour);
void __fastcall UTCtoJST(SDMMLOG *sp);
void __fastcall UTCtoJST(SYSTEMTIME *tp);
void __fastcall mBandToBand(SDMMLOG *sp, LPCSTR p);
LPCSTR __fastcall FreqTomBand(SDMMLOG *sp);
int __fastcall GetLMode(BYTE m);

extern	CLogFile	Log;
extern	const char	MONN[];
extern	const char	MONU[];
#endif

