# OpenHoldem Preferences - Popup Blocker

Popup Blocker preferences control if and how OpenHoldem handles any kind
of popups. A popup is any kind of. “unexpected” window, i.e anything
that is not

- the OpenHoldem GUI

- a MessageBox created by OpenHoldem

- a poker-table that fits to a tablemap in the scraper folder

<figure>
<img src="images/preferences_popup_blocker.jpg" />
</figure>

The popup blocker has just three options:

- *Diabled: no popup* will be closed. Choose this option if you want to
  handle popups with your hopper or if you are not afraid of any popups

- *Minimize popups*: any unexpecxted window will be minimized, but noit
  killed, Choose this option if popups are rare and you want to have a
  look at potential popups later.

- *Kill popups*: this will close any unexpected window immediatelly.

The popup-blocker is integrated into the auto-connector-thread, so you
need one unoccupied instance of OpenHoldem that tries to connect to new
windows if possible or to close everything that doesn’t fit to a
tablemap.
