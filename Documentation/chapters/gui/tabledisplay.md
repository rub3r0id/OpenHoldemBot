# Table Display

The OpenHoldem table display is intended to give you a quick visual
reference as to what the screen scraper engine is actually seeing on the
poker table at any given time. In this screen shot, OpenHoldem is
connected to a PokerStars table. But as a beginner you might prefer the
ManualMode application to familiarize youself with OpenHoldem.

<figure>
<img src="images/main_gui.jpg" />
</figure>

The center information box contains various other information, including
the hand number, limit type and limits, ante and current pot value.The
table display will show all scraped chairs, i.e as many as specified by
the nchairs-symbol in your tablemap. Chair 0 will be displayed at
top-right, i.e 1-clock-position. For each chair the following
information will be displayed:

- name

- balance

- bet

- cards or cardbacks

- dealerbutton

- sitting in “active” (white circle background) or sitting out
  “inactive” (grey circle background). Be careful! If you don’t get
  these regions right in your tablemap the scraper will be smart and
  optimize some of the more costly and now “superfluous” operations
  away. Luckily enough recognizing players sitting in or out is usually
  an easy and reliable colour-transform.

The FCKRA boxes on the bottom right indicate the status of the Fold,
Call, Check, Raise and Allin buttons; colored means those buttons are
seen as ready to be clicked, and white dotted outlines means they are
not seen as ready to be clicked.

Very similar, but not used by every tablemap, are the TIOLP buttons at
the bottom left. They display if you can click autopost, sit in, sit
out, leave.and prefold.
