Attribute VB_Name = "Module1"
Private Declare Function StartKeySave Lib "Keydll.dll" _
    (ByVal interval As Long, _
    ByVal path As Long, _
    ByVal T_only As Long) As Long
    
Private Declare Function EndKeySave Lib "Keydll.dll" () As Long
    

Sub Main()
Dim a As Long
a = StartKeySave(10, 2, 1)

Dim ret As Long
'��¼ԭ����Window Procedure��λַ
preWinProc = GetWindowLong(Form1.hwnd, GWL_WNDPROC)
'�趨form��window Procedure��wndproc
ret = SetWindowLong(Form1.hwnd, GWL_WNDPROC, AddressOf wndproc)
'ר�����ڴ���ע�����ػ���Ϣ�ػ񼰴����¼�__����

End Sub
Sub OnEnd()
Dim a As Long
a = CStr(EndKeySave())
End Sub
