# Scraping blinking fonts and name-plates

Sometimes it might be that a name-plate blinks and both the foreground
and the background colour change. Then it is usually not possible to
scrape the data the normal way just with one colour and one radius
(colour tolerance).

<figure>
<img src="images/blinking_01.jpg" />
</figure>

But as usual OpenHoldem provides a solution for blinking fonts: a second
region uXname in addition to pXname to scrape the playername. If one
region fails to return good data OpenHoldem will use the other one and
vice versa. In practice it looks like that: the normal name-plate (here
for player 6) gets recognized perfectly by p6name.

<figure>
<img src="images/blinking_p6_working_02.jpg" />
</figure>

But when the name is highlighted with inverted colours the region p6name
fails to recognize the name. Please notice the inverted pixel separation
(that might produce even complete nonsense if the colours were
different) and the missing result.

<figure>
<img src="images/blinking_p6_not_working_03.jpg" />
</figure>

But then u6name works

<figure>
<img src="images/blinking_u6_working_04.jpg" />
</figure>

And together both regions will always produce a good result.
