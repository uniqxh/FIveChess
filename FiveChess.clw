; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBoard
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FiveChess.h"

ClassCount=6
Class1=CFiveChessApp
Class2=CFiveChessDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_set_dlg
Resource2=IDR_MAINFRAME
Class4=CBoard
Resource3=IDD_ABOUTBOX
Resource4=IDD_FIVECHESS_DIALOG
Class5=set_dlg
Class6=CConnection
Resource5=IDR_MAIN_MENU

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
LastObject=ID_DRAW_GAME
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FiveChessDlg.h
ImplementationFile=FiveChessDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAboutDlg

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
LastObject=ID_RESTART
VirtualFilter=WC

[MNU:IDR_MAIN_MENU]
Type=1
Class=?
Command1=ID_NEW_GAME
Command2=ID_DRAW_GAME
Command3=ID_RESTART
Command4=ID_EXIT_GAME
CommandCount=4

[DLG:IDD_set_dlg]
Type=1
Class=set_dlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_host,button,1342177289
Control4=IDC_client,button,1342177289
Control5=IDC_ip,SysIPAddress32,1342242816
Control6=IDC_STATIC,static,1342308866
Control7=IDC_STATIC,static,1342308866
Control8=IDC_port,edit,1350631552

[CLS:set_dlg]
Type=0
HeaderFile=set_dlg.h
ImplementationFile=set_dlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_DRAW_GAME
VirtualFilter=dWC

[CLS:CConnection]
Type=0
HeaderFile=Connection.h
ImplementationFile=Connection.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CConnection

