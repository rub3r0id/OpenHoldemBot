# Keyboard DLL<span id="sec:Keyboard-DLL" label="sec:Keyboard-DLL"></span>

The keyboard DLL extension provides for a user-specified handling of
keyboard actions. The standard, reference keybaord.dll that is shipped
with OpenHoldem performs very un-human-like keyboard actions. For
example, there is no delay between keystrokes. When entering a betsize,
a human is likely to have somewhat random delays between keypresses as
the betsize amount is entered into the betsize box. Simulating keyboard
actions that are more human-like may help to avoid detection by casions.

The keyboard DLL extension is available if you would like to implement
custom keyboard action behavior. The source code for the reference
keyboard.dll implementation can be found on Google Code in the source
code repository.

Two methods must be exposed in your keyboard.dll in order to interface
properly with OpenHoldem.

“SendString” is called when OpenHoldem wants to send a string to the
poker client. Generally, this method is expected to click in the
specified rectangle first, to activate it. The prototype for the
“SendString” method is:

    KEYBOARDDLL_API int SendString(const HWND hwnd, const RECT rect, const CString s, const bool use_comma, const HWND restore_focus, const POINT restore_cursor);

“SendKey” is called when OpenHoldem wants to send a single key to the
poker client. Generally, this method is expected to click in the
specified rectangle first, to activate it. The prototype for the
“SendKey” method is:

    KEYBOARDDLL_API int SendKey(const HWND hwnd, const RECT rect, UINT vkey, const HWND restore_focus, const POINT restore_cursor);

| Parameter | Description |
|:---|:---|
| hwnd (in) | the HWND of the window to take the mouse action on |
| rect (in) | the bounding rectangle of the area to click in to activate – this generally corresponds to a Table Map Region record rectangle, like the chat box or the betsize field; this rectangle is in relative client context; if the members of the RECT struct are {-1,-1,-1,-1} then do not click in the rectangle first |
| s (in) | the string to be sent to the poker client |
| use_comma (in) | if true, then use a “comma” instead of a “dot” as the decimal separator |
| vkey (in) | the VKEY code of the key to send to the poker client |
| restore_focus (in) | the HWND of the window to return focus, active and foreground to, after the action has been taken; if this is NULL, no focus resotre is requested |
| restore_cursor (in) | a POINT to return the cursor to, after the action has been taken; if POINT.x and POINT.y are set to -1, then no cursor return is requested |
