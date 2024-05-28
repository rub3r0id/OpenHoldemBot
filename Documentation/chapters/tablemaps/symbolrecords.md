# Symbol Records 

## Description 

Symbol records are a general purpose record type that serves many
different purposes within OpenHoldem and OpenScrape. The common
characteristic of these records is that they all contain a name and a
free-form text field. The interpretation of that text field is
different, depending on the name of the symbol record. The table in the
technical reference section below describes how the free-form text is
interpreted for each different Symbol record type.

## Manipulating symbol records using OpenScrape 

To create a new symbol record, select the “Symbols” category in the
record tree display on the Table Map Editor window, and click the “New”
button. A window will be displayed that allows you to enter the
free-form text for this new record. To edit an existing symbol record,
select the record in the record tree display on the Table Map Editor
window, and click the “Edit” button. A window will be displayed that
allows you to adjust the free-form text for this record, or change the
record name itself. To delete an existing symbol record, select the
record in the record tree display on the Table Map Editor window, and
click the “Delete” button. A window will be displayed asking for
verification of this action.

Note: The Insert and Delete keys can also be used as a shortcut for
adding and deleting Symbol records.

In the case of the “New” and “Edit” actions, the window that pops up
also contains a field for “Titlebar text”, a button to parse the title
bar text, and a field to display the parse results. These three controls
are only relevant if the record name is one of the ttlimits types. If a
ttlimits record type is selected, these fields will be enabled,
otherwise they will be grayed out.

![image](images/os_editor_symbol_records.jpg)

These three fields allow you to test the parsing of the window’s title
bar text with the parse string that is specified in the “String” field,
and see the results of this parse in the results field at the bottom of
the window. The “Titlebar text” field is initially populated with the
titlebar text of the window that OpenScrape is attached to (via the
“Green Circle Button”), but this text can be overridden with anything
you want to test parse.

## Technical Reference

In the Table Map (.tm) file, these records will be preceded with the
characters s\$. Symbol records have the following format:

s\$\<name\> \<text\>

\<name\> is the name of the record (see table below) \<text\> is the
content of the record

## Valid symbol records 

