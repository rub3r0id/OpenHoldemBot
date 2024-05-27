# How the Interface-Buttons work

The holdem scraper has the concept of interface regions, that can be
clicked by the autoplayer to interact with the casino. Such an interface
region consists of three components:

![image](images_interface_buttons/iX_action_buttons.JPG)

| iXbutton | Location of the button, where X is the buttons number (0..9) and the location is a rectangle, specified by the coordinates of the top-left and bottom-right corner. |
|:---|:---|
| iXstate | Visibility of the button. If the button is visible it can be clicked by the autoplayer. If not then the action will be skipped or a backup-action will be chosen. |
| iXlabel | Type of the button, e.g.fold / call / rais |

In the tablemap file it looks like that:

    r$i0button           491 320 502 331   000000    0 N 
    r$i0state            491 331 491 331   ffffff    0 C 
    r$i0label            493 322 499 330   ffffff    0 H0 

The purpose of the button region is simply to tell the autoplayer where
it needs to click the mouse. You can set the transform to none, as only
the position of the clickable region is of interest for the autoplayer.
In the example above the position for button 0 is ((491, 320), (502,
331)).

The purpose of the state region is to determine whether or not the
button is visible or not. It’s generally a small color region which has
to return true when the button is visible. But you can use hash as well.
If you use hash, a true value will be identified as follows (so rename
your images accordingly):

- on

- yes

- checked

- true

- lit

OpenHoldem will search for any of these substrings, so “checked7” would
work too, but any other string will be seen as false. Finally each
interface should also have a label region or regions that will further
define the purpose of the button. So the engine recognizes the following
key words within labels:

- fold

- check

- call

- bet

- raise

- betsize (and “swag” for backward compatibility)

- allin (or all-in)

- prefold

- autopost (or auto-post / autoblind / auto-blind / postblind /
  post-blind)

- sitin (or sit-in )

- sitout (or sit-out )

- leave (or exit)

...and various forms of nearly fitting scrapes (e.g. “aut0post”, “a111n”
and other kind of leetspeak-lookalike). Any iXlabel region that produces
one of these keywords will be seen by the engine as clickable for that
specific action. Also all the strings starting with these keywords will
work: examples: callllll, check01, Raiseto:\$10 etc.

# Sitin/Sitout particular behaviour 

![image](images_interface_buttons/sitout_fulltilt.JPG)

Traditionally since the early days of FullTilt some special
interface-buttons are check-boxes: sitin / sitout / prefold / autopost
blinds. These buttons work slightly differently than the normal action
buttons. Here a button-state of “yes” or “true” means the button is
checked, whereas “no” or “false” means it is unchecked and can be
clicked. This is a Winholdem legacy, and derives from the first sites
supported, which used check-boxes as most sites still do today.
Therefore the bevaiour is inversted (compared to normal action-buttons)
and these buttons will be seen as clickable if their state is “off”.

# The spam buttons 

![image](images_interface_buttons/i86_spam_button.JPG)

OpenHoldem provides some special buttons for spam handling i86 and if
you need more i860...i869.. For spam we intend all the popups that can
occlude your table. Some sites advertise tournaments about to start,
other ask for confirmation when you leave the table, etc. OH can manage
these popups and close them as long as they appear inside the poker
table in a consistent position. There’s no label region to scrape here,
as type of the button is “spam” by default; just state and button
matter. The autoplayer will click them automatically as soon as they
become visible.

1.  Shoot a frame of the table with the popup showing, and create
    i86state as a color or hash region which returns true like you would
    for any other button.

2.  Paint a button region where you want OH to click to kill the popup.
    Done.

Notice that this is evaluated every heartbeat, so OH is very fast at
closing these popups. If popups show in inconsistent locations or out of
poker table, you need an external script, or external software like PTFB
to manage them.

# The betsize interface 

![image](images_interface_buttons/i3edit.JPG)

If we play NoLimit or PotLimit games we need a way to enter betsizes.
This is called “betsizing” (formerly “swagging”, WinHoldems abbreviation
for **“s**tated **wag**er”). To make betsizing work you need to
configure several things:

- first you need an input-box, which is *i3edit*, that specifies the
  region where the autoplayer should enter the betsize

- before we can enter the text into i3edit we should delete the old one
  or the default one. To do this properly we have to define how to
  select and how to delete this text.

  - betsize*selectionmethod*, the supported methods for selection are:
    *Click Drag* / *Dbl Click* / *Nothing* / *Sgl Click* / *Triple
    Click*

  - betsize*deletionmethod*, the supported methods for deletion are:
    *Delete* / *Backspace* / *Nothing*

- once the i3edit-field got cleared the autoplayer can enter the new bet
  and confirm it. To confirm the bet two methods are supported
  (betsize*confirmationmethod*):

  - *Enter*

  - *Click Bet*, which clicks the i3-button, which usually is the same
    as “raise”.

This is basically how NL-betsizing works. Every casino is a little bit
different. You have to play around a bit and identify which sequence
works, then you can specify the usual i3edit, i3state, i3button, i3label
and the methods for selection / deletion / confirmation. And that’s it –
nearly.

# Interpreting the betsize

Let’s assume the following situation: you sit in the big blind and had
to pay \$10. Everybody folds to the button who raises to \$30. Now it is
your turn again and you decide to enter “90” into the raise-box. What
does this mean? Well, it depends on the casino.

- at some casinos \$90 will be your final betsize
  (betsizeinterpretationmethod = 3). The entered amount will be
  identical to OpenHoldems f\$betsize function or to the RaiseTo-amount
  of OpenPPL.

- other casinos will add \$90 to the \$10 you already posted, so the
  final betsize will be \$100.(betsizeinterpretationmethod = 2)

- and finally some other casinos will add these \$90 to the \$30 of the
  last raiser, so the final betsize will be \$120
  (betsizeinterpretationmethod = 1, RaiseBy in OpenPPL)

Again you have to play a bit with your casino and have to find out how
it works, so that you can tell the autoplayer how it is expected to
execute your desired action. But that’s it finally – we promise!
