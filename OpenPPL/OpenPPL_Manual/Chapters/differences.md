# Differences To Shanky And Old-Style-PPL

If you are a botter who used Shanky-PPL in the past there are some
differences you should know about:

## Plain Text Only

The deciphering of encypted PPL is a business-secret of Shanky
BonusBots. We don’t know and will never support this data-format. Our
aim is to build an open-source botting-tool and not a marketing-platform
for shady salesmen. Therefore OpenPPL is plain text only — for profiles
you own legally, or even better: for profiles you build on your own.

## No Option Settings

Standard Shanky-PPL supports option settings to configure their
built-in-default bot; at least that was the old way to do so, but
nowadays most of these settings get overwritten by the profile and have
no effect at all. OpenHoldems built-in Gecko-bot does not support any
Shanky-opttions; they have no effect and simply get ignored.

    MakePotSizedPreFlopRaisesWhen = 6
    FoldToPre-FlopRaisesForAQAJsKQ = OFF
    FoldPost-FlopBelowTopPairToAnyBetOrRaise = OFF
    FoldToPost-FlopRaisesWithUnpairedBoardsFor = 2 
    ...
    custom

    preflop
    ...

## No Keyword Custom

As no built-in default bot exists the whole bot-logic is “custom”. Sure,
we could ignore that superfluous keyword, however it is an indication of
old-style or Shanky-style (Open)PPL. There will be more things “wrong”
for sure, so we prefer to show you a warning as early as possible.

## Preflop, Flop, Turn and River Sections

The four main code-sections are functions (technically speaking),
therefore they have OH-script-style function-header-syntax:

    ##f$preflop##
        WHEN ... RaiseMax FORCE
        ...

    ##f$flop##

    ##f$turn##

    ##f$river##

At least the f\$preflop-section must be present for OpenHoldem to switch
to OpenPPL-mode.

## Floating Point Numbers

There are some differences between Standard PPL and OpenPPL you should
care about – luckily only very few:

- Standard PPL uses integers everywhere, whereas OpenPPL uses floating
  point numbers. An example: in Standard PPL you could write code like:

      WHEN Stacksize = 1 AND ... RaiseBy 1 FORCE
      WHEN Stacksize = 2 AND

  or even

      WHEN AmountToCall = 70% Stacksize

  which will cause troubles with OpenHoldem, because OpenHolden uses
  real numbers like 31.41. Therefore it is recommended to use
  inequality-operators, for example like below:

      WHEN Stacksize < 1.5 AND ... RaiseBy 1 FORCE
      WHEN Stacksize < 2.5 AND

  Or you could even use the new approximately-equal-operator:

      WHEN Stacksize ~~ 3 RaiseMax FORCE

- Standard PPL’s symbol NutFullHouseOrFourOfAKind uses lower numbers for
  better full houses or quads, but 0 for no full house at all. This is
  somewhat inconsistent and OpenPPL uses a high number (999) for that
  case.

## Hand And Board Expressions

OpenHoldem’s formula engine uses floating-point-numbers internally and
there is no easy way to represent a board of cards as a single
floating-point-number. There could even be various different
board-expressions at the right side of an equality comparator that are
all true.

    WHEN Board = AT ...
    WHEN Board = ATSuited...

Therefore we don’t support native Shanky-syntax here but use
parameterized symbols

    WHEN board$AT ...
    WHEN board$ATSuited ...

## Cases Matter (Partially)

OpenHoldem is case-sensitive – contrary to standard PPL. Therefore the
case used (upper and/or lower) matters. The rules for your OpenPPL code
are more user-friendly and less rigid. Three areas where case matters:

- Keywords like “WHEN”, FORCE and operators like OR etc. For keywords,
  three different formats are allowed: all upper-case, all lower-case,
  or a reasonable mix.

      WHEN (Hand$AA) RaiseMax FORCE
      When (Hand$AA) RaiseMax Force
      when (Hand$AA) RaiseMax force

  For better readability we recommend to use only upper-case for
  keywords.

- OpenHoldem symbols. Native OpenHoldem symbols are case-sensitive and
  always lower-case.

      WHEN (pt_vpip0 < 0.10) Fold FORCE
      WHEN (balance0 < 50) RaiseMax FORCE

  However: you will probably use these symbols very rarely in your code.
  Probably only to create poker-logical symbols like PT_OpenRaiser_VPIP
  and BigBlindStackSize.

