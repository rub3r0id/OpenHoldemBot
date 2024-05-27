# The Bot Logic (OpenPPL)

Since version 7.0 OpenHoldem provides an alternative way to program the
bot-logic: OpenPPL. PPL means: Poker Programming Language, an
english-like programming languge once designed by Shanky BonusBots.
OpenPPL is completely integrated and can be mixed with OH-script if
desired. Once a non-empty f\$preflop function is present OpenHoldem will
switch to OpenPPL-mode and evaluate f\$preflop, f\$flop, f\$turn and
f\$river instead of the OH-script autoplayer-functions.

    ##f$preflop##
    WHEN hand$AA RaiseMax FORCE
    WHEN hand$KK AND Raises = 0 AND Calls = 0 RaiseTo 3 FORCE

To support an easy start we wrote a separate OpenPPL-manual that is
included in every download of OpenHoldem.

## Default Bot

An OpenPPL-bot might be “incomplete”. The end of a code-section might be
reached without a matching action being found, then the default.bot will
take over. We will talk about this default-bot in one of the next
chapters briefly; all the details are in an extra handbook, the
OpenPPL-manual.
