# ManualMode 

## Description

ManualMode is a tool for simulating a poker game state offine. It allows
you to set any game state you can think of, including your cards,
buttons, etc.

A Table Map is included with the ManualMode tool to allow OpenHoldem to
connect to the ManualMode main window and scrape the game state 100%
correctly into the OpenHoldem engine. This will allow for offline
construction of bot logic and the easy setup of various game state
situations, some of which are very rare online (think Straight Flushes).

## Familiarizing yourself with ManualMode

<figure>
<img src="Images/ManualMode.PNG" />
<figcaption>ManualMode</figcaption>
</figure>

The ManualMode interface is quite intuitive. All relevant elements on
the poker table are visible at all times, either populated with objects
(like cards or bets), or outlined in white dashed lines if not
populated. Each game state element is interacted with slightly
differently and is discussed below. In general, however, right-clicking
on any element will bring up a list

1.  Common Cards: Right-clicking on each common card will bring up a
    context

2.  Sit Down/Stand Up: OpenHoldem recognizes the difference between
    sitting in at a chair, and sitting in a game and being dealt a hand.
    allowing the player to Sit Down or Stand Up from the selected chair.

3.  Sit In/Sit Out: OpenHoldem recognizes the difference between sitting
    in at a chair, and sitting in a game and being dealt a hand. cards
    will bring up a context menu allowing the player to Sit In to the
    game or Sit out from the game. table. up a context menu allowing the
    assignment of the dealer button to the selected chair. around the
    table anti-clockwise or clockwise.

4.  Player Cards: Right-clicking on either of a player’s cards will
    bring up a context menu allowing the selection of rank/suit,
    “cardbacks” or “no card”. Note: prior to assigning cards, a player
    must have “Sat In” the game.

5.  Player Names: Right-clicking on the player’s name rectangle will pop
    up a window prompting for a string to use as the player’s name.
    Note: prior to assigning names, a player must have “Sat Down” at the
    table.

6.  Player Balances: Right-clicking on the player’s balance rectangle
    will pop up a window prompting for a string to use as the player’s
    balance. Note: prior to assigning balances, a player must have “Sat
    Down” at the table.

7.  Player Bets: Right-clicking on the player’s bet rectangle will pop
    up a window prompting for a string to use as the player’s bet. Note:
    prior to assigning bets, a player must have “Sat In” the game.

8.  Dealer Button: Right-clicking on either of a player’s cards will
    bring up a context menu allowing the assignment of the dealer button
    to the selected chair. The “D-” and “D+“ buttons can also be clicked
    to move the dealer button around the table anti-clockwise or
    clockwise.

9.  Blinds/Limits: Right-clicking on the center information box will pop
    up a window in which the small blind, big blind, big bet, ante, game
    type (FL, PL, NL), network (useful if integrating with
    {PokerTracker}), and tournament indicator can be set. Buttons:
    Left-clicking on any game-state button on the table will toggle its
    state from on to off. These include the FCKRA buttons on the bottom
    right (fold, call, check, table, prefold, autopost).

There are some shortcuts built into ManualMode to allow easier setup of
from the table. As players are added, they will Sit Down, Sit In, and
will be assigned a name and balance. Players will be added from chair 0
to chair 9, depending on what is open, and removed in reverse order. for
a string to be entered. The format of the macro string is described here
at the bottom of this page. Betting: Left-clicking (right click to set a
specific bet amount).

Note: When ManualMode detects a betting round change (i.e. 0 to 3, 3 to
4 or 4 to 5 common cards), then all player bets will be collected into
the pot, and all player bets will be reset to zero.

## Defining the game-type

If you right-clicking at the “white box” ManualMode will show a dialog
where you can set up the gametype to be simulated.

<figure>
<img src="Images/manualmode_gametype_setup.JPG" />
</figure>

## Macros 

<figure>
<img src="Images/manualmode_macro.JPG" />
</figure>

A macro string is a series of characters executed one at a time, left to
right. The meaning of each character is as follows:

<table>
<thead>
<tr class="header">
<th style="text-align: left;">Character</th>
<th style="text-align: left;">Meaning</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td style="text-align: left;">R (uppercase)</td>
<td style="text-align: left;">Reset the game state</td>
</tr>
<tr class="even">
<td style="text-align: left;">N (Uppercase)</td>
<td style="text-align: left;">Set the dealer button to this chair</td>
</tr>
<tr class="odd">
<td style="text-align: left;">P (uppercase)</td>
<td style="text-align: left;">Sit in a player at this chair, default
name, default balance, and cardbacks</td>
</tr>
<tr class="even">
<td style="text-align: left;">p (lowercase)</td>
<td style="text-align: left;">Unseat a player at this chair</td>
</tr>
<tr class="odd">
<td style="text-align: left;">b (lowercase)</td>
<td style="text-align: left;">Set the small blind at this chair</td>
</tr>
<tr class="even">
<td style="text-align: left;">B (uppercase)</td>
<td style="text-align: left;">Set the big blind at this chair</td>
</tr>
<tr class="odd">
<td style="text-align: left;">23456789tjqka</td>
<td style="text-align: left;"><p>Set the rank of the players cards at
this chair, or common cards</p>
<p>User cards have to be immediatelly after the player in question,</p>
<p>all additional cards will be considered common cards.</p></td>
</tr>
<tr class="even">
<td style="text-align: left;">cdhs</td>
<td style="text-align: left;">See the suit of the players cards at this
chair, or common cards (player first, common next)</td>
</tr>
</tbody>
</table>

The default macro provided (“RNbBPpPAdKsP”) used in the image above will

- reset (R) the table

- set the button (N) to chair 0

- set the small blind (b) to chair 1

- set the bigl blind (B) to chair 2

- set another player (P) to chair 3

- set an empty chair (p) to chair 4

- set another player (P) – the user! – to chair5 and deal him an ace of
  diamonds and a king of spades (AdKs)

- set another player (P) to chair 6

- finally leave the last 3 chairs will stay empty
