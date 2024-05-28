# Setting The Game-Type

If you create a tablemap it is pretty important to tell OpenHoldem which
game-type you are playing. If you play fixed limit the mimimum bet will
double up at the turn. So if you play a \$1/2-game the blinds will be
\$0.50 and \$1. The small bet, as it is called, will be \$1. That means
your mimimum bet and all raises have to be at least 1 dollar. But the
pot will grow, and betting \$1 into a large pot doesn’t make much sense.
So at the turn the betsizes double up and the now so-called big-bet
would be \$2 in our example. This results in a \$0.50/\$1/\$2
betting-structure, contrary to the now famous no-limit with a
\$0.50/\$1/\$1-structure, where you can choose your betsize as you like
and the minimum bet at later streets would be the same as preflop and at
the flop.

Why this elementary introduction? Because some players nowadays don’t
even know about the old days where fixed-limit was the only game of
choice in the internet. But does that matter and how does it affect
players who want to play only no-limit?

Well, per default OpenHoldem will assume a no-limit-game nowadays and
usually you can get the game-type from the title-sting ("^L" in
"ttlimits"). But sometimes there might be no title (or no reliable
title) and you might need to define another gametype as the default one.
As mostly there is an alternative way: this information can be scraped,
just like anything else that matters.

Using OpenScrape:

1.  Create the region "c0limits0".

2.  Optimally you want to choose a region at the table that displays
    "No-Limit", but if that is not present you might choose any
    fake-region that doesn’t change, like "Options". Create letters that
    return NL for whatever is shown in the region. Use a font that
    doesn’t get used for anything else to avoid conflicts (I used
    text1). I created a small region over the options field and instead
    of teaching OH the letter ’O’ and ’p’, I told it it stands for ’N’
    and ’L’ because I want a no limit map.

3.  Under symbols create "c0limits0". The symbol "s\$c0limits" simply
    tells OpenHoldem how to interpret the value of the region
    "r\$c0limits" and works exactly the same way like "ttlimits" works
    for the title-string. Here we set s\$c0limits to "^L" which is the
    gametype, as advertised in the section about symbol-records..

4.  Live happily ever after.

![image](images_setting_gametype/force_nl.jpg)
![image](images_setting_gametype/force_nl2.jpg)
