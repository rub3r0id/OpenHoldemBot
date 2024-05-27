# The Autoplayer<span id="sec:The-Autoplayer" label="sec:The-Autoplayer"></span> (OH-script)

OpenHoldem’s Autoplayer engine uses the following logic to decide what
action to take on the poker window when it is your turn and enough
stable frames have been seen:

1.  If the f\$prefold function evaluates to non-zero, and a fold control
    is present, then fold.

2.  Else if the f\$allin function evaluates to non-zero, and an all-in
    control is present (slider/betsize box/allin-button), then move
    all-in .

3.  Else if one of the betpot-functions (f\$betpot_2_1, f\$betpot_1_1,
    .. f\$betpot_1_4) is true then press the correspondenting
    betpot-button (and maybe the raise-button afterwards, depending on
    your casinos tablemap)

4.  Else if the f\$betsize function evaluates to non-zero, and an input
    box is present, then adapt the betsize according to a
    casino-specific input method, enter the result and confirm the bet.

5.  Else if the f\$raise function evaluates to non-zero, and the Raise
    button is present, then click the Raise button

6.  Else if the f\$call function evaluates to non-zero, and the Call
    button is present, then click the Call button

7.  Else if the f\$check function is true and the Check button is
    present, then click the Check button

8.  Else if the f\$fold function is true and the Fold button is present,
    then click the Check button
