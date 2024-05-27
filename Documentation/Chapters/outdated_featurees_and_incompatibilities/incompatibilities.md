# Outdated Features and Incompatibilities between OpenHoldem and WinHoldem

The original main goal of the OpenHoldem development team was the
attempt to create a WinHoldem-compatible botting-platform to support
existing bots, DLLs and TableMaps. However there has been functionality
such as “Teaming”, that always has been a tabu for the OpenHoldem
development team. Other functionality did never get implemented due to
lack of documentation and practical relevance. And now that OpenHoldem
is far more advanced and WinHoldem is practically dead,
backward-compatibility is no longer such an important issue. Recently
the development team revisits some features that look a bit mal-designed
and tries to improve them carefully, trying to affect the end-user as
little as possible. This chapter will tell you about such
incompatibilities.

## No Collusion aka “Teaming”

OpenHoldem does not support any kind of collusion. There is no support
for WinHoldems WinTellem-server and card-sharing either because such
activities are simply illegal in every country of the world, and — even
more important — because we consider them unfair too.

<figure>
<img src="images/winholdem_table.gif" />
</figure>

## TableMaps

Table Maps are in a different format due to hypothetical
copyright-issues. For some time it was possible to convert a WinHoldem
profile to an OpenHoldem Table Map with OpenScrape. But this is no
longer of any practical relevance, as all WinHoldem-”profiles” are
supposed to be outdated and there is no longer any maintenance going on.
So finally we removed support for WinHoldem-tablemaps completely.

## Formula-File-Format

The formula is saved in a single file instead of two. It uses the
extension \*.ohf instead of \*.whf and \*.whx. Old WH-formulae could be
converted for some time, but as there was no longer any demand for this
feature we were happy to simplify OpenHoldems code. OpenHoldem does
still use a plain-text-format, so \*.ohf-files can be edited using your
favourite text-editor. or the built-in formula-editor.

## ManualMode

ManualMode is not directly integrated into OpenHoldem, but became a
stand-alone application. This did simplify the GUI of OpenHoldem
extremely and made it far more easy to use.

## f\$evrais and f\$evcall

Calculating expectation values is only one possible way (out of many) to
implement a poker bot, but not necessary in general. Furthermore it
proved to be cumbersome and unpopular. So the functions f\$evrais and
f\$evcall from WinHoldems demo-bot have been degraded to
user-defined-functions.

## f\$play-Function

The function f\$play has been a quite messy concept to handle sitting
in, sitting out and leaving the table. Some extra coution was necessary
to avoid multiple button-clicks within a short time-frame on identical
or outdated game-states. With OpenHoldem 4.0.0 f\$play got replaced by
three indivudal functions: f\$sitin, f\$sitout and f\$leave, which get
executed exactly once every 4 seconds. Furthermore we added a
f\$close-function to click the \[x\] in the titlebar of a window if the
user desires to leave a table.

## f\$swag function

f\$swag (short for “stated wager”) was WinHoldems way to define the
betsize for No-Limit games. As online casinos interpret your input in at
least three different ways some adjustment was necessary, including:

| f\$srai | the desired amount to raise (the part which exceeds the bet of the aggressor) |
|:---|:---|
| f\$swag | the final amount to be entered into the software |
| f\$swag_adjust | the casino-specific adjustment between f\$srai and f\$swag |
| swagtextmethod | the casino-specific way to interpret swag, as defined in the tablemap |
| sraimin | the smallest possible raise |
| sraimax | the largest possible raise. |
| sraiprev | the difference between the two largest unique wagers |

All these computations had to be done by the user at the formula level.
With OpenHoldem 4.0.0 this mess got replaced by a single function
f\$betsize and OpenHoldem cares about all the rest automatically
(depending on the swagtextmethod specified in your tablemap, but that is
all work that’s left). The supporting tablemap symbols got renamed.

| Former TM-symbol         | New TM-symbol               |
|:-------------------------|:----------------------------|
| swagselectionmethod      | betsizeselectionmethod      |
| swagdeletionmethodmethod | betsizedeletionmethodmethod |
| swagconfirmationmethod   | betsizeconfirmationmethod   |
| swagtextmethod           | betsizeinterpretationmethod |

