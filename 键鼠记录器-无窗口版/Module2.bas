Attribute VB_Name = "Module2"
'专门用于处理注销、关机消息截获及处理事件__开始
Declare Function SetWindowLong Lib "user32" Alias "SetWindowLongA" _
(ByVal hwnd As Long, ByVal nIndex As Long, ByVal dwNewLong As Long) As Long
Declare Function GetWindowLong Lib "user32" Alias "GetWindowLongA" _
(ByVal hwnd As Long, ByVal nIndex As Long) As Long
Declare Function CallWindowProc Lib "user32" Alias "CallWindowProcA" _
(ByVal lpPrevWndFunc As Long, ByVal hwnd As Long, ByVal Msg As Long, _
ByVal wParam As Long, ByVal lParam As Long) As Long

Public Const GWL_WNDPROC = (-4)
Public Const WM_ENDSESSION = &H16
Public Const WM_QUERYENDSESSION = &H11

Public preWinProc As Long

Public Function wndproc(ByVal hwnd As Long, ByVal Msg As Long, _
ByVal wParam As Long, ByVal lParam As Long) As Long
If Msg = WM_QUERYENDSESSION Then '如果是注销
    OnEnd
     '在这里，你可以加一些自定义操作
    End '程序退出，防止用户因为本程序未退出而无法注销。
Else
    If Msg = WM_ENDSESSION Then '如果是关机
        If wParam = 0 Then '代表将顺利关机或LogOff，这时便得做正常结束程序的操作
        '在这里，你可以加一些自定义操作
        OnEnd
        End '程序退出，防止用户因为本程序未退出而无法关机。
        End If
    End If
End If
'将之送往原来的Window Procedure
wndproc = CallWindowProc(preWinProc, hwnd, Msg, wParam, lParam)
End Function
'专门用于处理注销、关机消息截获及处理事件__结束



