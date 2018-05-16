VERSION 5.00
Begin VB.Form Form1 
   AutoRedraw      =   -1  'True
   BackColor       =   &H00808080&
   BorderStyle     =   0  'None
   Caption         =   "Form1"
   ClientHeight    =   1230
   ClientLeft      =   9675
   ClientTop       =   4470
   ClientWidth     =   5325
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1230
   ScaleWidth      =   5325
   ShowInTaskbar   =   0   'False
   Begin VB.CommandButton af 
      Caption         =   "退出"
      BeginProperty Font 
         Name            =   "华文宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   3840
      TabIndex        =   3
      Top             =   240
      Width           =   1095
   End
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   200
      Left            =   1320
      Top             =   960
   End
   Begin VB.CommandButton cm3 
      Caption         =   "最小化"
      BeginProperty Font 
         Name            =   "华文宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   2640
      TabIndex        =   2
      Top             =   240
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "停止"
      BeginProperty Font 
         Name            =   "华文宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   1440
      TabIndex        =   1
      Top             =   240
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "开始"
      BeginProperty Font 
         Name            =   "华文宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   360
      TabIndex        =   0
      Top             =   240
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function StartKeySave Lib "Keydll.dll" _
    (ByVal interval As Long, _
    ByVal path As Long, _
    ByVal T_only As Long) As Long
    
Private Declare Function EndKeySave Lib "Keydll.dll" () As Long
    
Const C As Long = 0
Const D As Long = 1
Const E As Long = 2
Const This As Long = 4


    

Private Sub af_Click()
Print CStr(EndKeySave())
End
End Sub

Private Sub cm3_Click()
Me.Visible = False
Me.Hide

End Sub

Private Sub Command1_Click()
    Print CStr(StartKeySave(10, 2, 1))
End Sub

Private Sub Command2_Click()
Print CStr(EndKeySave())
End Sub

Private Sub Form_Load()
Print CurDir


End Sub

Private Sub Form_Unload(Cancel As Integer)
Print CStr(EndKeySave())
End Sub

Private Sub Timer1_Timer()
'Me.ShowInTaskbar = False
End Sub
