# Mouse DLL<span id="sec:Mouse-DLL" label="sec:Mouse-DLL"></span> 

The mouse DLL extension provides for a user-specified handling of mouse
actions. The standard, reference mouse.dll that is shipped with
OpenHoldem performs very un-human-like mouse activities. For example,
instantly warping the mouse pointer to a location on the button and
clicking is unlikely to be human behavior. A human is more likely to
start the mouse moving, accelerate to the target, then decelerate as the
pointer nears the position of the button. Simulating mouse movements
that are more human-like may help to avoid detection by casions.

The mouse DLL extension is available if you would like to implement
custom mouse action behavior. The source code for the reference
mouse.dll implementation can be found on Google Code in the source code
repository.

Two methods must be exposed in your mouse.dll in order to interface
properly with OpenHoldem.

“MouseClick” is called when OpenHoldem wants to click a mouse button on
a specific location on the screen. The prototype for the “MouseClick”
method is:

    MOUSEDLL_API int MouseClick(const HWND hwnd, const RECT rect, const MouseButton button, const int clicks, const HWND restore_focus, const POINT restore_cursor);

“MouseClickDrag” is called when OpenHoldem wants to click a mouse button
at a specific location on the screen, hold it, drag the cursor to
another location, and then release it. Dragging is from rect.left to
rect.right, halfway between rect.top and rect.bottom. The prototype for
the “MouseClickDrag” method is:

    MOUSEDLL_API int MouseClickDrag(const HWND hwnd, const RECT rect, const HWND restore_focus, const POINT restore_cursor);

<table>
<thead>
<tr class="header">
<th style="text-align: left;">Parameter</th>
<th style="text-align: left;">Description</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td style="text-align: left;">hwnd (in)</td>
<td style="text-align: left;">the HWND of the window to take the mouse
action on</td>
</tr>
<tr class="even">
<td style="text-align: left;">rect (in)</td>
<td style="text-align: left;">the bounding rectangle of the area to take
action on – this generally corresponds to a Table Map Region record
rectangle, like those that define button click areas; this rectangle is
in relative client context</td>
</tr>
<tr class="odd">
<td style="text-align: left;">button (in)</td>
<td style="text-align: left;"><p>the mouse button to be clicked, this is
an enum:</p>
<pre><code>enum MouseButton 
{ 
    MouseLeft, 
    MouseMiddle, 
    MouseRight 
}</code></pre></td>
</tr>
<tr class="even">
<td style="text-align: left;">clicks (in)</td>
<td style="text-align: left;">the number of clicks of the specified
button</td>
</tr>
<tr class="odd">
<td style="text-align: left;">restore_focus (in)</td>
<td style="text-align: left;">the HWND of the window to return focus,
active and foreground to, after the action has been taken; if this is
NULL, no focus resotre is requested</td>
</tr>
<tr class="even">
<td style="text-align: left;">restore_cursor (in)</td>
<td style="text-align: left;">a POINT to return the cursor to, after the
action has been taken; if POINT.x and POINT.y are set to -1, then no
cursor return is requested</td>
</tr>
</tbody>
</table>
