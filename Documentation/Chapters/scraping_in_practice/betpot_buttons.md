# Betpot Buttons

Betpot buttons work very similar to normal buttons.

- Each betpot button needs a clickable region, named betpot_X_Ybutton.
  X_Y is in the range 2_1 (2 \* pot) to 1_4 (1/4 \* pot). The transform
  is usually “None”.

- Each betpot button furthermore needs a betpot_X_Ybuttonstate that
  defines the visibility (and clickability) of that button.

- Contrary to other autoplayer buttons a betpot button does not need a
  label. Its type and action is defined by its naming.

<figure>
<img src="images_betpot_buttons/OS_betpot_3_4button.png" />
</figure>

# Confirming Betpot Actions

Usually it is sufficient if the autoplayer clicks the desired betpot
button, but some casinos need further input to confirm the action. To
support these casinos OpenHoldem supports an optional “betpotmethod”. If
this tablemap symbol is “raise” then OpenHoldems autoplayer will click
the raise-button after it has clicked a betpot button.
