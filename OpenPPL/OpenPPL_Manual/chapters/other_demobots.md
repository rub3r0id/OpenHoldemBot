# Other Default-bots

## Winngy Fixed Limit

Back in the days when Ms Bunnybaker won an online-ticket to one of the
main poker events online-poker became very popular; lots of
brick-and-mortar-players joined the online-tables. A visionary named Ray
E. Bornert created the WinHoldem pokerbotting-framework for the
fixed-limit games. A guy called Winngy used it to build his first
poker-bot. It played the so called low-stakes up to \$10/\$20 (big blind
and big bet, not buyins). Casinos offered the same limits like real
casinos these days; and all recreational players used to choose the same
limits they were used to from their local casino.

So Winngy enjoyed a nice win-rate and at a new online-casino an equally
nice prop-deal of 120% rakeback for a player who always hangs around in
order to get the games started. Unfortunately for Winngy the fixed-limit
games were drying up and became less popular due to a company named
PokerTragedy and their Chinese rakeback-slaves. So Winngy counted his
winnings and moved on to other game-types. As a true gentleman he
donated his pokerbot to the OpenHoldem community for learning and
tweaking.

## Termita SNG

One day our member TheHighFish out of curiousity had a look at some
Shanky demobots and came across a very special one. It was a SNG-bot
written by Tetre and Xiquetete, our member Termitapalahermita. THF
immediately recognized its potential. The bot-logic was nicely written
and well structured. It used dozens of user-variables in order to avoid
code-clones and achieve a readable, self-documenting code. Furthermore
it could be configured to play various types of SNGs nearly out of the
box.

So THF asked the sole creator who was left, Termita, for allowance to
include this bot as a default-bot for OpenHoldem. Termita agreed and so
THF started to work, rewriting the entire bot. OpenHoldem symbols like
StartingStackSize, StartingBigBlindSize and maxnplayersdealt made it
possible to get rid of the configuration section and detect the
game-type automatically, be it 6-max, 9-max, 10-max, deep-stack, normal,
turbo or hyper-turbo.

When THF ran out of time and money Trish took over, a lady who plays
poker since the shooting of Kennedy. She finished the work, fine-tuned
ranges, added some headsup-code and a little bit more aggression.
Postflop was said to be based on a mixture of Doodle and Zulu, so it got
completely removed in favour of roller-coaster Gecko.

Then we stepped a little bit back, looked at our work with pride and
decided that it was a wonderful starting-point for every SNG-botter.
