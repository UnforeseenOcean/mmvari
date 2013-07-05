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



//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <Printers.hpp>

#include "MacroKey.h"
#include "MacEdit.h"
#include "ComLib.h"
#include "InputWin.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
//TMacroKeyDlg *MacroKeyDlg;
MACKEY	mackeycom[]={
	{1, "<%TX>","���M�ɐ؂�ւ�", "Switch to TX"},
	{1, "<%RX>","��M�ɐ؂�ւ�", "Switch to RX"},
	{1, "<%TXRX>","����̐؂�ւ�", "Turns over TX/RX"},
	{1, "<%TXOFF>","���M�̋����I��", "Abort TX (Switch to RX immediately)"},
	{1, "<%AutoClear>","�����I�ɑ��M��ʂ��N���A", "Clear TX window automatically"},
	{1, "<%ClearTXW>","���M��ʂ��N���A", "Clear TX window"},
	{1, "<%ClearRXW>","��M��ʂ��N���A", "Clear RX window"},
	{1, "<%MyCall>","���ǂ̃R�[���T�C��", "My callsign"},
	{1, "<%HisCall>","����ǂ̃R�[���T�C��", "His/her callsign"},
	{1, "<%HisName>","����ǂ̖��O", "His/her name"},
	{1, "<%DearName>","Dear xxx �܂��� xxx����", "Dear xxx"},
	{1, "<%HisRST>","����ǂ�RST", "His/her RST"},
	{1, "<%MyRST>","���ǂ�(�`����ꂽ)RST", "My RST"},
	{1, "<%FREQ>","�^�p���g��(�� 7)", "Logging FREQ (e.g. 7)"},
	{1, "<%BAND>","�^�p�o���h(�� 40m)", "Logging BAND (e.g. 40m)"},
	{1, "<%HisQTH>","����ǂ�QTH", "His/her QTH"},
	{1, "<%Note>","Note(���l)", "Note (Remarks)"},
	{1, "<%UDATE>","���t(UTC)", "UTC date"},
	{1, "<%UTIME>","����(UTC) hh:mm", "UTC time (hh:mm)"},
	{1, "<%UTIMES>","����(UTC) hh:mm:ss", "UTC time (hh:mm:ss)"},
	{1, "<%LDATE>","���t(Local)", "Local date"},
	{1, "<%LTIME>","����(Local) hh:mm", "Local time (hh:mm)"},
	{1, "<%LTIMES>","����(Local) hh:mm:ss", "Local time (hh:mm:ss)"},
	{1, "<%PTIME>","1980/JAN/6 ����̌o�ߕb(UTC����)", "Passing time from 1980/JAN/6 (UTC)"},
	{1, "<%LPTIME>","1980/JAN/6 ����̌o�ߕb(���[�J������)", "Passing time from 1980/JAN/6 (local time)"},
	{1, "<%QPTIME>","QSO�J�nUTC����(1980/JAN/6 ����̌o�ߕb)", "QSO Starting time (passing time from 1980/JAN/6 (UTC)"},
	{1, "<%VALTIME=year,<%PTIME>>","PTIME�𕪉� (year/month/day/hour/minute/second..., PTIME)", "Takes the PTIME apart (year/month/day/hour/minute/second..., PTIME)"},
	{1, "<%Capture>","�R�[���T�C���̕ߊl", "Capture callsign"},
	{2, "<%HisGreetings=3>","�������A(�� 1-GA, 2-Good morning, 3-���͂悤�������܂�)", NULL},
	{3, "<%HisGreetings=2>","Auto Greetings (e.g. 1-GA, 2-Good morning)", NULL},
	{1, "<%HisNR>","HisRST�̃R���e�X�gNR", "Only the contest number part of his/her RST"},
	{1, "<%MyNR>","MyRST�̃R���e�X�gNR", "Only the contest number part of my RST"},
	{1, "<%Entity=<%HisCall>>","�G���e�B�e�B�R�[�h", "Code of the entity"},
	{1, "<%EntityName=<%HisCall>>","�G���e�B�e�B��", "Name of the entity"},
	{1, "<%Continent=<%HisCall>>","�嗤�R�[�h", "Code of the continent"},
	{1, "<%PLATFORM>","OS�̃v���b�g�t�H�[��", "Platform of the OS"},
	{1, "<%CodePage>","OS�̃R�[�h�y�[�W", "Code page of the OS"},
	{1, "<%LanguageID>","OS�̌���ID", "Language ID of the OS"},
	{1, "<%VER>","MMVARI�̃o�[�W����", "Program version of MMVARI"},
	{1, "<%VERMINOR>","MMVARI�̃}�C�i�[�o�[�W����", "Program minor version of MMVARI"},
	{1, "<%VARITYPE>","�o���R�[�h���(VariSTD, VariJA, VariHL, ...)", "Type of the VARICODE(VariSTD, VariJA, VariHL, ...)"},
	{1, "<%MODE>","���݂̃��[�h(�ϒ�����)���(GMSK, FSK, ...)", "Current type of the mode(GMSK, FSK, ...)"},
	{1, "<%Level>","�M����S/N���x��(dB)", "S/N level of the signals"},
	{1, "<%PeakLevel>","�M���̃s�[�NS/N���x��(dB)", "Peak S/N level of the signals"},
	{1, "<%AverageLevel>","�M���̕���S/N���x��(dB)", "Average S/N level of the signals"},
	{1, "<%MetricMFSK>","mfsk�M���̃��g���b�N���x��", "Metric level in mfsk"},
	{1, "<%MetricMFSK=even>","mfsk�M���̃r�^�r�ʃ��g���b�N���x��(even/odd)", "Metric level of the viterbi in mfsk (even/odd)"},
	{1, "<%SquelchLevel=3.0>","�X�P���`���x��(S/N=dB)�̐ݒ�", "Set squelch level (S/N=dB)"},
	{1, "<%CWID>","My callsign��CW�ő��M", "CWID of the MyCallsign"},
	{1, "<%CWID= 73 :>","�������CW�ő��M (AS @  SK :  AR ;  KN ]  BT =)", "CWID of the strings (AS @  SK :  AR ;  KN ]  BT =)"},
	{1, "<%CWSpeed=20>","CW���x(10 - 60)��ݒ�", "CWID speed (10-60)"},
	{1, "<%MODE=GMSK>","���[�h(�ϒ�����)�̐ݒ�(GMSK, FSK, ...)", "Set the mode(GMSK, FSK, ...)"},
	{1, "<%AutoNET>","�����I��NET��ON�ɂ���", "Turns NET into ON automatically"},
	{1, "<%NETON>","NET��ON�ɂ���", "Turns NET into ON"},
	{1, "<%NETOFF>","NET��OFF�ɂ���", "Turns NET into OFF"},
	{1, "<%AFCON>","AFC��ON�ɂ���", "Turns AFC into ON"},
	{1, "<%AFCOFF>","AFC��OFF�ɂ���", "Turns AFC into OFF"},
	{1, "<%ATCON>","ATC��ON�ɂ���", "Turns ATC into ON"},
	{1, "<%ATCOFF>","ATC��OFF�ɂ���", "Turns ATC into OFF"},
	{1, "<%RxCarrier>","��M�L�����A���g��(Hz)", "RX carrier FREQ(Hz)"},
	{1, "<%TxCarrier>","���M�L�����A���g��(Hz)", "TX carrier FREQ(Hz)"},
	{1, "<%RxCarrier=1750>","��M�L�����A���g��(Hz)��ݒ�", "Set RX carrier FREQ(Hz)"},
	{1, "<%TxCarrier=1750>","���M�L�����A���g��(Hz)��ݒ�", "Set TX carrier FREQ(Hz)"},
	{1, "<%AFCFrequency>","AFC���o���g��(Hz)", "AFC FREQ(Hz)"},
	{1, "<%MouseFrequency>","��߸���/����̫�قł̃}�E�X���g��(Hz)", "Mouse frequency on Waterfall(Hz)"},
	{1, "<%TONE>","�V���O���g�[���𑗐M", "Transmit single tone"},
	{1, "<%BPF=0>","BPF�ш敝(0-3)��ݒ�", "Set BPF width (0-3)"},
	{1, "<%BPFTaps=64,80,128,256>","BPF�̃^�b�v����ݒ�", "Set BPF taps"},
	{1, "<%Notch=ONOFF>","�m�b�`�t�B���^��ON/OFF (ON/OFF/ONOFF)", "Turns Notch into ON or OFF (ON/OFF/ONOFF)"},
	{1, "<%Notch=1750>","�m�b�`�t�B���^�̎��g��(Hz)��ݒ�", "Set Notch FREQ (Hz)"},
	{1, "<%NotchTaps=128>","�m�b�`�t�B���^�̃^�b�v����ݒ�(16�`512)", "Set taps of the Notch filter (16-512)"},
	{1, "<%NotchWidth=1>","�m�b�`�t�B���^�̑ш��ݒ�(1�`1000)", "Set width of the Notch filter (1-1000)"},
	{1, "<%BAUD>","�`���{�[���[�g", "BaudRate"},
	{1, "<%BAUD=31.25>","�`���{�[���[�g(20�`300)��ݒ�", "Set BaudRate(20-300)"},
	{1, "<%AFCWidth=50>","AFC�z�����ݕ�(Hz)��ݒ�", "Set AFC FREQ width(Hz)"},
	{1, "<%AFCLevel=12>","AFC�z�����݃��x��(dB)��ݒ�", "Set AFC sense level(dB)"},
	{1, "<%ATCSpeed=0>","ATC�������x(0-5)��ݒ�", "Set ATC speed(0-5)"},
	{1, "<%ATCLevel=15>","ATC���o���x��(dB)��ݒ�", "Set ATC sense level(dB)"},
	{1, "<%ATCPPM>","ATC�l(ppm)", "ATC value (ppm)"},
	{1, "<%PTT=COM1>","PTT�|�[�g��ݒ�", "Set PTT port"},
	{1, "<%COMFSK=ONOFF>","PTT�|�[�g FSK��ON/OFF (ON/OFF/ONOFF)", "Turns FSK into ON or OFF (ON/OFF/ONOFF)"},
	{1, "<%COMFSKINV=ONOFF>","PTT�|�[�g FSK�̘_�����]��ON/OFF (ON/OFF/ONOFF)", "Turns inverting logic (FSK) into ON or OFF (ON/OFF/ONOFF)"},
	{1, "<%Radio=COM2>","Radio�|�[�g��ݒ�", "Set Radio port"},
	{1, "<%RadioOut=\\$000000000F>","Radio�|�[�g�Ƀf�[�^���o��", "Output data to the radio port"},
	{1, "<%RadioCarrierKHz>","���O�̕␳�L�����A���g��(KHz)", "Adjusted carrier FREQ(KHz) of the radio"},
	{1, "<%RadioKHz>","���O��VFO���g��(KHz)", "VFO FREQ(KHz) of the radio"},
	{1, "<%RadioKHz=YAESU-HF,14073.000>","���O��VFO���g��(KHz)�̐ݒ�", "Set VFO FREQ(KHz) of the radio"},
	{1, "<%RadioMode>","���O�̃��[�h", "Mode of the radio"},
	{1, "<%RadioMode=CI-V,LSB>","���O�̃��[�h��ݒ�", "Set Mode of the radio"},
	{1, "<%PTTON>","PTT��ON�ɂ���", "Turns PTT into ON"},
	{1, "<%PTTOFF>","PTT��OFF�ɂ���", "Turns PTT into OFF"},
	{1, "<%FFTScale>","FFT�X�P�[��(0-100dB, 1-60dB, 2-���U��)", "FFT scale (0-100dB, 1-60dB, 2-Square amplitude)"},
	{1, "<%FFTScale=2>","FFT�X�P�[����ݒ�", "Set FFT scale"},
	{1, "<%FFTWidth=1000>","FFT�\����(500/1000/2000/3000)", "Choose FFT width(500/1000/2000/3000)"},
	{1, "<%SyncWidth=14>","Sync/Wave�\����(4-24)", "Choose Sync/Waveform width(4-24)"},
	{1, "<%ShowCH=1,ONOFF>","�T�u�`�����l��(1-8)�\��, ON/OFF/ONOFF", "Show sub-channel(1-8), ON/OFF/ONOFF"},
	{1, "<%SetCHSpeed=1,31.25>","�T�u�`�����l��(1-8)�̃{�[���[�g�ݒ�, 15�`300", "Set speed to the sub-channel(1-8), 15-300"},
	{1, "<%SetCHMode=1,GMSK>","�T�u�`�����l��(1-8)�̃��[�h�ݒ�", "Set mode to the sub-channel(1-8)"},
	{1, "<%ClearCHW=1>","�T�u�`�����l��(1-8)�̉�ʃN���A", "Clear window of the sub-channel(1-8)"},
	{1, "<%QSOON>","QSO�̊J�n(���O�ɋL�^)", "Start QSO (logging)"},
	{1, "<%QSOOFF>","QSO�̏I��(���O�ɋL�^)", "End of the QSO (logging)"},
	{1, "<%FREQ=7>","���O�̉^�p���g����ݒ�", "Set logging FREQ"},
	{1, "<%BAND=40m>","���O�̉^�p�o���h��ݒ�", "Set logging BAND"},
	{1, "<%LogMODE=SSB>","���O�̉^�p���[�h��ݒ�(�k��������Ŏ����ݒ�)", "Set logging MODE (null is auto)"},
	{1, "<%HisCall=<%Capture>>","����ǂ̃R�[����ݒ�", "Set his/her callsign"},
	{1, "<%HisRST=599>","����ǂ�RST��ݒ�", "Set his/her RST"},
	{1, "<%MyRST=599>","���ǂ�RST��ݒ�", "Set my RST"},
	{1, "<%Note=<%VARITYPE>>","Note(���l)�ɐݒ�", "Set note (Remarks)"},
	{1, "<%RefRXW>","��M��ʂ̎Q�Ɖ�ʂ��J��", "Show RX window with the editor"},
   	{1, "<%EditFile=memo.txt, 0>","�e�L�X�g�t�@�C���ҏW��ʂ��J��(Name, ReadOnly)", "Open text editer(Name, ReadOnly)"},
	{1, "<%SendFile=test.txt>","�e�L�X�g�t�@�C���̑��M", "Send file"},
	{1, "<%EditMacro=2>","�}�N���{�^��(1�`160)��ҏW", "Edit macro button (1-160)"},
	{1, "<%EditMacro=OnStart>","�C�x���g�}�N����ҏW(Event��)", "Edit event macro (Name of the event)"},
	{1, "<%EditMacro=AS(CW)>","AS(CW)�}�N����ҏW(Event)", "Edit AS(CW) macro"},
	{1, "<%EditMacro=MacroTxt.txt>","�e�L�X�g�t�@�C���̃}�N����ҏW", "Edit macro written in the text file"},
	{1, "<%MacroText=MacroTxt.txt>","�e�L�X�g�t�@�C���̃}�N�������s", "Execute macro written in the text file"},
	{1, "<%SaveMacro=Macros.mac>","�S�Ẵ}�N�����t�@�C���ɕۑ�", "Save all Macros"},
	{1, "<%LoadMacro=Macros.mac>","�S�Ẵ}�N�����t�@�C�����烍�[�h", "Load all Macros"},
	{1, "<%HEX2DEC=ABCD>","16�i����10�i���ɕϊ�", "Convert decimal to HEX"},
	{1, "<%CHAR=A>","�����R�[�h(10�i��)�ɕϊ�", "Convert character code (decimal)"},
	{1, "<%CHARX=A>","�����R�[�h(16�i��)�ɕϊ�", "Convert character code (HEX)"},
	{1, "<%CODE=82A0>","�����R�[�h(16�i��)�œ���", "Input as the character code (HEX)"},
	{1, "<%SP>","�X�y�[�X�����", "Input space"},
	{1, "<%CR>","CR�����", "Input CR"},
	{1, "<%BS>","BS�����", "Input BS"},
	{1, "<%TAB>","TAB�����", "Input TAB"},
	{1, "<%SkipCR>","�}�N�������̎���CR(���s)���X�L�b�v", "Skip next CR(Enter) in the macro sentence"},
	{1, "<%DisableCR>","�}�N��������CR(���s)�𖳌��ɂ���", "Disable CR(Enter) in the macro sentence"},
	{1, "<%EnableCR>","�}�N��������CR(���s)��L���ɂ���", "Enable CR(Enter) in the macro sentence"},
	{1, "<%DisableTAB>","�}�N��������TAB�𖳌��ɂ���", "Disable TAB in the macro sentence"},
	{1, "<%EnableTAB>","�}�N��������TAB��L���ɂ���", "Enable TAB in the macro sentence"},
	{1, "<%DisableSP>","�}�N�������̃X�y�[�X�𖳌��ɂ���", "Disable SPACE in the macro sentence"},
	{1, "<%EnableSP>","�}�N�������̃X�y�[�X��L���ɂ���", "Enable SPACE in the macro sentence"},
	{1, "<%Skip$=3,<%HisCall>>","�w��̕��������X�L�b�v(Ascii)", "Skip Ascii characters"},
	{1, "<%MSkip$=3,<%Note>>","�w��̕��������X�L�b�v(MBCS)", "Skip MBCS characters"},
	{1, "<%Find$=xx,ABCxxVVV>","�w��̕����������", "Find string"},
	{1, "<%StrLen=<%HisCall>>","������̒���", "String length"},
	{1, "<%MStrLen=<%Note>>","MBCS������̒���", "MBSC string length"},
	{1, "<%ONOFF=<%Cond=IsSQ>>","ON/OFF�𓾂�", "Get ON/OFF"},
	{1, "<%RepeatText=3,<%RepeatText=33,RY><%CR>>","�}�N��������̌J��Ԃ�", "Repeating the macro string"},
	{1, "<%IDLE>","�A�C�h���M����}��", "Insert idle signals"},
	{1, "<%DIDDLE=LTR>","RTTY��DIDDLE�R�[�h��ݒ�(BLK/LTR)", "Set DIDDLE code in RTTY (BLK/LTR)"},
	{1, "<%UOS=ON>","RTTY��UOS��ݒ�(ON/OFF/ONOFF)", "Set UOS in RTTY (ON/OFF/ONOFF)"},
	{1, "<%RTTYWaitC=0>","RTTY�̕����E�G�C�g��ݒ�(0-100)", "Set character wait in RTTY (0-100)"},
	{1, "<%RTTYWaitD=0>","RTTY��DIDDLE�E�G�C�g��ݒ�(0-100)", "Set DIDDLE wait in RTTY (0-100)"},
	{1, "<%RTTYWordOut=ON>","RTTY�̃��[�h�P�ʏo�͂�ݒ�(ON/OFF/ONOFF)", "Set word out in RTTY (ON/OFF/ONOFF)"},
	{1, "<%RTTYDEM=FFT>","RTTY�̕������ݒ�(IIR/FFT)", "Set demodulator in RTTY (IIR/FFT)"},
	{1, "<%TxShift=170.0>","RTTY/FSK-W�̑��M�V�t�g����ݒ�(10-450)", "Set TX's shift width in RTTY/FSK-W (10-450)"},
	{1, "<%RxShift=170.0>","RTTY/FSK-W�̎�M�V�t�g����ݒ�(10-450)", "Set RX's shift width in RTTY/FSK-W (10-450)"},
	{1, "<%ToUpper=<%HisName>>","�A�b�p�[�P�[�X(�啶��)�ɕϊ�", "Convert to upper case"},
	{1, "<%ToLower=<%HisCall> de <%MyCall>>","�����[�P�[�X(������)�ɕϊ�", "Convert to lower case"},
	{1, "<%IME=ON>","IME�𐧌䂷�� (ON/OFF/ONOFF)", "Control IME (ON/OFF/ONOFF)"},
	{1, "<%RepeatTX=3000>","�J��Ԃ����M�̎�M����(ms)��ݒ�", "Repeating TX mode (=RX times(ms))"},
	{1, "<%Repeat=10000>","�}�N���̌J��Ԃ�(ms)��ݒ�", "Repeating the macro (ms)"},
	{1, "<%OnTimer=<%WaterMsg=4,<%AFCFrequency>Hz>>","OnTimer�}�N����ݒ�", "Set OnTimer macro"},
	{1, "<%OnTimerInterval=1000>","OnTimer�}�N���̎��ԊԊu(ms)��ݒ�", "Set time interval(ms) of OnTimer macro"},
	{1, "<%Page=1>","���M��ʃy�[�W��؂�ւ� (1�`4)", "Choose TXW-page (1-4)"},
	{1, "<%AutoReturn>","�����I�ɑ��M��ʃy�[�W��߂�", "Return TXW-page automatically"},
	{1, "<%MoveTop>","�J�[�\����擪�Ɉړ�", "Move cursor to the TOP"},
	{1, "<%MoveEnd>","�J�[�\�����Ō�Ɉړ�", "Move cursor to the END"},
	{1, "<%ResetScroll>","��M��ʂ̃X�N���[����Ԃ�����", "Reset scroll in the RX window"},
	{1, "<%PopupTXW>","���M��ʂ̃|�b�v�A�b�v���j���[���J��", "Open Popup menu"},
	{1, "<%DupeText>","�P�O�̍s�Ɠ������e��}��", "Create dupe text"},
	{1, "<%SeekNext>","�{�^���y�[�W������", "Seek to the next Button page"},
	{1, "<%SeekPrev>","�{�^���y�[�W��O��", "Seek to the previous Button page"},
	{1, "<%SeekTop>","�{�^���y�[�W��擪��", "Seek to the top Button page"},
	{1, "<%DigitalLevel=16384>","�f�W�^���o�̓��x����ݒ�(1024 - 32768)", "Set digital output level (1024 - 32768)"},
	{1, "<%OutputVolume>","�o�̓{�����[��������ʂ��J��", "Open output volume"},
	{1, "<%InputVolume>","���̓{�����[��������ʂ��J��", "Open input volume"},
	{1, "<%Setup>","�ݒ��ʂ��J��", "Open Setup window"},
	{1, "<%SetupLog>","���O�ݒ��ʂ��J��", "Open Setup logging window"},
	{1, "<%SetupRadio>","���O�R���g���[���ݒ��ʂ��J��", "Open Setup radio command window"},
	{1, "<%Calibration>","�N���b�N�r����ʂ��J��", "Open calibration window"},
	{1, "<%BaseClock>","�x�[�X�N���b�N�l(Hz)", "Base clock(Hz)"},
	{1, "<%Clock>","RX�N���b�N�l(Hz)", "RX clock(Hz)"},
	{1, "<%Clock=11025.00>","RX�N���b�N�l��ݒ�", "Set RX clock"},
	{1, "<%TxOffset>","TX�I�t�Z�b�g�l(Hz)", "TX offset clock(Hz)"},
	{1, "<%TxOffset=0.00>","TX�I�t�Z�b�g�l��ݒ�", "Set TX offset clock"},
	{1, "<%DemodulatorClock>","������N���b�N�l(Hz)", "Demodulator clock(Hz)"},
	{1, "<%FFTClock>","FFT�N���b�N�l(Hz)", "FFT clock(Hz)"},
	{1, "<%FFTSize>","FFT�̃T�C�Y�i�_��)", "FFT size(points)"},
	{1, "<%WaterNoise>","�E�H�[�^�t�H�[���̌��o�m�C�Y���x��(dB)", "Sense noise level (dB) in WaterFall"},
	{1, "<%WaterNoise=35,65>","�E�H�[�^�t�H�[���̃m�C�Y���x���͈�(dB)��ݒ�", "Set noise level range (dB) in WaterFall"},
	{1, "<%WaterLevels>","�E�H�[�^�t�H�[���̃��x���z��", "Levels in WaterFall"},
	{1, "<%WaterLevels=10,60,134,192,220,240>","�E�H�[�^�t�H�[���̃��x���z����ݒ�", "Set levels in WaterFall"},
	{1, "<%WaterColors>","�E�H�[�^�t�H�[���̔z�F", "Colors in WaterFall"},
	{1, "<%WaterColors=0,FF0000,FFFFFF,FF,FFFF00,FF0000,FFFF00,FFFF,80FF,FF,FF,FF>","�E�H�[�^�t�H�[���̔z�F��ݒ�", "Set colors in WaterFall"},
	{1, "<%SpectrumColors>","�X�y�N�g�����̔z�F", "Colors in Spectrum"},
	{1, "<%SpectrumColors=0,FF00,FFFFFF,808080,FFFF00,FF0000>","�X�y�N�g�����̔z�F��ݒ�", "Set colors in Spectrum"},
	{1, "<%RxColors>","��M��ʂ̔z�F", "Colors in RX window"},
	{1, "<%RxColors=FFFFFF,0,FF0000,FF,E0E0E0>","��M��ʂ̔z�F��ݒ�", "Set colors in RX window"},
	{1, "<%TxColors>","���M��ʂ̔z�F", "Colors in TX window"},
	{1, "<%TxColors=FFFFFF,0,FF0000,FF,FFFFFF>","���M��ʂ̔z�F��ݒ�", "Set colors in TX window"},
	{1, "<%SoundName>","���̓T�E���h�̖��O", "Name of the input sound device"},
	{1, "<%SoundOutName>","�o�̓T�E���h�̖��O", "Name of the output sound device"},
	{1, "<%SoundDevice=MONO,-1>","�T�E���hCH(MONO/LEFT/RIGHT)�ƃf�o�C�XID�̐ݒ�", "Set CH.(MONO/LEFT/RIGHT) es device ID of the sound"},
	{1, "<%Suspend>","�T�X�y���h�ɂ���", "Suspend MMVARI"},
	{1, "<%Resume>","�T�X�y���h����������", "Resume MMVARI"},
	{1, "<%Wait=1000>","�w�莞��(ms)�E�G�C�g����", "Wait the time (ms)"},
	{1, "<%Execute=notepad.exe <%Folder>memo.txt>","�v���O�����̎��s", "Execute other program"},
	{1, "<%Shell=<%Folder>emmvari.txt>","�V�F���Ńh�L�������g���J��", "Open document by Shell32"},
	{1, "<%Exit>","MMVARI���I������", "Exit MMVARI"},
	{1, "<%ShutDown>","Windows���V���b�g�_�E������", "Shut down Windows"},
	{1, "<%YesNo=String>","Yes/No��ү�����ޯ��(Yes=6,No=7)", "Show Yes/No message(Yes=6,No=7)"},
	{1, "<%YesNoCancel=String>","Yes/No/Cancel��ү�����ޯ��(Yes=6,No=7,Cancel=2)", "Show Yes/No/Cancel message(Yes=6,No=7,Cancel=2)"},
	{1, "<%OkCancel=String>","Ok/Cancel��ү�����ޯ��(Ok=1,Cancel=2)", "Show Ok/Cancel message(Ok=1,Cancel=2)"},
	{1, "<%Error=Macro ERROR>","�G���[���b�Z�[�W��\��", "Show error message"},
	{1, "<%Warning=Macro WARNING>","�x�����b�Z�[�W��\��", "Show warning message"},
	{1, "<%Message=Macro message>","���b�Z�[�W��\��", "Show message"},
	{1, "<%WaterMsg=4,Metric=<%MetricMFSK>><%Repeat=1000>","�E�H�[�^�t�H�[���Ƀ��b�Z�[�W��\��(�ʒu=0-4)", "Show message in the WaterFall (Pos. 0-4)"},
	{1, "<%RxStatus=Status>","��M��ʂɃX�e�[�^�X��\��", "Show status in the RX window"},
	{1, "<%TableCount=AAA,BBB,CCC>","�e�[�u���̍��ڐ��𓾂�", "Get count of the table"},
	{1, "<%TableStr=1,AAA,BBB,CCC>","�e�[�u���̕�����𓾂�", "Get string of the table"},
	{1, "<%Table=<%BAUD>,20.0,31.25,45.0>","�e�[�u���̃C���f�N�b�X�𓾂�", "Get index of the table"},
	{1, "<%Menu=A,B,C,D>","���j���[�̕\��(Input$�ɓ���)", "Show menu (Put into Input$)"},
	{1, "<%MenuB=\x22<%Table=<%BAUD>,20.0,31.25,45.45,62.5>\x22,20.0,31.25,45.45,62.5>","�}�[�N�t�����j���[�̕\��(Input$�ɓ���)", "Show menu with mark (Put into Input$)"},
	{1, "<%Menu>","���j���[�C���f�b�N�X", "menu index"},
	{1, "<%Input=Input strings>","������̓���", "Input strings"},
	{1, "<%Input$>","���͂��ꂽ������", "The strings which was entered"},
	{1, "<%Click$>","��M��ʂŃN���b�N����������", "The strings which was clicked in the RX window"},
	{1, "<%CLICK$>","��M��ʂŃN���b�N����������(�啶��)", "The strings (upper case) which was clicked in the RX window"},
	{1, "<%vvv>","�e�X�g���b�Z�[�W(�p��)", "test message"},
	{2, "<%VVV>","�e�X�g���b�Z�[�W(���{��)", "test message"},
	{1, "<%KeyStroke=41>","�L�[(VK code)�������ė���", "Down and up the keyboard (VK code)"},
	{1, "<%KeyDown=12><%KeyStroke=<%CHARX=V>><%KeyUp=12>","�L�[(VK code)������(Shift=10,Ctrl=11,Alt=12)", "Down the keyboard(VK code, Shift=10,Ctrl=11,Alt=12)"},
	{1, "<%KeyUp=12>","�L�[(VK code)�𗣂�(Shift=10,Ctrl=11,Alt=12)", "Up the keyboard(VK code, Shift=10,Ctrl=11,Alt=12)"},
	{1, "<%DoMacro=2>","�}�N���{�^��(1�`160)�����s", "Execute macro button (1-160)"},
	{1, "<%DoEvent=OnMode>","�C�x���g�}�N�������s", "Execute event macro"},
	{1, "<%Events>","�C�x���g�̃��X�g", "List of the events"},
	{1, "<%ButtonName=1,Clear>","�}�N���{�^��(1�`160)�̖��O��ݒ�", "Set name of the button (1-160)"},
	{1, "<%ButtonContents=1,<%ClearTXW>>","�}�N���{�^��(1�`160)�̓��e��ݒ�", "Set contents of the button (1-160)"},
	{1, "<%PlayBack=ON>","�T�E���h�v���[�o�b�N�{�^���@�\�̐ݒ�(ON/OFF/ONOFF)", "Set Sound Playback function (ON/OFF/ONOFF)"},
	{1, "<%PlayBack=10>","�T�E���h�v���[�o�b�N(0�`60�b)�����s", "Execute Sound Playback (0-60s)"},
	{1, "<%PlayBackSpeed=5>","�T�E���h�v���[�o�b�N�̑��x(1�`20)��ݒ�", "Set speed of the Sound Playback (1-20)"},
	{1, "<%PlayBackButtons=60,30,15>","�T�E���h�v���[�o�b�N�{�^���̎��Ԃ�ݒ�", "Set time of the Sound Playback buttons"},
	{1, "<%PlaySound=sound.mmv>","�T�E���h�t�@�C���̍Đ�", "Sound playing from the file"},
	{1, "<%PlaySound>","�T�E���h�t�@�C���̍Đ��_�C�A���O��\������", "Show sound playing dialog"},
	{1, "<%RecordSound=sound.mmv>","�T�E���h�t�@�C���̘^��", "Sound recording to the file"},
	{1, "<%RecordSound>","�T�E���h�t�@�C���̘^���_�C�A���O��\������", "Show sound recording dialog"},
	{1, "<%QuickRecordSound>","�T�E���h�t�@�C���̘^��", "Sound recording (filename = Time stamp)"},
	{1, "<%StopPlayRecord>","�T�E���h�Đ�/�^���̒�~", "Close recording or playing"},
	{1, "<%SoundTime>","�Đ�/�^������(�b)", "Time (sec) of sound (playing or recording)"},
	{1, "<%Slider=CW speed,<%CWSpeed>,10,60,1,10>","�X���C�_�[��\��(����,�l,Min,Max,�ï��,�ڐ��̐�) Input$�ɓ���", "Show slider (Title,Value,Min,Max,Step,Scale) Put into Input$"},
	{1, "<%FileDialog=Text file,Text Files(*.txt)|*.txt|,Default,txt,>","�t�@�C���I���_�C�A���O��\��(Input$�ɓ���)", "Show choose file dialog box (Put into Input$)"},
	{1, "<%CPUBENCHMARK>","CPU�x���`�}�[�N�l (us)", "The values of CPU-benchmark (us)"},
	{1, "<%RANDOM=<%PTIME>>","�����̎�̏�����", "Initialization of a random seed"},
	{1, "<%RANDOM>","����(0�`32767)", "A random values (0 - 32767)"},
	{1, "<%String=Name>","#define�Œ�`�����������W�J", "Defined strings by #define"},
	{1, "<%CallProc=Name>","�v���V�W���[�����s", "Execute the procedure"},
	{1, "<%DebugProc=Name>","<%CallProc=...>�̃f�o�b�O��", "Debug version of <%CallProc=...>"},
	{1, "<%Format=%.3f,<%BAUD>>","�����ϊ�(C����)�w��œW�J (����������,��)", "Convert format (C Language) string"},
	{1, "<%Inv=<%Cond=IsSQ>>","�_���𔽓]", "Invert logic"},
	{1, "<%Floor=<%BAUD>>","�����_�ȉ���؂�̂�", "Returns the largest integer that is not greater than the argument"},
	{1, "<%Log=10>","���R�ΐ����v�Z", "Calculates logarithms"},
	{1, "<%Exp=2.302585092994046>","�w���֐� e �� x ����v�Z", "Calculates the exponential"},
	{1, "<%Sqrt=10>","���������v�Z", "Calculates the square root"},
	{1, "<%Pow=10,2>","x �� y ����v�Z", "Calculates x raised to the power of y"},
	{1, "<%Sin=0.5>","sin(x)���v�Z", "Calculates the sin(x)"},
	{1, "<%Cos=0.5>","cos(x)���v�Z", "Calculates the cos(x)"},
	{1, "<%Tan=0.5>","tan(x)���v�Z", "Calculates the tan(x)"},
	{1, "<%ArcTan=0.5>","arc-tan(x)���v�Z", "Calculates the arc-tan(x)"},
	{1, "<%Cond=IsSQ>","�������߂̃e�X�g����(0-FALSE, 1-TRUE)", "Test result of condition command (0-FALSE, 1-TRUE)"},
	{1, "<%ListSpeed=15.625,31.25,62.5,93.75,125.0,250.0>","Speed�{�b�N�X�̃��X�g��ݒ�", "Set list of Speed box"},
	{1, "<%ListCarrier=500,800,1000,1200,1500,1750,2000,2210>","Carrier�{�b�N�X�̃��X�g��ݒ�", "Set list of Carrier box"},
	{1, "<%ListRST=599,579,559,449,339>","RST�{�b�N�X�̃��X�g��ݒ�", "Set list of RST box"},
	{1, "<%ListLogFreq=1.8,3.5,7,10,14,18,21,24,28,50,144,430,1200>","���O���g���{�b�N�X�̃��X�g��ݒ�", "Set list of Log-FREQ box"},
	{1, "<%SetCaptureLimit>","������ߊl�̌����͈͂�ݒ�", "Set the limit of the capturing range"},
	{1, "<%ClearCaptureLimit>","������ߊl�̌����͈͂��N���A", "Clear the limit of the capturing range"},
	{1, "<%Font>","��M��ʂ̃t�H���g�p�����[�^(Name, Size, Charset)", "Font parameters of the RX window (Name, Size, Charset)"},
	{1, "<%Font=,14,>","��M/���M��ʂ̃t�H���g��ݒ�(=Name, Size, Charset)", "Sets font into the TX/RX window (=Name, Size, Charset)"},
	{1, "<%SetFocus>","���M��ʂɃL�[�{�[�h�t�H�[�J�X��ݒ肷��", "Sets keyboard focus to the TX window"},
	{1, "<%Folder>","MMVARI�̃t�H���_", "MMVARI's folder"},
	{1, "<%AddMenu=E&X,Caption&1,OnCaption1Click>","�g�����j���[�̒ǉ� (=Name,Caption,Procedure,Arg...)", "Add extension menu (=Name,Caption,Procedure,Arg...)"},
	{1, "<%InsertMenu=&H,&P,Caption&1, OnCaption1Click>","�g�����j���[�̑}�� (=Name,InsPos,Caption,Procedure,Arg...)", "Insert extension menu (=Name,InsPos,Caption,Procedure,Arg...)"},
	{1, "<%ShowMenu=&F, ONOFF>","���j���[�̕\�� (=Name...,ON/OFF/ONOFF)", "Show the menu (=Name...,ON/OFF/ONOFF)"},
	{1, "<%EnableMenu=&F, ONOFF>","���j���[�̋��� (=Name...,ON/OFF/ONOFF)", "Enable the menu (=Name...,ON/OFF/ONOFF)"},
	{1, "<%ShortCut=&V, &C, &1, Ctrl+1>","���j���[�ɃV���[�g�J�b�g��ݒ� (=Name...,Key)", "Set menu short cut (=Name...,Key)"},
	{1, "<%CheckMenu=&H, &P, ONOFF>","���j���[�Ƀ`�F�b�N�̕t���� (=Name...,ON/OFF/ONOFF)", "Set menu check (=Name...,ON/OFF/ONOFF)"},
	{1, "<%DeleteMenu=&X>","���j���[���폜 (=Name...)", "Delete menu (=Name...)"},
	{1, "<%DoMenu=&V,&C,&1>","���j���[�����s (=Name...)", "Execute the menu (=Name...)"},
	{1, "<%DoButton=FFT>","�{�^�����N���b�N����", "Click the button"},
	{1, "<%ShowHTML=home>","HTML/�E�F�[�u�T�C�g��\��", "Show html or Web site"},
	{1, "<%SendMessage=PSKGNRFUNC,0,1>","�E�C���h�E���b�Z�[�W�̑��M (=Name, wParam, lParam)", "Send window message (=Name, wParam, lParam)"},
//	{1, "<%SendMessage=this,16,0,0>","�E�C���h�E���b�Z�[�W�̑��M (this, uMsg, wParam, lParam)", "Send window message (this, uMsg, wParam, lParam)"},
//	{1, "<%CallDLL=QRZ.DLL,FuncName,<%HisCall>>","DLL�t�@���N�V�����̌Ăяo��", "Call the function in the DLL"},
	{1, "<%Memory>","���������(Load[%],Total[MB],Free[MB])", "Memory status(Load[%],Total[MB],Free[MB])"},
	{1, "<%BuffSize=4096>","�}�N���o�b�t�@�̍ŏ��̃T�C�Y��ݒ�(512-65536)", "Set minimum buffer size for Macro function (512-65536)"},
	{1, "<%EOF>","��`�̏I��", "End of the macro"},
	{0, NULL, NULL},
};

