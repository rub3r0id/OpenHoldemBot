# The Bot Logic (OH-script)

## OH-Script

Every bot needs some poker-specific logic to decide how to act.
OpenHoldem provides a basic scripting-language for that, which was
inherited from WinHoldem. The logic is action-centered, i.e. everytime
it is your turn the following basic questions have to be answered:

- “shall I go allin?” — f\$allin (boolean, interpreting 0 as false and
  everything else as true)

- “shall I click a betpot-button?” – f\$betpot_2_1...f\$betpot_1_4 for
  twice betpot to 1/4 betpot.

- “shall I raise, and how much?” — f\$betsize

- “shall I (min-)raise” — f\$raise (mainly for Fixed Limit; boolean)

- “shall I call” — f\$call (boolean)

- “shall I check” — f\$check (boolean)

- “shall I fold” — f\$fold (boolean)

Per default f\$check evaluates to true if it is free to call and f\$fold
is always true, so if all questions were answered with 0 or false, your
hand-will be check-folded.

<figure>
<img src="images/autoplayer_functions_formula_editor.JPG" />
</figure>

OH-script uses *C(++)*-style mathematical expressions, i.e. the same
mathematical operators like the C-programming-language and OpenHoldems
built-in symbols. An example:

    ##f$sitout##
    0                                // 0=off 1=on  
    && issittingin                   // i am sitting in  
    && (betround==2 || betround==3)  // it is the flop or turn  
    && nopponentsdealt<=5            // 5 or less opponents 

# The DLL-extension

Every bot needs such a formula file, even if it is programmed in *C++*.
There are no standalone C++-bots; the user-*DLL* is just a programming
extensions that make it possible to extend the functionality of
OpenHoldem by providing additional symbols (constants and parameter-less
functions). The very minimum is a small OH-script or *OpenPPL* formula
that redirects every primary function to a DLL-function.

    ##notes##
    // Very small OH-formula, that redirects 
    // primary functions to C++-functions in the user.DLL.

    ##f$alli##
    dll$alli

    ##f$betsize##
    dll$betsize

    ##f$raise##
    dll$rais

    ##f$call##
    dll$call

In practice formulas can become arbitary complex, but those are the
basic principles you will need to understand. We will deal with the
details of bot-programming in the chapter about OH-script.

## Parse-Time and Run-Time Errors 

The OpenHoldem scripting language will detect various error conditions
for you and warn you of these conditions. Each time a formula is loaded,
it is “parsed” for correctness – if there are any syntactical errors
upon this parse, then a message box will be displayed that alerts you to
the location of this error.

Additionally, several classes of run-time errors will be detected,
including divide-by-zero and infinite recursion. Note that the OH-Script
language does not support recursion in any form, due to the absence of
the assignment operator and function parameters to control the recursion
depth.

<figure>
<img src="images/run_time_error.JPG" />
</figure>

## Default Bot

All OH-script-bots are self-contained. Once all questions f\$alli ..
f\$fold have been answered the best action is well-defined. Therefore
OH-script does not support a default-bot. “All power (and
responsibilities) to the user” is the motto of OH-script. Things are
slightly different for OpenPPL, the other programming language, however.
An OpenPPL-bot might be “incomplete”. The end of a code-section might be
reached without a matching action being found, then the default.bot will
take over. We will talk about OpenPPL and this default-bot in the next
chapters briefly; all the details are in an extra handbook, the
OpenPPL-manual.
