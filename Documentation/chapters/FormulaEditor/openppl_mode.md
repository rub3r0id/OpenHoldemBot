# OpenPPL-Mode

OpenHoldem uses per default the main autoplayer functions (f\$allin,
f\$betsize, etc.). We call this default mode OH-script-mode. It is more
or less compatibel to the former WinHoldem behaviour. However if you
develop OpenPPL profiles the main autoplayer functions won’t be used;
OpenHoldem will use f\$preflop..f\$river instead and the formula editor
will switch to OpenPPL mode as soon as the formula contains a *non-empty
f\$preflop* function. Then all primary autoplayer-functions will be
hidden and a subtree with the four main OpenPPL functions will be shown
instead.

<figure>
<img src="images/openppl_mode.JPG" />
</figure>

If your formula-editor is in OH-script mode then just create a new
user-defined function, call it “f\$preflop”, start editing it, apply
your changes and reopen the editor.

<figure>
<img src="images/creating_f_preflop.JPG" />
</figure>
