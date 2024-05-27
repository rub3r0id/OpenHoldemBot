# Starting a new map

Let’s assume you start a new map completely from scratch. If you want to
ease your job and get meaningful intermediate results we recommend to do
your map in the following order.

- z\$clientsizemin/max and z\$targetsize first. They are absolutely
  necessary for connection.

- s\$titletext next. Juts like clientsize it is necessary for
  connection, because it might be that other applications or other
  casino tables have the same window size. Choose something unique like
  “No Limit Hold’em - Logged in as”. Once you have defined these two
  items and put this map into your scraper folder OpenHoldem will be
  able to connect to the table even if it does not yet scrape anything.
  but the autoplayer button should become active – and you will get lots
  of warnings at load-time because of an incomplete map.

- s\$nchairs next. OpenHoldem needs to know how many chairs are
  supported by the tablemap. OpenScrapes region-cloner needs this info
  too if it clones the regions of player 0 to all other players.

- r\$pXseated for all chairs 0..n-1 or at least for chair 0 if you make
  use of the region-cloner thereafter. This is usually an easy hash
  returning true/false like the following three items.

- r\$pXactive to determine if a player is sitting in.

- r\$p0cardback, r\$pXcardface0nocard and r\$pXcardface1nocard. It is
  usually easy to do these hashes and you can now recognize all cards
  except your own hole-cards.

- r\$pXdealer to know who is the dealer.

- r\$c0cardfaceXnocard and r\$c0cardfaceX. The community cards

- r\$pXcardface0 and r\$pXcardface1. The player cards.

- r\$pXbet and pXbalance. This usually requires text-scraping and
  sometimes chip-scraping and is probably the most time-consuming part
  of the job.

- r\$iXbutton, r\$iXlabel and r\$iXstate. The basic action buttons

- r\$i3edit, s\$betsizeconfirmationmethod, s\$betsizedeletionmethod,
  s\$betsizeselectionmethod and s\$betsizeinterpretationmethod if you
  want to create a no-limit or pot-limit-map.

That’s it. Now you are ready to start playing.
