# Scraping non-standard Titles

Usually poker-tables are standard-windows. They have a title that can be
accessed by OpenHoldem with the Windows API. These titles contain useful
information like the blind-levels and we only have to tell OpenHoldem
how to interpret these titles as explained in the chapter “Interpreting
Titletext”.

<figure>
<img src="images/title_scraping_old_888_standard.JPG" />
</figure>

However there are a some (very few) casinos that don’t provide such a
title:

- some casinos are browser-based and don’t change the brwoser-title

- some poker-tables are technically based on dialog-boxes that don’t
  posses a title.

- some casinos use standard windows with titles, but don’t use them
  properly.

An example of the latter case are some IPoker-skins like William-Hill.
They use standard windows with titles that work fine for cash-games.
However when it comes to tournaments they don’t update this title
properly. Instead the casino-software over-paints the real title with
some nice graphics that looks like a title, and the “real” title is
frozen at the first blind-level.

<figure>
<img src="images/title_scraping_william_hill.JPG" />
</figure>

Luckily there is a solution: if OpenHoldem can’t interpret the title
(ttlimits) it will try to scrape the blinds and all other info from the
table. To do so we need:

- dummy ttlimits that discards everything

      s$ttlimits    ^- tourney

- a region r\$c0limits that defines where to look for the painted info

      r$c0limits    375   7 474  16 ffffffff    0 T3

  As you can see this region is near the top of the table (y-coordinates
  7..16), horizontally near the middle (375..474) of a window with size
  800x600. We use a T3-text-transform and the fore-ground-colous is
  white 0xFFFFFFFF with a radius of 0 (exact match).

- now we need to scrape the text properly (see the chapter about
  “Collecting Fonts)” and we have the same info that we would get at
  other casinos automatically without any effort.

- finally we have to tell OpenHoldem how to interpret this text and
  create a symbol s\$c0limits that works exactly the same way like
  ttlimits.

That’s all to make it work.

<figure>
<img src="images/c0limits.JPG" />
</figure>

Finally in some very rare cases it could be that that positions and the
texts for the blind-levels change, especially if you want to create a
map that supports multiple game-types like in the image above. That’s no
problem at all, you can introduce some more regions
r\$c0limits0..r\$c0limit9 and corresponding symbols s\$c0limitsX to
scrape the info from the table. And if the data is spread all over the
table you can scrape each snippet of information individually with
c0sblind, c0bblind, c0bbet, c0ante and some more.
