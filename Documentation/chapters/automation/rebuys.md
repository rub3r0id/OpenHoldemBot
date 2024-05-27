# Rebuys

OpenHoldem is able to control external rebuy-scripts with the bot, as
this provides several advantages compared to hoppers:

- easy synchronisation with other bots due to built-in mutex-handling
  (avoiding mouse- and keyboard-conflicts).

- perfect timing, e.g. only when it is not your turn or between two
  hands.

- no need for the hopper to take care about your balance and simplified
  hopper-architecture in general.

## The rebuy-script

The process to rebuy is still very specific for each casino (similar to
TableMaps and lobby-handling), so there is no way to provide a built-in
method that works for every casino. This casino-specific part of the job
has to be done by an external rebuy-script, provided by the user. But
this rebuy-script will usually become quite simple: some mouse-clicks
and maybe keyboard-input are usually everything that needs to be done.
For an example and possible starting-point see “RebuyDemo” in the
source-tree at GoogleCode..

## Sanity-checks

Many things can go wrong, when you try to rebuy, be it incorrect timing
or a rebuy to the wrong value. To avoid such cases OpenHoldem does
provide some security measures:

- always acquire the autoplayer-mutex before executing the rebuy-script

- optionally (as specified in the preferences) require a change in
  hand-number between two rebuys

- optionally rebuy only, when the user doesn’t hold cards

- optionally test heuristically for occlusion and sane balances

- optionally wait for a user-defined time between two attempts to rebuy

## Calling the rebuy-script

Once all necessary conditions are met, OpenHoldem will execute the
rebuy-script, that got specified in the preferences, and pass the
necessary information as command-line-parameters:

| Commandline-parameters                     |
|:-------------------------------------------|
| Casino (name as specified in the TableMap) |
| Windowhandle of the pokertable (HWND)      |
| UserChair (0-9)                            |
| Balance (in dollars)                       |
| SmallBlind (in dollars)                    |
| BigBlind (in dollars)                      |
| BigBet (in dollars)                        |
| Target-amount (in dollars)                 |

<figure>
<img src="Images/pokerstars_poker_table.jpg" />
<figcaption>Rebuy</figcaption>
</figure>
