# OpenHoldem Preferences – Logging 

Logging preferences control what information OpenHoldem will
periodically write to various log files.

<figure>
<img src="Images/preferences_logging.JPG" />
</figure>

- *Basic Info*:This setting will cause OpenHoldem to log very basic
  information on every decision, giving you some hints what happened at
  the table and what OpenHoldem did. This information is given in a
  simple, beginner-friendly format, so that everybody can be able to
  understand what’s going on. But for more detailed information you
  should enable the next option.

      2014-09-30 07:11:37**** Basic Info *********************************************   
        Version:       7.3.4   
        Chairs:           10
        Userchair:         3
        Holecards:     5c5d
        Community:     ..........
        Handrank:      24
        Hand:          1pair
        My balance:      1000.00
        My currentbet:      0.00
        To call:           10.00
        Pot:               15.00
        Big blind:         10.00
        Big bet (FL):      20.00
        f$betsize:         30.00
        Formulas:      FC.RA   
        Buttons:       FC.RA   
        Best action:   f$betsize = 30.00
        Action taken:  f$betsize
      ***** Autoplayer Trace **************************************

- *Autoplayer Traces*: This option tells OpenHoldem to log the
  evaluation of formulas that lead to autoplayer actions, i.e the
  functions f\$allin, f\$betsize, f\$call for OH-script, the functions
  f\$preflop, f\$flop, f\$turn and f\$river for OpenPPL and also the
  evaluation of secondary functions like f\$sitout and f\$close. This
  information is very detailed and its interpretation will be discussed
  in the chapter about Logging.

- *Errors and Warnings*: This setting will write all errors and warnings
  to the log, which might be something like incomplete tablemaps,.
  syntax errors in your formula, run-time errors like division by zero
  or autoplayer errors like a missing input-box for the betsize. We
  consider this information so important that it will be always written
  to the log-file. No chance to turn it off.

- *DLL Messages*: Usually the autoplayer-trace will come to an end if a
  DLL-symbol gets evaluated as the DLL is a black-box for the
  OH-script-engine. However with this option enabled logging will
  continue even after DLL-symbols if the DLL calls back to OH-script to
  query the value of some OpenHoldem symbol or a user-defined function.

- *Maximum symbols to log*: This value defines how many special
  log-symbols shall be displayed in the white box in the GUI This
  affects user-defined log-messages that get printed when they get
  reached on evaluation:

      log$WOOHOO_preflop_works

- *Erase old logs larger than (MB):* This option does specify a maximum
  size of existing log-files (in mega-bytes). OpenHoldem does usually
  append new log messages to existing files. Unfortunatelly these
  log-files can grow really large, especially if you did enable detailed
  logging. With this option old files which are too large will be
  automatically deleted, if OpenHoldem opens them on startup.
