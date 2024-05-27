# Setting process CPU affinity - Sample Code 

In some cases it may be beneficial to force poker client process to work
off one CPU in multiprocessor machines (or dual VCPU VMs). Good example
is OnGame, which uses much more CPU on dual CPU machines than on single
CPU machines. This is of course a problem with their software but they
are unlikely to fix it.

The downside is that poker software operations (browsing lobby, updates,
table management, etc.) are now forced to work with one CPU, so
multitabling (4+) may be taxing CPU0 - make sure to observe the
behaviour with and without forcing affinity, and draw your own
conclusions.

Here is the code that will set the CPU affinity of PokerClient_Exe to
CPU0 (first CPU): Only one process should exist, \$PokerClient_Exe is
your lobby.

    Local $PIDs = ProcessList($PokerClient_Exe) 
    Local $OpenProcessHandle = _WinAPI_OpenProcess(
        $PROCESS_QUERY_INFORMATION+$PROCESS_SET_INFORMATION, False, $PIDs[1][1]) 
    Local $Process_Affinity_Before_Setting = _WinAPI_GetProcessAffinityMask(
        $OpenProcessHandle) 
    ;MsgBox(0, "Affinity Before Setting", $Process_Affinity_Before_Setting, 3)
    _WinAPI_SetProcessAffinityMask($OpenProcessHandle, 0x01)
    $Process_Affinity_After_Setting = _WinAPI_GetProcessAffinityMask(
        $OpenProcessHandle) 
    ;MsgBox(0,"Affinity After Setting", $Process_Affinity_After_Setting, 3) 
