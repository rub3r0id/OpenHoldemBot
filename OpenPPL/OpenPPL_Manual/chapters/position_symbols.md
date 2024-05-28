# Position Symbols

Good news: contrary to Standard-PPL most position symbols are not
restricted to first orbit preflop only. You can use them in later orbits
too and also postflop.

Positions are always BU — CO — MP3 — MP2 — MP1 — EP3 — EP2 — EP1 — BB —
SB. If there are less than 10 players at the table, then some of the
early positions will be missing (EP1 — EP2, etc.). Symbols like
“InButton” can be spelled in two different ways: “InButton” or just
“Button”.

<figure>
<img src="images/positions_at_the_table.jpg" />
</figure>

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
<td style="text-align: left;">FirstCallerPosition</td>
<td style="text-align: left;"><p>The position of the first caller</p>
<p>(big blind = 0 (although this can not happen), small blind = 1, then
counter-clockwise till UTG = 9)</p></td>
<td style="text-align: left;">First orbit preflop only</td>
</tr>
<tr class="even">
<td style="text-align: left;">FirstRaiserPosition</td>
<td style="text-align: left;"><p>The position of the first raiser</p>
<p>(big blind = 0, small blind = 1, then counter-clockwise till UTG =
9)</p></td>
<td style="text-align: left;">First orbit preflop only</td>
</tr>
<tr class="odd">
<td style="text-align: left;">InBigBlind</td>
<td style="text-align: left;">True, if you are big blind. OpenPPL is
smart enpugh to detect a missing small blind (e.g. he busted in a
tournament). In this case the player to the left of the dealer will be
big blind.</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">InButton</td>
<td style="text-align: left;">True if you are button (last to act
postflop)</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="odd">
<td style="text-align: left;">InCutOff</td>
<td style="text-align: left;">True, if you are CutOff (right to the
button; this position exists only, if the game is at least 4-handed,
otherwise the symbol will always be false)</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">InEarlyPosition</td>
<td style="text-align: left;">True, if you are in one of the early
positions</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="odd">
<td style="text-align: left;">InEarlyPosition1</td>
<td style="text-align: left;">True, if you are in EP1 (left to the big
blind, right to EP2; this position exists only, if the game is at least
10-handed, otherwise the symbol will always be false)</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">InEarlyPosition2</td>
<td style="text-align: left;">True, if you are in EP2 (this position
exists only, if the game is at least 9-handed, otherwise the symbol will
always be false)</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="odd">
<td style="text-align: left;">InEarlyPosition3</td>
<td style="text-align: left;">True, if you are in EP3 (this position
exists only, if the game is at least 8-handed, otherwise the symbol will
always be false)</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">InLatePosition</td>
<td style="text-align: left;">True, if you are either CutOff or
Button</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="odd">
<td style="text-align: left;">InMiddlePosition</td>
<td style="text-align: left;">True, if you are in one of the middle
positions</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">InMiddlePosition1</td>
<td style="text-align: left;">True, if you are in MP1 (this position
exists only, if the game is at least 7-handed, otherwise the symbol will
always be false)</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="odd">
<td style="text-align: left;">InMiddlePosition2</td>
<td style="text-align: left;">True, if you are in MP2 (this position
exists only, if the game is at least 6-handed, otherwise the symbol will
always be false)</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">InMiddlePosition3</td>
<td style="text-align: left;">True, if you are in MP3 (this position
exists only, if the game is at least 5-handed, otherwise the symbol will
always be false)</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="odd">
<td style="text-align: left;">InSmallBlind</td>
<td style="text-align: left;">True, if you are small blind</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">InTheBlinds</td>
<td style="text-align: left;">True, if you are either small blind or big
blind</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="odd">
<td style="text-align: left;">InUTG</td>
<td style="text-align: left;">True, if you are <em>under the gun</em>
(left to the big blind), independent of the number of players at the
table. This symbols is escpecially useful to sitout after the last hand
of a session (before the next blind), but should not be used for
positional play. Better use symbols like <em>InEarlyPosition1</em> for
selection of your starting hands.</td>
<td style="text-align: left;">None</td>
</tr>
<tr class="even">
<td style="text-align: left;">LastCallerPosition</td>
<td style="text-align: left;"><p>The position of the last caller</p>
<p>(big blind = 0, small blind = 1, then counter-clockwise till UTG =
9)</p></td>
<td style="text-align: left;">First orbit preflop only</td>
</tr>
<tr class="odd">
<td style="text-align: left;">LastRaiserPosition</td>
<td style="text-align: left;"><p>The position of the last raiser</p>
<p>(big blind = 0, small blind = 1, then counter-clockwise till UTG =
9)</p></td>
<td style="text-align: left;">First orbit preflop only</td>
</tr>
<tr class="even">
<td style="text-align: left;">Position</td>
<td style="text-align: left;"><p>Our position relative to the other
player, meant especially for postflop play. There are 3 positions at the
table:</p>
<pre><code>Position = First
Position = Middle
Position = Last</code></pre>
<p>Middle is everything, that is neither first nor last.</p></td>
<td style="text-align: left;">None</td>
</tr>
<tr class="odd">
<td style="text-align: left;">StillToAct</td>
<td style="text-align: left;"><p>The number of opponents that have not
yet acted in the hand when it is your turn, i.e. the players behind,
including the blinds.</p>
<div class="rem*">
<p><em> 1</em>. The Shanky-way to determine your preflop-position, but
there are better symbols, e.g. InButton, etc., which can also be used in
later orbits and in any betting-round.</p>
</div></td>
<td style="text-align: left;">First orbit only, both Preflop and post
Flop</td>
</tr>
</tbody>
</table>
