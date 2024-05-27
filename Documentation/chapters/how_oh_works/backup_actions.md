# Backup Actions

In some situations it might be not possible to execute the users
preferred action. For example he chose bet 3/4 pot, but the casino does
not provide a button for 3/4 pot. Then he usually wants to execute a
similar action, in this case betpot ot bet 2/3 pot. We call this a
*backup-action*.

## OH-Script and Backup-Actions

Long story short: OH-script does not provide any *built-in*
backup-actions. The OH-script-philosophy is: full control to the user.
Therefore the end-user has to care about backup-actions on his own and
add e.g. a rule that makes f\$betpot_2_3 true if f\$betpot_3_4 was true
but could not get executed.

    ##f$betpot_2_3##
    // backup for betpot_3_4
    f$petpot_3_4
    OR ... // rest of logic for 2/3 betpot

## OpenPPL and Backup-Actions

<figure>
<img src="images/OpenPPL_backup_actions.JPG" />
</figure>

OpenPPL is different: there is no way to control each possible action
separately when you specify what to do on preflop, flop, turn or river.
Only one action can be chosen and simplicity was an important
design-goal for OpenPPL. Therefore backup-actions are built-in and work
automatically. Most of them work the conservative way: if one action
fails OpenHoldem will choose the next, slightly less aggressive action:
so if betpot fails OpenHoldem will try to bet 3/4 pot, but not twice the
pot or even allin.

## Aggressive Backup-Actions

Most backup-actions are conservative, but there are two aggressive
exceptions:

- *f\$allin_on_betsize_balance_ratio*: playing poker it happens
  regularly that a preferred betsize is nearly allin. Then it usually
  does not make sense to bet that amount and keep only very few chips
  left. We would be committed anyway the next time we act, and with a
  larger bet we generate a little bit more fold-equity. The function
  *f\$allin_on_betsize_balance_ratio* controls how large a bet has to be
  in comparison to the stack to turn the betsize into an allin-action.
  If the value is 0.50 (meaning 50%) any bet that is larger than 50
  percent of our stack will cause an allin. This backup-action can be
  used in OH-script too, because it can be completely controlled by the
  user.

- *calling allin*: in some cases it might be that an opponent puts us
  allin and only calling and folding are possible. But our hero looked
  at his fine set of aces and decided to “bet 2/3 pot for value”.
  OpenHoldem ended up folding. What did happen? Well, some casinos don’t
  display a call button in this case, but only allin and fold. The
  conservative sequence of backup-actions therefore will finally (and
  successfully) try to fold. To make all the careless newbies happy we
  therefore created an aggressive backup-action that turns a call (or
  any raise) into an allin-action if only the two buttons fold and allin
  are visible.

## Attention! Danger!

Automatic backup-actions are convenient. But the last example also
illustrates some danger. Let’s assume that hero does not have a set of
aces, but a busted hand. He reasons that the board does not hit villains
range either, therefore he goes for a poor bluff and decides for
2/3 betpot. Unfortunately villain already raised allin and hero can only
fold or call. Instead of a 2/3 potsized raise he will call allin – with
air.

Truly: this is dangerous, but we can’t make both users happy at the same
time, so we took care about the most common use-case: newbies who hold
some value and really want to put money into the pot, but don’t consider
if villain is already allin and don’t consider the options they really
have. Please always remember: *There is no backup for your own thoughts
and for your carefulness.*
