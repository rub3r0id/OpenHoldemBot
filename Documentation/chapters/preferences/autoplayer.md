# OpenHoldem Preferences – Autoplayer

Autoplayer preferences control how the OpenHoldem Autoplayer functions.
See the {The Autoplayer} section for more information.

<figure>
<img src="Images/preferences_autoplayer.JPG" />
</figure>

- *Stable frames required*: This parameter specifies how many additional
  simultaneous identical screen scrapes must occur prior to the
  Autoplayer taking action. Generally, you want to have a stable poker
  screen before your take action, and this setting will allow various
  animations and so forth to finish, ensuring that your poker logic has
  correct game state information prior to making a decision. A
  frame-delay of 0 would mean that OpenHoldem acts immediatelly after a
  scrape contains your cards and action buttons. Each additional frame
  will require a “full” heartbeat, but as soon as it is your turn the
  heartbeat-pause will be reduced by 50% to achieve a better combination
  of stable frames and fast response time.

- *Autoplayer delays:* These delays control the little pauses inside a
  more complex autoplayer action, for example the time between entering
  a betsize and clicking the raise button.

  - *Button click delay:* This setting contriols the delay (in
    milliseconds) between multpile button clicks (double and triple
    clicks).

  - *Select to delete*: For betsize actions, this setting determines how
    long (in milliseconds) that OpenHoldem will pause after performing
    the betsize select action as specified in the Table Map, and prior
    to performing the betsize delete action as specified in the Table
    Map. These preferences are not set in the Table Map itself, as these
    are highly dependent on your CPU and network capacity and
    utilization, and thus are largely specific to your particular
    computing environment.

  - *Delete to entry*: For betsize actions, this setting determines how
    long (in milliseconds) that OpenHoldem will pause after performing
    the betsize delete action as specified in the Table Map and prior to
    performing the betsize entry action. These preferences are not set
    in the Table Map itself, as these are highly dependent on your CPU
    and network capacity and utilization, and thus are largely specific
    to your particular computing environment.

  - *Entry to confirm*: For betsize actions, this setting determines how
    long (in milliseconds) that OpenHoldem will pause after performing
    the betsize entry action, and prior to performing the betsize
    confirm action as specified in the Table Map. These preferences are
    not set in the Table Map itself, as these are highly dependent on
    your CPU and network capacity and utilization, and thus are largely
    specific to your particular computing environment.

- *Engage Autoplayer automatically* upon connection: This setting
  instructs OpenHoldem to automatically start the Autoplayer
  immediatelly after it connects to the table. It is especially no
  longer necessary to identify the userchair for that. This way it
  becomes possible to control the option to auto-post blinds and do
  other minor tasks.

- *Use ‘comma’ instead of ‘dot’*: Some casinos require the use of the
  “comma” as a decimal separator rather than the “dot”. This setting
  will instruct OpenHoldem to use a comma if needed. Eventually this
  setting should be moved to the Table Map file itself, as it is
  casino-specific.

In the past OpenHoldem supported some more autoplayer options, namely
acting only with known cards, acting only with known balance (potential
occlusion of the table) and cancelling autoplayer-actions that got
interrupted by other applications or other tables that pop up (so-called
loss of input-focus). These options got removed because it makes sense
to have these sanity-checks and stability-features always enabled.
