# Player- and OpponentSymbols

| Name | Meaning | Limitations |
|:---|:---|:---|
| HandIsHeadsup | True if two people compete for this pot. the hand might have been more-handed before. | None |
| LastAggressorActsAfterUs | True (returns 1) if the last aggressor acts after us | None |
| Opponents | The number of opponents that are currently in the hand. Does also count players that are allin (contrary to Shanky who count players that went allin in this betting round, but not players allin from previous rounds). | REMARK. To know the number of Opponents with balance above zero you should use the formula “Opponents - NumberOfOpponentsAllin” |
| OpponentsAtTable | The number of opponents that were dealt cards this hand | None |
| OpponentsLeft | Same meaning as Opponents but better naming. | None |
| OpponentsOnFlop | The number of opponents that saw the Flop | None |
| OpponentsWithHigherStack | The number of opponents that are seated and have higher balance than yourself | None |
| OpponentsWithLowerStack | The number of opponents that are seated and have less balance than yourself | None |
| TableIsHeadsup | True if only two people have been dealt (cash-game) and only two people are seated (tournaments, where players who sitout also get dealt). This symbol is especially meant to detect the latest stage of a tournament, contrary to HandIsHeadsup for cash-games. | None |
