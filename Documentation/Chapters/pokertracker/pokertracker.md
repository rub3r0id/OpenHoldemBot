# PokerTracker 

## Setup

Before you try to configure OpenHoldem to work with a Poker Tracker
database, you must have a properly working Poker Tracker configuration
set up first. This is not the most trivial of activities, and does have
a learning curve. The best information on how to set up Poker Tracker
can be found on the Poker Tracker website
(<http://www.pokertracker.com>).

Assuming you have a working Poker Tracker installation, let’s move on to
getting OpenHoldem to work with your Poker Tracker database. OpenHoldem
only works with PostgreSQL databases, not with Access databases; so if
you do not have Poker Tracker configured in that way (and you know if
you do), go back and get that set up first.

OK, so now you have Poker Tracker installed using PostgreSQL as the
underlying database. Do you have Poker Tracker setup to automatically
import hand histories into your database? If not, OpenHoldem will not be
able to provide you any useful information, as there will be no
information in your database to pull from. Learn how to automatically
import hand histories here: http://www.pokertracker.com

After all of that is configured, you can use the settings in
{Preferences} to instruct OpenHoldem how to connect to your Poker
Tracker database.

When connected, OpenHoldem will query the database using the sitename
and playername as key parameters for the query.

## Sitename 

Everything in Poker Tracker is first organized by what it calls a “site
id”. When querying the database, the first thing OpenHoldem will try to
do is associate your sitename or network, as specified in the Table Map,
to a Poker Tracker “site id”. This is done by doing a case-insensitive
substring lookup against the following lists. This means that if your
sitename string is “stars10sng” it will still be able to associate that
to the proper “site ID”, as “stars” is within that sitename.

If one of the below character strings can be found in either the
sitename or network strings, as specified in your Table Map file, using
a case-insensitive substring search, then OpenHoldem will be able to
lookup statistics for the players playing at your table. As a note, the
sitename string is searched first, and if a match cannot be found there,
then the network string is searched.

- Stars

- Party

- FullTilt

- IPoker

- Everest

- Ongame

- Boss

- Cereus

- Pacific

- B2B

- MicroGaming

- Cake

- Bodog

- BetFair

- Cryptologic

- Ultimate

- Absolute

- WPEX

- Tribeca

- Merge

- Winamax

- EverLeaf

- Yatahay

- ENet

- Barriere

- Peoples

## Playername 

The second critical piece of information that OpenHoldem needs to query
the database is the name of the player. OpenHoldem gets this from the
pXname/uXname regions on the Table Map. Note that this scraped name does
not need to exactly match the name as stored in the database. This is
useful, as there is currently no method for scraping spaces in players’
names. OpenHoldem will in all cases, return the statistics for an exact
name match if it exists, and if it does not exist, will find the closest
match using a Levenshtein distance algorithm
(<http://en.wikipedia.org/wiki/Levenshtein_distance>). Note that
Levenshtein distances that exceed a certain level (currently 30% of the
length of the name) are discarded as invalid.
