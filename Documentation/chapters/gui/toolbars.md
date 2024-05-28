# Toolbars

## OpenHoldem Main Toolbar

<figure>
<img src="images/toolbar.jpg" />
</figure>

From left to right, the buttons on the Main toolbar are:

- New formula file

- Open formula file

- Save formula file

- Engage (or stop) the Autoplayer (nested diamonds)

- Edit current formula

- Enable validator. The validator is a tool that analyzes built-in
  symbols to detect inconsistent game-states that are mostly caused by
  bad tablemaps or bad settings. It helps you to test your tablemap
  before you take it to the real-money tables.  

  <figure>
  <img src="images/validator.jpg" />
  </figure>

- Tag log-file. This will create an entry in the log that makes it easy
  to find and review critical situations.

      [*** ATTENTION ***] User tagged this situation for review

  If the autoplayer already acted this log-message will appear slightly
  after the interesting decision.

- Show scraper output

- Shoot a replay-frame

- Start ManualMode for offline simulations and testing

- Show the help-file (this file!)

## OpenHoldem Flags Toolbar

<figure>
<img src="images/flags_toolbar.jpg" />
</figure>

The Flags toolbar is used to set internal OpenHoldem flag symbols
f0..f19 to on or off. These flags can be used in your formula set to
quickly enanble or disable certain functionality. E.g. you could use
flag 0 to to tell your bot to use a different starting-hands-chart or to
do more conti-betting.

    ##f$preflop##
    WHEN f0 RETURN f$PokerTragedySHCAction FORCE
    WHEN Others RETURN f$SklanskySHCAction FORCE
