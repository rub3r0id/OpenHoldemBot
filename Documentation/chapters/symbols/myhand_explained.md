# MyHand explained

This chapter contains a detailed explanation of Winngys f\$mh\_-symbols,
written by <span class="smallcaps">SNGChamp</span> for the Wiki.
Basically, the f\$mh_str-symbols (e.g. f\$mh_str_twopair) return a
relative ranking of your hand (hole and common) from 1 (weak) to 5
(strong), but they can be discounted up to 3 points depending on the
board-texture. The handstrength symbols are a separate library in
text-format and can be downloaded from
<a href="TODO!!!!!" class="uri">TODO!!!!!</a>

## f\$mh_str_onepair

- 1 = Board has Pair and you have Two small cards

- 1 = Board has Pair and you have One overcard w/ King (K9-K2)

- 1 = Board has Pair and you have One overcard w/Ace (A9-A2)

- 1 = Board has Pair and you have Two overcards

- 1 = Board has No Pair and you have Bottom pair w/ poor kicker

- 1 = Board has Pair and you have Two overcards w/ King

- 1 = Board has Pair and you have Two overcards w/Ace

- 2 = Board has No Pair and you have Middle pair w/ poor kicker

- 2 = Board has No Pair and you have Underpair

- 2 = Board has No Pair and you have Bottom pair w/ overcard kicker

- 2 = Board has No Pair and you have Midpair 2 overcard

- 3 = Board has No Pair and you have Middle pair w/ overcard kicker

- 3 = Board has No Pair and you have Top pair Queen or lower w/ poor
  kicker (9-2)

- 3 = Board has No Pair and you have Top pair King w/ poor kicker (9-2)

- 3 = Board has No Pair and you have Midpair 1 overcard

- 4 = Board has No Pair and you have Top pair Ace w/ poor kicker (9-2)

- 4 = Board has No Pair and you have Top pair Queen or lower w/ good
  kicker (A-T)

- 4 = Board has No Pair and you have Overpair

- 5 = Board has No Pair and you have Top pair King w/ good kicker (A-T)

- 5 = Board has No Pair and you have Top pair Ace w/ good kicker (K-T)

- 5 = Board has No Pair and you have Overpair 10’s or better

### OnePairDiscount

If the board shows 3 or 4 suited cards OR if the board shows 4
connecting cards, the strength value is reduced by 1.

## f\$mh_str_twopair

- 1 = Board has Pair and you have Two pairs w/ poor kicker (9-2)

- 1 = Board has two pair and you have only two pair

- 2 = Board has Pair and you have Two pairs w/ good kicker (A-T)

- 2 = Board has Pair and you have Underpair

- 3 = Board has No Pair and you have Bottom two pairs

- 3 = Board has Pair and you have Overpair

- 4 = Two pair with a Rainbow board

- 4 = Board has No Pair and you have Top and bottom pair

- 5 = Board has No Pair and you have Top two pairs

### TwoPairDiscount

If the board shows 3 or 4 suited cards OR if the board shows 4
connecting cards, the strength value is reduced by 1.

## f\$mh_str_trips

- 1 = Board has trips

- 2 = Trips using 1 of your hole cards (w/ paired board)

- 2 = Board has trips but you have good kickers (10 to A)

- 2 = Board has Pair and you have Trips w/ poor kicker (not used)

- 3 = Board not paired catch all

- 3 = Board has No Pair and you have bottom set

- 3 = Board has Pair and you have Trips w/ moderate kicker (used as 5th
  ranked card)

- 4 = Board has Pair and you have Trips w/ good kicker (used as 4th
  ranked card)

- 4 = Board has No Pair and you have middle set

- 5 = Board has No Pair and you have top set

### TripsDiscount

If the board shows 3 or 4 suited cards OR if the board shows 4
connecting cards, the strength value is reduced by 1.

## f\$mh_str_straight

- 1 = Board has straight

- 1 = Board 4 to a straight, card used low end of straight (rank 5)

- 2 = Board 4 to a straight, card used in rank 4

- 2 = Board 4 to a straight, card used in rank 3

- 3 = Board 4 to a straight, card used in rank 2

- 3 = Board 4 to a straight, card used in rank 1

- 3 = Board 3 to a straight, cards in rank 4 and rank 5 (sucker’s
  straight)

