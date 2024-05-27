# Interpreting Titletext

Most casinos show very valuable info in the titlebar, for example

    Tournament 12345678 Table 5 - No Limit Hold'em - Blinds $600/$1200 Ante $75

Valuable informations in the example above (PokerStars) are:

- the game-type: tournament (and no-limit)

- the size of the blinds: \$600 / \$1200

- the ante: \$75

Besides of valuable info the titlestring comes with some technical
benefits:

- it is usually very reliable

- it can be accessed easily with the Windows API (GetWindowText) and
  does not require any scraping.

Therefore OpenHoldem provides a way to interpret the titletext:

<figure>
<img src="images_interpreting_title_text/title_text.JPG" />
</figure>

In the example above

- “^\*” followed by the constant string “- “ recognized and discards
  everything until it finds “- “ in the titlestring. This means the
  title-parser will skip “OpenHoldem Poker - ” because this data does
  not provide any useful info for us.

- Again there follows a dummy that needs to be skipped. “^\* - blinds ”
  will ignore everything until it finds “ - blinds ”.

- Now comes the first interesting piece of data. “^s” expects a
  numerical value, here “5” that will be interpreted as the size of the
  small blind.

- “/” is a constant string that will be ignored. In our exaple it
  separates small-blind from big blind.

- Finally “^b” works similar like “^s”: it expects a numerical value too
  and interprets it as the size of the big-blind.
