# BettingAction Symbols 

| Name | Meaning |
|:---|:---|
| Bets | The number of bets made by opponents this betting round, can only be 0 or 1 since the 2nd bet is a raise |
| BigBlindSittingOut | True, if the big blind is sitting out. This symbol is especially meant for use in tournaments |
| BotCalledBeforeFlop | True if we called preflop |
| BotCalledOnFlop | True if we called on the flop |
| BotCalledOnTurn | True if we called on the turn |
| BotCalledOnRiver | True if we called on the river |
| BotIsLastRaiser | True if we have the betting / raising initiative, i.e we were the last raiser on the previous round |
| BotRaisedBeforeFlop | True if we raised preflop, can also be used preflop |
| BotRaisedOnFlop | True if we bet or raised on the flop, can also be used on the flop |
| BotRaisedOnTurn | True if we bet or raised on the turn, can also be used on the turn |
| BotsActionsOnFlop | Number of actions where we put money in the pot on the Flop |
| BotsActionsOnThisRound | Number of actions this betting round where we put money in the pot |
| BotsActionsOnThisRoundIncludingChecks | Number of checks + number of actions where we put money in the pot |
| BotsActionsPreflop | Number of actions where we put money in the pot preflop, all-ins are not counted as the game would then be over |
| BotCheckedPreflop | True if bot checked preflop |
| BotCheckedOnFlop | True if bot checked on the flop |
| BotCheckedOnTurn | True if bot checked on the turn |
| BotCheckedOnRiver | True if bot checked on the river |
| BotsLastAction | Bot’s last action, can be one of the following: None, Beep, Raise, Bet, Call, or Check |
| BotsLastPreflopAction | Bot’s last preflop action, can be one of the following: None, Beep, Raise, Bet, Call, or Check |
| BotsLastFlopAction | Bot’s last flop action, can be one of the following: None, Beep, Raise, Bet, Call, or Check |
| BotsLastTurnAction | Bot’s last turn action, can be one of the following: None, Beep, Raise, Bet, Call, or Check |
| Calls | The number of calls by opponents on this betting round |
| CallsSinceLastRaise | The number of calls by all opponents since the last raise by an opponent on the current betting round |
| Checks | The number of checks made by opponents this betting round |
| Folds | The number of folds this betting round |
| MissingSmallBlind | True, if there is no small blind in this hand, e.g. the player who would have been SB did bust in the previous hand. |
| NoBettingOnFlop | True if no bets/raises were made on the Flop, may also be used on the Flop. Bets by hero are also counted |
| NoBettingOnTurn | True if no bets/raises were made on the Turn, may also be used on the Turn, p. Bets by hero are also counted |
| NoVillainBetOrRaisedOnFlop | No villan bet or raised on Flop. Bets by hero are not counted |
| NoVillainBetOrRaisedOnTurn | No villan bet or raised on Turn. p. Bets by hero are not counted |
| NumberOfOpponentsAllin | Number of opponents who raised or called allin. Range: 0..9. If the amount to call is equal to our stack size and we are headsUp we consider the villan as being allin. |
| NumberOfRaisesBeforeFlop | The number of raises before the Flop made by opponents |
| NumberOfRaisesOnFlop | The number of raises on the Flop made by opponents. Bets don’t count |
| NumberOfRaisesOnTurn | The number of raises on the Turn made by opponents. Bets don’t count. |
| OpponentCalledOnFlop | An opponent called on Flop, and did not raise or bet |
| OpponentCalledOnTurn | An opponent called on Turn, and did not raise or bet |
| OpponentIsAllin | An opponent is all in, there may still be other players in the hand. If the amount to call is equal to our stack size and we are headsUp we consider the villan as being allin. |
| OpponentsLeftSittingOut | True, if all remaining opponents are sitting out. This symbol is especially meant for use in tournaments |
| Raises | The number of raises made by opponents this betting round. Bets don’t count. |
| RaisesBeforeFlop | True if any opponent raised before the flop |
| RaisesOnFlop | True if any opponent raised on the flop. Bets don’t count. |
| RaisesOnTurn | True if any opponent raised on the turn. Bets don’t count. |
| RaisesSinceLastPlay | The number of raises since our last action. Bets don’t count |
| SmallBlindSittingOut | True, if the big small is sitting out. This symbol is especially meant for use in tournaments |

<div class="rem*">

* 1*. Please note: OpenPPL history counters like Raises and Calls need
to get updated exactly once per orbit when we see stable input (i.e. out
turn). This update gets executed after autoplayer-actions. Therefore
these counters need an active autoplayer to work properly for multiple
orbits.

</div>
