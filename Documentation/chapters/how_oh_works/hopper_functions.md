# Hopper functions

Once every four seconds OpenHoldem will evaluate and execute some
hopper-functions.

Function | Explanation  
-|-
f\$sitin | OpenHoldem will click the sitin-button (i.e. the button with label “sitin”) if f\$sitin evaluates to true.  
f\$sitout | OpenHoldem will click the sitout-button if f\$sitout evaluates to true.  
f\$leave | OpenHoldem will click the leave-button if f\$leave evaluates to true.  
f\$close | OpenHoldem will click the \[x\] in the titlebar of the table if f\$close evaluates to true.  
f\$rematch | OpenHoldem will click the rematch-button if f\$rematch evaluates to true.  
f\$autopost | OpenHoldem will click the autopost-button if f\$autopot evaluates to true.  
f\$rebuy | OpenHoldem will execute a user-defined rebuy-script if f\$rebuy evaluates to a positive target-amount (in dollars) and safety constraints have been met. For the details please see the chapters about automation and about the preferences dialog for rebuys.
f\$select_formula_file | OpenHoldem evaluates this function once per handreset and will load the formula-file that got selected by the loadformula\$XYZ-symbolm . The file is expected to be in the bot_logic-directory. Example:<table><tr><td>
```
##f$select_formula_file## 
  WHEN (StackSize < 15) RETURN loadformula$push_fold$ohf FORCE
  WHEN issng RETURN loadformula$my_sng_bot$ohf FORCE
```
</td></tr></table>