- 3 = Board 3 to a straight, cards in rank 3 and rank 5

- 3 = Board 3 to a straight, cards in rank 3 and rank 4

- 3 = Board 3 to a straight, cards in rank 2 and rank 5

- 4 = Board 3 to a straight, cards in rank 2 and rank 4

- 4 = Board 3 to a straight, cards in rank 2 and rank 3

- 4 = Board 3 to a straight, cards in rank 1 and rank 5

- 5 = Board 3 to a straight, nut straights

- 5 = Board 4 to a straight, card used in rank 5, nut straight with a
  Ten

- 5 = Board 4 to a straight, card used in rank 4, nut straight with a
  Jack

- 5 = Board 4 to a straight, card used in rank 3, nut straight with a
  Queen

- 5 = Board 4 to a straight, card used in rank 2, nut straight with a
  King

- 5 = Board 4 to a straight, card used in rank 1, nut straight with a
  Ace

- 5 = Board 3 to a straight, cards in rank 1 and rank 4

- 5 = Board 3 to a straight, cards in rank 1 and rank 3

- 5 = Board 3 to a straight, cards in rank 1 and rank 2 (high end)

### StraightDiscount

- If the board shows at least 3 suited cards, the strength value is
  reduced by 1.

- If the board shows at least 4 suited cards, the strength value is
  reduced by 2.

- If the board shows trips, the strength is reduced by 1.

- If the board shows 2 pair, the strength is reduced by 2.

- StraightDiscount is negated if there is a good draw (+1)

## f\$mh_str_flush

- 1 = board has flush, my cards don’t help

- 1 = Board has trips or more

- 1 = Four or more cards can beat my flush

- 2 = Three or less cards can beat my flush

- 3 = Three or more cards can beat my flush, board may be paired, flush
  came on turn \[something doesn’t seem right here...\]

- 3 = Two or more cards can beat my flush, board not paired

- 4 = One card can beat my flush

- 5 = Nut flush

### FlushDiscount

If the board shows two pair, the strength value is reduced by 2.

## f\$mh_str_fullhouse

- 1 = Board has full house

- 2 = Board trips, only one of my hole cards participates, the pair rank
  is lower than non-participating board cards e.g. QT/999TK

- 2 = Board trips, only one of my hole cards participates, the pair rank
  is higher than non-participating board cards e.g. QT/999T8

- 2 = Board trips, I have pocket pair lower than non-participating board
  cards e.g. QQ/JJJK2

- 2 = Board trips, I have pocket pair higher than non-participating
  board cards e.g. QQ/JJJ92

- 3 = none

- 4 = Board has two pair, I have top trips e.g. QT/QQJJ8

- 4 = Board paired, I don’t have pocket pair, I have bottom side full
  house, pair is lower than non-participating board cards e.g. QJ/QJJ53

- 4 = Board paired, I don’t have pocket pair, I have bottom side full
  house, pair is higher than non-participating board cards e.g. QJ/QJJ53

- 4 = Board paired, I don’t have pocket pair, I have top side full
  house, pair is lower than non-participating board cards e.g. QJ/QQJA3

- 4 = Board paired, I don’t have pocket pair, I have top side full
  house, pair is higher than non-participating board cards e.g. QJ/QQJ53

- 5 = Board paired, I have pocket pair and bottom side full house,
  pocket pair is lower than non-participating board cards e.g. QQ/QKKA6

- 5 = Board paired, I have pocket pair and bottom side full house,
  pocket pair is higher than non-participating board cards e.g. QQ/QKKT6

- 5 = Board paired, I have pocket pair and top side full house, pocket
  pair is lower than non-participating board cards e.g. QQ/QTTA3

- 5 = Best Full House; Board paired, I have pocket pair and top side
  full house, pocket pair is higher than non-participating board cards
  e.g. QQ/QTT53

## f\$mh_str_quads

- 1 = Board has quads, I don’t have best kicker

- 2 = Board has quads, I have a King kicker

- 3 = I may not have the highest, board does not have quads

- 4 = none

- 5 = Board quads, I have an Ace

- 5 = Nut 4 of a kind

## f\$mh_str_strflush

- 1 = Chop pot

- 2 = I may not have the highest, board does have a str8flush

- 3 = I may not have the highest, board does not have a str8flush

- 4 = none

- 5 = nuts
