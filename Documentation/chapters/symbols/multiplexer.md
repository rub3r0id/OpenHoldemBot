# Multiplexer

The multiplexer-engine is a module that enables you to access lots of
symbols in a poker-logical way.

<figure>
<img src="images/multiplexer.jpg" />
</figure>

## Historic background

The philosophy of WinHoldem in the by-gone past and early OpenHoldem
was: provide technical symbols and let the user do all the rest. For
example there were symbols currentbet0..currentbet9 for the bets of the
chairs 0,.9. If the user wanted to figure out the currentbet of the big
blind he first had to create a function that identified the
big-blind-chair

    ##f$bigblindchair##
    // Chair 0 dealt 2nd?
    ac_dealpos0 == 2 ? 0 :
    // Chair 1 dealt 2nd?
    ac_dealpos1 == 2 ? 1 :
    // Chair 2 dealt 2nd?
    ac_dealpos2 == 2 ? 2 :
    ...

This functions looks for the chair that got dealt 2nd and returns the
chair number, assuming it is the big-blind (it ignores some finer
details like a missing small-blind or reversed blinds headsup). With
this function it is now possbile to lookup the currentbet of the
big-blind in a similar way:

    ##f$bigblindcurrentbet##
    WHEN bigblindchair == 0 RETURN currentbet0 FORCE
    WHEN bigblindchair == 1 RETURN currentbet1 FORCE
    WHEN bigblindchair == 2 RETURN currentbet2 FORCE
    ...
    WHEN bigblindchair == 9 RETURN currentbet9 FORCE

Doable, but somewhat clumsy and lots of work, as such functions had to
be created for every logical chair and for every symbol you, the user,
wanted to access.

## The new multiplexer

First: OpenHoldem provides more than a dozen built-in logical
chair-symbols like dealerchair, firstraiserchair, lastcallerchair
utgchair. Second: the multiplexer-engine makes it possible to use these
chair-symbols for indexing numbered symnols. For example you can now
write:

    WHEN currentbet_lastraiserchair > ...
    WHEN balance_bigblindchair <= ...
    WHEN pt_vpip_smallblindchair < ...

## Chair symbols supported

The multiplexer-engine supports the following chair-symbols for indexing
other symbols:

- userchair

- bigblindchair

- smallblindchair

- dealerchair

- buttonchair (synonym for dealerchair)

- cutoffchair

- mp3chair

- mp2chair

- mp1chair

- ep3chair

- ep2chair

- ep1chair

- utgchair (under the gun, the player behind big blind, first to act
  preflop)

- firstraiserchair

- lastraiserchair

- raischair (historic synonym for lastraiserchair)

- firstcallerchair

- lastcallerchair

- headsupchair (chair of your last remaining opponent)

- bigstackchair

- smallstackchair

## Betrounds

Besides chair symbols the multiplexer engine supports also betting-round
symbols for indexing of game-history symbols. It is now possible to
write code like ncurentbets_previousround or the verbose
nplayersround_flop instead of nplayersround2. Symbols supported:

- preflop

- flop

- turn

- river

- currentround

- previousround

## Suits

Additionally the new symbols suitbitsplayerN (N = 0..3) and
rankbitsplayerN can be addressed in a verbose way with the following
multiplexer-postfixes.

- clubs

- diamonds

- hearts

- spades

## PokerTracker

In the past OpenHoldem supported similar functionality for PokerTracker
symbols only.These symbols get now also handled by the multiplexer in
order to avoid duplicate functionality in the code-base. as a
consequence some symbols got renamed slightly. E.g.
pt_vpip_lastcallerchair instead of the former pt_vpip_lastcaller.

## OpenPPL and user-defined symbols

Of course the multiplexer-engine works also for OpenPPL. For example the
OpenPPL-library contains technical functions StackSize0..Stacksize9 and
the values can be addressed in a logical way like StackSize_dealerchair.
And of course it works for user-defined functions exactly the same way.
