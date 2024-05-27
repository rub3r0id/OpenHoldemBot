# Hand Lists 

## OpenHoldem Hand List Editor

<figure>
<img
src="images/handlist_editor_matrix.jpg" />
</figure>

The OpenHoldem Hand List editor is displayed when you click on the “3x3
yellow squares” toolbar button from the Formula Editor window. This
provides a graphical interface for defining the Hand Lists as used
within OpenHoldem for various symbols and functions. The output of this
window is not all that difficult to understand, and if you choose your
card pairs here, save your formula, then open the formula in a text
editor, you can quite easily see the format used.

On this window, you specify which of your 169 starting hands (hole
cards) are included in which Hand List. In the screen shot above, Hand
List 7 was selected prior to clicking the “3x3 yellow squares” toolbar
button. There is a diagonal group of starting hands running from top
left to bottom right and identified with bolded checkboxes. These are
the paired starting hands, i.e. AA, KK, JJ, 55. Above this diagonal line
are checkboxes for the suited starting hands, i.e. AhKh, 3s2s, Jc7c.
Below this diagonal line are checkboxes for the unsuited starting hands,
i.e. AhJc, 3d2h.

When the “OK” button is clicked, the starting hand selections you have
made are saved to the Hand List you selected.

## Using Hand Lists 

Hand lists are used by the following calculated symbols, and can be
referenced in OH-Script code, or DLL-based logic.

| Symbol  | Meaning                                        |
|:--------|:-----------------------------------------------|
| listXYZ | true if your hand is in the list named listXYZ |
