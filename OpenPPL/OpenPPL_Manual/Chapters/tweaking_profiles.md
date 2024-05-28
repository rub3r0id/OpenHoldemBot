# Tweaking existing Profiles

Most people in the OpenHoldem world create their profile(s) completely
from scratch. However the users with Shanky-BonusBots experience know a
different approach: take an existing (demo-) bot and tweak it. Tweaking
OpenPPL-profiles is relative easy, especially if they are written the
simple way, everything in four large functions (f\$preflop, f\$flop,
f\$turn and f\$river). OpenPPL evaluates from top to bottom of a
function. So if you are not happy with the play in a certain situation
the solution is easy: create a rule (exception) and put it on top of
everything so that it overrides the current code. Higher position –
higher priority.

<figure>
<img src="images/tweaking_profiles.JPG" />
</figure>

## Why “WHEN Others”?

Tweaking this way is easy. Now there is just one little technical
pitfall. The profile to be tweaked might contain some
one-line-statements at the top that always got executed. Now if you add
your code on top of that profile the former one-line-statements would be
bound to the last potential open-ended when-condition in your code. They
would now only get executed if that open-ended when-condition was true.
Therefore you have to terminate your last open-ended when-condition and
start a new one that is always true:

    WHEN  Others   // Always true
       // former one-line-statements here

Now the former one-line-statements are guaranteed to get executed always
again, independent of any conditions in your code.

## Combining multiple Profiles

Of course it is possible to combine multiple profiles:

- a complete profile that plays somewhat reasonable on bottom to cover
  all situations.

- a tweaking, incomplete profile on top of it to fix the largest holes.

- finally your own tweaking code on the very top of everything for the
  fine-tuning.

## The final Action

Complete profiles usually end with the code

    WHEN Others
       WHEN Others Fold FORCE

This code first terminates the last open-ended when-condition and then
folds everything. If your favourite demo-bot misses such a statement
this is a clear sign that this profile is incomplete, i.e it is a tweak
for some other profile. In this case it usually needs some code for
completion; however if you are happy with it you can use this profile as
is. Whenever OpenHoldem reaches the end of a function it will evaluate
the end as zero / false / fold and take the action accordingly.

    f$flop = 0.000 [Line 27/73]
       ...
       empty_expression__false__zero__when_others_fold_force = 0.000