<table>
<thead>
<tr class="header">
<th style="text-align: left;">Symbol record</th>
<th style="text-align: left;">Description</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td style="text-align: left;">titletext, titletext0 - titletext9</td>
<td style="text-align: left;">When the “Green Circle Button” is pressed,
OpenHoldem will look through each of these symbols and do a partial
match of &lt;text&gt; to each window’s title bar text. If any substring
provided in any of these symbols matches, then the window is considered
a match.</td>
</tr>
<tr class="even">
<td style="text-align: left;">!titletext,  !titletext0 -
!titletext9</td>
<td style="text-align: left;">When the “Green Circle Button” is pressed,
OpenHoldem will look through each of these symbols and do a partial
match of &lt;text&gt; to each window’s title bar text. If all substrings
provided in all of these symbols do not match, then the window is
considered a match.</td>
</tr>
<tr class="odd">
<td style="text-align: left;">ttlimits, ttlimits0 - ttlimits9</td>
<td style="text-align: left;"><p>These symbols are intended to provide a
format string that is used to parse the window’s titlebar text, and
extract sblind, bblind, bigbet, ante and game type information. The
syntax usage of the format string is very much like the standard
C-language format strings for scanf and printf. The placeholders use the
caret character as the indicator and have the following meanings:</p>
<p>^h hand number</p>
<p>^d dummy integer (read chars 0-9 only)</p>
<p>^f dummy float (read chars 0-9 including decimal ’.’)</p>
<p>^s sblind</p>
<p>^b bblind</p>
<p>^B bigbet</p>
<p>^a ante</p>
<p>^v sb or bb depending on limit type</p>
<p>^V bb or BB depending on limit type</p>
<p>^<span>*</span> skip all text up to the literal character following
the <span>*</span></p>
<p>^R roman numeral as in Level VIII as typically seen in SNGs</p>
<p>^y buyin</p>
<p>^z prizepool</p>
<p>^Z prizepool-multiplier</p>
<p>^L limit indicator</p>
<p>For the integer and float numerics, the scanner will automatically
accept and skip a leading dollar sign “$” or leading/trailing cent sign
“¢” (ascii 162 hex a2). In the case of the cent sign the target number
will be divided by 100. The scanner will also recognize the standard
trailing metric unit multipliers of “k” and “m” (1000 and 1000000
respectively).</p>
<p>The following case-insensitive strings are recognized for the ^L
limit indicator: no limit, no-limit, nolimit, nl pot limit, pot-limit,
potlimit, pl fixed limit, fixed-limit, fixedlimit, fl, limit</p>
<p>As an example, this title bar text NL SNG Level VI 25/50 (2) could be
parsed with this format string ^L SNG Level ^R ^s/^b (^a) to result in
the sblind, bblind and game type being recognized.</p>
<p>If multiple ttlimits symbols are provided, then the engine will scan
each in order, and extract matching information from the first time it
is found. That means that if you specify ^s in both ttlimits and
ttlimits3, for example, it will be extracted from ttlimits and ignored
in ttlimits3. OpenHoldem allows you to specify up to 11 ttlimits records
in any single Table Map file. Specifying multiple ttlimits records might
be needed if a given Table Map file is intended to describe multiple
Texas Hold’em game flavors. However, it is a best practice to define
different game flavors in different Table Maps, and thus most Table Maps
contain a single ttlimits symbol record.</p></td>
</tr>
<tr class="even">
<td style="text-align: left;">c0limits, c0limits0-c0limits9</td>
<td style="text-align: left;">These are text format strings with the
same structure as the ttlimits records described above. They are
intended to be used to extract blind/limit information from the c0limits
regions using text transforms. As a poker site could certainly paint the
various blind/limit information in different locations in the window, it
is very likely that multiple c0limits records are required, if any are
needed at all.</td>
</tr>
<tr class="odd">
<td style="text-align: left;">sitename</td>
<td style="text-align: left;">This record describes the name of the
poker site that this Table Map is for. It is good practice to include
the number of chairs and game flavor that this Table Map is intended to
be used for. You might have a fulltilt9sng, fulltilt6ring and
fulltilt2ring for different Table Map files for Full Tilt’s various
table layouts and flavors. This record is what is queried via the
OpenHoldem sitename$ symbol.</td>
</tr>
<tr class="even">
<td style="text-align: left;">network</td>
<td style="text-align: left;"><p>The name of the poker network that this
Table Map is for. This is used to determine the appropriate network to
query Poker Tracker data for when s$sitename is not a Poker
Tracker-supported site. OpenHoldem will first check s$sitename for a
supported network name, then s$network.</p>
<p>Both s$sitename and s$network are not case-sensitive. OpenHoldem
converts them internally to lowercases.</p>
<p>The following names are supported for PT2:</p>
<ul>
<li><p>stars</p></li>
<li><p>party</p></li>
<li><p>ultimate</p></li>
<li><p>absolute</p></li>
<li><p>microgaming</p></li>
<li><p>ongame</p></li>
<li><p>cryptologic</p></li>
<li><p>pacific</p></li>
<li><p>fulltilt</p></li>
<li><p>b2b</p></li>
<li><p>tribeca</p></li>
<li><p>worldpex</p></li>
<li><p>ipoker</p></li>
<li><p>tain,</p></li>
<li><p>bodog</p></li>
<li><p>everest</p></li>
<li><p>boss</p></li>
<li><p>betfair</p></li>
</ul>
<p>The following names are supported for PT3:</p>
<ul>
<li><p>stars</p></li>
<li><p>party</p></li>
<li><p>fulltilt</p></li>
<li><p>ipoker</p></li>
<li><p>everest</p></li>
<li><p>ongame</p></li>
<li><p>boss</p></li>
<li><p>cereus</p></li>
<li><p>pacific</p></li>
<li><p>b2b</p></li>
<li><p>microgaming</p></li>
<li><p>cake</p></li>
<li><p>bodog</p></li>
</ul></td>
</tr>
<tr class="odd">
<td style="text-align: left;">nchairs</td>
<td style="text-align: left;">The number of chairs that this Table Map
supports. The value of this record is what is returned via the
OpenHoldem nchairs symbol.</td>
</tr>
<tr class="even">
<td style="text-align: left;">allinconfirmationmethod</td>
<td style="text-align: left;"><p>Used by the Autoplayer what
buttonßsequence to click to go allin</p>
<p>0: click only “max” (or “allin”)</p>
<p>non-zero: first click “max” (or “allin”), then click “raise” as
confirmation</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;">betsizeinterpretationmethod</td>
<td style="text-align: left;"><p>Used by the Autoplayer to determine how
to enter the f$betsize amount into the betsize entry box on the casino
window. This is necessary, as bets and raises get interpreted
differently by different casinos.</p>
<ol>
<li><p>Enter (f$betsize - currentbet - call)</p></li>
<li><p>Enter (f$betsize - currentbet)</p></li>
<li><p>Enter f$betsize without any adjustment.</p></li>
</ol>
<p>Default: 3</p>
<p>As an example let us assume, that you are short-stacked in a SNG.
Your balance is 9 big blinds before you have to post the big blind.
Everybody folds and button raises to 3 big blinds. You want to push
(f$betsize = 9). What amount should you enter for different casinos?</p>
<ol>
<li><p>6 bbs — the amount that exceeds the previous raise of 3
bbs.</p></li>
<li><p>8 bbs — the amount you have to add to your current bet of 1
bb.</p></li>
<li><p>9 bbs — your future current bet after have you raised.</p></li>
</ol></td>
</tr>
<tr class="even">
<td style="text-align: left;">potmethod</td>
<td style="text-align: left;"><p>This is used to determine the
appropriate site interpretation for the contents of c0pot0:</p>
<ol>
<li><p>Common pot</p></li>
<li><p>Total pot, includes current bets and side bets</p></li>
<li><p>Largest of all pots (common pot and sidepots)</p></li>
</ol>
<p>Default: 1</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;">t0type - t3type</td>
<td style="text-align: left;"><p>These symbols control which OCR
algorithm will get used for the specific text transform 0-3. For example
if the symbol h3type is defined as fuzzy then all regions with transform
Text3 will use the fuzzy algorithm. The default value is plain if no
symbol exists for a given group.</p>
<p>The possible values for these symbols are fuzzy, plain, or a specific
tolerance value. The default fuzzy text tolerance is 25%, but can be
overridden by stating the value in this symbol, such as , which would
cause the scraper engine to use the fuzzy text algorithm with a 35.5%
tolerance value. Values of 0 are the same as plain.</p></td>
</tr>
<tr class="even">
<td style="text-align: left;">betsizeselectionmethod</td>
<td style="text-align: left;"><p>New Symbol in version 2.0; previously,
this was a global preference set from the OpenHoldem preferences
GUI.</p>
<p>This symbol instructs the Autoplayer how to take the first action in
a betsize sequence. A betsize sequence always consists of:</p>
<ol>
<li><p>select the text in the betsize box</p></li>
<li><p>delete the text in the betsize box</p></li>
<li><p>enter the new bet in the betsize box</p></li>
<li><p>confirm the betsize bet amount.</p></li>
</ol>
<p>Valid values for this Symbol are available in a drop down control and
are:</p>
<ul>
<li><p>Sgl Click – Single left click on the betsize box to select the
existing text</p></li>
<li><p>Dbl Click – Double left click on the betsize box to select the
existing text</p></li>
<li><p>Triple Click’ – Triple left click on the betsize box to select
the existing text</p></li>
<li><p>Click Drag – Left click on the leftmost pixel of the betsize box,
drag to the rightmost pixel of the betsize box, and then release the
left mouse button to select the existing text</p></li>
<li><p>Nothing – Skip the text selection step of the betsize
action</p></li>
</ul>
<p>Default: None, must be explicitly specified</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;">betsizedeletionmethod</td>
<td style="text-align: left;"><p>New Symbol in version 2.0; previously,
this was a global preference set from the OpenHoldem preferences GUI.
This symbol instructs the Autoplayer how to take the second action in a
betsize sequence. A betsize sequence always consists of:</p>
<ol>
<li><p>select the text in the betsize box</p></li>
<li><p>delete the text in the betsize box</p></li>
<li><p>enter the new bet in the betsize box</p></li>
<li><p>confirm the betsize bet amount.</p></li>
</ol>
<p>Valid values for this symbol are available in a drop down control and
are:</p>
<ul>
<li><p>Delete – Press the “Delete” key to delete the selected text in
the betsize box</p></li>
<li><p>Backspace – Press the “Backspace” key to delete the selected text
in the betsize box</p></li>
<li><p>Nothing – Skip the text deletion step of the betsize
action</p></li>
</ul>
<p>Default: None, must be explicitly specified</p></td>
</tr>
<tr class="even">
<td style="text-align: left;">betsizeconfirmationmethod</td>
<td style="text-align: left;"><p>New Symbol in version 2.0; previously,
this was a global preference set from the OpenHoldem preferences GUI.
This symbol instructs the Autoplayer how to take the fourth action in a
betsize sequence. A betsize sequence always consists of:</p>
<ol>
<li><p>select the text in the betsize box</p></li>
<li><p>delete the text in the betsize box</p></li>
<li><p>enter the new bet in the betsize box</p></li>
<li><p>confirm the betsize bet amount.</p></li>
</ol>
<p>Valid values for this Symbol are available in a drop down control and
are:</p>
<ul>
<li><p>Enter – Press the “Enter” key to confirm the betsize bet
entry</p></li>
<li><p>Click Bet – Click the “Bet” button to confirm the betsize bet
entry</p></li>
<li><p>Nothing – Skip the bet confirmation step of the betsize
action</p></li>
</ul>
<p>Default: None, must be explicitly specified</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;">buttonclickmethod</td>
<td style="text-align: left;"><p>New Symbol in version 2.0; previously,
this was a global preference set from the OpenHoldem preferences GUI.
This symbol instructs the Autoplayer how to click any button defined by
the iXbutton region records.</p>
<p>Valid values for this Symbol are available in a drop down control and
are:</p>
<ul>
<li><p>Single – Single left click on buttons</p></li>
<li><p>Double – Double left click on buttons</p></li>
</ul>
<p>Default: Single</p></td>
</tr>
<tr class="even">
<td style="text-align: left;">betpotmethod</td>
<td style="text-align: left;"><p>Some casinos require additional input
to confirm betpot actions. Valid options:</p>
<ul>
<li><p>None</p></li>
<li><p>Raise – click the raise-button after having clicked a betpot
button.</p></li>
</ul></td>
</tr>
<tr class="odd">
<td style="text-align: left;">use_comma_instead_of_dot</td>
<td style="text-align: left;">Some casinos require the use of the
“comma” as a decimal separator rather than the “dot”. This setting will
instruct OpenHoldems autoplayer to use a comma if needed.</td>
</tr>
<tr class="even">
<td style="text-align: left;">handnumber_min_expected_digits</td>
<td style="text-align: left;">Optional parameter to specify the minimum
number of digits for a valid handnumber to reduce the risk of bad
scrapes and incorrect handresets.</td>
</tr>
<tr class="odd">
<td style="text-align: left;">handnumber_min_expected_digits</td>
<td style="text-align: left;">Optional parameter to specify the maximum
number of digits for a valid handnumber to reduce the risk of bad
scrapes and incorrect handresets.</td>
</tr>
<tr class="even">
<td style="text-align: left;">cardscrapemethod</td>
<td style="text-align: left;"><ul>
<li><p>Default: scraping first cardbacks, then nocard, then cardfaces
(or ranks + suits). Works for most casinos, optimal performance and also
serves the case where cards and cardbacks are at different
locations</p></li>
<li><p>“1”: scraping first card-faces, then cardbacks, finally nocard.
This method is necessary at casinos that display additional cardbacks
also for players that hold face-cards.</p></li>
</ul></td>
</tr>
<tr class="odd">
<td style="text-align: left;">chipscrapemethod</td>
<td style="text-align: left;">This Symbol instructs the “chip stack
counter” within the screen scraper engine to act in one of three
distinct modes of operation: If this Symbol is not present, or does not
match one of the other formats, the “chip stack counter” begins counting
chips at the 00 Region record, stops counting a given stack when a chip
match is not found, and stops counting all stacks when the first chip in
a given stack is not matched. This is the default, pre-2.0 behavior. If
this symbol is set to All”, then the scraper engine will check all 200
possible chip locations (10 stacks of 20 chips) every time a chip count
is required. If this symbol is set to the format XxY, where X is an
integer between 1 and 10 representing the number of stacks, and Y is an
integer between 1 and 20 representing the number of chips in each stack,
then the scraper engine will check X times Y chip locations every time a
chip count is required.</td>
</tr>
<tr class="even">
<td style="text-align: left;">islobby</td>
<td style="text-align: left;">If this symbol exists and is non-zero
OpenHoldem will know that it is connected to a lobby window (for
table.positioning and shutdown-handling). The tablemap-completeness
checker will be turned off and the OH-script-symbol islobby will become
true. Lobby-windows will always be positioned at the top-left of the
screen where absolute coordinates equal relative window-coordinates to
make hoppers more robust in case of lost focus.</td>
</tr>
<tr class="odd">
<td style="text-align: left;">ispopup</td>
<td style="text-align: left;">If this symbol exists and is non-zero
OpenHoldem will know that it is connected to a popup window. The
tablemap-completeness checker and the table-positioner will be be turned
off and the OH-script-symbol ispopup will become true. This feature can
be used to connect OpenHoldem to known popup-windows with a minimalistic
tablemap and then click confirmation-buttons with the i86x-regions or do
other simple hopper-tasks.</td>
</tr>
<tr class="even">
<td style="text-align: left;">iXbuttondefaultlabel</td>
<td style="text-align: left;"><p>Optional default label for button X.
The default label gets used when the button-text can’t get scraped. X =
0..9, A..F. Supported values are:</p>
<ul>
<li><p>allin</p></li>
<li><p>raise</p></li>
<li><p>call</p></li>
<li><p>check</p></li>
<li><p>fold</p></li>
<li><p>autopost</p></li>
<li><p>sitin</p></li>
<li><p>sitout</p></li>
<li><p>leave</p></li>
<li><p>rematch</p></li>
<li><p>prefold</p></li>
</ul></td>
</tr>
</tbody>
</table>