## Statistic-Symbols: “risk of ruin”

The symbols to calculate “risk of ruin” have never been implemented due
to lack of documentation and lack of practical relevance. As of
OpenHoldem 2.0.0 the risk-of-ruin-symbols are officially abolished and
removed from the code-base. The original documentation for these symbols
can be found here:

- WinHoldEm Help - Formula Editor
  (<http://www.winholdem.net/help/help-formula.html>)

- WinHoldem-Forum: Risk Of Ruin
  (<http://forum.winholdem.net/wbb/viewtopic.php?t=2120>)

## Outdated Symbols

OpenHoldem is now half a dozen years old. During these long period of
usage it became noticeable that some symbols and features of WinHoldem
were unnecessary (risk of ruin), some others unusable, some undocumented
(versus2), and some even undesired.

<table style="width:95%;">
<colgroup>
<col style="width: 30%" />
<col style="width: 30%" />
<col style="width: 35%" />
</colgroup>
<thead>
<tr class="header">
<th style="text-align: left;">Symbol</th>
<th style="text-align: left;">Explanation</th>
<th style="text-align: left;">Reason for removal</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td style="text-align: left;">nfriendsdealt</td>
<td style="text-align: left;">1 if you are dealt, 0 otherwise (0-1)</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> nfriendsblind</td>
<td style="text-align: left;">1 if you are in a blind, 0 otherwise
(0-1)</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> friendsseatedbits</td>
<td style="text-align: left;">bits 9-0: 1=seated 0=unseated, you
only</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> friendsactivebits</td>
<td style="text-align: left;">bits 9-0: 1=active 0=inactive, you
only</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> friendsdealtbits</td>
<td style="text-align: left;">bits 9-0: 1=dealt 0=notdealt, you
only</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> friendsplayingbits</td>
<td style="text-align: left;">bits 9-0: 1=playing 0=notplaying, you
only</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> friendsblindbits</td>
<td style="text-align: left;">bits 9-0: 1=blind 0=notblind, you
only</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;">swagdelay</td>
<td style="text-align: left;">Autoplayer delay in milliseconds between
swag keystrokes and button click as defined in Preferences (formerly
TableMap)</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> allidelay</td>
<td style="text-align: left;">Autoplayer delay in milliseconds between
alli slider jam and button click as defined in Preferences (formerly
TableMap);</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;">allinmethod</td>
<td style="text-align: left;">used to detrmine which method to use for
allin</td>
<td style="text-align: left;"><p>OpenHoldem will now automatically chose
an appropriate method</p>
<ol>
<li><p>try to click allin (or max), optionally followed by clicking
raise (if allinconfirmationmethod is non-zero).</p></li>
<li><p>try to use the slider if it exists in the tablemap.</p></li>
<li><p>finally try to swag the balance.</p></li>
</ol>
<p>This new behaviour tries the most fail-safe and most human-like
methods first and in addition reacts flexibly on the options
available.</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;">islistcall</td>
<td style="text-align: left;">true if your hand is in list 0</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> islistrais</td>
<td style="text-align: left;">true if your hand is in list 1</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> islistalli</td>
<td style="text-align: left;">true if your hand is in list 7</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> isemptylistcall</td>
<td style="text-align: left;">true if the call list is empty</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> isemptylistrais</td>
<td style="text-align: left;">true if the rais list is empty</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> isemptylistalli</td>
<td style="text-align: left;">true if the alli list is empty</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> nlistmax</td>
<td style="text-align: left;">highest list number in which your hand is
listed</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> nlistmin</td>
<td style="text-align: left;">lowest list number in which your hand is
listed</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;">handnumber</td>
<td style="text-align: left;">the site hand number if available</td>
<td style="text-align: left;"><p>Removing formula symbol handnumber for
various reasons from the formula level:</p>
<ul>
<li><p>there is no need for it at the formula level.</p></li>
<li><p>it may contain characters and therefore doesn’t fit into a
variable of type double.</p></li>
<li><p>its length may exceed the precision of double.</p></li>
</ul>
<p>Handnumber gets now used only internally to trigger
handresets.</p></td>
</tr>
<tr class="even">
<td style="text-align: left;">isfiveofakind</td>
<td style="text-align: left;">true when you have a five of a kind</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> fiveofakind</td>
<td style="text-align: left;">0xff000000 (pokerval constant)</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;">isppro</td>
<td style="text-align: left;">true if you’re connected to a ppro
server</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> site</td>
<td style="text-align: left;">0=user/ppro 1=scraped</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;">bankroll</td>
<td style="text-align: left;">the user defined, real world bankroll</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> rake</td>
<td style="text-align: left;">percentage amount added/subtracted to/from
the pot</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;">defcon</td>
<td style="text-align: left;"><p>defense level is typically used in the
f$P formula, which defines the adapted number of opponents to be used in
standard prwin. defcon therefore controls the optimism of the
prwin-simulation.</p>
<p>0.000=maxoffense 1.000=maxdefense</p>
<p>The Formula Editor parameters dialog uses values 0-10</p></td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> isdefmode</td>
<td style="text-align: left;">true when defcon is at max</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> isaggmode</td>
<td style="text-align: left;">true when defcon is at min</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;">clocks</td>
<td style="text-align: left;">number of CPU clocks since the last screen
scrape</td>
<td style="text-align: left;">Useless information and always a fraction
of a second</td>
</tr>
<tr class="even">
<td style="text-align: left;">nclockspersecond</td>
<td style="text-align: left;">number of CPU clocks per second</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> ncps</td>
<td style="text-align: left;">synonym for nclockspersecond</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;">nflopc</td>
<td style="text-align: left;">short for ncommoncardsknow</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> br</td>
<td style="text-align: left;">short for betround</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> ncps</td>
<td style="text-align: left;">short for nclockspersecond</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> oppdealt</td>
<td style="text-align: left;">short for nopponentsdealt</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;">isbring</td>
<td style="text-align: left;">true if OpenHoldem is attached to a Bring
client window</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> ismanual</td>
<td style="text-align: left;">true if you’re in manual mode, false
otherwise</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;">handrank</td>
<td style="text-align: left;">one of the handrank-symbols based on the
option specified in preferences</td>
<td style="text-align: left;">Getting rid of the symbol handrank and the
option symbols-&gt;Value of Handrank. We have handrank169, handrank1000,
handrank1326, handrank2625 and handrankp at the formula level. So the
user can clearly specify what he wants. But these symbols can hardly get
used interchangeably, so this option was only confusing and
superfluos.</td>
</tr>
<tr class="odd">
<td style="text-align: left;">randomround1 ... randomround4</td>
<td style="text-align: left;">random number in the range
<span>[</span>0.000..1.000) for round 1 - 4. Value is calculated only
once in that round.</td>
<td style="text-align: left;">Removed the symbols
randomround1..randomround4 from the codebase, because we have
randomround for the current betting round and additionally randomhand,
randomheartbeat and random, which gets calculated each time new. This
simplified the code and looks more clean.</td>
</tr>
<tr class="even">
<td style="text-align: left;">callshort</td>
<td style="text-align: left;">total amount that will be added to the pot
if all players call</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> raisshort</td>
<td style="text-align: left;">callshort + bet <span>*</span>
nplayersplaying</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;">seatposition</td>
<td style="text-align: left;">your seat position relative to the
dealer</td>
<td style="text-align: left;">Removing the symbol seatposition which
counted both active and inactive players and even empty chairs and was
of no real use for practical play.</td>
</tr>
<tr class="odd">
<td style="text-align: left;">elapsed1970</td>
<td style="text-align: left;">time in seconds since 1970-01-01 00:00:00
GMT (Thursday)</td>
<td style="text-align: left;">Removing the symbol elapsed1970 because
there was no real use for it.</td>
</tr>
<tr class="even">
<td style="text-align: left;">ncommoncardspresent</td>
<td style="text-align: left;">number of common cards present (normal or
highlighted)</td>
<td style="text-align: left;">Removing the symbol ncommoncardspresent,
because it was never implemented correctly, but always had the same
value as ncommoncardsknown. Furthermore its value would only differ at
some casinos and at showdown (highlighted cards / bad scrapes), but this
point of time is pretty meaningless for both OH-script and OpenPPL,
which evaluate mainly on the users turn, whereas DLLers still have
access to all info.</td>
</tr>
<tr class="odd">
<td style="text-align: left;">ac_pf_bets</td>
<td style="text-align: left;"><ol>
<li><p>no callers or blinds only</p></li>
<li><p>called Pot – 1 bet to call</p></li>
<li><p>raised Back – 1 more bet to call because someone behind you
raised after you’ve already bet/called/raised</p></li>
<li><p>raised Pot – 2 bets to call</p></li>
<li><p>reraised Pot – 3+ bets to call</p></li>
</ol>
<div class="rem*">
<p><em> 1.1</em>. Only valid when betround == 1</p>
</div></td>
<td style="text-align: left;">Removed the symbols ac_pf_bets, because it
was for fixed limit only, worked only on the first orbit preflop,
because that task can be done with other symbols and finally we have the
OpenPPL-library, so there is really no longer any need for that.</td>
</tr>
<tr class="even">
<td style="text-align: left;">ac_aggressor</td>
<td style="text-align: left;">which chair was aggressor (might be from
previous round)</td>
<td style="text-align: left;">Removed, as it was duplicate functionality
to raischair</td>
</tr>
<tr class="odd">
<td style="text-align: left;">nplayersblind</td>
<td style="text-align: left;">number of players blind (including you)
(0-10)</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> nopponentsblind</td>
<td style="text-align: left;">number of opponents blind (not including
you) (0-9)</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> playersblindbits</td>
<td style="text-align: left;">bits 9-0: 1=blind 0=not blind</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> opponentsblindbits</td>
<td style="text-align: left;">bits 9-0: 1=blind 0=not blind</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> bblindbits</td>
<td style="text-align: left;">bits 9-0: 1=big blind 0=not big blind</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;">ron$ / run$ symbols</td>
<td style="text-align: left;">These symbols report the total number of
possible river endings for the opponent (ron$) and the user (run$). A
value of zero means that type of poker hand is not possible. Any
non-zero value means that type of poker hand will be seen that many
times</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> ron$royfl</td>
<td style="text-align: left;">river opponent number : possible royal
flush</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> ron$strfl</td>
<td style="text-align: left;">river opponent number : possible straight
flush</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> ron$4kind</td>
<td style="text-align: left;">river opponent number : possible four of a
kind</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> ron$fullh</td>
<td style="text-align: left;">river opponent number : possible full
house</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> ron$flush</td>
<td style="text-align: left;">river opponent number : possible
flush</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> ron$strai</td>
<td style="text-align: left;">river opponent number : possible
straight</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> ron$3kind</td>
<td style="text-align: left;">river opponent number : possible three of
a kind</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> ron$2pair</td>
<td style="text-align: left;">river opponent number : possible two
pair</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> ron$1pair</td>
<td style="text-align: left;">river opponent number : possible one
pair</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> ron$hcard</td>
<td style="text-align: left;">river opponent number : possible high
card</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> ron$total</td>
<td style="text-align: left;">river opponent number : sum of all
possible river endings</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> ron$pokervalmax</td>
<td style="text-align: left;">the maximum possible pokerval for the
opponent</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> ron$prnuts</td>
<td style="text-align: left;">opponent chances of hitting the nuts on or
before the river</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> ron$prbest</td>
<td style="text-align: left;">opponent chances of hitting pokervalmax on
or before the river</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-2</span> ron$clocks</td>
<td style="text-align: left;">total number of cpu clocks used to
calculate the ron$ symbols</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-2</span> run$...</td>
<td style="text-align: left;">similar like the ron$symbols above, just
for the user</td>
<td style="text-align: left;"></td>
</tr>
</tbody>
</table>

## PrWin-functions

Some supporting functions and symbols for the PrWin-simulations got
renamed in OpenHoldem 4.0.0 to achieve more verbosity and better
formula-grouping in the editor.

| Former Name | New Name                      |
|:------------|:------------------------------|
| f\$P        | f\$prwin_number_of_opponents  |
| NIT         | f\$prwin_number_of_iterations |
| f\$topclip  | f\$prwin_topclip              |
| f\$mustplay | f\$prwin_mustplay             |
| f\$willplay | f\$prwin_willplay             |
| f\$wontplay | f\$prwin_wontplay             |
