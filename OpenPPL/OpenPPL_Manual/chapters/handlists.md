# Handlists

OpenHoldem supports preflop handlists to simplify preflop coding.

You can name handlists what you like, but handlist names need to start
with the word “**list**”.

```c
    ##list007##
        // Allin-range against crazy maniacs
        AA KK QQ JJ TT 99       // Pairs
        AKs AQs AJs ATs KQs     // Suited hands
        AKo AQo AJo             // Offsuited hands 

    ##list0fTr4sh1w4ntT0C4ll##
        72o 32o
```

After that you can use your custom handlist symbol like this:

    WHEN (Opponents = 1 AND userManiacFourBetsMe AND list007) RaiseMax FORCE

There is no limit to the number of lists you can define and you can use
any name you want. Indeed it is recommended that you choose verbose
names that speek for themselves.