- OpenPPL-symbols that are part of the library. They are case-sensitive
  OH-script-functions with mixed upper and lower case letters.

      WHEN (StillToAct < 2) RAISETO 3 FORCE

  The naming is pretty intuitive, but the function that generates
  error-messages is smart enough to look for similar named symbols and
  will show you a helpful warning if something is wrong.

## False Friends

Again: case-sensitivity matters. There are some (only three) symbols
with the “same” name that have a different meaning for OH-script and
OpenPPL.

| Symbol | Meaning                                                        |
|:-------|:---------------------------------------------------------------|
| bet    | The minimum bet for the current bet-round, measured in dollars |
| Bet    | The action min-bet (equivalent to min-raise)                   |
| call   | The amount you need to call, measured in dollars               |
| Call   | The action “Call”.                                             |
| random | Generates numbers in the range \[0..1)                         |
| Random | Generates integer numbers in the range \[0..99\]               |

You probably won’t need the OH-script symbols, but at least the library
of OpenPPL-functions uses them internally, so they have to be there. For
the first two cases OpenHoldem’s parser can detect if you took an
identifier instead of an action and will warn you about that. But at the
moment you need to take care about the latter case.

<figure>
<img src="images/oh_random.jpg" />
</figure>

## Keyword “Set” For User-Defined Variables

Long story short: Shanky-PPL is an easy, English-like language that is
intuitive to use, but it contains some technical flaws. For example, it
can’t be parsed with a one-token-look-ahead like all other modern
programming languages. This complicates the parser and especially the
generation of good, helpful error-messages. Therefore we had to deviate
at some points a liitle bit. The most conspicuous point is the new
keyword “Set” before a user-variable:

    WHEN ... Set user_utg_limp_raised_preflop

## No Shanky-Style Delay

    preflop
        WHEN ... RaiseBy 3 Delay 5 FORCE

A user-defined delay after an action simply does not fit the concept of
functions, that traditionally return only a single value. Besides that:
we believe that it is very clumsy to have thousands of lines with a
fixed delay. OpenHoldem natively supports a solution that is way better
suited for this use-case: a f\$delay-functions.

It requires only some (or some dozen) lines of code for perfect
randomized delays, depending e.g. on board-texture, betting-actions,
etc.

    ##f$delay##
       WHEN UncoordinatedFlop AND Random < 10 RETURN 2500 FORCE
       WHEN ...

## f\$sitout Function

For similar reasons OpenPPL does no longer support a SitOut-command. We
prefer to separate the playing logic from hopper-logic. Therefore
OpenHoldem has a f\$sitout-function. Furthermore OpenHoldem supports
f\$sitin, f\$autopost, f\$leave, f\$close and some more.

    ##f$InUTG##
        WHEN (dealposition = 3) RETURN True FORCE

    ##f$sitout##
       // issittingin, handsplayed and floppct are OpenHoldem symbols 
       // that can be used like any other OpenPPL symbol.
       // We wait until the orbit is finished and sitout
       // before we have to post the big blind again.
       WHEN (issittingin
            AND handsplayed > 15 
            AND floppct < 0.20 
            AND HaveNoCards 
            AND InUTG) 
         RETURN True Force  

## RaiseBy And RaiseTo Actions

Let’s assume the following situation: you sit in the big blind and had
to pay \$10. Everybody folds to the button who raises to \$30. Now it is
your turn again and you decide to enter “90” into the raise-box. What
does this mean?

Well, it depends on the casino.

- at some casinos \$90 will be your final betsize (RaiseTo,
  betsizeinterpretationmethod = 3)

- other casinos will add \$90 to the \$10 you already posted, so the
  final betsize will be \$100 (betsizeinterpretationmethod = 2).

- and finally some other casinos will add these \$90 to the \$30 of the
  last raiser, so the final betsize will be \$120 (RaiseBy,
  betsizeinterpretationmethod = 1)

How does Shanky handle this Babylonian confusion?

> In one case the small blind is counted as part of the pot and in the
> other it is not. This can vary between poker rooms as well. You just
> have to experiment to get it where you like and save each profile the
> way you want it.
>
> (<span class="smallcaps">Egor</span> at
> <http://bonusbots.com/support/index.php/topic,7934.msg79372.html#msg79372>)

However we don’t like undefined behaviour and we don’t want to keep
multiple versions of our bots for different casinos either. Therefore we
introduced 2 new commands: RaiseTo and RaiseBy. This way you can clearly
specify what behaviour you want. You only have to specify the correct
betsizeinterpretationmethod in your tablemap to tell OpenHoldem how your
casino behaves and OpenHoldem will care about all the
rest.automatically.

*That’s how it should be.*
