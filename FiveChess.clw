; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFiveChessDlg
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FiveChess.h"

ClassCount=4
Class1=CFiveChessApp
Class2=CFiveChessDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_FIVECHESS_DIALOG
Resource2=IDR_MAINFRAME
Class4=CBoard
Resource3=IDD_ABOUTBOX
Resource4=IDR_MAIN_MENU

[CLS:CFiveChessApp]
Type=0
HeaderFile=FiveChess.h
ImplementationFile=FiveChess.cpp
Filter=N

[CLS:CFiveChessDlg]
Type=0
HeaderFile=FiveChessDlg.h
ImplementationFile=FiveChessDlg.cpp
Filter=D
LastObject=CFiveChessDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=FiveChessDlg.h
ImplementationFile=FiveChessDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_VERSION

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FIVECHESS_DIALOG]
Type=1
Class=CFiveChessDlg
ControlCount=0

[CLS:CBoard]
Type=0
HeaderFile=Board.h
ImplementationFile=Board.cpp
BaseClass=CWnd
Filter=W
LastObject=CBoard
VirtualFilter=WC

[MNU:IDR_MAIN_MENU]
Type=1
Class=?
Command1=ID_NEW_GAME
Command2=ID_DRAW_GAME
Command3=ID_EXIT_GAME
CommandCount=3