#if AN(mackeycom) >= MACLISTMAX
#error	macro key over follow
#endif

MACKEY	condcom[]={
	{1, "IsCall","Call�ɕ��������݂��鎞", "Letters exists in the Call-box"},
	{1, "IsName","Name�ɕ��������݂��鎞", "Letters exists in the Name-box"},
	{1, "IsHisRST","His�ɕ��������݂��鎞", "Letters exists in the His-box"},
	{1, "IsMyRST","My�ɕ��������݂��鎞", "Letters exists in the My-box"},
	{1, "IsQTH","QTH�ɕ��������݂��鎞", "Letters exists in the QTH-box"},
	{1, "IsNote","Note�ɕ��������݂��鎞", "Letters exists in the Note-box"},
	{1, "IsLocal","�����G���e�B�e�B�̎�", "Same entity (country)"},
	{1, "IsQSO","QSO�{�^���������Ă��鎞", "QSO button down"},
	{1, "IsDupe","�d��QSO�̏ꍇ", "Is dupe QSO?"},
	{1, "IsAFC","AFC��ON�̎�", "Is AFC ON?"},
	{1, "IsNET","NET��ON�̎�", "Is NET ON?"},
	{1, "IsTX","���M���̎�", "Is transmitting?"},
	{1, "IsPTT","PTT��ON�̎�", "Is PTT ON?"},
	{1, "IsSQ","�X�P���`���J���Ă��鎞", "Is Squelch open?"},
	{1, "IsTone","�V���O���g�[�����M���̎�", "Is single tone transmitting?"},
	{1, "IsTXEmpty","�����M���������݂��Ȃ���", "Letters do not exist in the TX window"},
	{1, "IsRXScroll","��M��ʂ��X�N���[�����̎�", "Is RX window scrolling?"},
	{1, "IsRepeat","�}�N�����J��Ԃ����̎�", "Is the macro repeating?"},
	{1, "IsIME","IME��ON�̎�", "Is IME ON?"},
	{1, "IsPlaying","�T�E���h�Đ����̎�", "Is sound playing?"},
	{1, "IsFileSending","�t�@�C�����M���̎�", "Is file sending?"},
	{1, "IsRecording","�T�E���h�^�����̎�", "Is sound recording?"},
	{1, "IsFile(test.txt)","�t�@�C�������݂��鎞", "File exists"},
	{1, "IsDefined(Name)","������ϐ������݂��鎞", "Variable strings exists"},
	{1, "IsMBCS(<%HisName>)","�������MBCS���܂܂�鎞", "Is string including MBCS?"},
	{1, "IsAlpha(<%MyNR>)","�����񂪃A���t�@�x�b�g�̎�", "Is string alphabet?"},
	{1, "IsNumber(<%MyNR>)","�����񂪐����̎�", "Is string number?"},
	{1, "IsUOS","RTTY��UOS��ON�̎�", "Is UOS active in RTTY?"},
	{1, "IsRadioLSB","Rig��LSB���[�h�̎�", "Is LSB of the radio?"},
	{1, "IsCaptureText(CQ)","��M�e�L�X�g�ɕ����񂪑��݂��鎞", "Does string exist in the received text?"},
	{1, "IsOnTimer","OnTimer�}�N�������s���̎�", "Is OnTimer executing?"},
	{1, "IsIdle","�A�C�h����Ԃ̎�", "Is idle?"},
	{1, "IsEnglish","�p�ꃂ�[�h�̎�", "Is English mode running?"},
	{1, "IsMfskCenter","mfsk�����S���g�����킹�̎�", "Is center FREQ handling in mfsk?"},
	{1, "IsMfskMetricSq","mfsk�����g���b�N�X�P���`�̎�", "Is squelch metric in mfsk?"},
	{1, "Is1stCR","���M�J�n���Ɏ�����CR/LF�o�͂��鎞", "Is CR/LF sending automatically at the beginning?"},
	{1, "IsPlayBack","�T�E���h�v���[�o�b�N�@�\��ON�̎�", "Is sound play back enabled?"},
	{1, "IsCodeMM","MMVARI�R�[�h(VariJA, VariHL,...)�̎�", "Is MMVARI code (VariJA, VariHL,...)?"},
	{1, "IsCall(<%CLICK$>)","�����񂪃R�[���T�C���̎�", "Is the strings call sign?"},
	{1, "IsRST(<%CLICK$>)","������RST�̎�", "Is the strings RST?"},
	{1, "IsMenu(&H, &U)","���j���[�����݂��鎞", "Menu exists?"},
	{1, "IsMenuEnabled(&H, &U)","���j���[��������Ă��鎞", "Is the menu enabled?"},
	{1, "IsMenuChecked(&H, &U)","���j���[���`�F�b�N����Ă��鎞", "Is the menu checked?"},
	{1, "IsMenuVisible(&H, &U)","���j���[���\������Ă��鎞", "Is the menu visible?"},
	{1, "IsButton(QSO)","�{�^�������݂��鎞", "Button exists?"},
	{1, "IsButtonEnabled(QSO)","�{�^����������Ă��鎞", "Is the button enabled?"},
	{1, "IsButtonDown(QSO)","�{�^����������Ă��鎞", "Is the button down?"},
	{1, "ValFreq>=144","���O���g���̔�r", "Compare logging FREQ"},
	{1, "ValBaud==31.25","�`�����x(Bps)�̔�r", "Compare speed (baudrate)"},
	{1, "ValCarrierRX<1500","��M�L�����A���g���̔�r", "Compare RX carrier FREQ"},
	{1, "ValCarrierTX<1500","���M�L�����A���g���̔�r", "Compare TX carrier FREQ"},
	{1, "ValPage!=1","���M��ʃy�[�W�̔�r", "Compare TX window page"},
	{1, "ValTimeLocal<1200","����(Local)�̔�r", "Compare Local time"},
	{1, "ValTimeUTC>=0900","����(UTC)�̔�r", "Compare UTC time"},
	{1, "ValDateLocal>=0801","���t(Local)�̔�r", "Compare Local date"},
	{1, "ValDateUTC<0401","���t(UTC)�̔�r", "Compare UTC date"},
	{1, "ValScope","�X�R�[�v�̏�Ԃ��r(FFT=0, WF=1, SYNC=2)", "Compare condition of the scope (FFT=0, WF=1, SYNC=2)"},
	{1, "ValMacro(<%VER>)>="VERNO,"�}�N���W�J������̐��l���r", "Compare value of the Macro"},
	{1, "ValMenu","�I�����ꂽ<%Menu=...>�̃C���f�b�N�X�ԍ����r", "Compare value of the selected <%Menu=...> index"},
	{1, "StrCall==JA3QRZ","�R�[���T�C���̔�r", "Compare his callsign"},
	{1, "StrMode==GMSK","���[�h�̔�r", "Compare current Mode"},
	{1, "StrBand==40m","���O���g���i�o���h�j�̔�r", "Compare logging BAND"},
	{1, "StrHisRST==599","HisRST�̔�r", "Compare HisRST"},
	{1, "StrMyRST==599","MyRST�̔�r", "Compare MyRST"},
	{1, "StrNote==???","Note�̔�r", "Compare Note"},
	{1, "StrEntity==JA","�G���e�B�e�B�̔�r", "Compare the entity of his callsign"},
	{1, "StrContinent==AS","�嗤�̔�r", "Compare the continent of his callsign"},
	{1, "StrVARITYPE==JA","VARICODE���(JA/HL/BV/BY/STD)�̔�r", "Compare type of the VARICODE(JA/HL/BV/BY/STD)"},
	{1, "StrPLATFORM==XP","Windows�v���b�g�t�H�[��(95/98/98SE/ME/NT/2000/XP)�̔�r", "Compare platform of the Windows(95/98/98SE/ME/NT/2000/XP)"},
	{1, "StrMacro(<%VER>)=="VERNO,"�}�N���W�J������̔�r", "Compare strings of the Macro"},
	{1, "#else","�c��̂��ׂĂŐ^", "Rest of all"},
	{1, "#endif","�����u���b�N���I��", "Exit condition block"},
	{1, "#macro <%TX>","�}�N���R�}���h���p�X1�Ŏ��s", "Execute macro at the pass 1"},
	{1, "#proc Name","�v���V�W���[�̓o�^ (Name, Dummy...)", "Register procedure (Name, Dummy...)"},
	{1, "#endp","�v���V�W���[�̓o�^�̏I��", "End of the procedure"},
	{1, "#repeat 3","#repeat �` #endp�܂ł��J��Ԃ�", "Repeat the block #repeat to #endp"},
	{1, "#define Name Strings","������𖼑O�ϐ��ɒ�`", "Define variable strings to the name"},
	{1, "#DEFINE Name Strings","������𖼑O�ϐ��ɒ�`(INI�t�B�A���ɕۑ�)", "Define variable strings to the name (Save to INI file)"},
	{1, "#DELETE Name", "���O�ϐ��܂��̓v���V�W���[���폜", "Delete variable string or procedure"},
	{1, "#DELETEALL", "���ׂĂ̖��O�ϐ����폜", "Delete all variable strings and procedures"},
	{1, "#exit","�}�N�����̏I��(�p�X�P�ŏI��)", "Exit macro at the pass 1"},
	{1, "#comment","�R�����g�s", "Comment line"},
	{0, NULL, NULL},
};
static int g_Pos[2]={0,0};
static int g_TopPos[2]={0,0};
static POINT g_xySave;//={0,0};
//---------------------------------------------------------------------
__fastcall TMacroKeyDlg::TMacroKeyDlg(TComponent* AOwner)
	: TForm(AOwner)
{
  g_xySave.x = 0;
  g_xySave.y = 0;
	m_pDlg = NULL;
	FormStyle = ((TForm *)AOwner)->FormStyle;
	Font->Name = ((TForm *)AOwner)->Font->Name;
	Font->Charset = ((TForm *)AOwner)->Font->Charset;
	if( sys.m_MsgEng ){
//		Caption = "Choose macro";
		CancelBtn->Caption = "Close";
		SBIns->Caption = "Insert";
		SBSpace->Caption = "Space";
        SBCR->Caption = "Enter";
        SBUndo->Caption = "Undo";
		SBFind->Caption = "Find";
		SBPrint->Caption = "Print";

        SBIns->Hint = "Insert current command";
        SBSpace->Hint = "Insert 'Space'";
        SBCR->Hint = "Insert 'Enter'";
        SBUndo->Hint = "Cancel of the operation";
        SBFind->Hint = "Find strings";
        SBPrint->Hint = "Print the list (Right click for create file)";
        Grid->Hint = "Insert command for double click (Sort - click the title)";
	}
    OnWave();
	m_Type = 0;
    m_fSort = FALSE;
    m_fSortType = 0;
    m_fDisDblClick = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::FormDestroy(TObject *Sender)
{
	g_xySave.x = Left;
	g_xySave.y = Top;
	g_Pos[m_Type] = Grid->Row;
	g_TopPos[m_Type] = Grid->TopRow;
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::UpdateUI(int row)
{
	int r = row - 1;
	if( r >= 0 ){
		SBIns->Enabled = TRUE;
	}
	else {
		SBIns->Enabled = FALSE;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::UpdateUndo(BOOL undo)
{
	SBUndo->Enabled = undo;
}
//---------------------------------------------------------------------
int __fastcall TMacroKeyDlg::AddMacKey(MACKEY *mp, int n)
{
	for( ; mp->r; mp++){
		if( (mp->r == 2) && sys.m_MsgEng ) continue;
		if( (mp->r == 3) && !sys.m_MsgEng ) continue;
		mackey[n] = *mp;
		n++;
	}
	return n;
}
//---------------------------------------------------------------------
void __fastcall TMacroKeyDlg::Execute(int x, int y, TMacEditDlg *pDlg, int type)
{
	m_fSort = FALSE;
	m_Type = type;
	Grid->RowCount = AddMacKey(type ? condcom : mackeycom, 0) + 1;
	if( (g_Pos[type] > 0) && (g_Pos[type] < Grid->RowCount) ){
		Grid->Row = g_Pos[type];
		Grid->TopRow = g_TopPos[type];
	}
	UpdateUI(Grid->Row);
	if( type ){
		Caption = sys.m_MsgEng ? "Choose Condition command (pass 1 command)" : "��������(�p�X1����)�̑I��";
    }
    else {
		Caption = sys.m_MsgEng ? "Choose Macro command (pass 2 command)" : "�}�N���R�}���h(�p�X2����)�̑I��";
    }
    SBSpace->Enabled = !type;
	SBCR->Enabled = !type;
#if DEBUG
	char bf[256];
	sprintf(bf, "%s (Commands=%u/%u)", Caption.c_str(), Grid->RowCount-1, MACLISTMAX);
    Caption = bf;
#endif
	m_pDlg = pDlg;
	if( (x >= 0) && (y >= 0) ){
		if( g_xySave.x && g_xySave.y ){
			Left = g_xySave.x;
       		Top = g_xySave.y;
	    }
    	else {
			Left = x;
    	    Top = y;
	    }
    }
	Visible = TRUE;
	OnWave();
    Grid->SetFocus();
}
//---------------------------------------------------------------------
LPCSTR __fastcall TMacroKeyDlg::GetComment(const MACKEY *mp)
{
	LPCSTR pCom;

	if( sys.m_MsgEng ){
		pCom = mp->pEng;
		if( pCom == NULL ){
			pCom = mp->pJpn;
		}
	}
	else {
		pCom = mp->pJpn;
	}
    return pCom;
}
//---------------------------------------------------------------------
void __fastcall TMacroKeyDlg::GridDrawCell(TObject *Sender, int Col,
	  int Row, TRect &Rect, TGridDrawState State)
{
	char	bf[256];
	Grid->Canvas->Font->Height = -12;
	Grid->Canvas->FillRect(Rect);
	int X = Rect.Left + 4;
	int Y = Rect.Top + 2;

	if( Row ){
		Row--;
		bf[0] = 0;
		switch(Col){
			case 0:
                OnWave();
				strcpy(bf, mackey[Row].pKey);
				break;
			case 1:
				strcpy(bf, GetComment(&mackey[Row]));
				break;
		}
		Grid->Canvas->TextRect(Rect, X, Y, bf);
	}
	else {		// �^�C�g��
		LPCSTR	_tt[]={
			"Commands","Comments",
		};
		Grid->Canvas->TextRect(Rect, X, Y, _tt[Col]);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::GridSelectCell(TObject *Sender, int Col,
	  int Row, bool &CanSelect)
{
	UpdateUI(Row);
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::CancelBtnClick(TObject *Sender)
{
	g_Pos[m_Type] = Grid->Row;
	g_TopPos[m_Type] = Grid->TopRow;
	Visible = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::SBInsClick(TObject *Sender)
{
	if( m_pDlg ){
		if( Grid->Row ){
			LPCSTR p = mackey[Grid->Row - 1].pKey;
			if( m_Type ){
				char bf[256];
                sprintf(bf, (*p == '#') ? "%s\r" : "#if %s\r", p);
                p = bf;
            }
        	m_pDlg->OnInsertText(p);
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::SBSpaceClick(TObject *Sender)
{
	if( m_pDlg ){
       	m_pDlg->OnInsertText(" ");
    }
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::SBCRClick(TObject *Sender)
{
	if( m_pDlg ){
       	m_pDlg->OnInsertText("\r");
    }
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::SBUndoClick(TObject *Sender)
{
	if( m_pDlg ){
		m_pDlg->Undo();
	}
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::GridMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if( Y < Grid->DefaultRowHeight ){
		if( Button == mbLeft ){
			int type = (X <= Grid->ColWidths[0]) ? 0 : 1;
            if( type == m_fSortType ){
				m_fSort = m_fSort ? FALSE : TRUE;
            }
            else {
				m_fSort = TRUE;
            }
            m_fSortType = type;
            Sort(m_fSort, type);
            Grid->Invalidate();
			m_fDisDblClick = TRUE;
        }
    }
    else {
		m_fDisDblClick = FALSE;
    }
}
//---------------------------------------------------------------------------
static int _USERENTRY _cmpK(const void *s, const void *t)
{
	const MACKEY *sp = (const MACKEY *)s;
    const MACKEY *tp = (const MACKEY *)t;
    return strcmpi(sp->pKey, tp->pKey);
}
//---------------------------------------------------------------------------
static int _USERENTRY _cmpC(const void *s, const void *t)
{
	const MACKEY *sp = (const MACKEY *)s;
    const MACKEY *tp = (const MACKEY *)t;
	LPCSTR pComS, pComT;
	if( sys.m_MsgEng ){
		pComS = sp->pEng;
		if( pComS == NULL ) pComS = sp->pJpn;
		pComT = tp->pEng;
		if( pComT == NULL ) pComT = tp->pJpn;
	}
	else {
		pComS = sp->pJpn;
		pComT = tp->pJpn;
	}
    return strcmpi(pComS, pComT);
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::Sort(BOOL fSort, int type)
{
	if( fSort ){
		qsort(mackey, Grid->RowCount - 1, sizeof(MACKEY), type ? _cmpC : _cmpK);
    }
    else {
		AddMacKey(m_Type ? condcom : mackeycom, 0);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::GridDblClick(TObject *Sender)
{
	if( m_fDisDblClick ){
		m_fDisDblClick = FALSE;
        return;
    }
    SBInsClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::FormKeyPress(TObject *Sender, char &Key)
{
	if( isalpha(Key) ){
		int c = toupper(Key);
		if( !m_fSort || m_fSortType ){
			m_fSort = TRUE;
            m_fSortType = 0;
            Sort(m_fSort, m_fSortType);
        }
		MACKEY *mp = mackey;
        LPCSTR p;
        for( int i = 0; i < Grid->RowCount - 1; i++, mp++ ){
        	p = mp->pKey;
			if( p ){
	            if( *p == '<' ) p++;
	            if( *p == '%' ) p++;
    	        if( toupper(*p) == c ){
                    int top = i;
                    if( top < 1 ) top = 1;
					Grid->TopRow = top;
                	Grid->Row = i + 1;
	                break;
    	        }
            }
        }
		Grid->Invalidate();
    }
}
//---------------------------------------------------------------------------
static BOOL __fastcall jstrstr(LPCSTR s, LPCSTR p)
{
	CMBCS *pM = &MainVARI->m_RxSet[0].m_MBCS;
    int l = strlen(p);
	for( ; *s; s++ ){
		if( !strnicmp(s, p, l) ) return TRUE;
		if( pM->IsLead(BYTE(*s)) ) s++;
        if( !*s ) break;
    }
    return FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::SBFindClick(TObject *Sender)
{
	AnsiString as;
    if( InputMB("MMVARI", sys.m_MsgEng ? "Find string" : "����������", as) ){
		if( as.IsEmpty() ) return;
		MACKEY mac[MACLISTMAX];
        memset(mac, 0, sizeof(mac));
		int N = 0;
		MACKEY *wp = mac;
		MACKEY *mp = mackey;
        LPCSTR p;
        int i;
        for( i = 0; i < Grid->RowCount - 1; i++, mp++ ){
        	p = mp->pKey;
			if( p ){
				if( jstrstr(p, as.c_str()) ){
					memcpy(wp, mp, sizeof(MACKEY)), wp++;
                    N++;
                }
				else {
					p = GetComment(mp);
                    if( p && jstrstr(p, as.c_str()) ){
						memcpy(wp, mp, sizeof(MACKEY)), wp++;
                        N++;
                    }
                }
            }
		}
        mp = mackey;
        for( i = 0; i < Grid->RowCount - 1; i++, mp++ ){
			BOOL f = FALSE;
			MACKEY *rp = mac;
            for( int j = 0; j < N; j++, rp++ ){
				if( !memcmp(rp, mp, sizeof(MACKEY)) ){
					f = TRUE;
                    break;
                }
            }
            if( !f ){
				memcpy(wp, mp, sizeof(MACKEY)), wp++;
                N++;
            }
        }
        memcpy(mackey, mac, sizeof(mackey));
        m_fSort = FALSE;
        Grid->TopRow = 1;
        Grid->Row = 1;
        Grid->Invalidate();
    }
}
//---------------------------------------------------------------------------
// ���X�g�̈��
void __fastcall TMacroKeyDlg::SBPrintClick(TObject *Sender)
{
	CWaitCursor w;
#if 1		// �ݒ�_�C�A���O
	TPrinterSetupDialog *pBox = new TPrinterSetupDialog(this);
#else		// ����_�C�A���O
	TPrintDialog *pBox = new TPrintDialog(this);
	pBox->Options.Clear();
#endif
	OnWave();
    if( pBox->Execute() ){
		OnWave();
		char bf[512];

		Printer()->Title = VERTTL2;
		Printer()->BeginDoc();

		int kcount = Grid->RowCount - 1;			// ���ڂ̐�
		int pyw = Printer()->PageHeight;			// �p���̏c��
        int pxw = Printer()->PageWidth;				// �p���̉���
		int xoff = pxw * 5 / 100;					// ���E�̃}�[�W��
        int yoff = pyw * 5 / 100;					// �㉺�̃}�[�W��
        int yw = pyw - (yoff*2);					// ����̈�̏c��
        int xw = pxw - (xoff*2);					// ����̈�̉���
		int pline;
        if( yw > xw ){		// �c��
			pline = 50;
        }
        else {				// ����
			pline = 25;
        }
        int lyw = yw / (pline + 2);					// �P�s������̃s�N�Z����
		yw = lyw * (pline + 2);

		TCanvas *pCanvas = Printer()->Canvas;
        pCanvas->Font->Name = Font->Name;
        pCanvas->Font->Charset = Font->Charset;
        pCanvas->Font->Height = -(lyw * 8 / 10);
        pCanvas->Font->Color = clBlack;
        pCanvas->Pen->Color = clBlack;
		int pagemax = (kcount + pline - 1) / pline;	// �y�[�W�̐�
        TRect rc;									// �\�̘g�͈̔�
        rc.Left = xoff; rc.Top = yoff;
        rc.Right = rc.Left + xw; rc.Bottom = rc.Top + yw;
        int xt = (lyw * 1) / 10;					// �����̃I�t�Z�b�g
        int yt = (lyw * 1) / 10;					// �����̃I�t�Z�b�g
        if( !xt ) xt++;
        if( !yt ) yt++;
        int xp = ((rc.Right - rc.Left) * 4 / 10);	// �����������̈ʒu
		const MACKEY *mp = mackey;
        int n = 0;
		for( int i = 1; i <= pagemax; i++ ){
			OnWave();
			int y = rc.Top;
			for( int j = 0; j < (pline+2); j++, y += lyw ){
				switch(j){
					case 0:			// �^�C�g���̕`��
						sprintf(bf, "%s - " VERTTL2, m_Type ? "Conditions" : "Macros");
                        pCanvas->TextOut(rc.Left, y, bf);
						sprintf(bf, "%u/%u", i, pagemax);
                        pCanvas->TextOut(rc.Right - pCanvas->TextWidth(bf), y, bf);
                    	break;
                    case 1:			// ���ږ��̕`��
                        pCanvas->TextOut(rc.Left+xt, y+yt, sys.m_MsgEng ? "Commands" : "�R�}���h");
                        pCanvas->TextOut(rc.Left+xp+xt, y+yt, sys.m_MsgEng ? "Comments" : "�@�\/����");
                    	break;
                    default:		// �e���ڂ̕`��
						if( n < kcount ){
	                        pCanvas->TextOut(rc.Left + xt, y+yt, mp->pKey);
    	                    pCanvas->TextOut(rc.Left + xp + xt, y+yt, GetComment(mp));
                            n++; mp++;
                        }
                    	break;
                }
				pCanvas->MoveTo(rc.Left, y+lyw); pCanvas->LineTo(rc.Right, y+lyw);
            }
			y = rc.Top + lyw;
            pCanvas->MoveTo(rc.Left, y);
            pCanvas->LineTo(rc.Right, y);
            pCanvas->LineTo(rc.Right, rc.Bottom);
            pCanvas->LineTo(rc.Left, rc.Bottom);
            pCanvas->LineTo(rc.Left, y);
			pCanvas->MoveTo(rc.Left + xp, y); pCanvas->LineTo(rc.Left + xp, rc.Bottom);
			if( i < pagemax ) Printer()->NewPage();
        }
		Printer()->EndDoc();
		OnWave();
    }
    delete pBox;
}
//---------------------------------------------------------------------------
void __fastcall TMacroKeyDlg::SBPrintMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if( Button == mbRight ){
		TSaveDialog *pBox = new TSaveDialog(this);
		pBox->Options << ofOverwritePrompt;
	    pBox->Options << ofNoReadOnlyReturn;
		if( sys.m_MsgEng ){
			pBox->Title = "Create list file";
			pBox->Filter = "Text Files(*.txt)|*.txt|";
		}
		else {
			pBox->Title = "�ꗗ�\�t�@�C�����쐬";
			pBox->Filter = "�e�L�X�g�t�@�C��(*.txt)|*.txt|";
		}
		pBox->FileName = "Temp";
		pBox->DefaultExt = "txt";
		pBox->InitialDir = sys.m_TextDir;
		OnWave();
		if( pBox->Execute() == TRUE ){
			OnWave();
			FILE *fp = fopen(AnsiString(pBox->FileName).c_str(), "wt");	//JA7UDE 0428
			if( fp ){
				const MACKEY *mp = mackey;
        	    for( int i = 1; i < Grid->RowCount; i++, mp++ ){
					fprintf(fp, "%d\t%s\t%s\n", i, mp->pKey, GetComment(mp));
            	}
                fclose(fp);
            }
		}
		delete pBox;
    }
}
//---------------------------------------------------------------------------
