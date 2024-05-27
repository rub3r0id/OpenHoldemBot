# OpenHoldem Preferences – Scraper

Scraper preferences control how the OpenHoldem Screen Scraper engine
functions. At the moment there is only one preference available here.
See the {Creating a Table Map} section for more information.

<figure>
<img src="Images/preferences_scraper.JPG" />
</figure>

- *Scrape Delay*: This parameter specifies the amount of time (in
  milliseconds) that the OpenHoldem Screen Scraper engine will pause in
  between subsequent screen scrape passes. This amount of time does not
  specify the time from the beginning of scrape 1 to the beginning of
  scrape 2, but rather the amount of delay between the end of scrape 1
  and the beginning of scrape 2. The primary consideration for this
  parameter is that of CPU consumption, and the default of 750ms seems
  to work well for most people.
