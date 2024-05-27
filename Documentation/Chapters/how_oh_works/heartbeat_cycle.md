# The Heartbeat-Cycle

Once OpenHoldem has been connected to a table, it will enter into a
continuous loop that performs a variety of actions. The cycle of these
actions is described here in order of their execution.

Action | Explanation  
-|-
Scrape window | Ask the *screen scraper* engine to scrape and interpret the current pixels on the poker window based on the parameters in the loaded  ablemap. The scraper will look for example if a chair is occupied, if the player is sittong out, what the players betsize is and so on. It then will and over this information to the game-state-engine.  
Scraper preprocessor | OpenHoldems built-in *scraper preprocessor* will then preprocess some textual input from the scraper; especially title-string,  ets and balances. For example it will remove spaces inside numbers, replace commas inside numbers by dots, replace outlandish currency-signs by dollars r remove other superflous texts, such as “pot: (150 + 300)”.
Create replay frames | If a *replay frame* is requested in preferences , OpenHoldem will store an image file and a HTML-file in the replay-directory for a future settion-review with OHReplay  
Calculate symbols | Calculate the built-in OpenHoldem *symbols* that can be accessed by the user-defined poker-logic.  
Validate game state | If the *validator* is enabled in preferences, then it will check the current game state for inconsistencies that are usually caused by mis-scrapes or bad tablemaps.  
Evaluate the bot-logic | If it is our turn and the scraper-engine saw enough *stable frames* then OpenHoldem will evaluate the set of formulas that got provided by the user. <br><br> <li> OH-script: f\$alli..f\$fold <li>OpenPPL: f\$preflop..f\$river <br><br> This user-defined bot-logic usually resides in a plain-text file with the extension \*.ohf (OpenHoldem formula), \*.oppl (OpenPPL) or \*.txt (also OpenPPL)  
Handle spam | Evaluate any i86 regions, and dismiss any popups that occlude the table.  
Autoplay | If the autoplayer is engaged, then OpenHoldem will act: press buttons, enter betsizes, move the slider. The autoplayer will try to execute the most aggressive actions first, then continue with less agressive ones, i.e. in the following order: <li>f\$allin <li>f\$betpot_2_1 .. f\$betpot_1_4 <li>f\$betsize <li>f\$raise <li>f\$call <li>f\$check <li>f\$fold <br><br> The autoplayer works – as the name suggests – automatically, but the necessary actions differ a bit for each casino, therefore the autoplayer can be customized with the tablemap. For example you can tell how an old betsize should be selected before a new one can be entered: <table align="center"><tr><td>s$betsizeselectionmethod</td><td>Click Drag</td></tr></table> We will deal with that in the chapter about tablemaps.  
Wait | Sleep for some time, then start the next cycle. The heartbeat-sleeping-time can be specified in the preferences and defaults to 750 ms. However  the heartbeat delay is somewhat flexible: we scrape faster if it is our turn to act for faster reaction times and we sleep longer when we have no cards (folded) or if we are not seated at all to optimize CPU-usage.
