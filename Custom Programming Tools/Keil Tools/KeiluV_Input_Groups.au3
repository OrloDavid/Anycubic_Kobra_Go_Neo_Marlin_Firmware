

HotKeySet("{ESC}", "Terminate")

;Seup Vars
Global $Start_P_I = 0
Global $timeout = 0
Global $Msg_KPOP = "Keil - Auto Directory Populate"
Global $Msg_Pre = " "
Global $msgmain = ""
Global $Msg_Prep_Line = "Prepare New Line"
Global $Msg_New_Item = "New Entry"
Global $Msg_Item_Name = "Item Name"
Global $Msg_Item_Entered = "Item Entered"
Global $Msg_Post = "Press ESC at any time to exit"
Global $Res_X = @DesktopWidth / 2
Global $Res_Y = @DesktopHeight / 2
Global $Wiin_Title_MPI = "Manage Project Items"
Global $listBoxControlID = 1546
Global $editControlID = "[CLASS:Edit; INSTANCE:1]"
Global $Win_Title_uVision = ("[REGEXPTITLE:(?i)(.*- µVision *)]")
$file = "group-dirs.txt"
$fileOpen = FileOpen($file, 0)
$Lines = 0
$Line = 0
Global $Filearray = FileReadToArray($fileOpen)

ToolTip("Starting" & @CRLF & "Do Not Touch Mouse or Keyboard!" & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
Sleep(2000) ; Sleep to give tooltip time to display

;Check if file is open and exists
If $fileOpen = -1 Then
	ToolTip("", $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	MsgBox(0, "Error", "Unable to open file.")
	Exit
EndIf


ToolTip("Targeting Window" & @CRLF & "Keil uVision" & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)

;Find the current open version of Keil
WaitForKeil()
WinActivate($Win_Title_uVision)
Sleep(1000)
ToolTip("Targeting Window" & @CRLF & "Manage Project Items " & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)

If WinExists($Wiin_Title_MPI) Then
	ToolTip("SaWeeeeet" & @CRLF & "Manage Project Items Found" & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
ElseIf $Start_P_I = 0 Then
	ToolTip("Launching" & @CRLF & "Let's Switch Gears" & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	Open_Manage_P_I()
Else
	Sleep(5000)
	WaitForPM()
EndIf


; Activate the window
WinActivate($Wiin_Title_MPI)
WinWaitActive($Wiin_Title_MPI)
ToolTip("Targeting Window" & @CRLF & "Listbox 1546" & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
Sleep(450)
ControlFocus($Wiin_Title_MPI, "", $listBoxControlID)
ToolTip("Find End of Groups" & @CRLF & $Msg_Prep_Line & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
ControlSend($Wiin_Title_MPI, "", $listBoxControlID, "{DOWN 90}")
ToolTip("Ready to Enter Groups" & @CRLF & $Msg_New_Item & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
Sleep(2000)

; Main Loop
For $Lines = 0 To UBound($Filearray) - 1
	$Line = $Filearray[$Lines]
	Sleep(30)
	ToolTip($Msg_New_Item & @CRLF & $Line & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	ControlSend($Wiin_Title_MPI, "", $listBoxControlID, "{DOWN}")
	Sleep(50)
	ControlSend($Wiin_Title_MPI, "", $listBoxControlID, "{DOWN}")
	Sleep(50)
	ControlSend($Wiin_Title_MPI, "", $listBoxControlID, "{SPACE}")
	Sleep(50)
	ControlFocus($Wiin_Title_MPI, "", $editControlID)
	ToolTip($Msg_New_Item & @CRLF & $Line & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	Sleep(5)
	ControlSend($Wiin_Title_MPI, "", $editControlID, $Line)
	Sleep(50)
	ControlSend($Wiin_Title_MPI, "", $editControlID, "{ENTER}")
	ToolTip($Msg_Item_Entered & @CRLF & $Line & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	Sleep(30)
Next
Exit
; End Main Loop

;Give some time in case app was just launched 300,000 Milliseconds / 5 Minutes
Func WaitForKeil()
	$timeout = 0
	ToolTip("Waiting" & @CRLF & "Targeting Keil uVision" & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	Do
		Sleep(50)
		$timeout = $timeout + 1
	Until WinExists($Win_Title_uVision) Or $timeout > 300000
	Sleep(1000)
	If WinExists($Win_Title_uVision) Then
		ToolTip("Keil uVision Found" & @CRLF & "Attracting" & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	Else
		MsgBox(0, "Error", "Unable to open file.")
		Exit
	EndIf
EndFunc   ;==>WaitForKeil

Func WaitForPM()
	$timeout = 0
	ToolTip("Waiting" & @CRLF & "Targeting Project Items Window" & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	Do
		Sleep(50)
		$timeout = $timeout + 1
	Until WinExists($Wiin_Title_MPI) Or $timeout > 600000
	Sleep(1000)
	If WinExists($Wiin_Title_MPI) Then
		ToolTip("", $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
		ToolTip("Project Items Found" & @CRLF & "Attracting" & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	Else
		MsgBox(0, "Error", "Unable to open file.")
		Exit
		Exit
	EndIf
EndFunc   ;==>WaitForPM

;Manually opening PI
Func Open_Manage_P_I()
	$Start_P_I = $Start_P_I + 1
	ToolTip("Waiting" & @CRLF & "Give App Time to Load" & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	Sleep(2500)
	WinActivate($Win_Title_uVision)
	WinWaitActive($Win_Title_uVision)
	Sleep(150)
	ToolTip("", $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	ToolTip("Open Sesame" & @CRLF & "The Magic Recipe" & @CRLF & $Msg_Post, $Res_X, $Res_Y, $Msg_KPOP, 0, 2)
	Send("{ALTDOWN}")
	Sleep(150)
	Send("p")
	Sleep(150)
	Send("m")
	Sleep(150)
	Send("p")
	Sleep(150)
	Send("{ALTUP}")
	WaitForPM()
EndFunc   ;==>Open_Manage_P_I

Func Terminate()
	Exit
EndFunc   ;==>Terminate
