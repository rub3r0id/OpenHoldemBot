# The Formula Editor

!!! Formula-description not here!!!, but in introduction!!!

Figure 5.6-37 OpenHoldem Formula Editor

The large control on the right side of the window displays the code for
whatever function you have currently selected in the tree on the left.
Primary FunctionsFunction Description

## f\$allin

This function instructs the Autoplayer to move all-in, either with the
slider, or by entering the bet into the SWAG box, depending on the
parameters in the Table Map. If this function evaluates to a non-zero
result, and an appropriate control is present on the table (slider, swag
field), then the Autoplayer will move all in.

## f\$swag

This function instructs the Autoplayer to place a stated wager (SWAG) by
entering the bet into the SWAG box. If this function evaluates to a
non-zero result, and the SWAG box is present on the table, then the
Autoplayer will enter the results of f\$swag into the SWAG box and
confirm the bet.

## f\$raise

This function instructs the Autoplayer to raise. If this function
evaluates to a non-zero result, and the raise button is present on the
table, then the Autoplayer will click the raise button.

## f\$call

This function instructs the Autoplayer to call. If this function
evaluates to a non-zero result, and the call button is present on the
table, then the Autoplayer will click the call button.Secondary
FunctionsThe following table describes the secondary functions. These
are secondary, because they do not directly instruct the Autoplayer to
take action, but rather are used indirectly to determine the action,
some of which are not the traditional poker actions of all-in, raising,
checking, calling or folding.Function Description

## f\$P

This function is intended to evaluate to the number of opponents that
should be simulated when OpenHoldem calculates various symbols.The
symbols influenced by this function are those calculated by the Iterator
(see {The Iterator} section}, prwin, prlos, and prtie, and also by the
symbols prwinnow, prlosnow, and handrankp.The f\$P value is important to
these symbols because it determines how many opposing hands are
simulated. The f\$P value will radically affect the values of these
symbols. For example, the higher the f\$P value the more opponent hands
will be simulated and your win probability will be lower. Similarly, the
lower the f\$P value the less opponent hands will be simulated and your
win probability will be higher. For instance, AA against 9 opponents
(f\$P==9) has about a 30% chance of winning, assuming every hand stays
for the showdown (no-foldem). AA against 1 opponent (P=1) has about an
80% chance of winning. The possible values for f\$P are 0 to 22, both
inclusive. If f\$P exceeds 22, it will be set to 22, as 22 is the
maximum number of players our imaginary HoldEm table would be able to
play (22 opponents \* 2 cards = 44 cards, my two cards, the 5 common
cards).

## f\$srai

This function is a support function for f\$swag. The intent is that
f\$srai specifies the amount to raise above the current bet, and that
f\$swag then further adjusts that based on the style that the individual
casino uses to post SWAG bets. Here is an example of a vanilla f\$swag
function that calls f\$srai:

    ##f$swag##
    f$srai>0 ? ((((f$swag_adjust + f$srai)/sblind)+.5)^0)*sblind : 0

    ##f$swag_adjust##
    swagtextmethod == 3 ? (call + currentbet) : 
    swagtextmethod == 2 ? (call) : 
    0

Note that this f\$swag also rounds your bet to the nearest sblind.

## f\$prefold

If this function evaluates to non-zero, and a pre-fold button is visible
on the poker table window (as defined in the Table Map), then OpenHoldem
will engage that pre-fold button as soon as it can (which may be before
it is your turn to act). A good example of a f\$prefold function might
be the following:

    ##f$prefold##
    br==1 
    && nplayersdealt>4 
    && handrank2652>2652*0.66 
    && !currentbet && !f$swag &&!!!??? && !f$raise && !f$call

## f\$delay

The function controls how long to delay, once the specified number of
stable frames have been seen (see {Preferences} section}, to take a
poker action. The function evaluates to the delay time in
milliseconds.An example of this might be:

## f\$chat

f\$playThis function controls how the Autoplayer interacts with the
sitin, sitout, and leave buttons as defined in the Table Map. The
possible values that this function can return are explicit and limited.
Any other return values are ignored. The allow return values and their
meaning are: -2, Leave table -1, No change (if you are sitting out, stay
out, if sitting in stay that way) 0, Sit out 1, Sit in/Stay
inf\$evraisf\$evcallHelper FunctionsThe following table describes the
helper functions. These are not used by the Autoplayer.Function
Description

## Notes

This is a free form function for you to use as you please. This is
typically used for usage instructions and version notes.

## dll

Contains a filename or path to a DLL to load by default. For example:
my_user_dll.dll

## f\$test

This function is intended to be used to test expressions. Whatever is
typed in here gets calculated as a whole when the Calc button is
clicked. f\$test can be referenced from other formulas, although that is
not recommended, as f\$test is really intended as a
development/debugging aid.

## f\$debug

The debug function operates differently than the other function. Its
purpose is to allow for arbitrary expressions to be evaluated and the
results of those expressions to be displayed. To add a new expression
add a new line with an equal sign, followed by the expression. For
example:

    = 2+2
    = f$UserDefinedFormula
    = nopponents

In order for the results to be displayed you must either press the
’Calc’ or ’Auto’ button. The ’Auto’ button will recalculate the debug
formula once each heartbeat. For example:

    4 = 2+2
    1 = f$UserDefinedFormula
    6 = nopponents

If an expression is invalid it will be reported where the result would
normally be found.

## Menu Options

Figure 5.11-38 Formula Editor - File menuThe File menu has three options
to control how changes made to your formula are applied back to the
production formula:Apply: Copy changes made to the working formula to
the production formula and keep the Formula Editor window openOK: Copy
changes made to the working formula to the production formula and close
the Formula Editor windowCancel: Discard changes made to the working
formula and close the Formula Editor windowFigure 5.11-39 Formula
Editor - Edit menuThe Edit menu has a number of options:Undo, Redo,
Find, Cut, Copy, Paste, Delete Text, Select All: These are all standard
Windows menu items that operate in the standard way.Font: This menu
option opens the standard Windows font selector dialog to allow you to
select the font to display in the Scintilla editor window.

Settings: This opens a window that allows you to set the Bankroll,
Defcon, NIT, and Rake parameters of the formula file. These settings can
be used in your formulas, and are referenced by some symbols.

Hand List: When a Hand List is selected, this will open the Hand List
Editor window so you can specify which starting hands belong in the
selected Hand List. See the section about Hand Lists for more
information.

Figure 5.11-40 Formula Editor - View menu

The View menu has the standard Windows toolbar option, plus several
OpenHoldem specific options:

Show Line Numbers,

Show Selection Margin,

Show Folding Margin, and Syntax Coloring provide access to features of
the Scintilla Control (see <http://www.scintilla.org> for more
information). Sort UDFs and Group UDFs allow for grouping and sorting of
User Defined Functions that you create. These options simply allow for
ease of navigation, especially for formulas with large numbers of
UDFs.Figure 5.11-41 Formula Editor - Debug menuFigure 5.11-42 Formula
Editor - Help menu

The Help menu provides links to the OpenHoldem Wiki and to the
OpenHoldem discussion forums.ToolbarFigure 5.11-43 OpenHoldem Formula
Editor toolbar

From left to right, the buttons on the Main toolbar are:

- New function/hand list (empty document)

- Rename function/hand list (pencil)

- Delete function/hand list (big X)

- Open the Windows font selection dialog (two blue letter As)

- Open the Formula Parameters window (hand pointing at a document)

- Open the Hand List Editor window (3x3 squares)
