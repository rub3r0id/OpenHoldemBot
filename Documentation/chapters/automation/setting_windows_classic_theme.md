# Setting Windows Classic Display Theme

Below is some AutoIt code (reproduced from the Wiki:
<http://www.maxinmontreal.com/wiki/index.php5?title=Setting_Windows_Classic_Display_Theme_-_Sample_Code>)
to set your display / dekstop theme to Windows Classic. Typically used
at the beggining of the hopper script to force Windows Classic theme,
because XP can revert to XP style after reboot, which happens from time
to time.

    Local $Theme_To_Use = 'Windows Classic'
    Local $ScreenSaver_To_Use = '(None)'
    Run('rundll32.exe shell32.dll,Control_RunDLL desk.cpl,,5')
    WinWait('Display Properties')
    ControlCommand('Display Properties', , _
        'ComboBox1', 'SelectString', $Theme_To_Use)
    ; SELECT SCREEN SAVER TAB
    ControlCommand('Display Properties', "", _
        12320, "TabRight", "")
    ControlCommand('Display Properties', "", _
        12320, "TabRight", "")
    While (ControlGetText('Display Properties', "", 1303)) = ""
       Sleep(100)
    WEnd
    ControlCommand('Display Properties', _
       , 'ComboBox1', 'SelectString', $ScreenSaver_To_Use)
    ControlClick('Display Properties', , 'Button7')
    $OptWTMM = Opt('WinTitleMatchMode', 4)
    WinWait('classname=CoverWindowClass')
    WinWaitClose('classnam=CoverWindowClass')
    Opt('WinTitleMatchMode', $OptWTMM)
    ; DONE
