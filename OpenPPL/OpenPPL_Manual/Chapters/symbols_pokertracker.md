# Poker Tracker symbols (Version 3)

Assuming all the prerequisites as described in the configuration manual
are met, the following native OpenHoldem symbols will be available to
your bot for use in its logic processing. The appropriate use of these
symbols in opponent modeling is beyond the scope of this document, but
plenty of references can be found on the Internet with a Google search.

All the symbols below are available both for cash games and for
tournaments (SNG, MTT). OpenHoldem will automatically adapt the
database-queries for your game-type and provide the right stats. All
stats can be accessed in 3 different ways:

- for the chair of the aggressor, e.g. pt_icon\_*raischair*. This
  situation is one of the most common needs for PokerTracker stats.

- for a single opponent *headsup*, e.g. pt_icon_headsup

- to identify certain players by their preflop-position use the
  postfixes *smallblind, bigblind, dealer, cutoff, user.*

- besides that you can use *firstcaller, lastcaller* and *firstraiser*.
  They work for the current orbit only.

- by *chair number*, e.g pt_icon0..pt_icon9: this is more complex and
  less convenient than both methods above, but you get the ability to
  build any advanced stat on your own as long as you are able to
  identify the chair of your villain.

## Summary :

- You need to use the prefix “pt\_”.

- Then add the symbol name.

- Finally add one of those postfix:

  - \_raischair

  - \_headsup

  - \_smallblind

  - \_bigblind

  - \_dealer

  - \_cutoff

  - \_firstcaller

  - \_lastcaller

  - \_firstraiser

  - \_dealer

  - \_user

  - the chair number between 0 and 9

General stats  
 

| Symbol | Meaning |
|:---|:---|
| icon | Poker Tracker auto-rate icon code |
| hands | Poker Tracker number of hands that are in the database |
| vpip | Poker Tracker VP\$IP |
| pfr | Poker Tracker pre-flop raise |
| wtsd | Poker Tracker went to showdown |
| wssd | Poker Tracker won \$ at showdown |
| aggr_factor | Poker Tracker total aggression |
| aggr_factor_without_preflop | Poker Tracker total aggression excluding preflop |
| fold_to_3bet | Poker Tracker total folded while facing 3bet excluding preflop |
| 4bet | Poker Tracker Overall 4B |

Preflop stats  
 

| Symbol                    | Meaning                                        |
|:--------------------------|:-----------------------------------------------|
| preflop_aggr_factor       | Poker Tracker preflop aggression factor        |
| preflop_rfi               | Poker Tracker pre-flop raise first in          |
| preflop_3bet              | Poker Tracker 3bet preflop                     |
| preflop_fold_to_3bet      | Poker Tracker folded while facing 3bet preflop |
| preflop_called_raise      | Poker Tracker pre-flop called raise            |
| preflop_attempt_steal     | Poker Tracker attempt to steal blinds          |
| big_blind_fold_to_steal   | Poker Tracker folded big blind to steal        |
| small_blind_fold_to_steal | Poker Tracker folded small blind to steal      |
| preflop_3bet_vs_steal     | Poker Tracker 3bet vs. steal                   |
| big_blind_3bet_vs_steal   | Poker Tracker BB 3bet vs. steal                |
| small_blind_3bet_vs_steal | Poker Tracker SB 3bet vs. steal                |
| preflop_4bet              | Poker Tracker Preflop 4B                       |
| preflop_fold_to_4bet      | Poker Tracker Preflop fold to 4B               |

Flop stats  
 

| Symbol            | Meaning                                     |
|:------------------|:--------------------------------------------|
| flop_seen         | Poker Tracker saw flop                      |
| flop_aggr_factor  | Poker Tracker flop aggression factor        |
| flop_cbet         | Poker Tracker flop cbet                     |
| flop_fold_to_cbet | Poker Tracker folded while facing cbet flop |
| flop_raise_cbet   | Poker Tracker raise flop cbet               |
| flop_fold_to_3bet | Poker Tracker folded while facing 3bet flop |
| flop_checkraise   | Poker Tracker flop check-raise              |
| flop_donkbet      | Poker Tracker donk bet flop                 |

Turn stats  
 

| Symbol            | Meaning                                     |
|:------------------|:--------------------------------------------|
| turn_seen         | Poker Tracker saw turn                      |
| turn_aggr_factor  | Poker Tracker turn aggression factor        |
| turn_cbet         | Poker Tracker turn cbet                     |
| turn_fold_to_cbet | Poker Tracker folded while facing cbet turn |
| turn_fold_to_3bet | Poker Tracker folded while facing 3bet turn |
| turn_checkraise   | Poker Tracker turn Check-Raise              |
| turn_checkcall    | Poker Tracker turn Check-Call               |

River stats  
 

| Symbol             | Meaning                                      |
|:-------------------|:---------------------------------------------|
| river_seen         | Poker Tracker saw river                      |
| river_aggr_factor  | Poker Tracker river aggression factor        |
| river_fold_to_3bet | Poker Tracker folded while facing 3bet river |
| river_fold_to_cbet | Poker Tracker folded while facing cbet river |
| river_bet          | Poker Tracker river bet                      |
