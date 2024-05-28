# Scraping “10” as Ten

When it comes to text-scraping cards most things work intuitively the
natural way:

- we select a region that shows the rank of the card

- we select a transformation (here text3, but it might also be a hash or
  an image if there is no fuzzyness)

- we select a foreground-colour with the colour-picker and define a
  reasonable colour-tolerance.Sometimes we take the background-colour
  and a negative radius if we want to accept everything except the
  background. This is especially useful for blinking fonts on a
  non-blinking background. The colour-tolerance, called “radius”, has to
  be in the range \[0..255=0xff\], where 0 requires exact identity and
  255 accepts everything. (You might notice the radius of 225 below,
  which is near the upper end of the range. This is because the probably
  inexperienced creator of this tablemap chose a bad foreground-colour
  (the dirty red (d2, 2a, 03) at the bottom left of “1”) but he wanted
  to accept black (0, 0, 0) which differs significantly. This only works
  because the small blue component (02) of his chosen foreground-colour
  differs from the white background colour (ff, ff, ff) by more than 225
  (0xff = 255)). Usually a radius of 10 or 20 is perfect to accept a
  slightly fuzzy fore-ground-colour perfectly.

- if the rank of the card does not get recognized we create a new font.

And that’s it!

<figure>
<img src="images/scraping_10_as_ten_rank_only.jpg" />
</figure>

But what about the topic of this chapter? What is so special about
scraping the ten?

Well – nothing – except that some people try to create fonts for both
“1” and “0”, but the scraper expects a single character for a card rank:
“2”...”9” for the cards of lower value, “J”, “Q”, “K” and “A” for the
face-cards and “T” for “ten”. That’s the whole “difficulty” here. As you
can see in the picture above we did it right, scraping the rank of ten
as “T”. In the picture below we do the same work, but there we scrape
rank and suit together as “p4cardface0” and the result is “Th”.

<figure>
<img src="images/scraping_10_as_ten.jpg" />
</figure>
