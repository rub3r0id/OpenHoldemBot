# Handstrength-library

In the legendary golden age of Fixed Limit Hold’em Winngy, member of Lab
1, developed a hand-strength-library that rates all hands from 1 (weak)
to 5 (very strong). He used it successfully in his private
Fixed-Limit-bot that played \$5/\$10 at that time. For the No-Limit-guys
of modern times: these were the blinds, not buyins; and he also got a
100%-prop-deal to make his hobby even more enjoyable. Long story short:
Fixed Limit died slowly and so Winngy decided to donate his
hand-ranking-system to the OpenHoldem project. Our member HTC added his
outs-counter. Both are combined in a library, which can be downloaded
from
<https://github.com/OpenHoldem/openholdembot/blob/master/mh_str_Handstrength_Library/mh_str_Handstrength_Library.ohf>.To
make use of these functions just include this library in your bot-logic.

| Symbol | Meaning |
|:---|:---|
| f\$mh_3straightxy | (x=1 for wheel, 0 not, y=1 for broadway, 0 not) - returns true if the board has a wheel straight draw or broadway straight draw, given the wheel/broadway parameters 00 - true if the board has neither a wheel straight draw nor a broadway straight draw 10 - true if the board has a wheel straight draw 01 - true if the board has a broadway straight draw 11 - true if the board has either a wheel straight draw or a broadway straight draw |
| f\$mh_bottomsd | true if I have a bottom straight draw (if you are contributing a single card to an open-ended straight draw and that card is the smallest, this symbol is true e.g. hole: T2 common: 345K) |
| f\$mh_nsuitedbetter | number of missing suited cards that are higher than my best suited card |
| f\$mh_kickerbetter | number of cards that can beat your kicker f\$mh_kickerrank rank of your kicker (returns 0 if kicker is shared \[board\] and thus useless) |
| f\$mh_nouts | number of outs (HTC’s formula) f\$mh_str_strflush 0-5 (5 best) of the relative strength of your straight flush |
| f\$mh_str_quads | 0-5 (5 best) of the relative strength of your four of a kind |
| f\$mh_str_fullhouse | 0-5 (5 best) of the relative strength of your full house |
| f\$mh_str_flush | 0-5 (5 best) of the relative strength of your flush |
| f\$mh_str_straight | 0-5 (5 best) of the relative strength of your straight |
| f\$mh_str_trips | 0-5 (5 best) of the relative strength of your three of a kind |
| f\$mh_str_twopair | 0-5 (5 best) of the relative strength of your two pair |
| f\$mh_str_onepair | 0-5 (5 best) of the relative strength of your one pair |
