# OpenHoldem Preferences – Validator

Validator preferences control various aspects of OpenHoldem’s Validator
engine. See the {Validator} section for more information. The purpose of
the Validator is to help people to develop more reliable bots and Table
Maps. It will execute several hundred consistency-checks at the symbol
level to detect invalid game-states, mis-scrapes or incomplete
information. The Validator will write possible problems to the log-file
and also show a message box, as long as messages are not disabled. The
rules used by the Validator are always being refined and developed. The
discussion forum is the best place to keep on top of this
(<a href="http://www.maxinmontreal.com/forums/viewtopic.php?f=189 "
class="uri">http://www.maxinmontreal.com/forums/viewtopic.php?f=189 </a>).

![image](images/preferences_validator.jpg)

- *Enable Validator*: This preference determines when the Validator is
  engaged to do its work, either never (completely off), when it is my
  turn, or always.

- *Use Heuristic Rules*: Some rules are heuristic, i.e. they are common
  sense, but not always true. Example: A game does usually not last
  longer than 2 minutes, so the autoplayer has to act at least once per
  120 seconds. If it does not do so, there seems to be a problem. Maybe
  the Table Map does not detect the players cards or the buttons. This
  setting can result in false positives and is recommended for testing
  only, but not for real-money-play.

- *Stop Autoplayer on error*: If the Validator discovers an
  inconsistency, and this preference is checked, the Autoplayer will be
  instructed to stop autoplaying.

- *Shoot replay-frame on error:* If the Validator discovers an
  inconsistency, and this preference is checked, OpenHoldem will shoot a
  replay-frame and store it in the replay-folder. The replay frame will
  help you to find the source of the error.

It is never a bad idea to use the validator some time for testing new
tablemaps. We recommend to enable it at your turn, because your turn is
the most important time in a game: here the decisions will be taken,
here perfect input matters most and here we usually have stable input,
as the casino usually will no longer update the regions that need to be
scraped. Give it a try, but be prepared – the validator is a little
bitch!

<figure>
<img
src="images/validator.jpg" />
</figure>
