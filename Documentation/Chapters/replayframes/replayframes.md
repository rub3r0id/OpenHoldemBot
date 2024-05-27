# Replay Frames 

OpenHoldem has the ability to create “Replay Frames”, either
automatically as set in Preferences, or when the “camera” icon on the
main toolbar {Toolbars} is clicked. A “Replay Frame” (or “frame” for
short), is a combination of a Windows bitmap-formatted image file (.bmp)
and an associated HTML file. These two files, in combination, provide an
easy way to reproduce and diagnose a particular game situation. This is
extremely helpful in the building and testing of your Table Maps and bot
logic in an offline fashion. Simply connect OpenHoldem to a live poker
table, and collect interesting frames for later use. Then at a later
time, use OHReplay to display these frames. Further connect OpenScrape
or OpenHoldem to these OHReplay-displayed frames and work at your
leisure.

The HTML provides crucial context for the frame, the most important of
which is the title text. This text is used exhaustively in most Table
Maps to understand the game state.

Often, when you post a problem or discussion on the forums, you will be
asked to provide a frame and Table Map to help the developers diagnose
your problem. Feel free to open the bitmap image in your favorite image
editor (MS Paint?) and black out the sensitive portions if needed. Be
aware that blacking out some parts of the image may prevent the
developers or community from helping you, so be careful with that.

<div class="rem">

* 1.1*. Both parts of the frame (.bmp and .html) and the associated
Table Map are required to be provided when this is asked from you to
help solve your problem!

</div>

Frames are created in a “replay” directory directly under the directory
from which you launched OpenHoldem. The .bmp files are large, so ensure
that you have enough space to hold the maximum number of frames you
specified in {Preferences}. Once the maximum number is reached,
OpenHoldem will start reusing frame numbers from the beginning.
