# Poker Tracker symbols (Version 4)

Assuming all the prerequisites as described in the configuration manual
are met, the following native OpenHoldem symbols will be available to
your bot for use in its logic processing. The appropriate use of these
symbols in opponent modeling is beyond the scope of this document, but
plenty of references can be found on the Internet with a Google search.

All the symbols below are available both for cash games and for
tournaments (SNG, MTT). OpenHoldem will automatically adapt the
database-queries for your game-type and provide the right stats. All
stats can be accessed in multiple ways:

- for the chair of the aggressor, e.g. pt_icon\_*raischair*. This
  situation is one of the most common needs for PokerTracker stats.

- for a single opponent *headsup*, e.g. *pt_icon_headsup*

- to identify certain players by their preflop-position use the
  postfixes *smallblind, bigblind, dealer, cutoff, user.*

- besides of that you can use *firstcaller, lastcaller* and
  *firstraiser*. They work for the current orbit only.

## Summary 

- You need to use the prefix “pt\_”.

- Then add the symbol name.

- Finally add a chair number or one of the many postfixes described in
  the chapter about the multiplexer-engine. The list gets extended over
  time, here are some examples:

  - \_smallblindchair

  - \_dealerchair

  - \_firstcallerchair

  - \_lastraiserchair

  - \_headsupchair

<div class="rem*">

* 1*. PokerTracker stats for the userchair are excluded for performance
reasons.

</div>

## General stats

| Symbol | Meaning |
|:---|:---|
| hands | Poker Tracker number of hands that are in the database |
| vpip | Poker Tracker VP\$IP |
| pfr | Poker Tracker pre-flop raise |
| wtsd | Poker Tracker went to showdown |
| wssd | Poker Tracker won \$ at showdown |
| aggr_factor | Poker Tracker total aggression |
| total_af | Poker Tracker total aggression excluding preflop |
| postflop_fold_to_3bet | Poker Tracker total folded while facing 3bet excluding preflop |

## Preflop stats

| Symbol | Meaning |
|:---|:---|
| preflop_aggr_factor | Poker Tracker preflop aggression factor |
| rfi | Poker Tracker pre-flop raise first in |
| 3bet | Poker Tracker 3bet preflop |
| fold_to_3bet | Poker Tracker folded while facing 3bet preflop after raising |
| preflop_called_raise | Poker Tracker pre-flop called raise |
| steal_attempt | Poker Tracker attempt to steal blinds |
| bb_fold_to_steal | Poker Tracker folded big blind to steal |
| sb_fold_to_steal | Poker Tracker folded small blind to steal |
| 3bet_vs_steal | Poker Tracker 3bet vs. steal |
| bb_3bet_vs_steal | Poker Tracker BB 3bet vs. steal |
| sb_3bet_vs_steal | Poker Tracker SB 3bet vs. steal |
| 4bet | Poker Tracker Preflop 4B |
| fold_to_4bet | Poker Tracker Preflop fold to 4B |
| fold_to_resteal | Poker Tacker Preflop fold when faced 3bet after attempt to steal blinds |

## Flop stats

| Symbol            | Meaning                                     |
|:------------------|:--------------------------------------------|
| flop_seen         | Poker Tracker saw flop                      |
| flop_af           | Poker Tracker flop aggression factor        |
| flop_cbet         | Poker Tracker flop cbet                     |
| flop_fold_to_cbet | Poker Tracker folded while facing cbet flop |
| flop_raise_cbet   | Poker Tracker raise flop cbet               |
| flop_checkraise   | Poker Tracker flop check-raise              |
| flop_donkbet      | Poker Tracker donk bet flop                 |
| flop_afq          | Flop Aggression frequency                   |
| flop_float        | Bet IP flop vs missed cbet                  |

## Turn stats

| Symbol            | Meaning                                     |
|:------------------|:--------------------------------------------|
| turn_seen         | Poker Tracker saw turn                      |
| turn_af           | Poker Tracker turn aggression factor        |
| turn_cbet         | Poker Tracker turn cbet                     |
| turn_fold_to_cbet | Poker Tracker folded while facing cbet turn |
| turn_checkraise   | Poker Tracker turn Check-Raise              |
| turn_checkcall    | Poker Tracker turn Check-Call               |
| turn_afq          | Turn Aggression frequency                   |

## River stats

| Symbol             | Meaning                                      |
|:-------------------|:---------------------------------------------|
| river_seen         | Poker Tracker saw river                      |
| river_af           | Poker Tracker river aggression factor        |
| river_fold_to_cbet | Poker Tracker folded while facing cbet river |
| river_bet          | Poker Tracker river bet                      |
| river_afq          | River Aggression frequency                   |
