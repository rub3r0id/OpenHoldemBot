# Debugging Your Code

Why debugging? If you code your bot or if you watch it play you will for
sure find situations where the play doesn’t match your expectations.
Sometimes you know immediatelly what you did wrong or at what place of
the code you have to look for your error. But sometimes you don’t know
or it might even seem, that everything looks ok on your side. So you
might want to look a little bit deeper - at your code and maybe even at
the symbol library. Here in this chapter we will show you some
techniques to locate the problem:

## Working with the debug-tab

OpenHoldem provides a cool feature called the debug-tab. Just open the
formula-editor (for OH-script), switch to the f\$debug-section and then
you can enter your expressions. For example:

    = userchair
    = HaveTopPair

Here userchair is a native OpenHoldem symbol and HaveTopPair is an
OpenPPL-symbol. So once you have entered the symbols in question click
“Apply” to confirm your input and “Auto” to turn the evaluator on.
OpenHoldem will evaluate your expressions and show you their values.
Anything wrong with them?

<img src="images/debug_tab_pokerstars.jpg"
style="width:7.27778in;height:5.08333in" alt="image" />

<img src="images/pokerstars_nl_25.jpg"
style="width:7.31944in;height:5.27778in" alt="image" />

Everything is correct with this screenshot. But if something is wrong,
there might be several reasons:

- *incorrect input.* Have a look at OpenHoldem’s table display:
  everything ok?

- *a problem with your code (or with the symbol library):* a symbol like
  for example StillToAct depends on other symbols like dealposition and
  nchairsdealtleft. So if StillToAct was wrong you might put these
  symbols into the debug-tab to evaluate further until you find the
  problem.

## Simulating positions

The debug-tab is a wonderful tool — but: the problem happened at a
live-table — what can you do? There are two things you could try:
Openholdem provides a tool called ManualMode. Here you can set up some
situations to simulate your bot-logic. The other possibility: you could
shoot so-called replay-frames, i.e. screenshots of the casino-table that
get saved to the replay-directory in your bot-folder. Once the session
is over you can load these frames with OHReplay.exe and connect
OpenHoldem to OHReplay like a normal casino-table. And then you can work
with the debug-tab as described above. Please refer to OpenHoldem’s
manual for a more detailed description of these tools.

## Investigating log-files

Not satisfied with the play? You might also look at the autoplayer-log.
It is stored in your bot-folder and named e.g. oh_0.log. OpenHoldem uses
this file to not only store the action it took, but also the complete
evaluation process. First locate your hand (you can identify it e.g. by
the time, your cards, the hand-number, etc.). At first the log might
look like a complete mess, but actually it is well structured: function
names on the very left are higher-level functions; symbols that are more
indented got called by these higher-level functions. So what you see
below is actually an evaluation-tree:

    f$flop = -1000001.000 [Line 3/3]   
       HaveStraightDraw = 0.000 [Line 2/2740]     
          HaveOpenEndedStraightDraw = 0.000 [Line 10/2685]       
             HaveStraight = 0.000 [Line 1/2735]         
                nstraightfill = 3.000       
             rankbits = 24770.000     
          HaveDoubleGutshotDraw = 0.000 [Line 15/2286]   
       HaveQuads = 0.000 [Line 1/2679]   
          isfourofakind = 0.000   
       BotsLastAction = -1000008.000 [Line 20/549]   
          betround = 2.000     
          ConstBetRoundPreflop = 1.000 [Line 1/194] 
          me_re_MemBotsLastAction = 0.000   
          Fold = -1000001.000 [Line 1/77] 
          PrevActionWasAllin = 0.000 [Line 2/492] 
             prevaction = 3.000 
        PrevActionWasAllin = 0.000 [cached] 
       Raise = -1000008.000 [Line 1/134]  
       Raise = -1000008.000 [cached]  
       Fold = -1000001.000 [cached]

Long story short:

- At the very top you see an OpenPPL main-function, here f\$flop

- Below you see functions that get called by f\$flop either directly or
  indirectly

- Functions that are indented once are directly called by f\$flop. E.g
  HaveStraightDraw, HaveQuads, BotsLastAction

- Functions that are indented one level deeper are called by the
  function above them that was indented one level less, E.g.
  HaveStraightDraw calls HaveOpenEndedStraightDraw and
  HaveDoubleGutshotDraw.

- After the = you see the result of the function evaluation

- \[Line 10/2685\] means: the function returned the result at its tenth
  line, which is line 2685 in the file.

- \[cached\] means that the result already got calculated and the cached
  value gets reused.

- symbols without line information are built-in OpenHoldem symbols.

That’s it, basically. We were a bit in a hurry when we wrote this
paragraph. Any better explanation is very welcome.

## Things To Watch Out For

- *Incorrect hand-reset:* Most symbols depend only on the state of the
  table (cards, players, etc.) and are quite reliable. However there are
  some symbols, that depend on previous game-states, like
  BettingAction-symbols; these symbols reset whenever a new hand starts.
  Also user-defined variables will lose their value if a hand-reset
  occurs. These hand-resets can be triggered by certain events, like a
  changing dealer-chair or disappearing community cards, depending on
  your hand-reset-method defined in the tablemap. Depending on your
  settings it might be that an occlusion of the table will cause a
  hand-reset for OpenHoldem. So watch out for messages like below in
  your log-file.

      2012-01-21 19:50:17 -
      ************************************************************* 
      HAND RESET (num:  dealer: 0 cards: KhKd): PartyPoker Table ###### - NL Hold'em $1/$2 
      *************************************************************
      2012-01-21 19:50:17 - ROUND 1

  If they appear in the middle of a hand, then you should revisit your
  hand-reset-method.

- *Misread information:* Most problems (and most reported “bugs”) are of
  the from “garbage in - garbage out”. If OpenHoldem gets incorrect data
  from the scraper-engine (e.g. no seated players) then all further
  calculations by the symbol-engine and the evaluator will return bogus
  values. The reason is usually simple: a beginner with incorrect system
  settings or incorrect casino settings. Let us emphasize: Win2000
  classic theme and all animations turned off are recommended, but not
  necessary. In pronciple you can scrape whatever configuration you
  like. However: if you use somebody else’s tablemap, then you *have to*
  use exactly the same settings as the profile creator. So before you go
  crazy investigating log-files: have a look at basic OpenHoldem
  symbols: are they reasonable or plain wrong? And before you sit at a
  real-money-table observe your bot and OpenHoldem’s table-display for
  some time: does OpenHoldem recognize every game-state correctly? Don’t
  get frightened: *screenscraping is an easy and very flexible approach,
  that works great. But it requires some care from your side!*

## Using Flags

OpenHoldem provides a useful set of buttons with a number on it, from 0
to 19 called flags. When an OH flag button is pressed then corresponding
symbol (f0..f19) will be true. For example our code could look like the
following:

    WHEN betround=2 AND (BotRaisedBeforeFlop OR f0) Raise 50% FORCE 

The above line is true if the bot raised before the Flop or the flag 0
button has been pressed. This way you could simulate costom conditions
in Manual Mode.
