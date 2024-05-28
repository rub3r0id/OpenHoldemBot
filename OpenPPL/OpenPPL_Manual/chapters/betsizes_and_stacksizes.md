# Betsizes And Stacksizes

<div class="rem*">

* 1*. Standard PPL is a bit restrictive: betsizes, stacksizes and
potsizes may appear only on the left or on the right side of comparison
operators — please don’t ask us about the exact rules, we forgot them.
In OpenPPL you can put them anywhere you like.

    WHEN (AmountToCall < Pi * R * R) DANCE FORCE

It’s up to you, what and how you code.

</div>

<table>
<thead>
<tr class="header">
<th style="text-align: left;">Name</th>
<th style="text-align: left;">Meaning</th>
<th style="text-align: left;">Limitations</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td style="text-align: left;">AmountToCall</td>
<td style="text-align: left;">The amount to call, counted in
bigblinds</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">BetSize</td>
<td style="text-align: left;">The number of big blinds bet by the last
aggressor</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="odd">
<td style="text-align: left;">BigBlindSize</td>
<td style="text-align: left;">The size of the bigblind, usually in
dollars</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">MaxStacksizeOfActiveOpponents</td>
<td style="text-align: left;">The biggest stack size (expressed in
bblind and not dollars) of all opponents currently playing the
hand.</td>
<td style="text-align: left;">Could be bigger than your balance. Use
EffectiveMaxStacksizeOfActiveOpponents to know exactly the balance at
risk.</td>
</tr>
<tr class="odd">
<td
style="text-align: left;">EffectiveMaxStacksizeOfActiveOpponents</td>
<td style="text-align: left;">The biggest effective stack size
(expressed in bblind and not dollars) of all opponents currently playing
the hand.</td>
<td style="text-align: left;">You some opponents have more chips/money
than you the symbol will return the amout of your balance to reflect how
much bot is risking in a specified hand.</td>
</tr>
<tr class="even">
<td style="text-align: left;">MaxOpponentStackSize</td>
<td style="text-align: left;">The biggest stack of all opponents
(playing and not playing). measured in big blinds at the beginning of
the hand</td>
<td style="text-align: left;"><p>None</p>
<div class="rem*">
<p><em> 2</em>. Depends on game-history (game-state on your first
action)</p>
</div></td>
</tr>
<tr class="odd">
<td style="text-align: left;">MaxStillToActStackSize</td>
<td style="text-align: left;">The number of big blinds in the stack of
the opponent with the largest stack who has not acted yet</td>
<td style="text-align: left;">First action preflop only</td>
</tr>
<tr class="even">
<td style="text-align: left;">MinOpponentStackSize</td>
<td style="text-align: left;">The smallest stack of all opponents.
(playing and not playing) measured in big blinds at the beginning of the
hand</td>
<td style="text-align: left;"><p>None</p>
<div class="rem*">
<p><em> 3</em>. Depends on game-history (game-state on your first
action)</p>
</div></td>
</tr>
<tr class="odd">
<td style="text-align: left;">MinStillToActStackSize</td>
<td style="text-align: left;">The smallest stack of the opponents behind
you (including SB and BB), measured in big blinds</td>
<td style="text-align: left;">First action preflop only</td>
</tr>
<tr class="even">
<td style="text-align: left;">OpponentStacksizeHeadsUp</td>
<td style="text-align: left;">Stack size of opponent when headsup.
Please read Limitations</td>
<td style="text-align: left;">OpponentStacksizeHeadsUp return -1 when
not valid. When using this symbol you have to check if the result is
&gt; -1 and then make your comparison.</td>
</tr>
<tr class="odd">
<td style="text-align: left;">PotSize</td>
<td style="text-align: left;">The current pot, including all players
bets, counted in big blinds. PotSize returns effective pot size you are
participating in.</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">StackSize</td>
<td style="text-align: left;">Our current balance, counted in big
blinds</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="odd">
<td style="text-align: left;">StackSizeAtBeginningOfCurrentRound</td>
<td style="text-align: left;">Our Stack Size at the beginning of current
betting round (StackSize + TotalInvestedThisRound)</td>
<td style="text-align: left;">Valid on every betting round</td>
</tr>
<tr class="even">
<td style="text-align: left;">StackUnknown</td>
<td style="text-align: left;">Returns true if the userchair is unknown,
false otherwise. Introduced for compatibility with Shanky-PPL</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;">StartingChips</td>
<td style="text-align: left;">Our balance at the start of a session,
counted in “dollars” This symbol is especially meant for MTTs.</td>
<td style="text-align: left;">None.</td>
</tr>
<tr class="even">
<td style="text-align: left;">StartingStackSize</td>
<td style="text-align: left;">Our balance at the start of a session,
counted in big blinds</td>
<td style="text-align: left;"><p>None</p>
<div class="rem*">
<p><em> 4</em>. Depends on game-history (game-state on your first
action)</p>
</div></td>
</tr>
<tr class="odd">
<td style="text-align: left;">TotalInvested</td>
<td style="text-align: left;">The money put into the pot in this hand,
counted in big blinds</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">TotalInvestedThisRound</td>
<td style="text-align: left;">Amount Invested in current betting
round</td>
<td style="text-align: left;">None</td>
</tr>
</tbody>
</table>
