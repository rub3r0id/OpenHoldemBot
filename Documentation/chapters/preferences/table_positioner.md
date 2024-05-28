# OpenHoldem Preferences - Table Positioner

Table Positioner preferences control if and how OpenHoldem arranges
poker-tables at the screen

<figure>
<img src="images/preferences_table_positioner.jpg" />
</figure>

- *Tiled*: this option will align all tables nicely without much
  overlap, so that OpenHoldem can usually see and scrape the tables
  clearly. Some overlap at the borders is possible however, and
  Microsofts TileWindow-function will also resize ann maximized windows.

- *Cascaded*: this option will stack the tables with lots of overlap,
  but usually in a way that a little piece of every table is visible. A
  useful option at the operating-systems that support scraping
  overlapping tables.

- *Never*: this option will disable the table positioner and leave it to
  the casino software or to your hopper to align the tables in a
  reasonable way

- *Always keep position*: this option will check once per heartbeat if
  the table is at its assigned position and move it back if needed.

If table-positzioning is enabled the lobby will get moved to the top
left of the screen (0, 0) where absolute screen coordinates equal
relative window coordinates. This makes your hopper more robust in case
other windows pop up (lost focus). The lobby needs a minimalistic
tablemap, just with clientsize(min/max) for connection, titletext and
s\$islobby.
