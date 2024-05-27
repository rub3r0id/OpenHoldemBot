# Avoid race-conditions

Race-conditions happen if two or more processes interrupt each other and
try to access the same resource at the same time. For example it might
be, that OpenHoldem tries to enter a betsize at its poker table, but
then your hopper grabs the mouse and interrupts the bot in the middle of
an action. All kind of unexpected results can happen.

The good news: there is a solution to this problem. OpenHoldem will take
care of race-conditions automatically; it will synchronize the
autoplayer-actions of all instances, including actions taken by the
rebuy-function and by the chat-function. It uses a system-wide mutex to
ensure exclusive access to the keyboard and the mouse. Unfortunatelly
OpenHoldem is not the only program, which uses these resources; usually
the hopper competes for them, too.

So any good hopper should wait with its actions, until OpenHoldem has
finished its input; it has to implement the same protection-mechanism
and wait for the same mutex. The default name of that mutex is
“OHAntiColl”, but it can be changed in the preferences to your liking.

An example AutoIT-hopper-code has been provided by USBFreak
(<http://www.maxinmontreal.com/wiki/index.php5?title=System_Wide_Mutex_Handling_-_Sample_Code>):

## System Wide Mutex Handling - Sample Code

> Below are 3 functions you’ll need if you plan to avoid OH and hopper
> collisions over mouse and keyboard inputs. As you may know, OH ensures
> it can act on the table in a consistent manner by seizing control of
> mouse / keyboard input (system wide mutex), performing its actions
> (clicking buttons, entering the betsize in text field etc.) and then
> releasing mutex so other applications can perform their tasks.
>
> This works fine as long as you run one or few OH instances, and do not
> have a very active hopper to manage them. Once you are past that point
> and start running many tables with as many OH instances, plus moving
> tables around, browsing lobby etc., a situation where OH may interfere
> with hopper operations in the middle of an important task occurs,
> resulting in very unpredictable behaviour.
>
> To avoid such a possibility, you may want to implement mutex handling
> in your hopper using below code.

## The idea:

1.  Create mutex lock at the start of your hopper. This seizes control
    of keyboard / mouse and no other application can send any input
    using them until mutex is released/unlocked.

2.  Find a good time in your hopper loop when game state is stable (no
    lobby browsing, table opening / closing etc.) and release mutex for
    a period of time (in my case this is (number of OH instances opened
    \* 1) + 2 seconds). This allows OH instances to grab mutex control
    for themselves, perform any pending actions, and release mutex
    control again.

3.  Once the predetermined period of time expires, create mutex lock
    again, and proceed with hopper operations knowing nothing can
    interfere with mouse / keyboard.

4.  At the end of your hopper, release/unlock mutex.

## Main hopper loop

    ;START YOUR HOPPER, CREATE MUTEX LOCK 
    MutexLock() 
    $Global_Mutex_Handle = _CreateMutex("OHAntiColl") 
    ;ENTERING HOPPER LOOP 
    While (1) 
        ;... HOPPER OPERATIONS 
        ;... GAME STATE STABLE, UNLOCK MUTEX 
        MutexUnlock($Global_Mutex_Handle) 
        ;... WAIT FOR OH TO PERFORM ACTIONS 
        ;... TIME EXPIRED, CREATE MUTEX LOCK AGAIN 
        MutexLock() 
    wend 
    ;END OF HOPPER, RELEASE MUTEX 
    MutexUnlock($Global_Mutex_Handle) 
    ;END OF HOPPER, CLOSE MUTEX HANDLE 
    Close_Mutex_Handle($Global_Mutex_Handle)

## Hopper functions

    Func _CreateMutex($sOccurenceName) 
        Local $ERROR_ALREADY_EXISTS = 183 
        $Global_Mutex_Handle = DllCall("kernel32.dll", 
            "int", "CreateMutex", "int", 0, 
            "long", 1, "str", $sOccurenceName) 
        $lastError = DllCall("kernel32.dll", "int", "GetLastError") 
        If $lastError[0] = $ERROR_ALREADY_EXISTS Then 
            Return SetError($lastError[0], $lastError[0], 
                $Global_Mutex_Handle[0]) 
        EndIf 
        Return SetError(0, 0, $Global_Mutex_Handle[0]) 
    EndFunc ;==>_GetMutex

    Func MutexUnlock($Global_Mutex_Handle)        
        Local $releasemutex = DllCall("kernel32.dll", "int", 
            "ReleaseMutex", "long", $Global_Mutex_Handle)        
        Return (IsArray($releasemutex) And $releasemutex[0] > 0)  
    EndFunc   ;==>_ReleaseMutex

    Func Close_Mutex_Handle($hMutex)        
        Local $aCH = DllCall("Kernel32.dll", "int", 
            "CloseHandle", "hwnd", $Global_Mutex_Handle)        
        Return (IsArray($aCH) And $aCH[0] > 0)    
    EndFunc

    Func _API_WaitForSingleObject($Global_Mutex_Handle, $dwMilliseconds)
        Local $aResult = DllCall("kernel32.dll", "long", 
            "WaitForSingleObject", "long", $Global_Mutex_Handle, 
            "long", $dwMilliseconds)        
        Return $aResult[0]    
    EndFunc   ;==>_API_WaitForSingleObject

    Func MutexLock()        
        While 1                
            $Global_Mutex_Handle = _CreateMutex("OHAntiColl");                
            If @error = 0 Then                        
                ;SUCCESSFULLY CREATED AND LOCKED MUTEX                        
                ExitLoop                
            Else                        
                ;WE WILL EXAMINE MUTEX TO SEE IF IT IS RELEASED   
                Local $result = _API_WaitForSingleObject(
                    $Global_Mutex_Handle, 30000); 
                ;WAIT FOR MUTEX FOR 30 SECONDS                        
                If $result = 0 Or $result = 128 Then
                    ;SUCCESSFULLY LOCKED MUTEX                                
                    ExitLoop                      
                EndIf                
            EndIf                
            ;WAIT A BIT BEFORE TRYING AGAIN
            ;WE ARE NOT PROCEEDING UNTIL WE HAVE CONTROL OF MUTEX                
            Sleep(100)        
        WEnd    
    EndFunc ;==>MutexLock
