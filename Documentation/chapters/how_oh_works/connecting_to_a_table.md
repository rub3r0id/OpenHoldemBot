# Connecting to a table

As soon as you start OpenHoldem it will read all tablemaps in your
scraper-folder and parse them for the information that is necessary to
connect to a table. The auto-connector will then have a look for new
tables that are not yet served by other instances once per heartbeat and
connect if it finds a new one. This all happens automagically, however
an explanation of what happens behind the scenes is useful if you have
problems connecting to your target poker window. The following steps are
taken to identify which windows on your screen are valid poker tables.

<figure>
<img src="images/connecting_to_a_table.jpg" />
</figure>

1.  A list of all visible top level windows that have a non-blank
    caption is collected

2.  Each window in this list is compared against each tablemap that you
    have placed in your *scraper* directory. For each step that follows,
    if a non-match is detected, OpenHoldem will then immediately move on
    to the next window / tablemap.

3.  The size of the client portion of the window is compared to the
    *clientsize* records in the tablemap. The window is considered a
    match if the tablemap indicates the correct size as given by the
    record clientsize, or if the size is within the size limits given by
    *clientsizemin* and *clientsizemax*. Example from a
    real-world-tablemap:

        // 
        // sizes 
        //

        z$clientsizemin    400  300 
        z$clientsizemax   1600 1200 
        z$targetsize       800  600

4.  The window’s title text is compared to the keyword text filters
    provided by *titletext* records in the tablemap. The window is
    considered a match if the free-form text in any of the titletext
    records is found in the window’s title. Additionally, if any
    negative *!titletext* records are present in the Table Map, then a
    window is considered a non-match if the free-form text in any of the
    negative !titletext records is found in the window’s title. Example:

        s$titletext                 PartyPoker

5.  Optionally OpenHoldem will also compare tablepoints. These
    tablepoints are useful to distinguish very similar tables that
    require different tablemaps, for example 10-chair and
    6-chair-tables. They can be distinguished by placing a tablepoint at
    one of the chairs that does not exist for the other kind of table.

6.  If OpenHoldem finds a matching pair of tablemap and table it will
    look in the shared memory data-structures if the table gets already
    served by another bot. If this is not the case OpenHoldem will
    connect to that table. The connected table will then be moved to a
    free slot if the table-positioner is enabled, resized if a
    targetsize is specified and the autoplayer will start playing.
