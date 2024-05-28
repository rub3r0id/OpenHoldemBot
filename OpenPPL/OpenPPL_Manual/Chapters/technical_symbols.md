# Technical Symbols

While building the OpenPPL library the developers had to create lots of
internal supporting functions. Most of them are so technical that they
are of no use for the end-user. However some of them might be helpful
for people who want to extent the OpenPPL library with their own
symbols. A function like SmallBlindChair might for example be useful for
the development of PokerTracker symbols like PT_SmallBlind_VPIP.

| Symbol | Explanation | Remarks |
|:---|:---|:---|
| Chair0StartingStackSize ... Chair9StartingStackSize | Starting stacksize of Chair N at the beginning of the hand (balance + currentbet). Measured in bets, not in dollars. | Mainly for preflop. In other betting rounds it returns the starting stack at the beginning of that round. |
| BigBlindCurrentBet, SmallBlindCurrentBet | Current bets of the blind posters, measured in dollars | Mainly used to detect, if the blinds are truely raising or if they are “blind raisers”. |
| ConstCardTwo ... ConstCardAce | Named card constants to improve readability and maintenability. Useful if you want to access OpenHoldem’s card symbols \$\$pr0, \$\$pr1, \$\$cr0 ... \$\$cr4. | None |
| ConstBetRoundPreflop, ConstBetRoundFlop, ConstBetRoundTurn, ConstBetRoundRiver | Named constants for the four betting rounds. To be used with OpenHoldem’s “betround” symbol | None |
| CommonCard0Paired ... CommonCard4Paired | True, if the rank of common card N is equal to the rank of another common card. | Postflop only |
| MaximumPossibleBetsizeIndollars | Maximum Possible bet size in dollars considering our current bet and balance | None |
| PT_LastCaller_Chair | Last Caller Chair number | None |
| RankOfSetOnBoard | Rank of the set on board | Valid only, if there are 3 or 4 cards of the same rank, undefined otherwise |
| RankOfSpareCardWhenTwoPairOnBoard | returns rank of the spare card when two pair on board on the river | River only |
| RankOfTopPairOnBoard | returns rank of the highest pair on board (true also if set or twopair or fullhouse on board) | Postflop only |
| SidePot | Pot size (in number of blinds) we are not participating in due to opponent’s bet being bigger than the sum of our balance plus currentbet. PotSize returns effective pot size because SidePot amount is subtracted from it. | None |
| SidePotInDollars | Pot size (in dollars) we are not partecipating in due to opponent’s bet being bigger than the sum of our balance plus currentbet | None |
| EarlyPosition1Chair ... MiddlePosition3Chair, CutOffChair, ButtonChair, SmallBlindChair, BigBlindChair | Chair numbers of the specific players. Could be used e.g. for symbols like PT_SmallBlind_VPIP | None |
| AggressorChair | Same meaning as ac_aggressor, but more reliable. ac_aggressor alone is somewhat unreliable, as it gets scraped (by bets). But if we raise and there are super-fast calls behind us (e.g. at PokerAcademy), then we don’t have stable frames and soon we will switch to the next betting round, so OpenHoldem might miss the aggressor. This symbol also considers our last action and the amount to call to overcome this problem. | None |
| SmallBlindRaising ... ButtonRaising | True, if the chair in question is betting or raising. Contrary to OpenHoldem’s conventions “blind raisers” are not counted preflop; only if they truely raise. |  |
