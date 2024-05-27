# ICM - The independent chip model

(This explanation has been provided by an unknown author for the Wiki:
<http://www.maxinmontreal.com/wiki/index.php5?title=ICM)>)

Here follows an overview of basic ICM push fold decisions and how they
work with OpenHoldem.

## Equity

This is obviously very important for botters - and all poker players in
fact - to know about. When applied to a pot, it is how much of the pot
you currently own. Say I’m in a \$30 pot heads-up, and neither player
has looked at their cards. I could say I’m entitled to half the pot. Now
let’s take into account your probability of winning. So say we have AKs
and we’re up against JTo. Our prwin is 0.65, so I should rightly feel
I’m entitled to more than half the pot. We could say we currently own
0.65 of the pot (0.65\*30). This is our current pot equity.

Equity doesn’t only apply to pots, it applies to tournaments (and to
folding). If pot equity is the portion of the pot we currently own, then
tournament equity is the portion of the tournament prize pool we
currently own. So if it’s a tournament of 2 people, with a prize pool of
\$1 and we are equal in chips then I currently own half of the prize
pool or \$0.5. My tournament equity is 0.5. This is what the OH symbol
icm will calculate for you: my tournament equity before any action is
considered (just balances). We thank OH for this, because once you have
more than 2 players and the prize structure is complicated then
calculating the value for icm gets harder.

And we need to know what will happen to our tournament equity when my
balance changes from \$0.5 to something else. If I fold, I can lose my
blind so it will go down (or stay the same if I didn’t put in a blind).
If I go all-in it could double, go down to 0, or increase slightly as I
could win the blinds. And if I call an all-in it could double or go to
zero. Working out what will happen to the balances in such situations -
and the resulting value for my tournament equity - is all handled by OH.
Again, praise be to OH, because it gets complicated to calculate with
more players.

So, using OH we can work out (using the ICM-calculator-symbols):

- icm_fold - my tournament equity (TE) if I fold

- icm_callwin - my TE if I call and win

- icm_calllose - my TE if I call and lose

- icm_alliwin0 - my TE if I go all-in and everyone else folds

- icm_allilose1 - my TE if I go all in and lose (against 1 person)

- icm_alliwin1 - my TE if I go all in and win (against 1 person)

<div class="rem">

* 1*. That’s against 1 person. So like our example of fighting over the
\$1 prize pool. Or it could be when you’re in the BB and calling a SB
push or in the SB and pushing against the BB. I haven’t got to the
multiple people stage yet. More on that later.

</div>

<div class="rem">

* 2*. You need to set the distribution of the prize pool in the OH
Preferences

</div>

## Probability of Winning.

Remember in the first example our equity changed once we looked at our
cards? Well, so too does our TE. This means we need to know our prwin.
The more accurate a value for prwin, the more accurately we can asses
our TE. We *could* just use the standard OH prwin, but that’s not
advised. Better to put your opponent (remember we’re just up against one
person here) on a range of hands and then calculate the prwin. So, how
do we do that? Well, there’s Weighted Prwin, but I haven’t got to grips
with that yet. Instead, I went for \$vs\$prwin . We can get our prwin
via:

    vs$listX$prwin + (0.5 * vs$listX$prtie)

This is our probabilty of winning (and 1/2 our prop of tying) against
listX. LisX# needs to be defined in your .ohf file. For example, say you
have put your opponent on the top 5% of hands. Put this in your .ohf

    ##list105##
    AA KK QQ JJ TT
    AA AKs AQs AJs ATs A9s A8s
    AK AQ

Then our prwin will be

    vs$list105$prwin + (0.5 * vs$list105$prtie)

If you think your opponent is on any two cards then you can just use

    vs$prwin + (0.5 * vs$prtie)

So what I did was define hand lists for the top 5,10,20,30,40,60 percent
of hands. I then looked at my opponent’s chip stack. If he’s got under 5
bb then I reasoned he could be pushing any two cards, 5-10 then pushing
the top 50%, over 20BB then pushing the top 10%. Of course this is guess
work - some stacks might like to push light with 20BB+, some might push
tight. But once you start to look at the figures and change your
settings you’ll see that in most cases it doesn’t make *that* much
difference if they’re top 20 or top 50 - it can still be a clear
push/call whatever.

## Probability of our opponent folding/calling. 

Just like we need to know the probability of us winning when we enter a
pot, we also need to know the chance our opponent will call/fold. For
this, I simplified things and again decided my probabilities according
to my opponent’s chip stack. More than 20BB - 10% call probability,
10-19 - 20%, under 10 - 30%. I hate this oversimplification and can’t
wait to move to something more reliable (like the Poker Tracker Poker
folded blind to steal % maybe).

## Putting it all together

So, we have our TEs, we have our prwin and we have the probability that
our opponent will fold/call. Now what? Well, it’s just like the first
example. The pot size was multiplied by our chances of winning it. Here
we need to multiply each the TE equity in each situation by the chances
of that situation happening. Let’s take the simple example again: 2
opponents fighting over a \$1 pot, winner takes all, no blinds, 50c
stacks.

### Do we call a push?

Let’s say have AKs again and have worked out our prwin to be 0.65. OH
tells us that our icm_callwin is 1.000 and our icm_calllose is 0.000.
Simple: we call and win, we get 1. We call and lose: we have 0.

We can either:

- Scenario (a.i) Call and win. This probability it will happen is 1 (as
  we known we’re going to call it!) and the prob we win in 0.65.
  Multiply this by our icm_callwin. This gives 0.65.

- Scenario (a.ii) Call and lose. The prob it happens is again 1, and the
  prob we lose is (1-0.65). Multiply this by our icm_calllose. This
  gives 0.

So our total equity for scenario (a) is 0.65.

- Scenario (b) Fold. Prob it happens is 1 if we know we’re going to
  fold. Multiply this with our icm_fold. This gives 0.5.

So, as you can see, scenario (a) gives us more equity. We should call!

### Do we push?

Should we push? Same situation as before, but let’s add some 1-2 cent
blinds and a 20% prob we get called. What are our scenarios?

- Scenario (a.i). Push, get called, and lose. == 1 \* (prob of getting
  called) \* (prob of losing) == 1 \* 0.20 \* (1-0.65) = 0.07. We need
  to multiply this by our icm_allilose1, which gives us 0.07\*0 == 0.

- Scenario (a.ii). Push, get called, and win. = 1 \* (prob of getting
  called) \* (prob of winning) == 1 \* 0.20 \* (0.65) = 0.13. We need to
  multiply this by our icm_alliwin1, which gives is 0.13 \* 1.

- Scenario (a.iii). Push, not get called, and win blinds. = 1 \* (prob
  not get called) = 1 \* 0.8 = 0.8. We need to multiply this by our
  icm_alliwin0, which gives us 0.8 \* 0.52 (as we win the extra 2 cents
  from the small blind) = 0.416.

So in total our equity for Scenario a is 0 + 0.13 + 0.416 = 0.546.

- Scenario (b) Fold. Again, our icm_fold which is 0.49 (if we fold, we
  lose our cent).

So, once again the total equity for scenario (a) beats scenario (b). We
should push!

## Multiple-Players

Of course, all these calculations are just heads up. Once we go up
against multiple players we need much more info. If we’re the dealer
pushing into the BB and SB, we need to know the likelihood of *both*
folding, *both* calling and our prwin against both, or winning against
one and not the other and claiming a side-pot. The maths gets a lot more
complicated. At the moment I’m just trying to master heads-up, I’m
afraid.

## Conclusion 

All ICM does is give you a picture of how much your chips are worth in
certain scenarios. The real skill is finding out the probability of
those scenarios happening. For that, we need accurate prwin and accurate
folding probabilities.
