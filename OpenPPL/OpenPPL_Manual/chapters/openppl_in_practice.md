# OpenPPL In Practice

If you have read this manual up to this point you have some basic
understanding of OpenPPL: syntactical rules, symbols, etc. But the main
thing — turning your poker-knowledge into bot-logic — may look like a
different kind of beast, if you have no programming experience at all.
So let us take some small examples and see how OpenPPL is used in
practice.

## Folding Trash

```c
    ##list_of_biggest_trash##
        // Trashy hands. 
        // Never to be played, except we are in the blinds
        K8s K7s K6s K5s K4s K3s K2s Q7s...
        K8o ... 32o

    ##f$preflop##
        // Make life easy and get rid of the greatest trash
        WHEN NOT In BigBlind AND list_of_biggest_trash Fold FORCE
```

## Open-Raising On The Button

    WHEN StillToAct = 2 AND Calls = 0 AND Raises = 0
        WHEN hand$AA OR Hand$KK OR ... RaiseTo 3 FORCE

## Threebetting A Steal-Raiser

```c
    // LastRaiserPosition <= 3 means: CO, BU or SB
    WHEN Calls = 0 AND Raises = 1 AND LastRaiserPosition <= 3
        WHEN AmountToCall <= 3 AND list... RaiseTo 9 FORCE
```

## Contibetting

    ##f$flop##
        WHEN Bets = 0 AND BotIsLastRaiser
            WHEN Opponents = 1 AND Random < 80 BetHalfPot FORCE
            WHEN Opponents = 2 AND Position = Last RaiseBy 66% FORCE

## Effective StackSize

```c
    ##f$EffectiveStacksize##
        // First orbit preflop only, as it uses MaxStillToActStackSize
        WHEN StackSize > MaxStillToActStackSize RETURN MaxStillToActStackSize FORCE
        WHEN Others RETURN StackSize FORCE
```

## Push/Folding In A SNG

```c
    // Going into push-fold-mode when stacksizes are small
    // But be careful!
    // We don't want to push loosely if something is wrong with the stacksize,
    // e.g. because the table was occluded, so we check, if it is non-zero.
    WHEN EffectiveStacksize > 0 AND EffectiveStacksize <= 13
        WHEN Calls = 0 AND Raises = 0 AND (Hand$... RaiseMax FORCE
```

## Detecting A Limp-Raise

```c
    // First action preflop
    WHEN BotsActionsOnThisRound = 0 AND Calls >= 1 AND Raises = 0  
        // FirstCallerPosition is limited to first orbit preflop only,
        // so we remember it, making use of advanced memory symbols
        WHEN Others me_st_MemFirstCallerPosition_FirstCallerPosition
        // Then continue with normal bot-logic
        ....

    // After that we can detect a limp-raise like that
    // (assuming, there are no other raisers in the pot)
    WHEN LastRaiserPosition = me_re_MemFirstCallerPosition ...
```

## Counting Outs 

```c
    ##f$MySimpleOutsCounter##
        WHEN (HaveNutFlushDraw AND HaveNutStraightDraw)
            // We already have 9 + 8 - 2 duplicates
            // Plus up to 6 undiscounted outs for Overcards
            // but some may be already counted for the flush
            // (if we want to make it extra good, we should check the colours
            // of our hole cards with OpenHoldems symbols $$ps0 and $$ps1)
            // The others should be discounted a bit
            WHEN (Overcards = 2) RETURN 18 FORCE
            WHEN (Overcards = 1) RETURN 16.5 FORCE
            WHEN (Overcards = 0) RETURN 15 FORCE
        WHEN (HaveNutFlushDraw) // AND NOT HaveNutStraightDraw
            WHEN (HaveInsideStraightDraw AND Overcards = 2)... 
        ...
```

## Calling According To Odds And Outs

```c
    ##f$CardsLeft##
        WHEN betround = 2 RETURN 47 FORCE
        WHEN betround = 3 RETURN 46 FORCE
        // Drawing at other betrounds doesn't make much sense
        WHEN Others RETURN -1 FORCE

    WHEN AmountToCall / (AmountToCall + PotSize) > f$Outs / f$CardsLeft Call FORCE
```

## Playing Fit-Or-Fold Multiway

    ##f$HaveStrongDraw##
        WHEN HaveStraightDraw OR HaveFlushDraw RETURN true FORCE
        WHEN HaveInsideStraightDraw AND Overcards = 2 RETURN true FORCE

    ##f$HaveTopPairOrBetter##
        WHEN HaveTopPair RETURN true FORCE
        WHEN HaveOverPair RETURN true FORCE
        WHEN HaveBestOverpairOrBetter RETURN true FORCE

    ##f$flop##
    WHEN Opponents >= 3 AND NOT (f$HaveTopPairOrBetter OR f$HaveStrongDraw)
        WHEN AmountToCall = 0 Check FORCE

## Closing The Tables

```c
    ##f$leave##
    WHEN issittingout
         AND elapsedauto > 300   // 5 minutes without action
         AND nopponentsseated < 4
      RETURN true FORCE  
```

*Now it’s up to you. Let the fun begin!*
