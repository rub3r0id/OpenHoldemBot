# Handling Popup Windows

If you play at online-casinos for real money a couple of annoying things
will happen now and then. Spam-messages will popup announcing
tournaments, confirmation-popups will ask if you really want to leave or
request other input. Third-party-software like anti-viruses might
unexpectedly start running and open windows that overlap your tables

Of course you could create several external scripts, a complete hopper
or even a multi-site hopper-framework to handle everything, you also
could turn your anti-virus off like recommended in other forums (we
don’t recommend to do so). Thank god OpenHoldem already contains some
tools that handle many hopper-tasks automatically or make it easy to
deal with them with small effort, including the annoying popup windows.

## Messages that are painted on the table

Some casinos paint messages, mainly tournament-announcements, to the
table. These messages are from a technical point of view no separate
windows and therefore can’t be handled by traditional popup-blockers.
OpenHoldem tablemaps however support some anti-spam-buttons, that get
clicked as soon as they get identified. These so-called i86X-buttons
(i860..i869) require a clickable region and a button-state, but contrary
to autoplayer-buttons no button-label, because the sole meaning of this
buttons is “click it away”.

<figure>
<img src="Images/painted_popup_titan.bmp" />
</figure>

## The popup-blocker

Regular popups can be handled easily by OpenHoldems built-in
popup-blocker. It will kill or minimize any visible window that is
neither a connected poker-table nor an OpenHoldem window.

<figure>
<img src="Images/popup_blocker_options.png" />
</figure>

## Keeping popups open

Sometimes you might want a popup to stay alive, e.g because you have to
enter some data, like the amount of dollars you want to take to the
table. In this case you can create a very minimalistic tablemap:

    .osdb2
    // OpenScrape 11.1.0
    // 2017-01-28 18:47:19 
    // 32 bits per pixel
    // 
    // sizes 
    //
    z$clientsizemax    373  176 
    z$clientsizemin    373  176 
    z$targetsize       373  176
    // 
    // strings 
    //
    s$ispopup                   1 
    s$titletext                 Buyin 

- just clientsizemin/max and targetsize plus a titletext as usual for
  connection

- a symbol “ispopup” that disables the tablemap-completeness-checker and
  table-positioning. The popup will then stay at its ciurrent location
  and you can easily handle it, for example with a little script.

The same method is required to keep the lobby open if you use the
built-in popup-blocker. In this case you should create a tablemap-symbol

    s$islobby                   1

Poker-lobbies receive special treatment. The table-positioner moves them
to top-left of the screen (0, 0), where absolute screen-coordinates
equal relative window-coordinates. This makes hoppers more robust in
case a poker-table pops up and takes away the window-focus.

## Klicking buttons

In some cases handling the popup might require very little work like
clicking a confirmation-button. In this case the minimalistic
popup-tablemap can be extended by an i86x-region.like the spam-handling
example above. As soon as the button-state becomes true OpenHoldem will
click the corresponding region.

    r$i860button         272 144 347 159        0    0 N 
    r$i860state          300 150 300 150   f0f0f0    0 C

<figure>
<img src="Images/popup_WPT_poker.png" />
</figure>
