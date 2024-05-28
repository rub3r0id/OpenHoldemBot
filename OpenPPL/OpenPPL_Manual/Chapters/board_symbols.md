# Board Symbols

<div class="rem*">

* 1*. If a set is on board, “PairOnBoard” is also true; full houses do
also count as sets and pairs, made flushes as flushdraws, etc. One of
many reasons why you should code strong hands first.

</div>

| Name | Meaning |
|:---|:---|
| SecondTopFlopCardPairedOnRiver | Synonym for SecondTopFlopCardPairedOnRiver |
| SecondTopFlopCardPairedOnTurn | Synonym for SecondTopFlopCardPairedOnTurn |
| AcePresentOnFlop | An ace is present on Flop |
| FlushOnBoard | The entire board are the same suit |
| FlushPossible | A flush is possible on the current board (3 or more of 1 suit) |
| FlushPossibleOnFlop | The entire Flop is one suit |
| FlushPossibleOnTurn | A flush is possible on the Turn |
| FourCardsToWheelOnBoard | True if a wheel can be made by using only one hole card, i.e. if 4 cards of A2345 are on the board |
| FourOfOneSuitOnTurn | True if only 1 suit is/was present on the board on the Turn |
| FullHouseOnBoard | There is a full house on the board |
| HighCardOfCommonStraigh | Returns the value of the highest card of a shared straight. Especially meant to decide if we have the shared nuts (Ace) or if we can beat the board |
| KingPresentOnFlop | True, if at least one of the Flop-cards is a king |
| LowCardsOnBoard | The number of cards with the rank of 8 or lower (ace is counted as low). Duplicates of one rank are not counted |
| MoreThanOneStraightPossibleOnFlop | More than one straight is possible on the Flop |
| MoreThanOneStraightPossibleOnTurn | There is/was more than one way to make a straight on the Turn |
| NutsOnBoard | True if the best possible hand is on the onboard |
| OneCardFlushPossible | The board contains 4 or 5 cards of the same colour |
| OneCardStraightFlushPossible | Only one holecard is needed to make a straightflush |
| OneCardStraightPossible | Only one hole card is needed to make a straight |
| OneCardStraightPossibleOnTurn | A one card straight is/was possible on the Turn |
| Only1OneCardStraightPossible | only one straight can be made using only one hole card with the current board cards |
| OnlyOneStraightPossible | Only one straight possible |
| OvercardsOnBoard | The number of common cards that are higher than the highest card in our hand |
| PairOnBoard | There are at least 2 cards of the same rank on the board |
| PairOnFlop | A pair is present on the Flop |
| PairOnTurn | The board has a pair on the Turn or on the Flop |
| QuadsOnBoard | There are quads on the board |
| QueenPresentOnFlop | A queen is present on the Flop |
| RiverCardIsOvercardToBoard | The River card is the highest ranked common card |
| RunnerRunnerFlushPossibleAtRiver | True if a Runner Runner Flush is possible at the River |
| SecondTopFlopCardPairedOnRiver | True, if the 2nd highest Flop card paired on the River. If the Flop is paired it will be the lowest card. If all ranks are equal quads at the River will make this function true. |
| SecondTopFlopCardPairedOnTurn | True, if the 2nd highest Flop card paired on the Turn. If the Flop is paired it will be the lowest card. If all ranks are equal quads at the Turn will make this function true. |
| StraightFlushOnBoard | Straight flush is on board |
| StraightFlushPossible | Straight flush is possible |
| StraightFlushPossibleByOthers | A straight flush can be made by an opponent with regards to our cards |
| StraightOnBoard | The board contains a straight |
| StraightPossible | Straight is possible |
| StraightPossibleOnFlop | A stright is possible on the Flop |
| StraightPossibleOnTurn | A stright is possible on the Turn |
| SuitsOnBoard | The number of different suits on board. Always 0 Preflop. |
| SuitsOnFlop | The number of different suits on the Flop. Always 0 Preflop. |
| SuitsOnRiver | The number of different suits on the River. Always 0 Preflop, at the Flop and the Turn. |
| SuitsOnTurn | The number of different suits on the Turn. Always 0 Preflop and at the Flop. |
| ThreeCardStraightOnBoard | There are at least three connected cards on the board |
| TopFlopCardPairedOnRiver | The card with the highest rank on the Flop paired on the River |
| TopFlopCardPairedOnTurn | The card with the highest rank on the Flop paired on the Turn |
| TripsOnBoard | At least three cards of the same rank are present on the board |
| TripsOnBoardOnTurn | At least three cards of the same rank is present on the Turn |
| TurnCardIsOvercardToBoard | The Turn card is the highest ranked common card |
| TurnCardPaired | The card that was dealt on the Turn paired on the River |
| TwoOfOneSuitPresentOnFlop | True, if the Flop has / had at least 2 cards of the same suit. |
| TwoPairOnBoard | True, if the board contains two pairs |
| TwoPairOnBoardOnTurn | True, if the board contained two pairs on Turn |
| UncoordinatedFlop | True, if the Flop contains/contained no pair on board, no possible flush, three different suits, no possible straight and no opponent could have 7 or more outs to a straight |
| WheelPossible | True, if a straight with A2345 is possible |
