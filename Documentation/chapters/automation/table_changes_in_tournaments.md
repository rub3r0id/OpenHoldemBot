# Table Changes in Tournaments

If you play multi-table-tournaments then you will be regularly moved to
new tables when your opponents drop out and the table becomes too
short-handed. From a technical point of view there are six cases how
these table-changes can happen:

- The casino keeps the current window open, keeps the user in his
  current seat, only the opponents change. This case is completely
  non-critical and OpenHoldem will keep on playing.

- The casino keeps the current window open, but moves the user to a
  different seat. This case is not really critical either. As soon as
  OpenHoldem sees cards in a non-showdown-situation it will recognize
  the user-chair and then lock the new value for stability reasons.

- The casino closes the old table and opens a new one. No problem:
  OpenHoldem will disconnect and the auto-connector will connect to the
  new table as if it was a new session. Then OpenHoldem will continue
  playing like before.

- The casino doesn’t close the old table, but opens a new one. No
  problem: the built-in auto-starter (since version 11.1.0) will take
  care that at least one free instance is always running and waiting for
  new tables.

- The casino opens a new table with a different table-theme, e.g. the
  final table at FullTilt Poker. Not much problem either. You probably
  need a second tablemap for the new table-theme. If the table-size and
  the table-title are identical then your tablemap needs some
  tablepoints so that the auto-connector can select the correct map. But
  that’s it.

- The casino keeps the old-table, but changes the table-theme. Don’t
  worry. OpenHoldem will check the tablepoints regularly and if they do
  no longer match for a certain time then OpenHoldem will disconnect
  from the table and connect again, this time with the correct tablemap.
  And then OpenHoldem will continue playing like before.

Long story short: changing table-themes need a little bit support by
your tablemap, but otherwise OpenHoldem handles all table-changes the
automagical way.
