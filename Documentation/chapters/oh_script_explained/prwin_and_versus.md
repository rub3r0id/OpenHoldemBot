# PrWin and Versus - Winning Probabilities

<table>
<thead>
<tr class="header">
<th style="text-align: left;"></th>
<th style="text-align: left;">prwin</th>
<th style="text-align: left;">versus</th>
<th style="text-align: left;">weighted prwin</th>
<th style="text-align: left;">enhanced prwin</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td style="text-align: left;">preflop/postflop</td>
<td style="text-align: left;">both</td>
<td style="text-align: left;">both</td>
<td style="text-align: left;">both</td>
<td style="text-align: left;">both</td>
</tr>
<tr class="even">
<td style="text-align: left;">accuracy</td>
<td style="text-align: left;">depends on
f$prwin_number_of_iterations</td>
<td style="text-align: left;">100% exact</td>
<td style="text-align: left;">depends on
f$prwin_number_of_iterations</td>
<td style="text-align: left;">depends on
f$prwin_number_of_iterations</td>
</tr>
<tr class="odd">
<td style="text-align: left;">speed</td>
<td style="text-align: left;">depends on
f$prwin_number_of_iterations</td>
<td style="text-align: left;">superfast (precomputed table)</td>
<td style="text-align: left;">depends on
f$prwin_number_of_iterations</td>
<td style="text-align: left;">depends on
f$prwin_number_of_iterations</td>
</tr>
<tr class="even">
<td style="text-align: left;">handranges</td>
<td style="text-align: left;"><p>random only</p>
<p>(100% range)</p></td>
<td style="text-align: left;"><p>arbitrary handlists,</p>
<p>but usually fixed</p></td>
<td style="text-align: left;">userdefined range, but simplified
model</td>
<td style="text-align: left;"><p>arbitrary handrange,</p>
<p>userdefined</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;">opponnents</td>
<td style="text-align: left;">1-22, using
f$prwin_number_of_opponents</td>
<td style="text-align: left;">1</td>
<td style="text-align: left;">1-13, using f$prwin_number_of_opponents
(weighted prwin will be disabled, if value &gt; 13.)</td>
<td style="text-align: left;">nopponentsplaying</td>
</tr>
<tr class="even">
<td style="text-align: left;">formula / DLL</td>
<td style="text-align: left;">all</td>
<td style="text-align: left;">all</td>
<td style="text-align: left;">all</td>
<td style="text-align: left;">DLL only</td>
</tr>
</tbody>
</table>

## Standard PrWin

Standard PrWin was the first way to calculate winning probabilities with
WinHoldem. Just like so many other features of WinHoldem it is based on
an oversimplified model, assuming a 100% range for all opponents, i.e.
just random cards, no matter what.

This method has an obvious drawback: the calculated winning-percentages
are way too optimistic.

Instead of improving that basic model a rude workaround got introduce:
f\$prwin_number_of_opponents, a function to adapt the number of
opponents considered by the PrWin-Iterator. So instead of modelling
hand-ranges for your opponents depending on the texture of the boards
and the bettinglevel you had to do some guesswork about how many
opponents to add to get the same numbers.

<div class="rem">

* 1*. For an explanation about the required number of iterations see the
chapter ”Iterations and Standard Deviation”. But as a rule of thumb
10.000 to 100.000 should give you reasonable numbers.

</div>

## Versus 

Versus is a capability introduced into WinHoldem in 2005 (and
implemented in OH from startup) which allows the user to assess his
probability of winning against a single opponent with a specified
handlist. It does use large pre-computed tables and the result is
substantially obtained by table lookup rather than the Monte Carlo
iteration used for Prwin. It is much faster than Prwin, and the user can
weight the result by selecting a suitable handlist for the opponent. It
is thus a powerful tool for calculating good win probability against a
single opponent.

Especially useful is the multiplexer-function

    vs$multiplex$X$prwin  // or prlos, prtie

that looks up a numbered list depending on a range-function. For example
the calculation of allin-equity could become as simple as

    ##f$allin_equity_against_bigblind##
    vs$multiplex$f$bigblind_calling_range$prwin
    + 0.5 * vs$multiplex$f$bigblind_calling_range$prtie

Against multiple opponents its utility is much reduced, since the
existence of the same cards in different opponent handlists is not
allowed for the versus calculation, and combining the results from
several independent versus assessments creates an increasingly
inaccurate estimate as the number of opponents increases.

## Weighted PrWin

Weighted Prwin does work similar to Standard PrWin, but enables you to
model opponents handranges. It got developed by Matrix as part of his
DLL and then contributed to OpenHoldem.

<figure>
<img src="images/weighted_prwin.jpg" />
</figure>

The hand-range of your opponent gets described by four parameters, each
specifying a handrank169-value:

- f\$mustplay: absolute premium-hands, that will never be folded by your
  opponent, even if the betting-action does not indicate a monster-hand.
  If you are dead-sure, that your opponent doesn’t slowplay aces, you
  can set f\$mustplay to zero.

- f\$topclip: the top of your opponents range, which will be played with
  certainty. Cards between f\$topclip and f\$mustplay will also be
  included, but with reduced probability.

- f\$willplay: the bottom of your opponents range, which will be played
  with certainty.

- f\$wontplay: the border to pure trash. Hands rated lower will never be
  played by your opponent. Hands between f\$willplay and f\$wontplay
  will be included in his range, but with reduced probability.

Ideally you would base the calculations of these points on the
statistics for opponent betting pre-flop at various bet levels. This
information is not currently available from OH (unless you use the
PokerTracker capabilities), but the single most useful statistic,
SingleMalt’s floppct, can be used. Using this to set f\$willplay and
f\$wontplay gives the major advantage which a weighted prwin gives; the
elimination of rags from the iterator calculations. A starting point
might be something like:

    ##f$willplay## 
    handsplayed<10 ? 72 : 180*floppct

    ##f$wontplay## 
    f$willplay * 1.4

Weighted PrWin will fall back to Standard PrWin, when the parameters
provided are unusable, e.g.

- if f\$willplay is absent, or returns zero.

- if f\$prwin_number_of_opponents is greater than 13.

The calculation will furthermore not weight the cards for an opponent
who is BB and has limped into the flop. f\$willplay will be increased
internally if it is so low that the iterator cannot assign cards for all
opponents from the available matching hands.

Weighted PrWin gives far better results than Standard PrWin, but the
ability to specify handranges is still somewhat limited due to the
ordering of hands according to their handrank-value. It is e.g. a bit
hard to model playing tendencies or the preference for hands with low
equity but good playability, like low pairs and suited connectors.

Furthermore the same range will be assumed for all opponents in the
hand.

<div class="rem">

* 2*. As the hand-ranges are more concrete than for Standard PrWin
f\$prwin_number_of_opponents should obviously return the correct number
of opponents in the hand.

</div>

## Enhanced PrWin

To overcome that limitations Enhanced PrWin got developed (again by
Matrix). Enhanced PrWin does allow you to specify a probability for
every single hand and thus gives you exact winning probabilities
(provided you model the hand-ranges correctly). However — this
mightiness causes some complexity and some labour. Advanced opponent
modelling and calculating probabilities for every single hand is too
complex for OH-script. Therefore this features is only available at the
DLL-level and gets described in more detail in the chapter about
DLL-programming.
