# Seated, active, playing

A player will be considered:

- *seated*, if his chair is occupied

- *active*: if he is posting blinds, i.e not sitting out

- *playing*, if he holds cards; i.e either face-cards or cardbacks.

OpenHoldem will scrape the above information in this order and much
depends on getting this information right. For example if a player is
not even seated, then OpenHoldem will be smart and avoid the costly
scraping of cards and especially names. Fortunately deciding if a player
is seated or active can usually be done with an inexpensive and reliable
hash-transformation, which usually requires only the colour of a single
pixel.

Scraping cards works in a similar way: It requires:

- cardbacks: again this information can usually be scraped with a cheap
  and reliable colour-transform

- “nocard”-regions. These regions were introduced for two reasons: if a
  player holds no cards we can avoid the somewhat costly scraping for
  card-faces which usually requires fuzzy fonts. As an additional
  benefit we get improved error-detection in debug-mode, because a
  player either shows cardbacks, cardfaces or no-card.

- cardfaces (or alternatively ranks plus suits): this information can
  sometimes be done with hashes or images, if the cards are always
  displayed the same way: but often the display will differ a little bit
  and you will need text-scraping (fuzzy fonts).

In practice it looks like this:

Image|Situation|Parameters
-|-|-
![image](images_seated_active_playing/sap_1.jpg) | Not seated | <li>pXseated == false <li>Rest does not matter
![image](images_seated_active_playing/sap_2.jpg) | Seated, but sitting out | <li>pXseated == true <li>pXactive == false
![image](images_seated_active_playing/sap_3.jpg) | Seated and active, but not playing | <li>pXseated == true <li>pXactive == true <li>pXcardback == false <li>pYcardfaceYnocard == true
![image](images_seated_active_playing/sap_4.jpg) | Seated, active and playing (villain) | <li>pXseated == true  <li>pXactive == true <li>pXcardback == true
![image](images_seated_active_playing/sap_5.jpg) | Seated, active and playing <br> (usually hero, at some casinos villain at showdown) | <li>pXseated == true <li>pXactive == true <li>pXcardback == false <li>pXcardfaceYnocard == false

  
