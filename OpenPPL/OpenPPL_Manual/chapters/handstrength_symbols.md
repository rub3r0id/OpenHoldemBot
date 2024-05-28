# HandStrength Symbols

<div class="rem*">

* 1*. If a set is on board, “PairOnBoard” is also true; full houses do
also count as sets and pairs, made flushes as flushdraws, etc. Therefore
it is a strongly recommended to code made hands first (and strong made
hands at the very beginning), then weaker holding with positive
potential and weaker draws at the very last.

</div>

<table>
<thead>
<tr class="header">
<th style="text-align: left;">Name</th>
<th style="text-align: left;">Meaning</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td style="text-align: left;">HadOverpairOnFlop</td>
<td style="text-align: left;">Our pocketpair is/was of higher rank than
the highest ranked flop card</td>
</tr>
<tr class="even">
<td style="text-align: left;">HadOverPairOnTurn</td>
<td style="text-align: left;">Our pocketpair is/was of higher rank than
the highest ranked turn card</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HadPairOnFlop</td>
<td style="text-align: left;">We had a pair on the flop</td>
</tr>
<tr class="even">
<td style="text-align: left;">HadPairOnTurn</td>
<td style="text-align: left;">We had a pair on the turn</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HadSetOnFlop</td>
<td style="text-align: left;">We had a Set on flop</td>
</tr>
<tr class="even">
<td style="text-align: left;">HadSetOnTurn</td>
<td style="text-align: left;">We had a Set on turn</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HadTopPairOnFlop</td>
<td style="text-align: left;">Have/had top pair on flop</td>
</tr>
<tr class="even">
<td style="text-align: left;">HadTopPairOnTurn</td>
<td style="text-align: left;">Have/had top pair on turn</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HadTwoPairOnFlop</td>
<td style="text-align: left;">We had two pair on the flop</td>
</tr>
<tr class="even">
<td style="text-align: left;">HadSecondOverPairOnFlop</td>
<td style="text-align: left;">We had 2nd over pair on flop</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HadSecondOverPairOnTurn</td>
<td style="text-align: left;">We had 2nd over pair on turn</td>
</tr>
<tr class="even">
<td style="text-align: left;">HadSecondTopPairOnFlop</td>
<td style="text-align: left;">We had 2nd top pair on flop</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveSecondBestKicker</td>
<td style="text-align: left;">There is only one card that is better than
our current kicker</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveSecondBestKickerOrBetter</td>
<td style="text-align: left;"><p>We have the best or second best
kicker.</p>
<p>For Shanky-compatibility please see HaveBestKickerOrBetter.</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveSecondBestOverPairOrBetter</td>
<td style="text-align: left;">We have the second best overpair (KK) or a
stronger hand</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveSecondNutFlush</td>
<td style="text-align: left;">We have the second best flush
possible</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveSecondNutFlushDraw</td>
<td style="text-align: left;">We have the second best flush draw</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveSecondNutStraight</td>
<td style="text-align: left;">We have the second best straight
possible</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveSecondOverPair</td>
<td style="text-align: left;">We have a hole pair which is between the
highest board card and the 2nd highest card rank on board</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveSecondTopPair</td>
<td style="text-align: left;">We have the second highest pair</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveSecondTopSet</td>
<td style="text-align: left;">We have the second best set</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveThirdBestKicker</td>
<td style="text-align: left;">We have the third best kicker</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveThirdBestKickerOrBetter</td>
<td style="text-align: left;"><p>We have the third best, second best or
very best kicker.</p>
<p>For Shanky-compatibility please see HaveBestKickerOrBetter.</p></td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveThirdBestOverPairOrBetter</td>
<td style="text-align: left;">We have the third best overpair (QQ) or a
better hand</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveThirdNutFlush</td>
<td style="text-align: left;">We have the Third best flush</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveThirdNutFlushDraw</td>
<td style="text-align: left;">We have the Third best flushdraw</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveThirdOverPair</td>
<td style="text-align: left;">We have a hole pair which is between the
2nd highest board card and the 3rd highest card rank on board</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveThirdTopPair</td>
<td style="text-align: left;">we have the Third highest pair</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveThirdTopSet</td>
<td style="text-align: left;">We have the Third highest set</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveFourthNutFlush</td>
<td style="text-align: left;">We have the Fourth highest flush</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveFourthNutFlushDraw</td>
<td style="text-align: left;">We have the Fourth highest flushdraw</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveFourthOverPair</td>
<td style="text-align: left;">We have a hole pair which is between the
3rd highest board card and the 4tf highest card rank on board</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveFourthTopPair</td>
<td style="text-align: left;">We have the Fourth highest pair</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveFourthTopSet</td>
<td style="text-align: left;">We Have the Fourth highest set</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveFifthNutFlush</td>
<td style="text-align: left;">We have the Fifth highest flush</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveFifthNutFlushDraw</td>
<td style="text-align: left;">We have the Fifth highest flushdraw</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveFifthOverPair</td>
<td style="text-align: left;">We have a hole pair which is between the
4th highest board card and the 5th highest card rank on board</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveFifthTopPair</td>
<td style="text-align: left;">We have the Fifth pair</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveBackdoorSecondNutFlushDraw</td>
<td style="text-align: left;">We have the 2nd highest backdoor nut flush
draw</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveBackdoorThirdNutFlushDraw</td>
<td style="text-align: left;">We have the Third highest backdoor nut
flush draw</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveBackdoorFlushDraw</td>
<td style="text-align: left;"><p>We have a flush, flushdraw or a
backdoor flushdraw. Have BackdoorFlushdraw is only true, if</p>
<ul>
<li><p>we contribute 2 cards</p></li>
<li><p>or we contribute 1 card to the nuts</p></li>
<li><p>or we contribute 1 card to the 2nd nuts</p></li>
</ul></td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveBackdoorNutFlushDraw</td>
<td style="text-align: left;">We have a backdoor nut flush draw</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveBackdoorStraightDraw</td>
<td style="text-align: left;">True, if we need 2 cards to complete a
straight</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveBestKicker</td>
<td style="text-align: left;">We have the best kicker</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveBestKickerOrBetter</td>
<td style="text-align: left;"><p><em>Deprecated!</em></p>
<p>“OrBetter” means in the Shanky-world: any better hand, including any
pair, any set, even straights, whereas in the Openholdem world
HaveXBestKickerOrBetter considers only kickers. If you use this function
that mentions better hands than best kicker in its name OpenHoldem will
switch all kicker-functions to Shanky-style behaviour.</p>
<p>Not recommended, symbol exists for compatibility only.</p></td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveBestOverPairOrBetter</td>
<td style="text-align: left;">Have the best overpair (AA) or a better
hand</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveBottomPair</td>
<td style="text-align: left;">We have a hole card that is paired with
the lowest card on board</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveBottomSet</td>
<td style="text-align: left;">We have a set with the lowest board
card</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveBottomTrips</td>
<td style="text-align: left;">We have a trips with the lowest board
card</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveBottomTwoPair</td>
<td style="text-align: left;">We have bottom two pair</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveDoubleGutshotDraw</td>
<td style="text-align: left;">We have a double gut shot draw</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveFlush</td>
<td style="text-align: left;">We have a flush</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveFlushDraw</td>
<td style="text-align: left;">We have a flushdraw</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveFullHouse</td>
<td style="text-align: left;">We have a full house</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveInsideNutStraightDraw</td>
<td style="text-align: left;">True if the bot has an inside nut straight
draw. An inside nut straight draw is defined as a hand with at least 4
‘outs’ to a nut straight. Unlike NutStraightDraw, outs that make a flush
possible are not excluded</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveInsideStraightDraw</td>
<td style="text-align: left;">We have an inside straight draw</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveNothing</td>
<td style="text-align: left;">We have nothing (no pair, overcards,
flushdraw or straightdraw)</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveNutFlush</td>
<td style="text-align: left;">We have the nut flush</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveNutFlushCard</td>
<td style="text-align: left;">We have the nut flush card</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveNutFlushDraw</td>
<td style="text-align: left;">We have the nut flush draw</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveNuts</td>
<td style="text-align: left;">We have the best hand possible at this
time</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveNutStraight</td>
<td style="text-align: left;">We have the best possible straight</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveNutStraightDraw</td>
<td style="text-align: left;">True, if we have a draw to the best
straight; this means: if we hit, no better straight is possible. E.g.87
at a board of 653. A nut straight draw requires “at least 7 outs”
according to Shankys definition. Therefore straight draws get discounted
if there is a flush draw possible. Use HaveUnDiscountedNutStraightDraw
if you don’t worry about possible flushes.</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveNutStraightFlush</td>
<td style="text-align: left;">We have the nut straight flush</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveOpenEndedStraightDraw</td>
<td style="text-align: left;">We have an open ended straight draw</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveOverPair</td>
<td style="text-align: left;">We have a pocketpair higher than any card
on the board</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HavePair</td>
<td style="text-align: left;">We have a pair, a paired board doesen’t
count</td>
</tr>
<tr class="even">
<td style="text-align: left;">HavePocketPair</td>
<td style="text-align: left;">We have a pocket-pair like AA or 55</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveQuads</td>
<td style="text-align: left;">We have quads</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveRunnerRunnerFlushAtRiver</td>
<td style="text-align: left;">We have Flush and we made it with Turn and
River card</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveSet</td>
<td style="text-align: left;">We have a set, i.e. three of a kind with a
pair in the hand</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveStraight</td>
<td style="text-align: left;">We have a straight</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveStraightDraw</td>
<td style="text-align: left;">We have a straightdraw</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveStraightFlush</td>
<td style="text-align: left;">We have a straight flush</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveTopNonBoardPairedPair</td>
<td style="text-align: left;">One of our hole cards is the same value as
the highest non-paired card on board</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveTopPair</td>
<td style="text-align: left;">One of our hole cards is paired with the
highest ranked card on the board</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveTopSet</td>
<td style="text-align: left;">True, if we have a set with the highest
board card</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveTopTwoPair</td>
<td style="text-align: left;">The two highest cards on the board are
paired with our hole cards</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveTopTrips</td>
<td style="text-align: left;">True if we have the best possible
trips</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveTrips</td>
<td style="text-align: left;">We have trips, i.e. three of a kind with a
pair on the board</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveTwoPair</td>
<td style="text-align: left;">We have two pair, pair on board does not
count</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveUnderPair</td>
<td style="text-align: left;">We have a pocketpair lower than the lowest
ranked card on board</td>
</tr>
<tr class="odd">
<td style="text-align: left;">HaveUnderStraight</td>
<td style="text-align: left;">We have the lower part of a straight</td>
</tr>
<tr class="even">
<td style="text-align: left;">HaveWeakBackdoorStraightDraw</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-1</span>
HaveWeakDoubleGutshotDraw</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-1</span> HaveWeakFlush</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-1</span> HaveWeakFlushDraw</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-1</span>
HaveWeakInsideStraightDraw</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><span>1-1</span> HaveWeakStraight</td>
<td style="text-align: left;"></td>
</tr>
<tr class="even">
<td style="text-align: left;"><span>1-1</span> HaveWeakStraightDraw</td>
<td style="text-align: left;"></td>
</tr>
<tr class="odd">
<td style="text-align: left;">KingPresentOnFlop</td>
<td style="text-align: left;">A king is present on the flop</td>
</tr>
<tr class="even">
<td style="text-align: left;">NutFullHouseOrFourOfAKind</td>
<td style="text-align: left;"><p>This symbol evaluates the strength of
quads and full houses. Top quads are always rated as 1, bottom quads or
best-full house as 2, next best hand as 3 and so on. This symbol does
not take straight flushes into account. So it could return 1 even if our
hand can be beaten by a straight flush.</p>
<div class="rem*">
<p><em> 2</em>. Standard PPL returns 0 if we don’t have any quads / FH
at all. However we think this is counterintuitive and causes problems,
as a smaller number means a better hand. OpenPPL returns 999 for that
case.</p>
</div></td>
</tr>
<tr class="odd">
<td style="text-align: left;">Overcards</td>
<td style="text-align: left;">The number of hole cards that are
overcards to the board</td>
</tr>
<tr class="even">
<td style="text-align: left;">PairInHand</td>
<td style="text-align: left;">True, if we have a pocketpair</td>
</tr>
<tr class="odd">
<td style="text-align: left;">SuitsInHand</td>
<td style="text-align: left;">The number if unique suits in our
hand</td>
</tr>
<tr class="even">
<td style="text-align: left;">TopPairRank</td>
<td style="text-align: left;">Rank of the hole card giving you Top Pair
(2-14 where 14 is Ace)</td>
</tr>
<tr class="odd">
<td style="text-align: left;">SecondTopPairRank</td>
<td style="text-align: left;">Rank of our second Top Pair</td>
</tr>
<tr class="even">
<td style="text-align: left;">ThirdTopPairRank</td>
<td style="text-align: left;">Rank of our third Top Pair</td>
</tr>
<tr class="odd">
<td style="text-align: left;">ForthTopPairRank</td>
<td style="text-align: left;">Rank of our forth Top Pair</td>
</tr>
<tr class="even">
<td style="text-align: left;">FifthTopPairRank</td>
<td style="text-align: left;">Rank of our fifth Top Pair</td>
</tr>
<tr class="odd">
<td style="text-align: left;">TopPairKickerRank</td>
<td style="text-align: left;">Rank of the hole kicker card when you have
Top Pair (2-14 where 14 is Ace)</td>
</tr>
<tr class="even">
<td style="text-align: left;">TripsRank</td>
<td style="text-align: left;">Rank of our Trips</td>
</tr>
<tr class="odd">
<td style="text-align: left;">TripsKickerRank</td>
<td style="text-align: left;">Rank of the kicker of our Trips</td>
</tr>
</tbody>
</table>
