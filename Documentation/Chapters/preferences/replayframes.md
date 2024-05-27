# OpenHoldem Preferences - Replay Frames

Replay Frames preferences control how OpenHoldem collects Replay Frames
for offline development and debugging use. See the {Replay Frames}
section for more information on using Replay Frames.

<figure>
<img src="Images/preferences_replay_frames.JPG" />
</figure>

- *Never*: If this setting is checked, OpenHoldem will not record any
  Replay Frames.

- *When it’s my turn*: If this setting is checked, OpenHoldem will
  collect exactly one replay-frame when it is your turn, exactly on the
  same heartbeat-cycle when the decision is taken. This is probably the
  most commonly used option, as it helps you to reproduce OpenHoldems
  decision making process.

- *On change in tablestate when in hand*: If this preference is checked,
  it instruct OpenHoldem to collect Replay Frames on every screen scrape
  cycle when you are in the hand. This option is usefuk to reproduce a
  complete game-history, but it avoids duplicate frames and thus saves
  space on your hard disk..

- *On change in tablestate when in hand*: Just lie the setting above
  this option will save every new replay-frame, but this time even if
  you are not in the hand. This might be usesful if you build your own
  stats-tracker, if you want to review your some of the
  secondary-formulas (f\$sitin, f\$close, ...) or if you want to build
  tablemaps that support these functions.

- *Maximum frames to store*: OpenHoldem will collect a maximum number of
  Replay Frames as specified by this parameter, then it will reuse
  filenames starting at the beginning.
