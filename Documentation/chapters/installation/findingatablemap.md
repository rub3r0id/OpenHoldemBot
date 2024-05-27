# Finding a Table Map 

Table maps provide the OpenHoldem game state engine the instructions for
deriving the state of the game from the pixels on the screen. These
files have the “.tm” extension on them and reside in the “scraper”
directory where they get loaded automatically when OpenHoldem starts.
The challenge with table maps is that every casino needs its own map. In
some cases, you might need different maps for different game flavors. NL
vs. FL, SNG vs. Ring, 10-seat vs. Heads-Up, for example.

Maintaining thousands of tablemaps would be a more than full time job,
and thus instead we put the power in your hands; we provide Table Map
creation tools and testing tools to allow you to be self-sufficient. If
you favour a casino is not supported by any other bot or if your casino
changes its display slightly you don’t depend on anybody else.
“OpenScrape” is the tool that helps you to adapt your tablemap or to
create a completely new one if you find a nice new casino or game-type.

## Tablemaps for simulators

Poker simulators are an easy starting point for every newbie and a good
tool for experienced users to develop and test bot-logic offline. As an
additional benefit their interface does not change, so their tablemaps
don’t need any updates OpenHoldem comes with a set of tablemaps for some
offline simulators. . OpenHoldem ManualMode seems to work out of the box
at every system, but some of the others need special settings: e.g.
window size or screen resolution. Please see the
<span class="smallcaps">Readme</span> files for details.

- <span class="smallcaps">DDPoker</span>, which is freeware and can be
  downloaded from <http://www.ddpoker.com/>

- <span class="smallcaps">OpenHoldem ManualMode</span>, which is part of
  the OpenHoldem package

- <span class="smallcaps">PokerAcademy</span>

- <span class="smallcaps">PokerSnowie</span>

- <span class="smallcaps">PokerTH</span>, which is open-source and can
  be downloaded from
  <a href="www.pokerth.net/" class="uri">www.pokerth.net/</a>

## Downloading the “official” tablemaps

Since version 13 OpenHoldem provides a tablemap-distribution-service for
“official” tablemaps. It requires the software: TortoiseSVN that you can
get from <https://tortoisesvn.net/downloads.html>.Once TortoiseSVN is
installed you simply execute the batch-script “Update_tablemaps.bat” and
the latest tablemaps will be downloaded into your scraper-directory.

<figure>
<img src="images/update_tablemap_script.png" />
</figure>

<figure>
<img src="images/official_real_world_casinos.png" />
</figure>

Please don’t get fooled by this screenshot. The initial
tablemap-distribution-service might contain some tablemaps less, but
soon it will provide some dozen tablemaps for nearly all casinos and
game-types. Our generous users make it happen.

## Using the “official” tablemaps

All “official” tablemaps have been tested before release. The following
setup is recommended if you are a beginner:

- any version of Windows should be OK, though the maps have been tested
  with Windows 7

- colour-depth of 24 or 32-bit is mandatory

- any screen-resolution should be OK, though the maps have been tested
  at 1024x768, as this resolution gets supported by nearly all machines.

- turning font-smoothing and clear-type fonts off is recommended. Some
  tablemaps use “fuzzy fonts” and accept some differences, but other
  tablemaps require an exact match.

- window-style (size of window-borders and titlebar) should no longer
  matter nowadays, as OpenHoldem cares only about the client-area of the
  table and good casinos do the same. If in doubt use the old Windows
  2000 classic style.

Furthermore we recommend the following casino settings:

- default table-theme and background-colour, because we want you to
  configure as less as possible

- either default-size or mini-size (the tablemaps are able to resize the
  table, but first they have to connect to it)

- avatars turned off

- animatzions turned off

To ease the setup every real-world tablemap comes with two anonymised
replay-frames (call them “screen-shots”) that illustrate the correct
setup. One replay-frame before connection and resizing, the other one
after connection when it is heros turn postflop and some cards and the
buttons are visible.

## What if my casino is not yet supported?

If the “official” tablemaps do not yet support your favourite casino and
gametype then chances are good that you will find a map in our forum at
<http://www.maxinmontreal.com/>

<figure>
<img src="images/maxinmontreal_tablemap_forums.png" />
</figure>

Our users have posted several hundred tablemaps in the forum. Most
probably your favourite casino and game-type is already covered. We
simply did not yet have the time to test all these maps and make them
“official”. If you find a map that makes you happy you can help us:

- test it

- suggest it

- provide two replay-frames, one before connection and one when it is
  your turn postflop (shoot them with OpenReplayShooter; this tool
  creates HTML-files without any odentifying info, this makes
  anonymisation of the frames less work).

## What if a tablemap does not work?

Don’t worry. Fixing an existing map is often relative easy. It regularly
comes down to adjusting a balance-region by some pixels or selecting a
different colour for a font. These little fixes can be done by every
dedicated newby. The chapter about tablemapping.explains the finer
points in more depth and you will find some help in the tablemap school
too.
